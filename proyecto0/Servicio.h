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

public:  
    Servicio() {
        this->descrip = "";
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

    bool operator==(const Servicio &other) {
        return this->descrip == other.descrip;
    }
};

ostream &operator<<(ostream &os, Servicio &servicio) {
    os << servicio.getDescripcion();
    return os;
}

