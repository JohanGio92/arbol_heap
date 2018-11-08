#include <iostream>
#include "MinHeap.h"
using namespace std;

int main() {
	MinHeap heap(7);
	heap.insert(4);
	heap.insert(3);
	heap.insert(8);
	heap.insert(9);
	heap.insert(2);
	heap.insert(1);

	for (int i = 0; i < heap.getLenght(); ++i) {
		cout << heap[i] << endl;
	}
	std::cout << "-------------------------------" << std::endl;
//	heap.removeByPosition(3);
	heap.sort();
	for (int i = 0; i < heap.getLenght(); ++i) {
		cout << heap[i] << endl;
	}
	return 0;
}
