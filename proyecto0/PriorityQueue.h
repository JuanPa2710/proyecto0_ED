/*
Clase base en la que se define cuales métodos tendrán las clases que heredan de la misma.
Se tiene el constructor y destructor, junto a los diversos métodos para definir los comportamientos de la clase y como funciona su manejo. Dependiendo de la clase,
el método tiene una diferente ejecución. insert ingresa un nuevo elemento a la cola junto a la prioridad, remove elimina un elemento específico, min retorna el
primer elemento en la cola, removeMin lo elimina, clear limpia totalmente la cola, getSize retorna el tamaño total de la cola, isEmpty verifica si la cola está
vacía o no, y print muestra la cola en la consola.
Código hecho por Fiorella González.
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

