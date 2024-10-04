/*
Archivo el cual define el comportamiento de las listas de arreglos.
Contiene sus atributos protegidos, incluyendo un puntero a los elementos, y varios enteros que definen el tamaño máximo de la lista, el tamaño actual, y la posición
actual.
En cuanto su aspecto privado, tenemos expand, el cual expande el almacenamiento de la lista al doble.
En sus métodos públicos tenemos el constructors, el cual recibe el tamaño máximo, el destructor donde se libra la memoria donde se tenía la lista, insert agrega un
elemento al final de la lista, append agrega de igual manera un elemento pero lo agrega al final de la lista, remove elimina el elemento en la posición actual,
getElement retorna el elemento en la posición actual, clear limpia la lista, goToStar y goToEnd pone la posición actual al inicia y al final respectivamente, contains,
determina si la lista contiene cierto elemento, indexOf indica el índice de un elemento respecto a un índice dado, goToPos actualiza la posición actual en una nueva 
posición dada, next y previous mueve la posición un paso adelante y atrás respectivamente, atStart y atEnd indica si la posición se encuentra al inicio o al final
respectivamente, getPos retorna la posición actual, getSize retorna el tamaño actual, y ambos prints muestran la lista actual en diferentes formatos.
Código hecho por Jose Adrián Piedra y Juan Pablo Jímenez.
*/

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
				return i;
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
			cout << i + 1 << ". " << elements[i] << endl;
		}
	}
};
