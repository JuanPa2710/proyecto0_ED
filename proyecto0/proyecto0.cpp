/*
El archivo principal en el que se maneja toda la interacción de la consola con el usuario.
En el main, se encuentra diversos prints y manejos de input para decidir que mostrar en el menú, basado en lo que decida el usuario.
Además, se puede encontrar algunos aspectos lógicos del programa en general, como la inicialización de listas en las que se trabajara.
Código hecho por Fiorella Gónzalez, Jose Adrián Piedra y Juan Pablo Jímenez.
*/

#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <iomanip>

#include "LinkedPriorityQueue.h"
#include "LinkedList.h"
#include "Usuarios.h"
#include "Servicio.h"
#include "Area.h"
#include "Tiquete.h"

using namespace std;
using std::cin;
using std::stoi;
using std::chrono::system_clock;

List<Usuarios *> *usuarios = new ArrayList<Usuarios *>();
List<Area *> *areas = new ArrayList<Area *>();
List<Servicio *> *servicios = new ArrayList<Servicio *>();
List <Ventanilla *> *ventanillas = new ArrayList<Ventanilla *>;

std::chrono::time_point<std::chrono::system_clock> horaActual;
int tiqueteConsecutivo = 100;

//Funciones auxiliares
int chequeoRestriccionesEnteros(string input) {
    try {
        int num = stoi(input);

        if (num < 0) {
            cout << "\nError: El número está fuera del rango permitido. Intente de nuevo" << endl;
            return -1;
        } else {
            return num;
        }
    } catch (const invalid_argument &) {
        cout << "\nError: Entrada no válida, por favor ingrese un número entero. Intente de nuevo" << endl;
        return -1;
    } catch (const std::out_of_range &) {
        std::cout << "\nError: El número está fuera del rango permitido. Intente de nuevo" << std::endl;
        return -1;
    }
}

int chequeoRestriccionesRangos(string input, int r1, int r2) {
    try {
        int num = stoi(input);
        int option = 0;
        if (r1 != r2)
            option = (num >= r1 && num <= r2) ? num : 0;
        else
            option = (num == 1) ? num : 0;

        if (option == 0) {
            cout << "\nError: El número está fuera del rango permitido. Intente de nuevo" << endl;
            return 0;
        } else {
            return option;
        }
    } catch (const invalid_argument &) {
        cout << "\nError: Entrada no válida, por favor ingrese un número entero. Intente de nuevo" << endl;
        return 0;
    } catch (const std::out_of_range &) {
        std::cout << "\nError: El número está fuera del rango permitido. Intente de nuevo" << std::endl;
        return 0;
    }
}

void imprimirOpciones(string arr[], int max) {
    system("cls");

    for (int i = 0; i < max; i++)
        cout << i + 1 << ". " << arr[i] << endl;
}

