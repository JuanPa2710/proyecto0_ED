/*
Archivo donde se define como objeto los tipos de usuarios. 
Contiene su atributo principal nombre, con su debido constructor el cual recibe el nombre que recibirá el tipo de usuario.
Además, contiene un metodo para descubrir el nombre del tipo de usuario, y otro para verificar si dos tipos de usuarios tienen el mismo nombre.
Código hecho por Fiorella González.
*/

#pragma once
#include <stdexcept>
#include <ostream>
#include <string>

using std::string;
using std::ostream;

class Usuarios {
private:
    string nombre;
    int prioridad;
    int count;

public:
    Usuarios() {
        this->nombre = "";
        this->prioridad=0;
        this->count = 0;
    }

    Usuarios(string nombre) {
        this->nombre = nombre;
        this->count = 0;
        this->prioridad = 0;
    }

    Usuarios(string nombre, int prioridad) {
        this->nombre = nombre;
        this->prioridad= prioridad;
        this->count = 0;
    }

    string getNombre() {
        return nombre;
    }

    int getPrioridad() {
        return prioridad;
    }

    int getCount() {
        return count;
    }

    void setCount() {
        this->count++; 
    }


    bool operator==(Usuarios *other) {
        return this->nombre == other->nombre;
    }

    bool operator==(Usuarios& other) {
        return this->nombre == other.nombre;
    }

    void operator=(const Usuarios &other) {
        this->nombre = other.nombre;
        this->prioridad = other.prioridad;
        this->count = other.count;
    }

};
ostream &operator<<(ostream& os, Usuarios usuario) {
    os << usuario.getNombre();
    return os;
}

ostream &operator<<(ostream &os, Usuarios *usuario) {
    os << usuario->getNombre();
    return os;
}
