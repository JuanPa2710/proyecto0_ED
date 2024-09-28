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

    while (true) {
        int option;

        cout << "¡Buen día!" << endl;        
        cout << "1- Manejo de usuarios." << endl;
        cout << "2- Manejo de áreas." << endl;
        cout << "3- Salir." << endl;
        cout << "Inserte la opción que quiere realizar: " << endl;

        cin >> option;
        switch (option) {
        case 1:
            cout << "1- Agregar usuario. " << endl;
            cout << "2- Eliminar usuario. " << endl;
            cout << "3- Regresar. " << endl;

            int suboption;
            cin >> suboption;
            if (suboption == 1) {
                string name;
                int priority;

                cout << "Inserte su nombre:  " << endl;
                cin >> name;
                cout << "Inserte la prioridad: " << endl;
                cin >> priority;

                queue->insert(name, priority);
                queue->print();
            }

            if (suboption == 2) {
                string name;
                int priority;

                cout << "Inserte su nombre:  " << endl;
                cin >> name;

                queue->remove(name);
                queue->print();
            }
            break;

        case 2: {
            cout << "1- Agregar un área. " << endl;
            cout << "2- Modificar cantidad de ventanillas. " << endl;
            cout << "3- Eliminar un área. " << endl;
            cout << "4- Regresar." << endl;

            int optionArea = 0;
            cin >> optionArea;

            if (optionArea == 1) {
                string descripcion, codigo, ventanillas;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nIngrese la descripción del área: ";
                getline(cin, descripcion);

                cout << "\nIngrese el código del área: ";
                getline(cin, codigo);

                cout << "\nIngrese la cantidad de ventanillas del área: ";
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