//Funciones principales
void operacionTiquetes() {
    system("cls");

    if (usuarios->getSize() > 0 && servicios->getSize() > 0) {
        usuarios->printShow();
        string tipoUsuarioSeleccionado;
        int usuarioOp = 0;

        cout << "Seleccione el tipo de usuario: ";
        getline(cin, tipoUsuarioSeleccionado);
        usuarioOp = chequeoRestriccionesRangos(tipoUsuarioSeleccionado, 1, usuarios->getSize());
        while (usuarioOp == 0) {
            cout << "Seleccione el tipo de usuario: ";
            getline(cin, tipoUsuarioSeleccionado);
            usuarioOp = chequeoRestriccionesRangos(tipoUsuarioSeleccionado, 1, usuarios->getSize());
        }        
        cout << endl;

        servicios->printShow();
        string servicioSeleccionado;
        int servicioOp = 0;

        cout << "Seleccione el servicio que desea usar: ";
        getline(cin, servicioSeleccionado);
        servicioOp = chequeoRestriccionesRangos(servicioSeleccionado, 1, servicios->getSize());
        while (servicioOp == 0) {
            cout << "Seleccione el servicio que desea usar: ";
            getline(cin, servicioSeleccionado);
            servicioOp = chequeoRestriccionesRangos(servicioSeleccionado, 1, servicios->getSize());
        }

        servicios->goToPos(stoi(servicioSeleccionado) - 1);
        Servicio *servicioActual = servicios->getElement();
        Area *areaActual = new Area();

        string areaSeleccionada = servicioActual->getAreaAsignada();
        bool areaEncontrada = false;
        string codigoArea;
        for (areas->goToStart(); !areas->atEnd(); areas->next()) {
            Area *temp = areas->getElement();

            if (temp->getDescripcion() == areaSeleccionada) {
                areaActual = temp;
                codigoArea = temp->getCodigo();
                break;
            }
        }

        string codigoTiquete = codigoArea + to_string(tiqueteConsecutivo);
        horaActual = std::chrono::system_clock::now();

        usuarios->goToPos(stoi(tipoUsuarioSeleccionado) - 1);
        Usuarios *usuario = usuarios->getElement();
        int prioridadUsuario = usuario->getPrioridad();
        int prioridadServicio = servicioActual->getPrioridad();
        int prioridadTiquete = prioridadUsuario * 10 + prioridadServicio;

        std::time_t tiempoActual = std::chrono::system_clock::to_time_t(horaActual);
        std::tm *horaLocal = std::localtime(&tiempoActual);

        // Crear el tiquete y agregarlo a la cola
        Tiquete *nuevoTiquete = new Tiquete(codigoTiquete, horaActual, prioridadTiquete);

        areaActual->agregarTiquete(nuevoTiquete, prioridadTiquete);
        areaActual->setCount();
        usuario->setCount();
        servicioActual->setCount();

        cout << "\nTiquete generado: " << codigoTiquete << endl;
        cout << "Hora: " << std::put_time(horaLocal, "%H:%M:%S") << endl;
        cout << "Prioridad: " << prioridadTiquete << endl;
        tiqueteConsecutivo++;
        cout << "Presione cualquier tecla para continuar...";
        cin.get();
    }
    else {
        if (usuarios->getSize() == 0) {
            cout << "No se puede realizar esta operación." << endl;
            cout << "Causa: No hay usuarios registrados." << endl;
        } else {
            cout << "No se puede realizar esta operación." << endl;
            cout << "Causa: No hay servicios registrados." << endl;
        }
        cout << "Presione cualquier tecla para continuar...";
        cin.get();
    }
}

void operacionAtender() {
    system("cls");

    if (areas->getSize() > 0) {
        string areaSeleccionada;
        string ventanilla;

        areas->printShow();
        int areaOP = 0;

        cout << "Ingrese el área que desee atender: ";
        getline(cin, areaSeleccionada);
        areaOP = chequeoRestriccionesRangos(areaSeleccionada, 1, areas->getSize());
        while (areaOP == 0) {
            cout << "Ingrese el área que desee atender: ";
            getline(cin, areaSeleccionada);
            areaOP = chequeoRestriccionesRangos(areaSeleccionada, 1, areas->getSize());
        }
        areas->goToPos(areaOP-1);
        Area *areaActual = areas->getElement();

        if (areaActual->tiquetes->getSize() > 0) {
            cout << endl;
            areaActual->ventanillas->printShow();
            int ventanilaOp = 0;

            cout << "Ingrese el número de ventanilla: ";
            getline(cin, ventanilla);
            ventanilaOp = chequeoRestriccionesRangos(ventanilla, 1, areaActual->ventanillas->getSize());
            while (ventanilaOp == 0) {
                cout << "Ingrese el número de ventanilla: ";
                getline(cin, ventanilla);
                ventanilaOp = chequeoRestriccionesRangos(ventanilla, 1, areaActual->ventanillas->getSize());
            }

            Ventanilla* ventanillaActual = new Ventanilla();
            bool ventanillaEncontrada = false;

            areaActual->ventanillas->goToPos(ventanilaOp - 1);
            ventanillaActual = areaActual->ventanillas->getElement();

            Tiquete* tiqueteAtendido = areaActual->atenderTiquete();

            horaActual = std::chrono::system_clock::now();
            Tiempo horaTiquete = tiqueteAtendido->getHora();
            std::chrono::duration<double> duracion = horaActual - horaTiquete;
            auto duracionEnSegundos = std::chrono::duration_cast<std::chrono::seconds>(duracion).count();
            int minutos = duracionEnSegundos / 60;
            int segundos = duracionEnSegundos % 60;

            areaActual->setTiempoProm(segundos);

            ventanillaActual->agregarTiquete(tiqueteAtendido);
            ventanillaActual->setCodTiquete(tiqueteAtendido->getCod());
            cout << "\nSe está atendiendo el tiquete: " << tiqueteAtendido->getCod() << endl;
            ventanillaActual->setCount();

            ventanillaActual->toString();
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        } 
        else {
            cout << "No hay tiquete para atender en esta área." << endl;
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }
    } 
    else {
        cout << "No se puede realizar esta operación." << endl;
        cout << "Causa: No hay areas registradas, ni tiquetes para atender." << endl;
        cout << "Presione cualquier tecla para continuar...";
        cin.get();
    }
}

