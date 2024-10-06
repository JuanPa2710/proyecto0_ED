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

public:
    Usuarios() {
        this->nombre = "";
        this->prioridad=0;
    }

    Usuarios(string nombre) {
        this->nombre = nombre;
    }

    Usuarios(string nombre, int prioridad) {
        this->nombre = nombre;
        this->prioridad= prioridad;
    }

    string getNombre() {
        return nombre;
    }

    int getPrioridad() {
        return prioridad;
    }

    bool operator==(const Usuarios& other) {
        return this->nombre == other.nombre;
    }

};
ostream& operator<<(ostream& os, Usuarios usuario) {
    os << usuario.getNombre();
    return os;
}
