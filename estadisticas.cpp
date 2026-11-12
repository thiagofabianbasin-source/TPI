#include <iostream>
 using namespace std;
#include "guardarGanadores.h"

 void Estadisticas(string ganadores[], int puntajes[], int cantidad){
  cout <<"==============="<<endl;
  cout <<"ESTADISTICAS"<<endl;
  cout <<"==============="<<endl;
  cout << endl;
mostrarHistorial(ganadores, puntajes, cantidad);
}
