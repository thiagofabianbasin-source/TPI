#include <iostream>
#include "rlutil.h"
 using namespace std;
#include "guardarGanadores.h"
#include "marco.h"
 void Estadisticas(string ganadores[], int puntajes[], int cantidad){
  marco();
  // separadores
    for (int x=31; x<100; x++) {
        rlutil::locate(x,11);
        cout << (char)196;
    }
  rlutil::locate(57,10);
  cout <<"ESTADISTICAS"<<endl;



mostrarHistorial(ganadores, puntajes, cantidad);
 rlutil::anykey();
 rlutil::cls();
}
