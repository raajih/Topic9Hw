//TODO: Due to the tree being complete and full. To get the children of a node, multiply the index of node then add 1 for the left node, or add 2 for right node.
//TODO: To get the parent node. Subtract by 1 then divide by 2 (works for both because int math truncates decimal)
#include <iostream>
#include "ArrayMaxHeap.h"
using namespace std;

int main()
{
	//TODO: wasn't supposed to add QueueInteface, supposed to be priority queue interface so check attachments to see if prof fixed that
	ArrayMaxHeap<int> h;

	h.add(10);
	cout << h.getHeight() << endl;
	cout << h.getNumberOfNodes() << endl;
	cout << h.isEmpty() << endl;

	h.add(9);
	h.add(6);
	cout << h.getHeight() << endl;
	h.add(3);
	h.add(2);
	h.add(5);

	h.getHeight();
	h.dbg();
	h.remove();
	h.dbg();

	return 0;
}