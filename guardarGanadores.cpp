#include <iostream>
using namespace std;
#include <string>
#include "guardarGanadores.h"

void guardarGanador(string nombre, int puntaje, string ganadores[], int puntajes[], int &cantidad) {
    if (cantidad < MAX_PARTIDAS) {
        ganadores[cantidad] = nombre;
        puntajes[cantidad] = puntaje;
        cantidad++;
    }
}

void registrarResultado(string nombres[2], int puntos[2], string ganadores[], int puntajes[], int &cantidad) {
    bool llego0 = (puntos[0] >= 50);
    bool llego1 = (puntos[1] >= 50);

    if (!llego0 && !llego1) return;

    if (llego0 && llego1) {
        if (puntos[0] > puntos[1]) {
            guardarGanador(nombres[0], puntos[0], ganadores, puntajes, cantidad);
        } else if (puntos[1] > puntos[0]) {
            guardarGanador(nombres[1], puntos[1], ganadores, puntajes, cantidad);
        }
    } else if (llego0) {
        guardarGanador(nombres[0], puntos[0], ganadores, puntajes, cantidad);
    } else {
        guardarGanador(nombres[1], puntos[1], ganadores, puntajes, cantidad);
    }
}

void mostrarHistorial(string ganadores[], int puntajes[], int cantidad) {
    if (cantidad == 0) {
        cout << "Todavia no hay partidas ganadas." << endl;
        return;
    }

    int mejor = 0;
    for (int i = 1; i < cantidad; i++) {
        if (puntajes[i] > puntajes[mejor]) mejor = i;
    }

    cout << "Mejor puntaje:" << endl;
    cout << "===============" << endl;
    cout << "Nombre:  " << ganadores[mejor] << endl;
    cout << "Puntaje: " << puntajes[mejor] << endl;
    cout << endl;

    cout << "Ganadores de esta sesion:" << endl;
    cout << "===============" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << i + 1 << ") " << ganadores[i]
             << " - " << puntajes[i] << " puntos" << endl;
    }
}
