/*
EL archivo tipo objeto el cual define el comportamiento de las colas.
En la secci�n privada, se tiene una copia del destructor junto a un operator =, los cuales previenen la copia accidental de colas.
En cuanto la secci�n p�blica, se tiene el constructor y destructor de las colas, enqueque el cual pone un elemento en la cola, dequeue el cual elimina un elemento de
la cola al principio, remove elimina un elemento en espec�fico de la cola, frontValue retorna el primer elemento en la cola, clear limpia totalmente la cola, isEmpty
verifica si la cola est� vac�a, getSize retorna el tama�o de la cola, y por �ltimo, se tiene el print el cual muestra en la consola la cola.
C�digo hecho por Fiorella Gonz�lez.
*/

#pragma once

template <typename E>
class Queue {
private:
	Queue(const Queue<E> &other) {}
	void operator =(const Queue<E> &other) {}

public:
	Queue() {}
	virtual ~Queue() {}
	virtual void enqueue(E element) = 0;
	virtual E dequeue() = 0;
	virtual void remove(E element) = 0;
	virtual E frontValue() = 0;
	virtual void clear() = 0;
	virtual bool isEmpty() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
};

