//TODO: Due to the tree being complete and full. To get the children of a node, multiply the index of node then add 1 for the left node, or add 2 for right node.
//TODO: To get the parent node. Subtract by 1 then divide by 2 (works for both because int math truncates decimal)
#include <iostream>
#include "ArrayMaxHeap.h"
using namespace std;

int main()
{
	ArrayMaxHeap<int> h;
	cout << h.getHeight() << endl;
	cout << h.getNumberOfNodes() << endl;
	cout << h.isEmpty() << endl;

	return 0;
}