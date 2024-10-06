/*
EL archivo tipo objeto el cual define el comportamiento de los tiquetes.
En la parte privada, se tiene los atributos de los tiquetes, los cuales incluye el c�digo, la hora en la que se di� el tiquete, y la prioridad del tiquete.
En cuanto la secci�n p�blica, se tiene el constructor, tanto el general como el que recibe los atributos en especifico, a su vez, tiene sets y gets para cada uno de
sus atributos, operator== el cual compara el c�digo de dos tiquetes, y por �ltimo  &operator<<, el cual permite usar cout con los objetos tipo tiquete.
C�digo hecho por Jose Adri�n Piedra y Juan Pablo J�menez.
*/

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

