#ifndef MINHEAP_H_
#define MINHEAP_H_

#include <cmath>
#include <cassert>

class MinHeap {
private:
	int* data;
	int capacity;
	int lenght;
public:
	MinHeap(int capacity);
	int getParent(int position);
	int getRightChild(int parent);
	int getLeftChild(int parent);
	int getLenght();
	void changeKey(int position, int key);
	int getMin();
	void removeByPosition(int position);
	void insert(int key);
	int operator[](int position);
	void sort();
	virtual ~MinHeap();
private:
	void insertInTheLast(int key);
	void swap(int from, int to);
	void trickleUp(int position);
	void trickleDown(int position);
	void heapify(int parent, int lenght);
	bool isInTheRange(int position, int lenght);
	bool isInTheRange(int position);
	bool isChildLesserThanParent(int position);
	bool isParentGreaterThanChild(int parent, int child);
	bool isParentLesserThanChild(int parent, int child);
	void buildMaxHeap();
};

#endif
