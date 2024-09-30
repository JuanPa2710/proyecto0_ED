#pragma once

#define DEFAULT_MAX 1024

#include <stdexcept>
#include <iostream>
#include "List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
protected:
	E* elements;
	int max;
	int size;
	int pos;

private:
	void expand() {
		max = max * 2;
		E *temp = new E[max];

		for (int i = 0; i < size; i++) {
			temp[i] = elements[i];
		}
		delete[] elements;
		elements = temp;
		cout << "Se expande el espacio a: " << max << endl;
	}

public:
	ArrayList(int max = DEFAULT_MAX) {
		if (max < 1)
			throw runtime_error("Invalid max size.");
		elements = new E[max];
		this->max = max;
		size = 0;
		pos = 0;
	}

	~ArrayList() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			expand();

		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];
		elements[pos] = element;
		size++;
	}

	void append(E element) {
		if(size == max)
			expand();

		elements[size] = element;
		size++;
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");

		E result = elements[pos];
		for (int i = pos + 1; i < size; i++)
			elements[i - 1] = elements[i];
		size--;
		return result;
	}

	E getElement() {
		if (size == 0)
			throw runtime_error("List is empty.");
		if (pos == size)
			throw runtime_error("No current element.");
		return elements[pos];
	}

	void clear() {
		size = pos = 0;
	}

	void goToStart() {
		pos = 0;
	}

	void goToEnd() {
		pos = size;
	}

	void goToPos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds.");
		this->pos = pos;
	}

	void next() {
		if (pos < size)
			pos++;
	}

	void previous() {
		if (pos > 0)
			pos--;
	}

	bool atStart() {
		return pos == 0;
	}

	bool atEnd() {
		return pos == size;
	}

	bool contains(E element) {
		if (size == 0)
			throw runtime_error("List is empty.");

		int i = 0;
		while (i < size) {
			if (element == elements[i])
				return true;
			i++;
		}

		return false;
	}

	int indexOf(E element, int start) {
		if (size == 0)
			throw runtime_error("List is empty.");

		if (start < 0 || start >= size)
			throw runtime_error("Index out of bounds.");

		int i = start;
		while (i < size) {
			if (element == elements[i])
				return i + 1;
			i++;
		}

		return -1;
	}

	int getPos() {
		return pos;
	}

	int getSize() {
		return size;
	}

	void print() {
		cout << "[ ";
		for (int i = 0; i < size; i++) {
			if (i == pos)
				cout << "*";
			cout << elements[i] << " ";
		}
		if (pos == size)
			cout << "*";
		cout << "]" << endl;
	}

	void printShow() {
		for (int i = 0; i < size; i++) {
			cout << i + 1 << ". " << elements[i] << " ";
		}
	}
};