void subOperacionUsuarios() {
    system("cls");

    string input = "";
    int option = 0;

    string ops[3] = {
            "Agregar un tipo de usuario.",
            "Eliminar un tipo de usuario.",
            "Regresar."
    };

    while (option != 3) {
        imprimirOpciones(ops, 3);
        cout << "Inserte la opción que quiere realizar: ";
        getline(cin, input);
        option = chequeoRestriccionesRangos(input, 1, 3);

        while (option == 0) {
            cout << "Inserte la opción que quiere realizar: ";
            getline(cin, input);
            option = chequeoRestriccionesRangos(input, 1, 3);
        }

        if (option == 1) {
            system("cls");
            string nombre;
            int prioridad;

            cout << "Ingrese el nombre del Usuario: ";
            getline(cin, nombre);

            string inputPrioridad = "";
            cout << "Ingrese la prioridad: ";
            getline(cin, inputPrioridad);
            prioridad = chequeoRestriccionesEnteros(inputPrioridad);
            while (prioridad < 0) {
                cout << "Ingrese la prioridad: ";
                getline(cin, inputPrioridad);
                prioridad = chequeoRestriccionesEnteros(inputPrioridad);
            }

            Usuarios *tipo = new Usuarios(nombre, prioridad);
            usuarios->insert(tipo);

            cout << "El tipo de usuario -" << nombre << "- fue agregado." << endl;
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 2) {
            system("cls");

            if (usuarios->getSize() > 0) {
                string nombre;
                int nombreOp = 0;
                usuarios->printShow();
                cout << "Ingrese el usuario a eliminar: ";
                getline(cin, nombre);
                nombreOp = chequeoRestriccionesRangos(nombre, 1, usuarios->getSize());
                while (nombreOp == 0) {
                    usuarios->printShow();
                    cout << "Ingrese el usuario a eliminar: ";
                    getline(cin, nombre);
                }

                int decisionOp = 0;
                string decision = "";
                usuarios->goToPos(nombreOp - 1);

                cout << "¿Está seguro de eliminar el usuario?" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                cout << "Escoja una opción: ";
                getline(cin, decision);
                decisionOp = chequeoRestriccionesRangos(decision, 1, 2);
                while (decisionOp == 0) {
                    cout << "¿Está seguro de eliminar el usuario?" << endl;
                    cout << "1. Si" << endl;
                    cout << "2. No" << endl;
                    cout << "Escoja una opción: ";
                    getline(cin, decision);
                    decisionOp = chequeoRestriccionesRangos(decision, 1, 2);
                }

                if (decisionOp == 1) {
                    for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                        areas->getElement()->limpiarCola();
                    }

                    cout << "Usuario " << usuarios->remove() << " eliminado correctamente" << endl;
                    cout << "Presione cualquier tecla para continuar...";
                    cin.get();
                } else {
                    cout << "El usuario no fue eliminado." << endl;
                    cout << "Presione cualquier tecla para continuar...";
                    cin.get();
                }
            }
            else {
                cout << "Actualmente no hay registrado ningún usuario." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }

        if (option == 3) {
            break;
        }
    }
}

