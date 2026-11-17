#include <iostream>
using namespace std;
#include <cstdlib>

void mazoPoker(bool usadas[54]) {
    for (int i = 0; i < 54; i++) {
        usadas[i] = false;
    }
}

int robarUna(bool usadas[54]) {
    int pos = rand() % 54;
    while (usadas[pos]) {
        pos = rand() % 54;
    }
    usadas[pos] = true;
    return pos;
}

int cartasRestantes(bool usadas[54]) {
    int cantidad = 0;
    for (int i = 0; i < 54; i++) {
        if (!usadas[i]) cantidad++;
    }
    return cantidad;
}

int valorCarta(int pos) {
    if (pos >= 52) return 0;      // comodines
    return pos % 13 + 1;
}

char paloCarta(int pos) {
    if (pos >= 52) return 'J';
    char palos[4] = {'P', 'C', 'T', 'D'};
    return palos[pos / 13];
}

void mostrarCarta(int pos) {
    int v = valorCarta(pos);

    if (v == 0) {
        cout << "[COMODIN]";
        return;
    }

    cout << "[";
    if (v == 1)       cout << "A";
    else if (v == 11) cout << "J";
    else if (v == 12) cout << "Q";
    else if (v == 13) cout << "K";
    else              cout << v;
    cout << " " << paloCarta(pos) << "]";
}

void devolverCarta(bool usadas[54], int pos) {
    usadas[pos] = false;
}

