#ifndef TABLEROGRAFICO_H
#define TABLEROGRAFICO_H

#include <string>

int dibujarTablero(std::string nombres[2], int jugador, int cartas[3][5],
                   int puntos[2], int restantes, int carta1, int carta2);
void dibujarFila(int fila, int x0, int cartas[3][5]);
void prepararZonaInferior(int x0);
void mostrarMensaje(int x, int y, const char* texto);
int pedirOpcion(int x, int y, const char* texto, int minimo, int maximo);
 int calcularX0();
#endif
