//Raajih Roland
//Heap Homework
#include <iostream>
#include "Heap_PriorityQueue.h"
using namespace std;

//Struct to hold items in queue
struct Item
{
	int priority;
	string task;

	bool operator<(Item rhs)
	{
		return this->priority < rhs.priority;
	}

	bool operator>(Item rhs)
	{
		return this->priority > rhs.priority;
	}

	bool operator==(Item rhs)
	{
		return this->priority == rhs.priority;
	}
};

int main()
{
	Heap_PriorityQueue<Item> list;
	int tempPriority, choice;
	string tempTask;
	Item item;

	cout << "Welcome to your to do list\n\n";
	do {
		
			cout << "1)Add new item to list\n"
			<< "2)View most important item\n"
			<< "3)Remove most important item from list\n"
			<< "4)Clear list\n"
			<< "5)Quit\n"
			<< "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nEnter the priority of your item (more important tasks have higher numbers): ";
			cin >> tempPriority;
			cin.ignore();
			cout << "\nEnter your task: ";
			getline(cin, tempTask);

			//Put correct priority and task in Item, then add item to queue
			item.priority = tempPriority;
			item.task = tempTask;
			list.add(item);
			break;
		case 2:
			try
			{
				cout << "\nTask: " << list.peek().task << endl;
			}
			catch (PrecondViolatedExcep)
			{
				cout << "\nList is empty!\n";
			}
			break;
		case 3:
			if (list.remove())
				cout << "\nTask removed\n";
			else
				cout << "\nNo tasks in list\n";
			break;
		case 4:
			list.clear();
			cout << "\nList cleared\n";
			break;
		case 5:
			break;
		default:
			cout << "\nInvalid choice, please try again.\n";
			break;
		}

	} while (choice != 5);

	
	

	return 0;
}