/*
Clase base en la que se define cuales m�todos tendr�n las clases que heredan de la misma.
Se tiene el constructor y destructor, junto a los diversos m�todos para definir los comportamientos de la clase y como funciona su manejo. Dependiendo de la clase,
el m�todo tiene una diferente ejecuci�n. insert ingresa un nuevo elemento a la cola junto a la prioridad, remove elimina un elemento espec�fico, min retorna el
primer elemento en la cola, removeMin lo elimina, clear limpia totalmente la cola, getSize retorna el tama�o total de la cola, isEmpty verifica si la cola est�
vac�a o no, y print muestra la cola en la consola.
C�digo hecho por Fiorella Gonz�lez.
*/

#pragma once

template <typename E>
class PriorityQueue {
private:
	PriorityQueue(const PriorityQueue<E> &other) {}
	void operator =(const PriorityQueue<E> &other) {}

public:
	PriorityQueue() {}
	virtual ~PriorityQueue() {}
	virtual void insert(E element, int priority) = 0;
	virtual E min() = 0;
	virtual E removeMin() = 0;
	virtual void clear() = 0;
	virtual int getSize() = 0;
	virtual bool isEmpty() = 0;
	virtual void print() = 0;
	virtual void printShow() = 0;
};

