#ifndef MAZOPOKER_H_INCLUDED
#define MAZOPOKER_H_INCLUDED

 void mazoPoker(bool usadas[54]);
int robarUna(bool usadas[54]);
int cartasRestantes(bool usadas[54]);
int valorCarta(int pos);
char paloCarta(int pos);
void mostrarCarta(int pos);
void devolverCarta(bool usadas[54], int pos);

#endif // MAZOPOKER_H_INCLUDED
