/*
Archivo tipo objeto en donde se define el comportamiento de los servicios.
Entre sus atributos privados, se tiene la descripción del servicio, la prioridad que tiene, y la área en donde se encuentra.
En cuanto sus métodos públicos, se tiene su constructor determinado y su constructor para servicios específicos, a su vez, se tienen gets y sets para tanto las
descripciones como el área asignada, además, se tiene operator= el cual cambia los atributos de un servicio a ser idénticas a la de otra servicio, operator==
el cual compara la descripción de dos servicios, y por último  &operator<<, el cual permite usar cout con los objetos tipo servicio.
Código hecho por Jose Adrián Piedra y Juan Pablo Jímenez.
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
