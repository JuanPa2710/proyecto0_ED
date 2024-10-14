
/*
EL archivo tipo objeto el cual define el comportamiento de las áreas.
Entre sus diversos atributos, se tiene la descripción del área, el código del área, la cantidad de las ventanillas, dos listas para las ventanillas y los sevicios
ofrecidos, y una lista de prioridad para los tiquetes. Además, como parte de la parte privada de la clase, aparte de los atributos, se tiene el método
asignarCodigosVentanillas, el cual asigna las ventanillas con los códigos indicados.
En cuanto su parte publica, se tiene su constructor determinado y su constructor para áreas específicas, diversos gets para ver los atributos de áreas específicas,
sets para los diferentes atributos para modificarlos a áreas específicas, agregarServicio y agregarTiquetes los cuales agregan un nuevo servicio o tiquete dependiendo
del caso, toString lo muestra de manera legible el objeto en la consola, operator= el cual cambia los atributos de un área a ser idénticas a de otra área, operator==
el cual compara la descripción de dos áreas, y por último  &operator<<, el cual permite usar cout con los objetos tipo área.
Código hecho por Jose Adrián Piedra y Juan Pablo Jímenez.
*/

#define DEFAULT_MAX 100

#pragma once

#include <string>
#include <ostream>
#include "ArrayList.h"
#include "Servicio.h"
#include "Tiquete.h"
#include "Ventanilla.h"
#include "PriorityQueue.h"
#include "MinHeap.h"
#include "HeapPriorityQueue.h"


using std::string;
using std::ostream;
using std::to_string;

class Area {
private:
	string descrip;
	string codigo;
	int cantVentanillas;
	int count;
	int tiempoProm;

	void asignarCodigosVentanillas() {
		if (ventanillas->getSize() > 0)
			ventanillas->clear();

		for (int i = 1; i <= cantVentanillas; i++) {
			string tempCod = codigo + to_string(i);
			ventanillas->append(new Ventanilla(tempCod));
		}
	}

public:
	List<Servicio *> *servicios;
	List <Ventanilla *> *ventanillas;
	PriorityQueue<Tiquete *> *tiquetes;

	Area() {
		descrip, codigo = "";
		cantVentanillas = 0;
		count = 0;
		ventanillas = new LinkedList<Ventanilla *>();
		servicios = new LinkedList<Servicio *>();
		tiquetes = new HeapPriorityQueue<Tiquete *>();
	}

	Area(string descrip, string codigo, int cantVentanillas) {
		this->descrip = descrip;
		this->codigo = codigo;
		this->cantVentanillas = cantVentanillas;
		this->count = 0;
		ventanillas = new ArrayList<Ventanilla *>();
		servicios = new ArrayList<Servicio *>();
		tiquetes = new HeapPriorityQueue<Tiquete *>();
		asignarCodigosVentanillas();
	}

	Area(string descrip) {
		this->descrip = descrip;
		this->codigo = "";
		this->cantVentanillas = 0;
		this->count = 0;
	}

	~Area() {
		servicios->clear();
		ventanillas->clear();
		tiquetes->clear();
	}

	void setDescripcion(string descrip) {
		this->descrip = descrip;
	}

	string getDescripcion() {
		return descrip;
	}

	void setCodigo(string codigo) {
		this->codigo = codigo;
	}

	string getCodigo() {
		return codigo;
	}

	void setCantVentanillas(int cantVentanillas) {
		this->cantVentanillas = cantVentanillas;
		asignarCodigosVentanillas();
	}

	int getCantVentanillas() {
		return cantVentanillas;
	}

	void setCount() {
		this->count += 1;
	}

	void restartCount() {
		this->count = 0;
	}

	int getCount() {
		return this->count;
	}

	void setTiempoProm(int tiempo) {
		this->tiempoProm += tiempo;
	}

	int getTiempoProm() {
		return this->tiempoProm;
	}

		 
	void agregarServicio(Servicio *serv) {
		servicios->append(serv);
	}

	Servicio *obtenerServicio() {
		return servicios->getElement();
	}

	void eliminarServicio(Servicio *serv) {
		servicios->goToPos(servicios->indexOf(serv, 0));
		servicios->remove();
	}

	void agregarTiquete(Tiquete *tiquete, int prioridad) {
		tiquetes->insert(tiquete, prioridad);
	}

	Tiquete *atenderTiquete() {
		if (!tiquetes->isEmpty()) {
			return tiquetes->removeMin();
		} else {
			throw runtime_error("No hay tiquetes en la cola");
		}
	}

	void limpiarCola() {
		tiquetes->clear();
	}

	void toString() {
		cout << "Area: " << cantVentanillas << endl;
		cout << "Ventanillas: ";  ventanillas->print();
		cout << "Servicios: "; servicios->print();
		cout << "Tiquetes: "; tiquetes->print();
	}

	void operator=(const Area &other) {
		this->descrip = other.descrip;
		this->codigo = other.codigo;
		this->cantVentanillas = other.cantVentanillas;
		this->count = other.count;

		this->ventanillas = other.ventanillas;
		this->servicios = other.servicios;
		this->tiquetes = other.tiquetes;
	}

	bool operator==(const Area &other) {
		return descrip == other.descrip;
	}

	bool operator !=(const Area &other) {
		return (this->descrip != other.descrip &&
			this->codigo != other.codigo &&
			this->cantVentanillas != cantVentanillas &&
			this->count != other.count &&
			this->ventanillas != other.ventanillas &&
			this->servicios != other.servicios &&
			this->tiquetes != other.tiquetes);
	}
};

ostream &operator<<(ostream &os, Area *area) {
	os << area->getDescripcion();
	return os;
}

ostream &operator<<(ostream &os, Area &area) {
	os << area.getDescripcion();
	return os;
}
