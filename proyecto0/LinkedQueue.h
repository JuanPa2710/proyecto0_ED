/*
Archivo el cual define el comportamiento de la cola enlazada.
Incluye dos punteros, uno para el frente y otro para el final, junto a un entero que indica el tamaño.
En cuanto a sus métodos, tenemos su constructor el cual por determinado crea un nodo nuevo al inicio y al final, y define el tamaño como 0. El destructor elimina
los elementos de la cola y elimina el espacio dedicado a la cola en la memoria. Enqueue inserta un elemento atrás, dequeue elimina el elemento en la parte de al
frente de la cola, remove elimina un elemento dado de la cola, frontValue retorna el elemento al frente en el momento, clear limpia la cola, getSize retorna el
tamaño de la cola y por último, print muestra la cola.
Código hecho por Fiorella Gónzalez.
*/

#pragma once
#include <stdexcept>
#include <iostream>
#include "Queue.h"
#include "Node.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class LinkedQueue : public Queue<E> {
private:
	Node<E> *front;
	Node<E> *back;
	int size;

public:
	LinkedQueue() {
		back = front = new Node<E>();
		size = 0;
	}
	~LinkedQueue() {
		clear();
		delete front;
	}
	void enqueue(E element) {
		back = back->next = new Node<E>(element);
		size++;
	}
	E dequeue() {
		if (size == 0)
			throw runtime_error("Queue is empty.");
		E result = front->next->element;
		Node<E> *temp = front->next;
		front->next = temp->next;
		delete temp;
		size--;
		if (size == 0)
			back = front;
		return result;
	}

	void remove(E element) {
		if (size == 0)
			throw runtime_error("Queue is empty.");
		Node<E> *current = front->next;
		Node<E> *previous = front;
		while (current != nullptr) {
			if (current->element == element) {
				previous->next = current->next;
				if (current == back) {
					back = previous;
				}
				delete current;
				size--;
				return;
			}
			previous = current;
			current = current->next;
		}
		throw runtime_error("Element not found in queue.");
	}

	E frontValue() {
		if (size == 0)
			throw runtime_error("Queue is empty");
		return front->next->element;
	}
	void clear() {
		while (front->next != nullptr) {
			Node<E> *temp = front->next;
			front->next = temp->next;
			delete temp;
		}
		back = front;
		size = 0;
	}
	bool isEmpty() {
		return size == 0;
	}
	int getSize() {
		return size;
	}
	void print() {
		cout << "[ ";
		Node<E> *nodoTemp = front->next;
		while (nodoTemp != nullptr) {
			cout << nodoTemp->element << " ";
			nodoTemp = nodoTemp->next;
		}
		cout << "]" << endl;
	}
};

