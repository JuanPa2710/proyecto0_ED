#pragma once
#include <stdexcept>
#include <ostream>
#include <string>

using std::string;
using std::ostream;

class Usuarios {
private:
    string nombre;

public:
    Usuarios() {
        this->nombre = "";
    }

    Usuarios(string nombre) {
        this->nombre = nombre;
    }

    ~Usuarios() {}

    void setNombre(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() {
        return nombre;
    }

    bool operator==(const Usuarios& other) {
        return this->nombre == other.nombre;
    }
};
