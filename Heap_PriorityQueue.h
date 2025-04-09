/** ADT priority queue: Heap-based implementation. 
 @file Heap_PriorityQueue.h */ 
#ifndef _HEAP_PRIORITY_QUEUE 
#define _HEAP_PRIORITY_QUEUE
#include "ArrayMaxHeap.h" 
//TODO: get this file#include "PriorityQueueInterface.h" 
template<class ItemType>
//TODO: when you get PriorityQueueInterface, add public PriorityQueueInterface<ItemType>, before private ArrayMaxHeap<ItemType> here
class Heap_PriorityQueue : private ArrayMaxHeap<ItemType> 
{ 
public: 
    Heap_PriorityQueue(); 
    bool isEmpty() const;
    bool add(const ItemType& newEntry);
    bool remove();
    void clear(); //Added method
    /** @pre The priority queue is not empty. */ 
    ItemType peek() const throw(PrecondViolatedExcep); 
}; // end Heap_PriorityQueue 
#include "Heap_PriorityQueue.cpp" 
#endif 