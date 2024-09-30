#pragma once

#include <string>
#include <ostream>
#include "ArrayList.h"

using std::string;
using std::ostream;

class Area {
private:
	string descrip;
	string codigo;
	int cantVentanillas;
	List<string> *ventanillas = new ArrayList<string>();

	void asignarCodigosVentanillas() {
		if (ventanillas->getSize() > 0) 
			ventanillas->clear();
		
		for (int i = 0; i < cantVentanillas; i++) {
			string tempCod = codigo + ("" + i);
			ventanillas->append(tempCod);
		}
		
	}

public:
	Area() {
		descrip, codigo = "";
		cantVentanillas = 0;
	}

	Area(string descrip, string codigo, int cantVentanillas) {
		this->descrip = descrip;
		this->codigo = codigo;
		this->cantVentanillas = cantVentanillas;
		asignarCodigosVentanillas();
	}

	~Area() {
		delete ventanillas;
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

	friend ostream& operator<<(ostream& os, const Area& area) {
        os << area.descrip;
        return os;
    }
};

