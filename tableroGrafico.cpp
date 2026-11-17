#include "rlutil.h"
#include <iostream>
using namespace std;
#include <string>
#include "tableroGrafico.h"
#include "mazoPoker.h"

// Medidas del tablero :
//   carta: 7 de ancho x 3 de alto, con 2 columnas de separacion
//   las filas del tablero empiezan en y = 7, 11 y 15
//   las cartas robadas se dibujan en y = 20
//   los pedidos de datos van en y = 24, 25 y 26


void colorNormal() {
    rlutil::setBackgroundColor(rlutil::BLACK);
    rlutil::setColor(rlutil::WHITE);
}

// borra una linea de 67 caracteres a partir de la columna x
void borrarLinea(int x, int y) {
    colorNormal();
    rlutil::locate(x, y);
    for (int i = 0; i < 67; i++) {
        cout << ' ';
    }
}

const char* textoValor(int valor) {
    const char* textos[14] = {"", "A", "2", "3", "4", "5", "6",
                              "7", "8", "9", "10", "J", "Q", "K"};
    return textos[valor];
}


string simboloPalo(char palo) {

    switch(palo) {
        case 'D':
            return "\u2666"; // Diamante

        case 'T':
            return "\u2663"; // Trebol

        case 'P':
            return "\u2660"; // Pica

        case 'C':
            return "\u2665"; // Corazon

        default:
            return "?";
    }
}


void dibujarRectangulo(int x, int y, int ancho, int alto, int colorFondo) {
    rlutil::setBackgroundColor(colorFondo);
    for (int fila = 0; fila < alto; fila++) {
        rlutil::locate(x, y + fila);
        for (int col = 0; col < ancho; col++) {
            cout << ' ';
        }
    }
}

// pos es la posicion de la carta en el mazo (0 a 53)
void dibujarCarta(int pos, int x, int y) {
    int valor = valorCarta(pos);
    char palo = paloCarta(pos);

    dibujarRectangulo(x, y, 7, 3, rlutil::WHITE);

    if (valor == 0) {
        rlutil::setColor(rlutil::MAGENTA);
        rlutil::locate(x + 1, y);
        cout << "JOKER";
        rlutil::locate(x + 3, y + 1);
        cout << '*';
        colorNormal();
        return;
    }

    if (palo == 'C' || palo == 'D') {
        rlutil::setColor(rlutil::RED);
    } else {
        rlutil::setColor(rlutil::BLACK);
    }

    const char* texto = textoValor(valor);
    int largo = (valor == 10) ? 2 : 1;

    rlutil::locate(x + 1, y);
    cout << texto;
    rlutil::locate(x + 3, y + 1);
    cout << simboloPalo(palo);
    rlutil::locate(x + 6 - largo, y + 2);
    cout << texto;

    colorNormal();
}

void dibujarCasilleroVacio(int x, int y) {
    dibujarRectangulo(x, y, 7, 3, rlutil::DARKGREY);
    rlutil::setColor(rlutil::GREY);
    rlutil::locate(x + 3, y + 1);
    cout << "\xE2\x97\x86";
    colorNormal();
}

void dibujarReverso(int x, int y) {

    rlutil::setBackgroundColor(rlutil::BLUE);
    rlutil::setColor(rlutil::LIGHTBLUE);

    for (int fila = 0; fila < 3; fila++) {
        rlutil::locate(x, y + fila);

        for (int col = 0; col < 7; col++) {
            cout << "\xE2\x96\x91";
        }
    }

    colorNormal();
}

// dibuja una fila del tablero con sus 5 casilleros, la cantidad y la suma
void dibujarFila(int fila, int x0, int cartas[3][5]) {
    int y = 7 + fila * 4;
    int cantidad = 0;
    int suma = 0;

    colorNormal();
    rlutil::locate(x0, y + 1);
    cout << "Fila " << fila + 1;

    for (int col = 0; col < 5; col++) {
        int x = x0 + 9 + col * 9;

        if (cartas[fila][col] == 0) {
            dibujarCasilleroVacio(x, y);
        } else {
            dibujarCarta(cartas[fila][col] - 1, x, y);
            cantidad++;
            suma += valorCarta(cartas[fila][col] - 1);
        }
    }

    colorNormal();
    rlutil::locate(x0 + 55, y + 1);
    cout << cantidad << "/5   Suma ";
    if (suma >= 40) {
        rlutil::setColor(rlutil::LIGHTRED);   // ya es crisis de los 40
    }
    cout << suma;
    colorNormal();
}

