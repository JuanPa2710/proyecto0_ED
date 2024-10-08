/*
Archivo el cual define el comportamiento de las listas.
En la parte privada, se tiene una copia del constructor para prevenir la copia accidental del objeto, de igual manera, se tiene el operator =, de igual manera, hecho
de esta manera para prevenir copias accidentales.
En cuanto la parte publica, se tiene tanto el constructor como el destructor, inserte el cual ingresa un elemento en la lista, append de igual manera ingresa un 
elemento pero lo ingresa al final de la lista, remove elimina un elemento, getElement retorna el elemento actual, clear limpia toda la lista, goToStart y goToEnd
lleva el puntero al inicio y al final respectivamente, next y previous mueve el puntero al elemento siguiente y anterior respectivamente, atStart y atEnd verifica si
el puntero está en el inicio y final de la lista respectivamente, contains confirma si un elemento está dentro de la lista, indexOf busca el indice de un elemento
dado, desde un punto específico de la lista, getPos retorna la posición actual, getSize retorna el tamaño de la lista, y dos prints, los cuales muestran la lista de
manera diferente en la consola.
Código hecho por Jose Adrián Piedra y Juan Pablo Jímenez.
*/

#pragma once

template <typename E>
class List {
private:
	List(const List<E>& other) {}
	void operator =(const List<E>& other) {}

public:
	List() {}
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual E remove() = 0;
	virtual E getElement() = 0;
	virtual void clear() = 0;
	virtual void goToStart() = 0;
	virtual void goToEnd() = 0;
	virtual void goToPos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool atStart() = 0;
	virtual bool atEnd() = 0;
	virtual bool contains(E element) = 0;
	virtual int indexOf(E element, int start) = 0;
	virtual int getPos() = 0;
	virtual int getSize() = 0;
	virtual void print() = 0;
	virtual void printShow() = 0;
};

