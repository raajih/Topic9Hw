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
ArrayMaxHeap<ItemType>::ArrayMaxHeap()
{
	itemCount = 0;
	maxItems = DEFAULT_CAPACITY;
	items = new ItemType[maxItems]; //Using new because items is a pointer.
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
		return items[0];
	else
		throw PrecondViolatedExcep("Called peekTop on an empty heap");
}
