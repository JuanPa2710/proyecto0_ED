#pragma once
#include <stdexcept>
#include <ostream>
#include <string>

#include "Area.h"

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

    void setAreaAsignada(string areaAsignada) {
        this->areaAsignada = areaAsignada;
    }

    string getAreaAsignada() {
        return areaAsignada;
    }

    void operator=(Servicio other) {
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

