/** Heap-based implementation of the ADT priority queue. 
@file Heap_PriorityQueue.cpp */ 
#include "Heap_PriorityQueue.h" 
template< class ItemType> 
Heap_PriorityQueue<ItemType>::Heap_PriorityQueue() 
{ 
    ArrayMaxHeap<ItemType>(); 
} // end constructor 
template<class ItemType> 
bool Heap_PriorityQueue<ItemType>::isEmpty() const
{ 
    return ArrayMaxHeap<ItemType>::isEmpty(); 
} // end isEmpty 
template<class ItemType> 
bool Heap_PriorityQueue<ItemType>::add(const ItemType& newEntry) 
{ 
    return ArrayMaxHeap<ItemType>::add(newEntry); 
} // end add 
template<class ItemType> 
bool Heap_PriorityQueue<ItemType>::remove() 
{ 
    return ArrayMaxHeap<ItemType>::remove(); 
} // end remove 
template<class ItemType>
void Heap_PriorityQueue<ItemType>::clear()
{
    return ArrayMaxHeap<ItemType>::clear();
}
template<class ItemType> 
ItemType Heap_PriorityQueue<ItemType>::peek() const throw(PrecondViolatedExcep) 
{ 
    try
    { 
        return ArrayMaxHeap<ItemType>::peekTop(); 
    } 
    catch (PrecondViolatedExcep e) 
    { 
        throw PrecondViolatedExcep("Attempted peek into an empty priority queue."); 
    } // end try/catch 
} // end peek