#pragma once

#include <string>
#include <ostream>
#include <chrono>

using Tiempo = std::chrono::time_point<std::chrono::system_clock>;	
using std::string;
using std::ostream;

class Tiquete {
private:
	string cod;
	Tiempo hora;
	int prioridadFinal;

public:
    Tiquete() {
        this->cod = "";
        this->hora = std::chrono::system_clock::now();
        this->prioridadFinal = 0;
    }

	Tiquete(string cod, Tiempo hora, int prioridadFinal) {
		this->cod = cod;
		this->hora = hora;
		this->prioridadFinal = prioridadFinal;
	}
	
	~Tiquete() {

	}

    void setCod(string codigo) {
        this->cod = codigo;
    }

    string getCod() {
        return cod;
    }

    void setHora(Tiempo nuevaHora) {
        this->hora = nuevaHora;
    }

    Tiempo getHora() {
        return hora;
    }

    void setPrioridadFinal(int nuevaPrioridad) {
        this->prioridadFinal = nuevaPrioridad;
    }

    int getPrioridadFinal() {
        return prioridadFinal;
    }

    bool operator==(const Tiquete &other) {
        return this->cod == other.cod;
    }
};

ostream &operator<<(ostream &os, Tiquete &tiquete) {
    os << tiquete.getCod();
    return os;
}

