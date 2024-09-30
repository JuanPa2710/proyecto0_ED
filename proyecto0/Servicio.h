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

    ~Servicio() {}

    void setDescripcion(string descrip) {
        this->descrip = descrip;
    }

    string getDescripcion() {
        return descrip;
    }

    bool operator==(const Servicio &other) {
        return this->descrip == other.descrip;
    }
};

ostream &operator<<(ostream &os, Servicio &servicio) {
    os << servicio.getDescripcion();
    return os;
}

