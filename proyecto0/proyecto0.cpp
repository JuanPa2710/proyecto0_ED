#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include "LinkedPriorityQueue.h"

using namespace std;

int main() {

    PriorityQueue<string>* queue = new LinkedPriorityQueue<string>(3);

    while (true) {
        int option;

        cout << "¡Buen día!" << endl;
        cout << "Inserte la opción que quiere realizar: " << endl;
        cout << "1- Manejo de usuarios" << endl;
        cout << "2- Salir" << endl;

        cin >> option;
        switch (option)
        {
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
                cout << "Inserte la prioridad: " << endl;
                cin >> priority;

                queue->remove(name, priority);
                queue->print();
            }

        default:
            break;
        }
    }
}
