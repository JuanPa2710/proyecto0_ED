/*
Archivo donde se define como objeto los tipos de usuarios. 
Contiene su atributo principal nombre, con su debido constructor el cual recibe el nombre que recibir� el tipo de usuario.
Adem�s, contiene un metodo para descubrir el nombre del tipo de usuario, y otro para verificar si dos tipos de usuarios tienen el mismo nombre.
C�digo hecho por Fiorella Gonz�lez.
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

public:
    Usuarios() {
        this->nombre = "";
    }

    Usuarios(string nombre) {
        this->nombre = nombre;
    }

    string getNombre() {
        return nombre;
    }

    bool operator==(const Usuarios& other) {
        return this->nombre == other.nombre;
    }

};
ostream& operator<<(ostream& os, Usuarios usuario) {
    os << usuario.getNombre();
    return os;
}
