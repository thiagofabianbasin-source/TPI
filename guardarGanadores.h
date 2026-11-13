#ifndef GUARDARGANADORES_H_INCLUDED
#define GUARDARGANADORES_H_INCLUDED
#include <string>

using namespace std;
const int MAX_PARTIDAS = 100;
void guardarGanador(string nombre, int puntaje, string ganadores[], int puntajes[], int &cantidad);
void registrarResultado(string nombres[2], int puntos[2], string ganadores[], int puntajes[], int &cantidad);
void mostrarHistorial(string ganadores[], int puntajes[], int cantidad);

#endif // GUARDARGANADORES_H_INCLUDED
