#include <iostream>
#include <cstdlib>
using namespace std;

int cantidadRestantes = 54;
  //valores declrados fuera de "mazoPOker" xq sino las otras variables no accedian
  int valores[54] = {
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, // Picas
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, // Corazones
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, // Treboles
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, // Diamantes
    0, 0 // Comodines
};

char palos[54] = {
    'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
    'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
    'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T',
    'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D',
    'J', 'J'
};
         //bool para que no se repitan las cartas robads
bool usadas[54] = {false};
         //reinicio del mazo
void mazoPoker() {
    cantidadRestantes = 54;

    for (int i = 0; i < 54; i++) {
        usadas[i] = false;
    }

}
      //sigue el robo de cartas :(
int robarUna() {
    int pos = rand() % 54;

    while (usadas[pos]) {
        pos = rand() % 54;
    }

    usadas[pos] = true;
    cantidadRestantes--;

    return pos;
}
    int cartasRestantes () {
      return cantidadRestantes;

}
      // aca termna el sistema de cartas robadas :)

void mostrarCarta(int pos) {
    int v = valores[pos];

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

    cout << " " << palos[pos] << "]";
}
