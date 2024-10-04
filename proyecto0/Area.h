/*
EL archivo tipo objeto el cual define el comportamiento de las áreas.
Entre sus diversos atributos, se tiene la descripción del área, el código del área, la cantidad de las ventanillas, dos listas para las ventanillas y los sevicios
ofrecidos, y una lista de prioridad para los tiquetes. Además, como parte de la parte privada de la clase, aparte de los atributos, se tiene el método
asignarCodigosVentanillas, el cual asigna las ventanillas con los códigos indicados.
En cuanto su parte publica, se tiene su constructor determinado y su constructor para áreas específicas, diversos gets para ver los atributos de áreas específicas,
sets para los diferentes atributos para modificarlos a áreas específicas, agregarServicio y agregarTiquetes los cuales agregan un nuevo servicio o tiquete dependiendo
del caso, toString lo muestra de manera legible el objeto en la consola, operator= el cual cambia los atributos de un área a ser idénticas a de otra área, operator==
el cual compara la descripción de dos áreas, y por último  &operator<<, el cual permite usar cout con los objetos tipo área.
Código hecho por Código hecho por Jose Adrián Piedra y Juan Pablo Jímenez.
*/

#define DEFAULT_MAX 1024

#pragma once

#include <string>
#include <ostream>
#include "ArrayList.h"
#include "Servicio.h"
#include "Tiquete.h"

using std::string;
using std::ostream;
using std::to_string;

class Area {
private:
	string descrip;
	string codigo;
	int cantVentanillas;
	List<string> *ventanillas;
	List<Servicio> *servicios;
	PriorityQueue<Tiquete> *tiquetes;

	void asignarCodigosVentanillas() {
		if (ventanillas->getSize() > 0)
			ventanillas->clear();

		for (int i = 1; i <= cantVentanillas; i++) {
			string tempCod = codigo + to_string(i);
			ventanillas->append(tempCod);
		}
	}

public:
	Area() {
		descrip, codigo = "";
		cantVentanillas = 0;
		ventanillas = new ArrayList<string>();
		servicios = new ArrayList<Servicio>();
		tiquetes = new LinkedPriorityQueue<Tiquete>(10);
	}

	Area(string descrip, string codigo, int cantVentanillas) {
		this->descrip = descrip;
		this->codigo = codigo;
		this->cantVentanillas = cantVentanillas;
		ventanillas = new ArrayList<string>();
		servicios = new ArrayList<Servicio>();
		tiquetes = new LinkedPriorityQueue<Tiquete>(10);
		asignarCodigosVentanillas();
	}

	Area(string descrip) {
		this->descrip = descrip;
		this->codigo = "";
		this->cantVentanillas = 0;
	}

	~Area() {
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

	void agregarServicio(Servicio serv) {
		servicios->append(serv);
	}

	void agregarTiquete(Tiquete tiquete, int prioridad) {
		tiquetes->insert(tiquete, prioridad);
	}


	void toString() {
		cout << "Area: {" << descrip << ", " << codigo << ", " << cantVentanillas << "}" << endl;
		cout << "Ventanillas: ";  ventanillas->print();
		cout << "Servicios: "; servicios->print();
		cout << "Tiquetes: "; tiquetes->print();
	}

	void operator=(Area other) {
		this->descrip = other.descrip;
		this->codigo = other.codigo;
		this->cantVentanillas = other.cantVentanillas;
		this->ventanillas = other.ventanillas;
		this->tiquetes = other.tiquetes;
	}

	bool operator==(const Area &other) {
		return descrip == other.descrip;
	}
};

ostream &operator<<(ostream &os, Area area) {
	os << area.getDescripcion();
	return os;
}
