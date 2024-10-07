#pragma once
#include <string>
using namespace std;

class Ventanilla {
private:
	string nombre;
	string codTiquete;

public:
	Ventanilla() {
		this->nombre = "";
		this->codTiquete = "";
	}

	Ventanilla(string nombre) {
		this->nombre = nombre;
		this->codTiquete = "";
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
}; 

ostream& operator<<(ostream& os, Ventanilla venta) {
	os << venta.getNombre();
	return os;
}

