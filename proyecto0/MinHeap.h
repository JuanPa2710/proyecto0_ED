#pragma once
#define DEFAULT_MAX 1024

#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class MinHeap {
private:
	E* elements;
	int max;
	int size;

	void siftUp(int pos) {
		while (pos != 0 && elements[pos] < elements[parent(pos)]) {
			swap(pos, parent(pos));
			pos = parent(pos);
		}
	}

	void siftDown(int pos) {
		while (!isLeaf(pos) && elements[pos] > elements[minChild(pos)]) {
			int mChild = minChild(pos);
			swap(pos, mChild);
			pos = mChild;
		}
	}

	int parent(int pos) {
		return (pos - 1) / 2;
	}

	int leftChild(int pos) {
		return 2 * pos + 1;
	}

	int rightChild(int pos) {
		return 2 * pos + 2;
	}

	bool isLeaf(int pos) {
		return leftChild(pos) >= size;
	}

	void swap(int pos1, int pos2) {
		E temp = elements[pos1];
		elements[pos1] = elements[pos2];
		elements[pos2] = temp;
	}

	int minChild(int pos) {
		if (rightChild(pos) >= size || 
			elements[leftChild(pos)] < elements[rightChild(pos)])
			return leftChild(pos);
		return rightChild(pos);
	}

public:
	MinHeap(int max = DEFAULT_MAX) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		size = 0;
		this->max = max;
	}

	~MinHeap() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			throw runtime_error("Heap is full.");
		elements[size] = element;
		size++;
		siftUp(size - 1);
	}

	E first() {
		if (size == 0)
			throw runtime_error("Heap is empty.");
		return elements[0];
	}	

	E removeFirst() {
		if (size == 0)
			throw runtime_error("Heap is empty.");
		return remove(0);
	}	

	E remove(int pos) {
		if (pos < 0 || pos >= size)
			throw runtime_error("Index out of bounds.");
		swap(pos, size - 1);
		size--;
		siftDown(pos);
		return elements[size];
	}

	void clear() {
		for (int i = 0; i < size; i++) {
			E temp = elements[i];
			delete temp;
		}

		elements[0];
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void print() {
		int temp = 0;
		for (int i = 0; i < size; i++) {
			if (i == temp) {
    			cout << (i != 0? "]" : "") << "\n[ ";
				temp = temp * 2 + 1;
			}
			cout << elements[i] << " ";
		}

		cout << "]\n";
	}

	void printShow() {
		for (int i = 0; i < size; i++) {
			cout << "-" << elements[i] << "- ";
		}
	}

};

