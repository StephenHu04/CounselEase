#pragma once
#include <iostream>
#include "Date.hpp"

class PriorityQueue {

public:

	//constructor that takes an int
	PriorityQueue(int total);

	//deconstructor
	~PriorityQueue();

	//removes minimum from the heap
	void removeMin();

	//finds the minimum in the priority queue
	Date findMin();

	//functions that allows user to insert date into heap
	bool insert(Date newDate);

	//function that is used to set all items in the right priority q to the left
	void swap(PriorityQueue &rightQ, int i);

	//function that is used to set all items in the right priority q to the left
	void operator = (PriorityQueue &rightQ);

	int total;

private:

	//swap two nodes in the heap
	void swap(int i, int j);

	//function that returns true or false if the left child exist
	bool leftChild(int i);

	//function that returns true or false if the right child exist
	bool rightChild(int i);

	//returns the parent node given an idex
	int getParent(int);

	//returns the left child node given an idex
	int getLeft(int);

	//returns the right child node given an idex
	int getRight(int);

	//recursive function that sifts the value down
	void siftDown(int);

	//recursive function that sifts the value up
	void siftUp(int);

	//private variables for array
	Date *priorityQueue;
	int priorityQueueSize;

};

