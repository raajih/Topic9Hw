#include "ArrayMaxHeap.h"

template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const
{
	int leftChildIndex = (nodeIndex * 2) + 1;

	if (leftChildIndex < itemCount)
		return leftChildIndex;
	else
		return -1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(int nodeIndex) const
{
	int rightChildIndex = (nodeIndex * 2) + 2;

	if (rightChildIndex < itemCount)
		return rightChildIndex;
	else
		return -1;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(int nodeIndex) const
{
	if (nodeIndex == ROOT_INDEX)
		return -1;
	else
		return ((nodeIndex - 1) / 2);
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const
{
	return (getLeftChildIndex(nodeIndex) == -1 && getRightChildIndex(nodeIndex) == -1);
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int subTreeRootIndex)
{
	if (!isLeaf(subTreeRootIndex))
	{
		int leftChildIndex = getLeftChildIndex(subTreeRootIndex);
		int rightChildIndex = getRightChildIndex(subTreeRootIndex);
		int largerChildIndex = leftChildIndex; //Assume left is larger, must have a left
		if (rightChildIndex != -1) //Has a right?
			if (items[rightChildIndex] > items[leftChildIndex]) //Is right greater?
				largerChildIndex = rightChildIndex; //Right is larger child.

		//Find out if larger child is bigger than current node.
		if (items[subTreeRootIndex] < items[largerChildIndex])
		{
			ItemType temp = items[subTreeRootIndex];
			items[subTreeRootIndex] = items[largerChildIndex];
			items[largerChildIndex] = temp;

			//Recursively go down heap
			heapRebuild(largerChildIndex);
		}
	}
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate()
{
	for (int index = itemCount / 2; index >= 0; index--)
		heapRebuild(index);
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;
	items = new ItemType[maxItems]; //Using new because items is a pointer.
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const ItemType someArray[], const int arraySize)
{
	maxItems = arraySize * 2;
	itemCount = arraySize;
	items = new ItemType[maxItems];

	//Copy values into array
	for (int i = 0; i < itemCount; i++)
		items[i] = someArray[i];

	heapCreate();
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap()
{
	delete[] items;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const
{
	return itemCount == 0;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const
{
	return itemCount;
}

template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const
{
	if (itemCount > 0)
		return floor(log2(itemCount)) + 1;
	else
		return 0;//If heap is empty.
}

template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcep)
{
	if (itemCount > 0)
		return items[ROOT_INDEX];
	else
		throw PrecondViolatedExcep("Called peekTop on an empty heap");
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData)
{
	//Heap is full and cannot add any items.
	if (itemCount == maxItems)
		return false;

	items[itemCount] = newData;

	//Bubble up until item is in correct place.
	int newDataIndex = itemCount;
	bool inPlace = false;
	if (itemCount == 0)
		inPlace = true;
	while (newDataIndex >= ROOT_INDEX && !inPlace) //Keep going until we hit the root or item is in place.
	{
		int parentIndex = getParentIndex(newDataIndex);
		if (parentIndex == -1)
			inPlace = true;
		else
		{
			if (items[newDataIndex] < items[parentIndex])
				inPlace = true;
			else
			{
				ItemType temp = items[newDataIndex];
				items[newDataIndex] = items[parentIndex];
				items[parentIndex] = temp;
				newDataIndex = parentIndex;
			}
		}
	}

	itemCount++;
	return true;
}

template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove()
{
	if (isEmpty())//Nothing to remove, return false.
		return false;
	
	items[ROOT_INDEX] = items[itemCount - 1];//Put last item in heap to the top of heap.
	itemCount--;
	heapRebuild(ROOT_INDEX);
	return true;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::dbg()
{
	for (int i = 0; i < itemCount; i++)
		cout << i << "=" << items[i] << endl;
}

template<class ItemType>
void ArrayMaxHeap<ItemType>::clear()
{
	itemCount = 0;
}
