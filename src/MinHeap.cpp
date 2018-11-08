#include "MinHeap.h"

MinHeap::MinHeap(int capacity) : data(new int[capacity]), capacity(capacity), lenght(0){
}

int MinHeap::getParent(int position) {
	return (int)std::floor((position-1)/2);
}

int MinHeap::getRightChild(int parent) {
	return (parent + 1) / 2;
}

int MinHeap::getLeftChild(int parent) {
	return (parent - 1) / 2;
}

int MinHeap::getMin() {
	return data[0];
}

void MinHeap::insertInTheLast(int key) {
	data[lenght++] = key;
}

void MinHeap::insert(int key) {
	assert(lenght != capacity);
	insertInTheLast(key);
	this->trickleUp(lenght-1);
}

void MinHeap::swap(int from, int to) {
	int temporal = data[from];
	data[from] = data[to];
	data[to] = temporal;
}

bool MinHeap::isChildLesserThanParent(int position) {
	return data[position] < data[this->getParent(position)];
}

void MinHeap::trickleUp(int position) {
	while (isChildLesserThanParent(position)) {
		this->swap(position, this->getParent(position));
		position = this->getParent(position);
	}
}

void MinHeap::changeKey(int position, int key) {
	assert(this->isInTheRange(position));
	data[position] = key;
	this->trickleUp(position);
}

void MinHeap::removeByPosition(int position) {
	this->swap(position, lenght-1);
	--lenght;
	this->trickleDown(position);
}

int MinHeap::operator [](int position) {
	assert(this->isInTheRange(position));
	return data[position];
}

int MinHeap::getLenght() {
	return lenght;
}


void MinHeap::buildMaxHeap() {
	for (int parent = std::floor(lenght/2 - 1); 0 <= parent; --parent) {
		this->heapify(parent, lenght);
	}
}

void MinHeap::sort() {
	buildMaxHeap();
	for (int i = lenght-1; 0 <= i; --i) {
		this->swap(0, i);
		this->heapify(0, i);
	}
}

bool MinHeap::isParentLesserThanChild(int parent, int child) {
	return this->isParentGreaterThanChild(child, parent);
}

bool MinHeap::isParentGreaterThanChild(int parent, int child) {
	return data[parent] > data[child];
}

void MinHeap::trickleDown(int parent) {
	assert(this->isInTheRange(parent));
	int leftChild = this->getLeftChild(parent);
	int rightChild = this->getRightChild(parent);
	int smallestChild = parent;
	if (this->isInTheRange(leftChild) && isParentGreaterThanChild(parent, leftChild)) {
		smallestChild = leftChild;
	}
	if (this->isInTheRange(rightChild) && isParentGreaterThanChild(smallestChild, rightChild)) {
		smallestChild = rightChild;
	}
	if(smallestChild != parent){
		this->swap(parent, smallestChild);
		this->trickleDown(smallestChild);
	}
}

void MinHeap::heapify(int parent, int lenght) {
	assert(this->isInTheRange(parent));
	int leftChild = this->getLeftChild(parent);
	int rightChild = this->getRightChild(parent);
	int largesttChild = parent;
	if (this->isInTheRange(leftChild, lenght)
			&& isParentLesserThanChild(parent, leftChild)) {
		largesttChild = leftChild;
	}
	if (this->isInTheRange(rightChild, lenght)
			&& isParentLesserThanChild(largesttChild, rightChild)) {
		largesttChild = rightChild;
	}
	if (largesttChild != parent) {
		this->swap(parent, largesttChild);
		this->heapify(largesttChild, lenght);
	}
}

bool MinHeap::isInTheRange(int position) {
	return this->isInTheRange(position, this->lenght);
}

bool MinHeap::isInTheRange(int position, int lenght) {
	return 0 <= position && position < lenght;
}

MinHeap::~MinHeap() {
	delete data;
}

