#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

#include "LinkedPriorityQueue.h"
#include "Area.h"
#include "Usuarios.h"

using namespace std;
using std::cin;
using std::stoi;
using std::chrono::system_clock;

//int prueba() {
//    setlocale(LC_ALL, "es_ES.UTF-8");
//
//    PriorityQueue<string> *queue = new LinkedPriorityQueue<string>(3);
//    List<Area> *areas = new ArrayList<Area>();
//    queue->insert("Adulto mayor.", 0);
//    queue->insert("Menor de 6 años.", 1);
//    queue->insert("Usuario regular.", 2);
//
//    while (true) {
//        int option;
//
//        cout << "¡Buen día!" << endl;
//        cout << "Seleccione la acción que desea realizar: " << endl;
//        cout << "0- Solicitar un tiquete." << endl;
//        cout << "1- Manejo de usuarios." << endl;
//        cout << "2- Manejo de áreas." << endl;
//        cout << "3- Mostrar estadísticas." << endl;
//        cout << "4- Salir." << endl;
//        cout << "Inserte la opción que quiere realizar: ";
//
//
//        cin >> option;
//        switch (option) {
//
//            case 1: {
//                system("cls");
//                cout << "1- Agregar usuario. " << endl;
//                cout << "2- Eliminar usuario. " << endl;
//                cout << "3- Regresar. " << endl;
//                cout << "Inserte la opción que quiere realizar: ";
//
//                int suboption;
//                cin >> suboption;
//                if (suboption == 1) {
//                    system("cls");
//                    string name;
//                    int priority;
//
//                    cout << "Inserte la categoría:  " << endl;
//                    cin >> name;
//                    cout << "Inserte la prioridad: " << endl;
//                    cin >> priority;
//
//                    queue->insert(name, priority);
//                    queue->print();
//                }
//
//                if (suboption == 2) {
//                    system("cls");
//                    string name;
//
//                    int priority = 0;
//
//                    cout << "Inserte la categoría:  " << endl;
//                    cin >> name;
//
//                    queue->remove(name);
//                    queue->print();
//                }
//            }
//                  break;
//
//            case 2: {
//                system("cls");
//                cout << "\n1- Agregar un área. " << endl;
//                cout << "2- Modificar cantidad de ventanillas. " << endl;
//                cout << "3- Eliminar un área. " << endl;
//                cout << "4- Regresar." << endl;
//                cout << "Inserte la opción que quiere realizar: ";
//
//                int optionArea = 0;
//                cin >> optionArea;
//
//                if (optionArea == 1) {
//                    system("cls");
//                    string descripcion, codigo, ventanillas;
//                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//                    cout << "\nIngrese la descripción del área: ";
//                    getline(cin, descripcion);
//
//                    cout << "Ingrese el código del área: ";
//                    getline(cin, codigo);
//
//                    cout << "Ingrese la cantidad de ventanillas del área: ";
//                    getline(cin, ventanillas);
//
//                    Area tempArea(descripcion, codigo, stoi(ventanillas));
//                    areas->append(tempArea);
//                    areas->print();
//                }
//                
//            
//            }
//                  break;
//
//            default:
//                break;                  
//        }
//    }
//    return 0;
//}

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    PriorityQueue<Usuarios>* usuarios = new LinkedPriorityQueue<Usuarios>(2048);
    List<Area>* areas = new ArrayList<Area>();
    List<Servicio>* servicios = new ArrayList<Servicio>();

    bool continuar = true;

    Usuarios tipo0("Adulto mayor.");
    Usuarios tipo1("Menor de 6 años.");
    Usuarios tipo2("Usuario regular.");

    usuarios->insert(tipo0, 0);
    usuarios->insert(tipo1, 1);
    usuarios->insert(tipo2, 2);

    int option;

    while (option != 3) {
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

        if (option == 2) {}

        if (option == 3) {}

        if (option == 4) {
            int suboption;
            while (suboption != 5) {
                cout << "1- Manejo de tipos de usuarios." << endl;
                cout << "2- Manejo de áreas." << endl;
                cout << "3- Manejo de servicios." << endl;
                cout << "4- Limpiar colas y estadísticas." << endl;
                cout << "5- Regresar." << endl;

                if (suboption == 1) {
                    system("cls");
                    int optionUsers;

                    while (optionUsers != 3) {
                        system("cls");
                        cout << "1- Agregar un tipo de usuario. " << endl;
                        cout << "2- Eliminar un tipo de usuario. " << endl;
                        cout << "3- Regresar." << endl;
                        cout << "Inserte la opción que quiere realizar: ";

                        cin >> optionUsers;

                        if (optionUsers == 1) {
                            string nombre;
                            int prioridad;

                            cout << "Ingrese el nombre del área: ";
                            cin >> nombre;

                            cout << "Ingrese la descripción del área: ";
                            cin >> prioridad;

                            Usuarios tipo(nombre);
                            usuarios->insert(tipo, prioridad);

                            cout << "El tipo de usuario " << nombre << " fue agregado." << endl;
                        }

                        if (optionUsers == 2) {}

                        if (optionUsers == 3) {
                            break;
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

                                Area tempArea(descripcion, codigo, stoi(ventanillas));
                                areas->append(tempArea);
                                cout << "El área " << descripcion << " fue creada correctamente." << endl;
                                Tiquete tempTiquete("C100", std::chrono::system_clock::now(), 0);
                                tempArea.agregarTiquete(tempTiquete, 0);
                            }

                            if (optionArea == 2) {
                                system("cls");
                                Area tempArea;
                                string resul;

                                cout << "Áreas disponibles: " << endl;
                                areas->printShow();

                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\nIngrese que área desea modificar: ";
                                getline(cin, resul);

                                for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                                    if (areas->getElement().getDescripcion() == resul)
                                        tempArea = areas->getElement();
                                }

                                int pos = areas->indexOf(tempArea, 0);
                                areas->goToPos(pos);
                                tempArea.setDescripcion(areas->getElement().getDescripcion());
                                cout << "Se ha encontrado el área: " << tempArea.getDescripcion() << endl;
                                cout << "Ingrese el nuevo número de ventanillas: ";
                                getline(cin, resul);

                                tempArea.setCantVentanillas(stoi(resul));
                                tempArea.toString();
                                cin >> resul;
                            }

                            if (optionArea == 3) {
                                system("cls");

                                string resul;
                                cout << "Áreas disponibles: " << endl << endl;
                                for (areas->goToStart(); !areas->atEnd(); areas->next())
                                    areas->getElement().toString();

                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> resul;
                            }

                            if (optionArea == 4) {
                                Area tempArea;
                                string resul;
                                system("cls");

                                cout << "Áreas disponibles: " << endl;
                                areas->printShow();

                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cout << "\nIngrese que área desea eliminar: ";
                                getline(cin, resul);

                                for (areas->goToStart(); !areas->atEnd(); areas->next()) {
                                    if (areas->getElement().getDescripcion() == resul)
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
                            cout << "2- Reodenar servicios. " << endl;
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
                                    areas->getElement().toString();
                                cout << "Ingrese a que área pertenece: ";
                                getline(cin, area);

                                Area tempArea(area);
                                int pos = areas->indexOf(tempArea, 0);
                                areas->goToPos(pos);
                                tempArea = areas->getElement();

                                Servicio tempServicio(descripcion, stoi(prioridad), area);
                                areas->getElement().agregarServicio(tempServicio);
                                servicios->append(tempServicio);
                                servicios->print();
                                getline(cin, prueba);
                            }
                        }
                    }

                    if (suboption == 4) {}
                }
            }

            if (option == 5) {}

            if (option == 6) {}

        }
    }
    return 0;
}
