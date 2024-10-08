/*
Archivo tipo objeto en donde se define el comportamiento de los servicios.
Entre sus atributos privados, se tiene la descripci�n del servicio, la prioridad que tiene, y la �rea en donde se encuentra.
En cuanto sus m�todos p�blicos, se tiene su constructor determinado y su constructor para servicios espec�ficos, a su vez, se tienen gets y sets para tanto las
descripciones como el �rea asignada, adem�s, se tiene operator= el cual cambia los atributos de un servicio a ser id�nticas a la de otra servicio, operator==
el cual compara la descripci�n de dos servicios, y por �ltimo  &operator<<, el cual permite usar cout con los objetos tipo servicio.
C�digo hecho por Jose Adri�n Piedra y Juan Pablo J�menez.
*/

#pragma once
#include <stdexcept>
#include <ostream>
#include <string>


using std::string;
using std::ostream;

class Servicio {
private:
    string descrip;
    int prioridad;
    string areaAsignada;

public:  
    Servicio() {
        this->descrip, this->areaAsignada = "";
        this->prioridad = 0;
    }

    Servicio(string descrip, int prioridad,string areaAsignada) {
        this->descrip = descrip;
        this->prioridad = prioridad;
        this->areaAsignada = areaAsignada;
    }

    Servicio(string descrip) {
        this->descrip = descrip;
    }

    ~Servicio() {}

    void setDescripcion(string descrip) {
        this->descrip = descrip;
    }

    string getDescripcion() {
        return descrip;
    }

    void setPrioridad(int prioridad) {
        this->prioridad;
    }

    int getPrioridad() {
        return prioridad;
    }

    void setAreaAsignada(string areaAsignada) {
        this->areaAsignada = areaAsignada;
    }

    string getAreaAsignada() {
        return areaAsignada;
    }

    void operator=(const Servicio &other) {
        this->descrip = other.descrip;
        this->prioridad = other.prioridad;
        this->areaAsignada = other.areaAsignada;
    }

    bool operator==(const Servicio &other) {
        return this->descrip == other.descrip;
    }
};

ostream &operator<<(ostream &os, Servicio &servicio) {
    os << servicio.getDescripcion();
    return os;
}

ostream &operator<<(ostream &os, Servicio *servicio) {
    os << servicio->getDescripcion();
    return os;
}
