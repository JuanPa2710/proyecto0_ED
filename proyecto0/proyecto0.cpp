/*
El archivo principal en el que se maneja toda la interacción de la consola con el usuario.
En el main, se encuentra diversos prints y manejos de input para decidir que mostrar en el menú, basado en lo que decida el usuario.
Además, se puede encontrar algunos aspectos lógicos del programa en general, como la inicialización de listas en las que se trabajara.
Código hecho por Fiorella Gónzalez, Jose Adrián Piedra y Juan Pablo Jímenez.
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

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

static int countAreas = 0;


int main() {
    std::chrono::time_point<std::chrono::system_clock> horaActual;
    setlocale(LC_ALL, "es_ES.UTF-8");

    List<Usuarios *> *usuarios = new ArrayList<Usuarios *>();
    List<Area*> *areas = new LinkedList<Area*>();
    List<Servicio*> *servicios = new ArrayList<Servicio*>();

    bool continuar = true;

    Usuarios *tipo0 = new Usuarios("Adulto mayor", 0);
    Usuarios *tipo1 = new Usuarios("Menor de edad", 1);
    Usuarios *tipo2 = new Usuarios("Usuario regular", 2);

    usuarios->insert(tipo0);
    usuarios->insert(tipo1);
    usuarios->insert(tipo2);

    Area *tempArea1 = new Area("Cajas", "C", stoi("4"));
    Area *tempArea2 = new Area("Farmacia", "F", stoi("5"));

    Servicio *tempServicio1 = new Servicio("Pagos", stoi("0"), "Cajas");
    Servicio *tempServicio2 = new Servicio("Facturas", stoi("1"), "Cajas");
    Servicio *tempServicio3 = new Servicio("Consulta", stoi("2"), "Cajas");

    tempArea1->agregarServicio(tempServicio1);
    tempArea1->agregarServicio(tempServicio2);
    tempArea1->agregarServicio(tempServicio3);

    areas->append(tempArea1);
    areas->append(tempArea2);

    servicios->append(tempServicio1);
    servicios->append(tempServicio2);
    servicios->append(tempServicio3);

    int tiqueteConsecutivo = 100;
    int option = 0;

    while (option != 6) {
        cout << "1- Estado de las colas." << endl;
        cout << "2- Tiquetes." << endl;
        cout << "3- Atender." << endl;
        cout << "4- Administración." << endl;
        cout << "5- Estadísticas del sistema." << endl;
        cout << "6- Salir." << endl;
        cout << endl;
        cout << "Inserte la opción que quiere realizar: ";
        cin >> option;

        if (option == 1) {}

        if (option == 2) {  // Opción para solicitar un tiquete
            system("cls");
            usuarios->printShow();
            string tipoUsuarioSeleccionado;
            cout << "Seleccione el tipo de usuario: ";
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getline(cin, tipoUsuarioSeleccionado);
            cout << endl;

            servicios->printShow();
            cout << endl;
            string servicioSeleccionado;
            cout << "Seleccione el servicio que desea usar: ";
            getline(cin, servicioSeleccionado);

            servicios->goToPos(stoi(servicioSeleccionado));
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

            usuarios->goToPos(stoi(tipoUsuarioSeleccionado));
            Usuarios *usuario = usuarios->getElement();
            int prioridadUsuario = usuario->getPrioridad();
            int prioridadServicio = servicioActual->getPrioridad();
            int prioridadTiquete = prioridadUsuario * 10 + prioridadServicio;

            std::time_t tiempoActual = std::chrono::system_clock::to_time_t(horaActual);

            // Crear el tiquete y agregarlo a la cola
            Tiquete nuevoTiquete(codigoTiquete, horaActual, prioridadTiquete);

            areaActual->agregarTiquete(nuevoTiquete, prioridadTiquete);
            areaActual->setCount();
            usuario->setCount();

            cout << "Tiquete generado: " << codigoTiquete << endl;
            cout << "Hora: " << tiempoActual << endl;  // Mostrar la hora
            cout << "Prioridad: " << prioridadTiquete << endl;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            tiqueteConsecutivo++;
        }

        if (option == 3) {
            system("cls");
            string areaSeleccionada;
            string ventanilla;

            areas->printShow();

            cout << "Ingrese el área que desee atender: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, areaSeleccionada);

            cout << "Ingrese el número de ventanilla: ";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin, ventanilla);

            Area *areaActual = new Area();
            bool areaEncontrada = false;

            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                if (areas->getElement()->getDescripcion() == areaSeleccionada) {
                    areaActual = areas->getElement();
                    areaEncontrada = true;
                }
            }

            if (!areaEncontrada) {
                cout << "Error: No se encontró el área seleccionada." << endl;
            } else {
                Tiquete tiqueteAtendido = areaActual->atenderTiquete(); //**
                cout << "Se está atendiendo el tiquete. " << endl;
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (option == 4) {
            int suboption = 0;
            while (suboption != 5) {
                cout << "1- Manejo de tipos de usuarios." << endl;
                cout << "2- Manejo de áreas." << endl;
                cout << "3- Manejo de servicios." << endl;
                cout << "4- Limpiar colas y estadísticas." << endl;
                cout << "5- Regresar." << endl;
                cout << "Inserte la opción que quiere realizar: ";
                cin >> suboption;

                if (suboption == 1) {
                    system("cls");
                    int optionUsers = 0;

                    while (optionUsers != 3) {
                        system("cls");
                        cout << "1- Agregar un tipo de usuario. " << endl;
                        cout << "2- Eliminar un tipo de usuario. " << endl;
                        cout << "3- Regresar." << endl;
                        cout << "Inserte la opción que quiere realizar: ";

                        cin >> optionUsers;

                        if (optionUsers == 1) {
                            system("cls");
                            string nombre;
                            int prioridad;

                            cout << "Ingrese el nombre del Usuario: " << endl;
                            cin >> nombre;

                            cout << "Ingrese la prioridad: " << endl;
                            cin >> prioridad;

                            Usuarios *tipo = new Usuarios(nombre, prioridad);
                            usuarios->insert(tipo);

                            cout << "El tipo de usuario " << nombre << " fue agregado." << endl;
                        }

                        if (optionUsers == 2) {
                            system("cls");
                            string nombre;
                            cout << "Ingrese el nombre del área: " << endl;
                            getline(cin, nombre);

                            int pos = usuarios->indexOf(new Usuarios(nombre), 0);
                            usuarios->goToPos(pos);
                            cout << "Usuario " << usuarios->remove() << " eliminado correctamente" << endl;
                        }

                        if (optionUsers == 3) {
                            break;
                        }
                    }
                }

                if (suboption == 2) {
                    system("cls");
                    int optionArea = 0;
                    while (optionArea != 5) {
                        system("cls");
                        cout << "1- Agregar un área. " << endl;
                        cout << "2- Modificar cantidad de ventanillas. " << endl;
                        cout << "3- Consultar áreas. " << endl;
                        cout << "4- Eliminar un área. " << endl;
                        cout << "5- Regresar." << endl;
                        cout << "Inserte la opción que quiere realizar: ";

                        cin >> optionArea;

                        if (optionArea == 1) {
                            system("cls");
                            string descripcion, codigo, ventanillas;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Ingrese la descripción del área: ";
                            getline(cin, descripcion);

                            cout << "Ingrese el código del área: ";
                            getline(cin, codigo);

                            cout << "Ingrese la cantidad de ventanillas del área: ";
                            getline(cin, ventanillas);

                            Area *tempArea = new Area(descripcion, codigo, stoi(ventanillas));
                            areas->append(tempArea);
                            cout << "El área " << descripcion << " fue creada correctamente." << endl;

                        }

                        if (optionArea == 2) {
                            system("cls");
                            Area *tempArea = new Area();
                            string resul;

                            cout << "Áreas disponibles: " << endl;
                            areas->printShow();

                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nIngrese que área desea modificar: ";
                            getline(cin, resul);

                            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                                if (areas->getElement()->getDescripcion() == resul)
                                    tempArea = areas->getElement();
                            }

                            int pos = areas->indexOf(tempArea, 0);
                            areas->goToPos(pos);
                            tempArea->setDescripcion(areas->getElement()->getDescripcion());
                            cout << "Se ha encontrado el área: " << tempArea->getDescripcion() << endl;
                            cout << "Ingrese el nuevo número de ventanillas: ";
                            getline(cin, resul);

                            tempArea->setCantVentanillas(stoi(resul));
                            tempArea->toString();
                            cin >> resul;
                        }

                        if (optionArea == 3) {
                            system("cls");

                            string resul;
                            cout << "Áreas disponibles: " << endl << endl;
                            for (areas->goToStart(); !areas->atEnd(); areas->next())
                                areas->getElement()->toString();

                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cin >> resul;
                        }

                        if (optionArea == 4) {
                            Area *tempArea = new Area();
                            string resul;
                            system("cls");

                            cout << "Áreas disponibles: " << endl;
                            areas->printShow();

                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "\nIngrese que área desea eliminar: ";
                            getline(cin, resul);

                            for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                                if (areas->getElement()->getDescripcion() == resul)
                                    tempArea = areas->getElement();
                            }

                            int pos = areas->indexOf(tempArea, 0);
                            areas->goToPos(pos);
                            cout << "Se ha eliminado correctamente el área: " << areas->remove() << endl;
                            getline(cin, resul);
                        }
                    }
                }

                if (suboption == 3) {
                    system("cls");
                    int optionServicio = 0;
                    while (optionServicio != 5) {
                        system("cls");
                        cout << "1- Agregar un servicio. " << endl;
                        cout << "2- Reordenar servicios. " << endl;
                        cout << "3- Consultar servicios. " << endl;
                        cout << "4- Eliminar servicios. " << endl;
                        cout << "5- Regresar." << endl;
                        cout << "Inserte la opción que quiere realizar: ";
                        cin >> optionServicio;

                        if (optionServicio == 1) {
                            system("cls");
                            string descripcion, prioridad, area, prueba;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Ingrese la descripción del servicio: ";
                            getline(cin, descripcion);

                            cout << "Ingrese la prioridad del servicio: ";
                            getline(cin, prioridad);

                            cout << "\nÁreas disponibles: " << endl << endl;
                            for (areas->goToStart(); !areas->atEnd(); areas->next())
                                areas->getElement()->toString();
                            cout << "Ingrese a que área pertenece: ";
                            getline(cin, area);

                            Area *tempArea = new Area(area);
                            int pos = areas->indexOf(tempArea, 0);
                            areas->goToPos(pos);
                            tempArea = areas->getElement();

                            Servicio *tempServicio = new Servicio(descripcion, stoi(prioridad), area);
                            areas->getElement()->agregarServicio(tempServicio);
                            servicios->append(tempServicio);
                            servicios->print();
                            getline(cin, prueba);
                        }

                        if (optionServicio == 2) {
                            system("cls");
                            servicios->printShow();

                            string servicio;
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');

                            cout << "Digite el servicio que desee reordenar: ";
                            getline(cin, servicio);
                            int pos = servicios->indexOf(new Servicio(servicio), 0);
                            servicios->goToPos(pos);
                            Servicio *elemento = servicios->remove();
                            servicios->print();
                            string posicion;
                            cout << "Digite la posición a la que desea mover el elemento: ";
                            getline(cin, posicion);

                            servicios->goToPos(stoi(posicion) - 1);
                            servicios->insert(elemento);
                            cout << "Lista reordenada..." << endl;
                            servicios->printShow();
                            getline(cin, posicion);
                        }

                        if (optionServicio == 3) {
                            system("cls");
                            string detener;
                            cout << "Servicios disponibles: " << endl;
                            servicios->printShow();
                            cin >> detener;
                        }

                        if (optionServicio == 4) {
                            system("cls");
                            string servicio;
                            cout << "Servicios disponibles: " << endl;
                            servicios->printShow();

                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            cout << "Digite el servicio que desea eliminar: ";
                            getline(cin, servicio);

                            int pos = servicios->indexOf(new Servicio(servicio), 0);

                            if (pos != -1) {
                                servicios->goToPos(pos);
                                Servicio *elemento = servicios->remove();
                                int pos = areas->indexOf(new Area(elemento->getAreaAsignada()), 0);
                                areas->goToPos(pos);
                                Area *element = areas->getElement();
                                element->eliminarServicio(elemento);
                                cout << "El servicio " << servicio << " fue eliminado correctamente." << endl;
                            } else {
                                cout << "El servicio " << servicio << " no ha sido encontrado." << endl;
                            }
                            cout << endl << "Servicios disponibles: " << endl;
                            servicios->printShow();
                            getline(cin, servicio);

                        }
                    }
                }

                if (suboption == 4) {}

            }
        }

        if (option == 5) {
            int optionServicio = 0;
            while (optionServicio != 6) {
                system("cls");
                cout << "1- Tiempo de espera por área." << endl;
                cout << "2- Cantidad de tiquetes por área" << endl;
                cout << "3- Cantidad de tiquetes por ventanilla" << endl;
                cout << "4- Cantidad de tiquetes por servicio. " << endl;
                cout << "5- Cantidad de tiquetes por tipo de usuario" << endl;
                cout << "6- Regresar." << endl;
                cout << "Inserte la opción que quiere realizar: ";
                cin >> optionServicio;

                if (optionServicio == 1) {
                    system("cls");

                }

                if (optionServicio == 2) {
                    system("cls");
                    for (areas->goToStart(); !areas->atEnd(); areas->next()) {

                        cout << areas->getElement()->getDescripcion() << endl;
                        cout << areas->getElement()->getCount() << endl;
                    }
                    cout << "Presione cualquier tecla para continuar...";
                    cin.ignore();
                    cin.get();
                }

                if (optionServicio == 3) {
                    system("cls");

                }

                if (optionServicio == 4) {
                    system("cls");

                }

                if (optionServicio == 5) {
                    system("cls");
                    for (usuarios->goToStart(); !usuarios->atEnd(); usuarios->next()) {

                        cout << usuarios->getElement()->getNombre() << endl;
                        cout << usuarios->getElement()->getCount() << endl;
                    }
                    cout << "Presione cualquier tecla para continuar...";
                    cin.ignore();
                    cin.get();

                }
            }
        }

        if (option == 6) {}
    }

    return 0;
}