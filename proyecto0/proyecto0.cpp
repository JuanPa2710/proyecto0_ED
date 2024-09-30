#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "LinkedPriorityQueue.h"
#include "Area.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "spanish");
    setlocale(LC_ALL, "es_ES");

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
<<<<<<< HEAD
        cout << "3- Salir." << endl;
        cout << "Inserte la opción que quiere realizar: ";
=======
        cout << "3- Mostrar estadísticas." << endl;
        cout << "4- Salir." << endl;
        cout << "Inserte la opción que quiere realizar: " << endl;
>>>>>>> d72b4b97f5eeb832f3c7263de822cc55826aaede

        cin >> option;
        switch (option) {
        case 0:

            break;

        case 1:
<<<<<<< HEAD
            cout << "\n1- Agregar usuario. " << endl;
            cout << "2- Eliminar usuario. " << endl;
=======
            cout << "1- Agregar tipo de usuario. " << endl;
            cout << "2- Eliminar tipo de usuario. " << endl;
>>>>>>> d72b4b97f5eeb832f3c7263de822cc55826aaede
            cout << "3- Regresar. " << endl;

            int suboption;
            cin >> suboption;
            if (suboption == 1) {
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
                string name;
<<<<<<< HEAD
                int priority = 0;
=======
>>>>>>> d72b4b97f5eeb832f3c7263de822cc55826aaede

                cout << "Inserte la categoría:  " << endl;
                cin >> name;

                queue->remove(name);
                queue->print();
            }
            break;

        case 2: {
            cout << "\n1- Agregar un área. " << endl;
            cout << "2- Modificar cantidad de ventanillas. " << endl;
            cout << "3- Eliminar un área. " << endl;
            cout << "4- Regresar." << endl;
            cout << "Inserte la opción que quiere realizar: ";

            int optionArea = 0;
            cin >> optionArea;

            if (optionArea == 1) {
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

        case 3: 
            break;

        case 4:
            exit(0);
            break;
        }
            break;

        default:
            break;
        }
    }
}
