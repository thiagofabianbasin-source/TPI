#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "tablero.h"

using namespace std;

float jugar() ;
float jugar() {
    string nombre[2];

    int jugador;

    srand(time(0));

    for (int i = 0; i < 2; i++) {
        cout << "Ingrese el nombre del jugador "<<i+1<<": ";
        cin >> nombre[i];
    }

    jugador = rand() % 2;

    cout << "Empieza: " << nombre[jugador] << endl;

    cout << "El otro jugador es: " << nombre[1 - jugador] << endl;

    tablero(nombre);

    return 0;
}
