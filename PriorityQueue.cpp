#include "PriorityQueue.hpp"

//Time complexity would be O(1) since it can be done in constant time
PriorityQueue::PriorityQueue(int total) {
	this->priorityQueueSize = 0;
	this->total = total;
	this->priorityQueue = new Date[total];
}

//Time complexity would be O(1) since it can be done in constant time
PriorityQueue::~PriorityQueue() {
	this->priorityQueueSize = 0;
	this->total = 0;
	delete this->priorityQueue;
}

//Time complexity would be O(1) since it can be done in constant time
int PriorityQueue::getParent(int i) {
	return (i - 1) / 2;
}

//Time complexity would be O(1) since it can be done in constant time
int PriorityQueue::getLeft(int i) {
	return (2 * i + 1);
}

//Time complexity would be O(1) since it can be done in constant time
int PriorityQueue::getRight(int i) {
	return (2 * i + 2);
}

//Time complexity would be O(1) since it can be done in constant time
void PriorityQueue::swap(int i, int j) {
	Date temp = this->priorityQueue[i];
	this->priorityQueue[i] = this->priorityQueue[j];
	this->priorityQueue[j] = temp;
}

//Time complexity would be O(1) since it can be done in constant time
bool PriorityQueue::leftChild(int i) {
	return (getLeft(i) < this->priorityQueueSize);
}

//Time complexity would be O(1) since it can be done in constant time
bool PriorityQueue::rightChild(int i) {
	return (getRight(i) < this->priorityQueueSize);
}

//Time complexity would be O(logn) because the number of choices
//would keep cutting down by about 1/2 every time where n is the size of the heap
void PriorityQueue::siftDown(int i) {

	int left = getLeft(i);
	int right = getRight(i);

	int smallest = i;
	if (left < priorityQueueSize && priorityQueue[left] < priorityQueue[i])
		smallest = left;
	if (right < priorityQueueSize
			&& priorityQueue[right] < priorityQueue[smallest])
		smallest = right;

	if (smallest != i) {
		swap(i, smallest);
		siftDown(smallest);
	}
}


//Time complexity would be O(n) where n is the size of the array
//because it swaps with its parents, which manages to be close to linear
void PriorityQueue::siftUp(int i) {
	if (i != 0){
		int parent = getParent(i);
		if(priorityQueue[parent] > priorityQueue[i]){
			swap(parent,i);
			siftUp(parent);
		}
	}
}

//Time complexity would be O(n) where n is the size of the array
//because it swaps with its parents, which manages to be close to linear
bool PriorityQueue::insert(Date newDate) {
	//if there is no more space in the heap, prompt user
	if (this->priorityQueueSize == this->total) {
		return false;
	} else {
		this->priorityQueueSize++;
		priorityQueue[this->priorityQueueSize - 1] = newDate;
		siftUp(this->priorityQueueSize - 1);
//		std::cout << priorityQueue[0] << std::endl;
		return true;

	}
}

//Time complexity would be O(1) since it can be done in constant time
Date PriorityQueue::findMin(){
	return this->priorityQueue[0];
}

//Time complexity would be O(1) since it can be done in constant time
void PriorityQueue::removeMin() {
	priorityQueue[0] = priorityQueue[priorityQueueSize - 1];
	priorityQueueSize--;
	siftDown(0);
}

//Time complexity would be O(n) n being the number of items in the array
void PriorityQueue::swap(PriorityQueue &rightQ, int i){
	if(i == rightQ.priorityQueueSize){
		return;
	}
	else{
		this->priorityQueue[i] = rightQ.priorityQueue[i];
		swap(rightQ, i++);
	}
}

//Time complexity would be O(n) n being the number of items in the array
void PriorityQueue::operator =(PriorityQueue &rightQ) {
	delete[] this->priorityQueue; // Delete existing memory
	this->total = rightQ.total;
	this->priorityQueueSize = rightQ.priorityQueueSize;
	this->priorityQueue = new Date[rightQ.total];
	// Copy the contents of oldQ.priorityQueue to this->priorityQueue
	swap(rightQ,0);
}