// dibuja toda la pantalla y devuelve la columna donde empieza el tablero
int dibujarTablero(string nombres[2], int jugador, int cartas[3][5],
                   int puntos[2], int restantes, int carta1, int carta2) {

    int columnas = rlutil::tcols();
    if (columnas < 70) {
        columnas = 120;
    }
    int x0 = columnas / 2 - 33;

    rlutil::cls();
    colorNormal();

    // titulo y separador
    rlutil::locate(x0 + 25, 1);
    cout << "CRISIS DE LOS 40";
    rlutil::locate(x0, 2);
    for (int i = 0; i < 67; i++) {
         cout << "\xE2\x94\x80";
    }

    // turno y puntajes
    rlutil::locate(x0 + 25, 5);
    rlutil::setColor(rlutil::YELLOW);
    cout << "Turno de " << nombres[jugador];
    colorNormal();
    rlutil::locate(x0 + 47, 3);
    cout << "Objetivo: 50 puntos";

         if (jugador==0){
          rlutil::locate(x0, 3);
            cout << ">";
         }else {
          rlutil::locate(x0, 3);
          cout << " ";
          }
        rlutil::locate(x0 + 2, 3);
        cout << nombres[0] << ": " << puntos[0] << " puntos";

        if (jugador==1){
          rlutil::locate(x0, 4);
            cout << ">";
         }else {
          rlutil::locate(x0, 4);
          cout << " ";
          }
        rlutil::locate(x0 + 2, 4);
        cout << nombres[1] << ": " << puntos[1] << " puntos";


    // numeros de columna
    for (int col = 0; col < 5; col++) {
        rlutil::locate(x0 + 9 + col * 9 + 3, 6);
        cout << col + 1;
    }

    // las tres filas
    for (int fila = 0; fila < 3; fila++) {
        dibujarFila(fila, x0, cartas);
    }

    // separador
    rlutil::locate(x0, 18);
    for (int i = 0; i < 67; i++) {
        cout << "\xE2\x94\x80";
    }

    // cartas robadas
    rlutil::locate(x0, 19);
    cout << "Cartas robadas:";

    rlutil::locate(x0 + 5, 21);
    cout << "1)";
    dibujarCarta(carta1, x0 + 9, 20);
    colorNormal();
    rlutil::locate(x0 + 17, 21);
    if (valorCarta(carta1) != 0) {
        cout << "vale " << valorCarta(carta1);
    } else {
        cout << "comodin";
    }

    rlutil::locate(x0 + 30, 21);
    cout << "2)";
    dibujarCarta(carta2, x0 + 34, 20);
    colorNormal();
    rlutil::locate(x0 + 42, 21);
    if (valorCarta(carta2) != 0) {
        cout << "vale " << valorCarta(carta2);
    } else {
        cout << "comodin";
    }

    // mazo
    rlutil::locate(x0 + 57, 19);
    cout << "Mazo: " << restantes;
    dibujarReverso(x0 + 57, 20);

    return x0;
}

// limpia la parte de abajo de la pantalla para mensajes largos
// (por ejemplo los del comodin o los de una fila completada)
void prepararZonaInferior(int x0) {
    for (int y = 18; y <= 29; y++) {
        borrarLinea(x0, y);
    }
    rlutil::locate(x0, 19);
    rlutil::showcursor();
}

void mostrarMensaje(int x, int y, const char* texto) {
    borrarLinea(x, y);
    rlutil::locate(x, y);
    rlutil::setColor(rlutil::LIGHTRED);
    cout << texto;
    colorNormal();
}

// pide un numero entre minimo y maximo en la posicion (x, y) de la pantalla
int pedirOpcion(int x, int y, const char* texto, int minimo, int maximo) {
    int valor = 0;
    bool valido;

    rlutil::showcursor();

    do {
        borrarLinea(x, y);
        rlutil::locate(x, y);
        cout << texto;

        cin >> valor;
        valido = !cin.fail() && valor >= minimo && valor <= maximo;

        if (!valido) {
            cin.clear();
            cin.ignore(1000, '\n');
            mostrarMensaje(x, 28, "Opcion invalida.");
        }
    } while (!valido);

    borrarLinea(x, 28);
    rlutil::hidecursor();

    return valor;
}
