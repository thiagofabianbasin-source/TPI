#include <iostream>
using namespace std;

void mazoPoker(){

int valores [54]={
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,   // picas
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,   // corazones
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,   // treboles
    1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13,   // diamantes
    0, 0                                         // comodines
};

char palos[54] = {
    'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
    'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C',
    'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T', 'T',
    'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D', 'D',
    'J', 'J'
};
}
int robarUna(int excluir) {
    int pos = rand() % 54;
    while (pos == excluir) {
        pos = rand() % 54;
    }
    return pos;
}
void mostrarCarta(int pos) {
    int valores,palos;
    int v = valores[pos];

    if (v == 0) {
        cout << "[COMODIN]";
        return;
    }
      cout << "[";
    if (v == 1)       cout <<" "  << 'A';
    else if (v == 11) cout <<" "  << 'J';
    else if (v == 12) cout <<" "  << 'Q';
    else if (v == 13) cout <<" "  << 'K';
    else              cout <<" " << v;
    cout << " " << palos[pos] << "]";
}


