#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "LinkedPriorityQueue.h"
#include "Area.h"
#include <chrono>
#include <string>

using namespace std;
using std::chrono::seconds;


int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");

    PriorityQueue<string> *queue = new LinkedPriorityQueue<string>(3);
    List<Area> *areas = new ArrayList<Area>();
    queue->insert("Adulto mayor.", 0);
    queue->insert("Menor de 6 años.", 1);
    queue->insert("Usuario regular.", 2);

    while (true) {
        int option;

        cout << "¡Buen día!" << endl;
        cout << "Seleccione la acción que desea realizar: " << endl;
        cout << "0- Solicitar un tiquete." << endl;
        cout << "1- Manejo de usuarios." << endl;
        cout << "2- Manejo de áreas." << endl;
        cout << "3- Mostrar estadísticas." << endl;
        cout << "4- Salir." << endl;
        cout << "Inserte la opción que quiere realizar: " << endl;


        cin >> option;
        switch (option) {

            case 1: {
                system("cls");

                cout << "\n1- Agregar usuario. " << endl;
                cout << "2- Eliminar usuario. " << endl;
                cout << "3- Regresar. " << endl;

                int suboption;
                cin >> suboption;
                if (suboption == 1) {
                    system("cls");
                    string name;
                    int priority;

                    cout << "Inserte la categoría:  " << endl;
                    cin >> name;
                    cout << "Inserte la prioridad: " << endl;
                    cin >> priority;

                    queue->insert(name, priority);
                    queue->print();
                }

                if (suboption == 2) {
                    system("cls");
                    string name;

                    int priority = 0;

                    cout << "Inserte la categoría:  " << endl;
                    cin >> name;

                    queue->remove(name);
                    queue->print();
                }
            }
                  break;

            case 2: {
                system("cls");
                cout << "\n1- Agregar un área. " << endl;
                cout << "2- Modificar cantidad de ventanillas. " << endl;
                cout << "3- Eliminar un área. " << endl;
                cout << "4- Regresar." << endl;
                cout << "Inserte la opción que quiere realizar: ";

                int optionArea = 0;
                cin >> optionArea;

                if (optionArea == 1) {
                    system("cls");
                    string descripcion, codigo, ventanillas;
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "\nIngrese la descripción del área: ";
                    getline(cin, descripcion);

                    cout << "Ingrese el código del área: ";
                    getline(cin, codigo);

                    cout << "Ingrese la cantidad de ventanillas del área: ";
                    getline(cin, ventanillas);

                    Area tempArea(descripcion, codigo, stoi(ventanillas));
                    areas->append(tempArea);
                    areas->print();
                }
                
            
            }
                  break;

            default:
                break;                  
        }
    }
}