void subOperacionAreas() {
    system("cls");

    string input = "";
    int option = 0;

    string ops[5] = {
            "Agregar un área.",
            "Modificar cantidad de ventanillas.",
            "Consultar áreas.",
            "Eliminar un área.",
            "Regresar."
    };

    while (option != 5) {
        imprimirOpciones(ops, 5);
        cout << "Inserte la opción que quiere realizar: ";
        getline(cin, input);
        option = chequeoRestriccionesRangos(input, 1, 5);

        while (option == 0) {
            cout << "Inserte la opción que quiere realizar: ";
            getline(cin, input);
            option = chequeoRestriccionesRangos(input, 1, 5);
        }

        if (option == 1) {
            system("cls");
            string descripcion, codigo, ventanilla;

            cout << "Ingrese la descripción del área: ";
            getline(cin, descripcion);

            cout << "Ingrese el código del área: ";
            getline(cin, codigo);

            int ventanilaCant = 0;
            cout << "Ingrese la cantidad de ventanillas del área: ";
            getline(cin, ventanilla);
            ventanilaCant = chequeoRestriccionesEnteros(ventanilla);
            while (ventanilaCant < 0) {
                cout << "Ingrese la cantidad de ventanillas del área: ";
                getline(cin, ventanilla);
                ventanilaCant = chequeoRestriccionesEnteros(ventanilla);
            }

            Area *tempArea = new Area(descripcion, codigo, ventanilaCant);
            areas->append(tempArea);
            cout << "\nEl área " << descripcion << " fue creada correctamente." << endl;
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 2) {
            system("cls");

            if (areas->getSize() > 0) {
                Area *tempArea = new Area();
                string resul;

                cout << "Áreas disponibles: " << endl << endl;
                areas->printShow();

                int resulOp = 0;
                cout << "Ingrese que área desea modificar: ";
                getline(cin, resul);
                resulOp = chequeoRestriccionesRangos(resul, 1, areas->getSize());
                while (resulOp == 0) {
                    cout << "Ingrese que área desea modificar: ";
                    getline(cin, resul);
                    resulOp = chequeoRestriccionesRangos(resul, 1, areas->getSize());
                }

                areas->goToPos(resulOp - 1);
                tempArea = areas->getElement();
                cout << "\nSe ha encontrado el área: " << tempArea->getDescripcion() << endl;

                int ventanilaCant = 0;
                cout << "\nCantidad actual de ventanillas: " << tempArea->getCantVentanillas() << endl;
                cout << "Ingrese la nueva cantidad de ventanillas: ";
                getline(cin, resul);
                ventanilaCant = chequeoRestriccionesEnteros(resul);
                while (ventanilaCant < 0) {
                    cout << "Ingrese la nueva cantidad de ventanillas: ";
                    getline(cin, resul);
                    ventanilaCant = chequeoRestriccionesEnteros(resul);
                }

                tempArea->setCantVentanillas(ventanilaCant);
                cout << "\nLa nueva cantidad de ventanillas es: " << tempArea->getCantVentanillas() << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
            else {
                cout << "Actualmente no hay áreas registradas." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }

        if (option == 3) {
            system("cls");

            if (areas->getSize() > 0) {
                string resul;
                cout << "Áreas disponibles: " << endl << endl;
                for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                    Area *temp = areas->getElement();
                    cout << "Nombre: " << temp->getDescripcion() << endl;
                    cout << "Cantidad de ventanillas: " << temp->getCantVentanillas() << endl;
                    cout << "Ventanillas: ";
                    temp->ventanillas->print();
                    cout << endl;
                }

                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
            else {
                cout << "Actualmente no hay áreas registradas." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }

        if (option == 4) {
            system("cls");

            if (areas->getSize() > 0) {
                Area *tempArea = new Area();
                string resul;
                system("cls");

                cout << "Áreas disponibles: " << endl;
                areas->printShow();

                int resulOp = 0;
                cout << "\nIngrese que área desea eliminar: ";
                getline(cin, resul);
                resulOp = chequeoRestriccionesRangos(resul, 1, areas->getSize());
                while (resulOp < 0) {
                    cout << "\nIngrese que área desea eliminar: ";
                    getline(cin, resul);
                    resulOp = chequeoRestriccionesRangos(resul, 1, areas->getSize());
                }

                string decision = "";
                int decisionOp = 0;
                cout << "¿Está seguro de eliminar el área?" << endl;
                cout << "También se eliminaran todos los servicios, ventanillas y tiquetes asociados a esta área" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                cout << "Escoja la opción: ";
                getline(cin, decision);
                decisionOp = chequeoRestriccionesRangos(decision, 1, 2);
                
                while (decisionOp == 0) {
                    cout << "¿Está seguro de eliminar el área?" << endl;
                    cout << "1. Si" << endl;
                    cout << "2. No" << endl;
                    cout << "Escoja la opción: ";
                    getline(cin, decision);
                    decisionOp = chequeoRestriccionesRangos(decision, 1, 2);
                }

                if (decisionOp == 1) {
                    areas->goToPos(resulOp - 1);
                    tempArea = areas->getElement();
                    List<Servicio *> *serviciosEliminar = new ArrayList<Servicio *>();
                    for (servicios->goToStart(); !servicios->atEnd(); servicios->next()) {
                        Servicio *servicioActual = servicios->getElement();
                        if (tempArea->servicios->contains(servicioActual)) {
                            serviciosEliminar->append(servicioActual);
                        }
                    }

                    for (serviciosEliminar->goToStart(); !serviciosEliminar->atEnd(); serviciosEliminar->next()) {
                        int pos = servicios->indexOf(serviciosEliminar->getElement(), 0);
                        servicios->goToPos(pos);
                        servicios->remove();
                    }
                    cout << "Se ha eliminado correctamente el área: " << areas->remove() << endl;
                }
                else {
                    cout << "El area no ha sido eliminada" << endl;
                }

                
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
            else {
                cout << "Actualmente no hay áreas registradas." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }
    }
}

void subOperacionServicios() {
    system("cls");

    string input = "";
    int option = 0;

    string ops[5] = {
            "Agregar un servicio.",
            "Reordenar servicios.",
            "Consultar servicios.",
            "Eliminar un servicios.",
            "Regresar."
    };

    while (option != 5) {
        imprimirOpciones(ops, 5);
        cout << "Inserte la opción que quiere realizar: ";
        getline(cin, input);
        option = chequeoRestriccionesRangos(input, 1, 5);

        while (option == 0) {
            cout << "Inserte la opción que quiere realizar: ";
            getline(cin, input);
            option = chequeoRestriccionesRangos(input, 1, 5);
        }

        if (option == 1) {
            system("cls");

            if (areas->getSize() > 0) {
                string descripcion, prioridad, area, prueba;

                cout << "Ingrese la descripción del servicio: ";
                getline(cin, descripcion);

                int prioridadOp = 0;
                cout << "Ingrese la prioridad del servicio: ";
                getline(cin, prioridad);
                prioridadOp = chequeoRestriccionesEnteros(prioridad);
                while (prioridadOp < 0) {
                    cout << "Ingrese la prioridad del servicio: ";
                    getline(cin, prioridad);
                    prioridadOp = chequeoRestriccionesEnteros(prioridad);
                }

                cout << "\nÁreas disponibles: " << endl;
                areas->printShow();

                int areaOp = 0;
                cout << "Ingrese a que área pertenece: ";
                getline(cin, area);
                areaOp = chequeoRestriccionesRangos(area, 1, areas->getSize());
                while (areaOp == 0) {
                    cout << "\nÁreas disponibles: " << endl;
                    areas->printShow();
                    cout << "Ingrese a que área pertenece: ";
                    getline(cin, area);
                    areaOp = chequeoRestriccionesRangos(area, 1, areas->getSize());
                }

                areas->goToPos(areaOp - 1);
                Area *tempArea = areas->getElement();

                Servicio *tempServicio = new Servicio(descripcion, prioridadOp, tempArea->getDescripcion());
                tempArea->agregarServicio(tempServicio);
                servicios->append(tempServicio);
                cout << "El servicio " << tempServicio->getDescripcion() << " fue agregado correctamente." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
            else {
                cout << "Actualmente no hay áreas registradas." << endl;
                cout << "Se necesitan áreas, para poder asignar los servicios." << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }

        if (option == 2) {
            system("cls");            

            if (servicios->getSize() > 1) {
                cout << "Servicios disponibles: " << endl;
                servicios->printShow();
                string servicio = "";
                int servicioOp = 0;
                cout << "Digite el servicio que desee reordenar: ";
                getline(cin, servicio);
                servicioOp = chequeoRestriccionesRangos(servicio, 1, servicios->getSize());
                while (servicioOp == 0) {
                    cout << "Digite el servicio que desee reordenar: ";
                    getline(cin, servicio);
                    servicioOp = chequeoRestriccionesRangos(servicio, 1, servicios->getSize());
                }

                string posicion;
                int posicionOp = 0;
                cout << "Digite la posición a la que desea mover el elemento: ";
                getline(cin, posicion);
                posicionOp = chequeoRestriccionesRangos(posicion, 1, servicios->getSize());
                while (servicioOp == 0) {
                    cout << "Digite la posición a la que desea mover el elemento: ";
                    getline(cin, posicion);
                    posicionOp = chequeoRestriccionesRangos(posicion, 1, servicios->getSize());
                }

                servicios->goToPos(servicioOp - 1);
                Servicio *elemento = servicios->remove();

                servicios->goToPos(posicionOp - 1);
                servicios->insert(elemento);

                cout << "Lista reordenada..." << endl;
                servicios->printShow();
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
            else {
                if (servicios->getSize() == 0)
                    cout << "No hay servicios registrados actualmente" << endl;

                if (servicios->getSize() == 1)
                    cout << "No se puede reodenar los servicios, porque solo hay uno." << endl;

                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }

        if (option == 3) {
            system("cls");

            if (servicios->getSize() > 0) {
                cout << "Servicios disponibles: " << endl;
                for (servicios->goToStart(); !servicios->atEnd(); servicios->next()) {
                    Servicio *temp = servicios->getElement();
                    cout << "Nombre: " << temp->getDescripcion() << endl;
                    cout << "Area asignada: " << temp->getAreaAsignada() << endl;
                    cout << "Prioridad: " << temp->getPrioridad() << endl;
                    cout << endl;
                }
            }
            else {
                cout << "No hay servicios registrados actualmente" << endl;
            }

            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 4) {
            system("cls");

            if (servicios->getSize() > 0) {
                string servicio;
                cout << "Servicios disponibles: " << endl;
                servicios->printShow();

                int servicioOp = 0;
                cout << "Digite el servicio que desee eliminar: ";
                getline(cin, servicio);
                servicioOp = chequeoRestriccionesRangos(servicio, 1, servicios->getSize());
                while (servicioOp == 0) {
                    cout << "Digite el servicio que desee eliminar: ";
                    getline(cin, servicio);
                    servicioOp = chequeoRestriccionesRangos(servicio, 1, servicios->getSize());
                }

                string decision = "";
                int decisionOp = 0;
                cout << "¿Está seguro de eliminar el servicio?" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                cout << "Escoja una opción: ";
                getline(cin, decision);
                decisionOp = chequeoRestriccionesRangos(decision, 1, 2);

                while (decisionOp == 0) {
                    int decisionOp = 0;
                    cout << "¿Está seguro de eliminar el servicio?" << endl;
                    cout << "1. Si" << endl;
                    cout << "2. No" << endl;
                    cout << "Escoja una opción: ";
                    getline(cin, decision);
                    decisionOp = chequeoRestriccionesRangos(decision, 1, 2);
                }

                if (decisionOp == 1) {
                    servicios->goToPos(servicioOp - 1);
                    Servicio *elemento = servicios->remove();
                    Area* element = areas->getElement();

                    for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                        Area* temp = areas->getElement();
                        if (temp->getDescripcion() == elemento->getAreaAsignada())
                            element = temp;
                    }

                    element->eliminarServicio(elemento);
                    cout << "El servicio " << servicio << " fue eliminado correctamente." << endl;
                } else {
                    cout << "No se eliminó el servicio" << endl;
                }

                cout << endl << "Servicios disponibles: " << endl;
                servicios->printShow();
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
            else {
                cout << "No hay servicios registrados actualmente" << endl;
                cout << "Presione cualquier tecla para continuar...";
                cin.get();
            }
        }
    }
}

void subOperacionColasListas() {
    system("cls");
    cout << "Limpiando las colas..." << endl;
    ventanillas->clear();
    for (areas->goToStart(); !areas->atEnd(); areas->next()) {
        areas->getElement()->limpiarCola();
        areas->getElement()->restartCount();
        Area* areaActual = areas->getElement();
        ventanillas = areaActual->ventanillas;
        for (ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()) {
            ventanillas->getElement()->restartCount();
        }
    }

    for (servicios->goToStart(); !servicios->atEnd(); servicios->next()) {
        servicios->getElement()->restartCount();
    }

    for (usuarios->goToStart(); !usuarios->atEnd(); usuarios->next()) {
        usuarios->getElement()->restartCount();
    }

    cout << "Presione cualquier tecla para continuar...";
    cin.get();
}

void operacionAdministracion() {
    string input = "";
    int option = 0;

    while (option != 5) {
        string ops[5] = {
                "Manejo de tipos de usuarios.",
                "Manejo de áreas.",
                "Manejo de servicios.",
                "Limpiar colas y estadísticas.",
                "Regresar."
        };

        imprimirOpciones(ops, 5);
        cout << "Inserte la opción que quiere realizar: ";
        getline(cin, input);
        option = chequeoRestriccionesRangos(input, 1, 5);


        while (option == 0) {
            cout << "Inserte la opción que quiere realizar: ";
            getline(cin, input);
            option = chequeoRestriccionesRangos(input, 1, 5);
        }

        if (option == 1) {
            subOperacionUsuarios();
        }

        if (option == 2) {
            subOperacionAreas();
        }

        if (option == 3) {
            subOperacionServicios();
        }

        if (option == 4) {
            subOperacionColasListas();
        }
    }
}

void operacionEstadisticas() {
    system("cls");

    string input = "";
    int option = 0;

    string ops[6] = {
            "Tiempo de espera por área.",
            "Cantidad de tiquetes por área.",
            "Cantidad de tiquetes por ventanilla.",
            "Cantidad de tiquetes por servicio.",
            "Cantidad de tiquetes por tipo de usuario",
            "Regresar."
    };

    while (option != 6) {
        imprimirOpciones(ops, 6);
        cout << "Inserte la opción que quiere realizar: ";
        getline(cin, input);
        option = chequeoRestriccionesRangos(input, 1, 6);

        while (option == 0) {
            cout << "Inserte la opción que quiere realizar: ";
            getline(cin, input);
            option = chequeoRestriccionesRangos(input, 1, 6);
        }

        if (option == 1) {
            system("cls");
            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                Area* temp = areas->getElement();
                if (temp->getCount() > 0) {
                    int tiempoPromedio = temp->getTiempoProm() / temp->getCount();
                    cout << "Nombre área: " << temp->getDescripcion() << endl;
                    cout << "Tiempo promedio de espera: " << tiempoPromedio << "sgs" << endl;
                }
            }
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 2) {
            system("cls");
            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                cout << areas->getElement()->getDescripcion() << endl;
                cout << areas->getElement()->getCount() << endl;
            }
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 3) {
            system("cls");
            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                Area *areaActual = areas->getElement();
                ventanillas = areaActual->ventanillas;
                for (ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()) {
                    cout << "Area: " << areaActual->getDescripcion() << endl;
                    cout << "Código de ventanilla: " << ventanillas->getElement()->getNombre() << endl;
                    cout << "Cantidad de tiquetes: " << ventanillas->getElement()->getCount() << endl << endl;
                }
            }
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 4) {
            system("cls");
            for (servicios->goToStart(); !servicios->atEnd(); servicios->next()) {
                Servicio *servicioActual = servicios->getElement();
                cout << "Area: " << servicioActual->getAreaAsignada() << endl;
                cout << "Servicio: " << servicioActual->getDescripcion() << endl;
                cout << "Tiquetes: " << servicioActual->getCount() << endl << endl;
            }
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 5) {
            system("cls");
            for (usuarios->goToStart(); !usuarios->atEnd(); usuarios->next()) {

                cout << usuarios->getElement()->getNombre() << endl;
                cout << usuarios->getElement()->getCount() << endl;
            }
            cout << "Presione cualquier tecla para continuar...";
            cin.get();
        }
    }
}

int main() {    
    setlocale(LC_ALL, "es_ES.UTF-8");   
    bool continuar = true;


    Usuarios* tipo0 = new Usuarios("Adulto mayor", 0);
    Usuarios* tipo1 = new Usuarios("Menor de edad", 1);
    Usuarios* tipo2 = new Usuarios("Usuario regular", 2);

    usuarios->insert(tipo0);
    usuarios->insert(tipo1);
    usuarios->insert(tipo2);

    Area* tempArea1 = new Area("Cajas", "C", stoi("4"));
    Area* tempArea2 = new Area("Farmacia", "F", stoi("5"));

    Servicio* tempServicio1 = new Servicio("Pagos", stoi("0"), "Cajas");
    Servicio* tempServicio2 = new Servicio("Facturas", stoi("1"), "Cajas");
    Servicio* tempServicio3 = new Servicio("Consulta", stoi("2"), "Cajas");

    tempArea1->agregarServicio(tempServicio1);
    tempArea1->agregarServicio(tempServicio2);
    tempArea1->agregarServicio(tempServicio3);

    areas->append(tempArea1);
    areas->append(tempArea2);

    servicios->append(tempServicio1);
    servicios->append(tempServicio2);
    servicios->append(tempServicio3);

    string input = "";
    int option = 0;

    while (option != 6) {  
        string ops[6] = {
            "Estado de las colas.",
            "Tiquetes.",
            "Atender.",
            "Administración.",
            "Estadísticas del sistema.",
            "Salir."
        };

        imprimirOpciones(ops, 6);
        cout << "Inserte la opción que quiere realizar: ";
        getline(cin, input);
        option = chequeoRestriccionesRangos(input, 1, 6);

        while (option == 0) {
            cout << "Inserte la opción que quiere realizar: ";
            getline(cin, input);
            option = chequeoRestriccionesRangos(input, 1, 6);
        }        

        if (option == 1) {
            system("cls");
            cout << "Estado de las colas: ";

            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                Area *temp = areas->getElement();
                cout << "\n\nNombre del área: " << temp->getDescripcion() << endl;
                cout << "Cantidad de ventanillas: " << temp->getCantVentanillas() << endl;
                cout << "Tiquetes en espera en el área: "; temp->tiquetes->printShow();
                cout << "\nVentanillas: " << endl;
                ventanillas = temp->ventanillas;
                for (ventanillas->goToStart(); !ventanillas->atEnd(); ventanillas->next()) {
                    Ventanilla *temp2 = ventanillas->getElement();
                    cout << "\t*Ventanilla " << temp2->getNombre();
                    cout << "\t\t///\tÚltimo tiquete atendido: " << temp2->getCodTiquete() << endl;
                }
            }
            cout << "\n\nPresione cualquier tecla para continuar...";
            cin.get();
        }

        if (option == 2) {
            operacionTiquetes();
        }

        if (option == 3) {
            operacionAtender();
        }

        if (option == 4) {
            operacionAdministracion();
        }

        if (option == 5) {
            operacionEstadisticas();
        }
    }

    return 0;
}