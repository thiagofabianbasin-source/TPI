#include <iostream>
using namespace std;
int elegirCarta() {
    int a = robarUna(-1);   // primera carta, es -1 pq asi se da cuenta el compilador que
    //es el primer intento de robar una carta
    int b = robarUna(a);    // segunda carta, distinta de la primera
    int opcion;
    int elegida;

    cout << "Cartas robadas:" << endl;
    cout << "1) ";
    mostrarCarta(a);
    cout << endl;
    cout << "2) ";
    mostrarCarta(b);
    cout << endl;

    cout << "Carta a jugar (1 o 2): ";
    cin >> opcion;

    while (opcion != 1 && opcion != 2) {
        cout << "Opcion invalida. Carta a jugar (1 o 2): ";
        cin >> opcion;
    }

    if (opcion == 1) {
        elegida = a;
    } else {
        elegida = b;
    }

    cout << "Elegiste: ";
    mostrarCarta(elegida);
    cout << endl;

    return elegida;
}
