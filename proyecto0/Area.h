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
	List<string> *ventanillas = new ArrayList<string>();
	List<Servicio> *servicios = new ArrayList<Servicio>();
	PriorityQueue<Tiquete> *tiquetes = new LinkedPriorityQueue<Tiquete>(DEFAULT_MAX);
	

	void asignarCodigosVentanillas() {
		cout << "Cantidad de ventanillas: " << cantVentanillas << endl;
		cout << "Estoy acá" << endl;
		for (int i = 0; i <= cantVentanillas; i++) {
			string tempCod = codigo + to_string(i);
			cout << tempCod << endl;
			ventanillas->append(tempCod);
		}
	}

public:
	Area() {
		descrip, codigo = "";
		cantVentanillas = 0;
		ventanillas = new ArrayList<string>();
		servicios = new ArrayList<Servicio>();
		tiquetes = new LinkedPriorityQueue<Tiquete>(DEFAULT_MAX);
	}

	Area(string descrip, string codigo, int cantVentanillas) {
		this->descrip = descrip;
		this->codigo = codigo;
		this->cantVentanillas = cantVentanillas;
		asignarCodigosVentanillas();
	}

	~Area() {
		ventanillas->clear();
		servicios->clear();
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

	void agregarTiquete(Tiquete tiquete, int prioridad) {
		tiquetes->insert(tiquete, prioridad);
	}

	void toString() {
		cout << "Area: {" << descrip << ", " << codigo << ", " << cantVentanillas << endl;
		ventanillas->print();
		servicios->print();
		tiquetes->print();
	}
};

ostream &operator<<(ostream &os, Area &area) {
	os << area.getDescripcion();
	return os;
}
