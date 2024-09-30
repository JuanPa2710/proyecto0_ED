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

	bool operator==(const Area other) {
		return descrip == other.descrip;
	}
};

ostream &operator<<(ostream &os, Area area) {
	os << area.getDescripcion();
	return os;
}
