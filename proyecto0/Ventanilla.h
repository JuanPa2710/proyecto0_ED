#pragma once
#include <string>
#include <iostream>
#include "LinkedQueue.h"
#include "Tiquete.h"

using namespace std;

class Ventanilla {
private:
	string nombre;
	string codTiquete;
	Queue <Tiquete *> *tiquetes;
	int count;

public:
	Ventanilla() {
		this->nombre = "";
		this->codTiquete = "";
		this->tiquetes = new LinkedQueue<Tiquete *>();
		this->count = 0;
	}

	Ventanilla(string nombre) {
		this->nombre = nombre;
		this->codTiquete = "";
		this->tiquetes = new LinkedQueue<Tiquete *>();
		this->count = 0;
	}

	void setNombre(string nombre) {
		this->nombre = nombre;
	}

	string getNombre() {
		return this->nombre;
	}

	void setCodTiquete(string codTiquete) {
		this->codTiquete = codTiquete;
	}

	string getCodTiquete() {
		return this->codTiquete;
	}

	void agregarTiquete(Tiquete *tiquete) {
		if (!tiquetes->isEmpty()) {
			cout << "" << endl;
			tiquetes->dequeue();
			tiquetes->enqueue(tiquete);
		} else {
			cout << "No hay usuarios esperando en la cola" << endl;
			tiquetes->enqueue(tiquete);
		}
	}

	int getCount() {
		return count;
	}

	void setCount() {
		this->count++;
	}

	void toString() {
		cout << "Ventanillas: ";  nombre;
		cout << "Servicios: "; codTiquete;
		cout << "Tiquetes: "; tiquetes->print();
	}

	void operator=(Ventanilla *other) {
		this->nombre = other->nombre;
		this->codTiquete = other->codTiquete;
		this->tiquetes = other->tiquetes;
		this->count = other->count;
	}

	bool operator==(const Ventanilla &other) {
		return this->nombre == other.nombre;
	}

};

ostream &operator<<(ostream &os, Ventanilla venta) {
	os << venta.getNombre();
	return os;
}

ostream &operator<<(ostream &os, Ventanilla *venta) {
	os << venta->getNombre();
	return os;
}

