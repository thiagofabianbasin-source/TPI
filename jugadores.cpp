#include "rlutil.h"
#include <iostream>
using namespace std;
#include <string>
#include <cstdlib>
#include <ctime>
#include "tablero.h"
#include "turnos.h"

float jugar(string ganadores[], int puntajes[], int &cantidadGanadores) ;
float jugar(string ganadores[], int puntajes[], int &cantidadGanadores) {
    string nombre[2];

    int jugador;

    srand(time(0));

    for (int i = 0; i < 2; i++) {
        cout << "Ingrese el nombre del jugador "<<i+1<<": ";
        cin >> nombre[i];
    }

    jugador = rand() % 2;
    rlutil::cls();
    cout << "========================================\n";

    cout << "          Empieza: " << nombre[jugador] << endl;

    cout << "         El otro jugador es: " << nombre[1 - jugador] << endl;

    cout << "========================================\n";

        rlutil :: anykey();
        rlutil::cls();
    turnos(nombre, jugador, ganadores, puntajes, cantidadGanadores);

    return 0;
}

