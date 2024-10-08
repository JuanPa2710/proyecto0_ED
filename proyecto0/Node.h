/*
Archivo el cual define el comportamiento de los nodos.
Contiene dos atributos, uno cual define el nodo actual, y un puntero que apunta al siguiente.
En cuanto a sus m�todos, se tiene el constructor el cual recibe el elemento que va a componer el nodo y el puntero siguiente. En el caso de no recibir el par�metro,
se asigna como nullptr. En conjunto, se tiene un constructor en donde se recibe �nicamente el puntero de igual manera, y solo se asigna el puntero.
C�digo hecho por Fiorella Gonz�lez.
*/

#pragma once

template <typename E>
class Node {
public:
	E element;
	Node<E> *next;

	Node(E element, Node<E> *next = nullptr) {
		this->element = element;
		this->next = next;
	}
	Node(Node<E> *next = nullptr) {
		this->next = next;
	}
};


