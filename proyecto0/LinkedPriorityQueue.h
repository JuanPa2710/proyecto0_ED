#pragma once
#include <stdexcept>
#include "PriorityQueue.h"
#include "LinkedQueue.h"

using std::runtime_error;

template <typename E>
class LinkedPriorityQueue : public PriorityQueue<E> {
private:
	LinkedQueue<E>* queues;
	int priorities;
	int size;

	int firstQueue() {
		for (int i = 0; i < priorities; i++) {
			if (!queues[i].isEmpty())
				return i;
		}
		throw runtime_error("Queue not found.");
	}

public:
	LinkedPriorityQueue(int priorities) {
		if (priorities < 1)
			throw runtime_error("Invalid number of priorities.");
		queues = new LinkedQueue<E>[priorities];
		this->priorities = priorities;
		size = 0;
	}

	~LinkedPriorityQueue() {
		delete[] queues;
	}

	void insert(E element, int priority) {
		if (priority < 0 || priority >= priorities)
			throw runtime_error("Invalid priority.");
		queues[priority].enqueue(element);
		size++;
	}

	void remove(E element) {
		for (int i = 0; i < priorities; i++) {
			try {
				queues[i].remove(element);
				size--;
				return;
			}
			catch (runtime_error& e) {
			}
		}
		throw runtime_error("Element not found in the priority queue.");
	}

	E min() {
		if (size == 0)
			throw runtime_error("Priority queue is empty.");
		return queues[firstQueue()].frontValue();
	}

	E removeMin() {
		if (size == 0)
			throw runtime_error("Priority queue is empty.");
		size--;
		return queues[firstQueue()].dequeue();
	}

	void clear() {
		for (int i = 0; i < priorities; i++)
			queues[i].clear();
		size = 0;
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void print() {
		for (int i = 0; i < priorities; i++) {
			cout << i << ": ";
			queues[i].print();
		}
	}

};

