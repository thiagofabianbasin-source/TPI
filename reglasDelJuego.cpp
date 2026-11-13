#include <iostream>
#include "rlutil.h"
#include "marco.h"
 using namespace std;
 void general(){

rlutil::locate(57, 12);
cout << " GENERAL ";
rlutil::locate(32, 14);
cout << " - Juego de cartas para 2 jugadores en la misma computadora." ;
rlutil::locate(32, 15);
cout << " - Mazo de 54 cartas: las 52 del poker mas 2 comodines." ;
rlutil::locate(32, 16);
cout << " - Hay un solo mazo y no existe pila de descarte." ;
rlutil::locate(32, 17);
cout << " - Tablero de 3 filas de 5 casilleros cada una. " ;
rlutil::locate(32, 18);
cout << " - Cada jugador comienza con 0 puntos." ;
rlutil::locate(32, 19);
cout << " - Gana el primero en llegar a 50 puntos o mas." ;
rlutil::locate(32, 20);
cout << " - Quien empieza se sortea, como el lanzamiento de una moneda." ;
rlutil::locate(55, 23);
cout << "ENTER para volver " << endl;
                      cin.get();
                      rlutil::cls();
 }
 void valorDeLasCartas(){

rlutil::locate(54, 12);
cout << " VALOR DE LAS CARTAS";
rlutil::locate(32, 14);
cout << " - As ............ 1";
rlutil::locate(32, 15);
cout << " - 2 a 10 ........ su valor nominal";
rlutil::locate(32, 16);
cout << " - J ............. 11";
rlutil::locate(32, 17);
cout << " - Q ............. 12";
rlutil::locate(32, 18);
cout << " - K ............. 13";
rlutil::locate(32, 19);
cout << " - Comodin ....... no tiene valor, no se coloca en el tablero";
rlutil::locate(32, 20);
cout << " - Los palos no cambian el valor de la carta.";
rlutil::locate(32, 21);
cout << " - Palos: P (picas), C (corazones), T (treboles), D (diamantes).";
rlutil::locate(32, 22);
cout << " - Los diamantes y los comodines tienen jugadas especiales.";
rlutil::locate(55, 25);
cout << "  ENTER para volver ";
                      cin.get();
                      rlutil::cls();
}
void desarrolloDeUnTurno(){

rlutil::locate(50, 12);
cout << " DESARROLLO DE UN TURNO";
rlutil::locate(32, 13);
cout << " 1) Se muestra el estado: puntajes y tablero (cartas y suma";
rlutil::locate(55, 14);
cout << "    por fila).";
rlutil::locate(32, 15);
cout << " 2) El jugador activo roba las 2 cartas de arriba del mazo.";
rlutil::locate(32, 16);
cout << "    Si son los dos comodines y el tablero esta vacio,; pierde";
rlutil::locate(32, 17);
cout << "    el turno.";
rlutil::locate(32, 18);
cout << " 3) Elige una de las dos cartas y la jugada a realizar con ella.";
rlutil::locate(32, 19);
cout << " 4) Se aplica la jugada. Si una fila llega a 5 cartas, se suma y ";
rlutil::locate(32, 20);
cout << "    se puntua.";
rlutil::locate(32, 21);
cout << " 5) Vuelven al mazo: las cartas que salieron del tablero, el comodin";
rlutil::locate(32, 22);
cout << "    usado y la carta que no se jugo.";
rlutil::locate(32, 23);
cout << " 6) Se mezcla el mazo.";
rlutil::locate(32, 24);
cout << " 7) Se verifican las condiciones de victoria.";
rlutil::locate(32, 25);
cout << " 8) El turno pasa al rival.";
rlutil::locate(32, 26);
cout << " - Pasar no esta permitido: el jugador esta obligado a jugar.";
rlutil::locate(55, 29);
cout << "  ENTER para volver " << endl;
                      cin.get();
                      rlutil::cls();
}
void jugadasSegunLaCarta(){

rlutil::locate(50, 12);
cout << "JUGADAS SEGUN LA CARTA";
rlutil::locate(32, 13);
cout << " Cartas comunes (picas, corazones y treboles):";
rlutil::locate(32, 14);
cout << "-Se colocan en cualquier casillero vacio de cualquier fila.";

rlutil::locate(32, 15);
cout << "Diamantes (una de dos formas):";
rlutil::locate(32, 16);
cout << "-Colocarse en un casillero vacio, como cualquier otra carta.";
rlutil::locate(32, 17);
cout << "-Reemplazar a cualquier carta ya colocada, incluido otro diamante.";
rlutil::locate(32, 18);
cout << " -La carta reemplazada vuelve al mazo.";
rlutil::locate(32, 19);
cout << " -Reemplazar no agrega cartas a la fila, por lo que nunca";
rlutil::locate(32, 20);
cout << "  completa una fila.";
rlutil::locate(32, 21);
cout << " Comodin (el jugador elige una opcion):";
rlutil::locate(32, 22);
cout << " -Intercambiar de lugar dos cartas del tablero, aunque esten en";
rlutil::locate(32, 23);
cout << "  filas distintas.";
rlutil::locate(32, 24);
cout << " -Mover una carta a un casillero vacio de otra fila.";
rlutil::locate(32, 25);
cout << "  -Si es la quinta carta de su nueva fila, la fila se completa y";
rlutil::locate(32, 26);
cout << "   puntua quien jugo el comodin.";
rlutil::locate(32, 27);
cout << " -Retirar una carta del tablero y devolverla al mazo.";
rlutil::locate(32, 28);
cout << " -Despues de usarlo, el comodin vuelve al mazo.";
rlutil::locate(32, 29);
cout << " -Si el tablero esta vacio, el comodin no puede jugarse.";
rlutil::locate(55, 31);
cout << "  ENTER para volver " << endl;
                      cin.get();
                      rlutil::cls();
}
void completasUnaFila(){
rlutil::locate(50, 12);
cout << " COMPLETAR UNA FILA";
rlutil::locate(32, 13) ;
cout << " - Una fila se completa cuando se coloca su quinta carta, ya sea";
rlutil::locate(32, 14);
cout << "   jugando una carta o moviendola con un comodin.";
rlutil::locate(32, 15);
cout << " - Se suman los cinco valores y se puntua segun la tabla:";
rlutil::locate(32, 16);
cout << "     Suma de la fila     Resultado";
rlutil::locate(32, 17);
cout << "     -----------------   ----------------------------------------       ";
rlutil::locate(32, 18);
cout << "     Menor que 30        Nadie suma puntos.";
rlutil::locate(32, 19);
cout << "     Exactamente 30      Quien la completo suma 30 y su rival";
rlutil::locate(32, 20);
cout << "                         resta 15.";
rlutil::locate(32, 21);
cout << "     De 31 a 39          Quien la completo suma la suma de la fila.";
rlutil::locate(32, 22);
cout << "     40 o mas            CRISIS DE LOS 40: el rival de quien la";
rlutil::locate(32, 23);
cout << "                         completo suma la suma de la fila.";
rlutil::locate(32, 25);
cout << " - El puntaje nunca baja de 0.";
rlutil::locate(32, 26);
cout << "   Si el rival tiene menos de 15 cuando le cierran un 30 exacto,";
rlutil::locate(32, 27);
cout << "   queda en 0.";
rlutil::locate(32, 28);
cout << " - Despues de puntuar, las cinco cartas vuelven al mazo y la fila";
rlutil::locate(32, 29);
cout << "   queda vacia, disponible para volver a usarse.";
rlutil::locate(32, 30);
cout << " - El orden de las cartas dentro de la fila no importa: solo cuentan";
rlutil::locate(32, 31);
cout << "   cuantas cartas tiene y cuanto suman.";
rlutil::locate(55, 33);
cout << "  ENTER para volver " << endl;
                      cin.get();;
                      rlutil::cls();
}
void condicionesDeVictoriaYDerrota(){
rlutil::locate(47, 12);
cout << " CONDICIONES DE VICTORIA Y DERROTA";
rlutil::locate(32, 13);
cout << " - Victoria: ser el primero en llegar a 50 puntos o mas.";
rlutil::locate(32, 14);
cout << " - Derrota: que el rival llegue primero a 50 puntos o mas.";
rlutil::locate(32, 15);
cout << " - La partida termina inmediatamente, aunque el ganador haya llegado";
rlutil::locate(32, 16);
cout << "   con los puntos de una fila en la que su rival entro en la crisis";
rlutil::locate(32, 17);
cout << "   de los 40.";
rlutil::locate(55, 20);
cout << "  ENTER para volver " << endl;
                      cin.get();
                      rlutil::cls();
}
void situacionesEspeciales(){
rlutil::locate(50, 12);
cout << " SITUACIONES ESPECIALES";
rlutil::locate(32, 13);
cout << " - Dos comodines con el tablero vacio: se pierde el turno.";
rlutil::locate(32, 14);
cout << " - Mazo agotado: no puede ocurrir. Como mucho hay 12 cartas en el";
rlutil::locate(32, 15);
cout << "   tablero, asi que en el mazo quedan siempre al menos 42.";
rlutil::locate(32, 16);
cout << " - Siempre hay lugar: una fila nunca queda con 5 cartas al terminar";
rlutil::locate(32, 17);
cout << "   un turno (se completa y se vacia), por lo que siempre hay un";
rlutil::locate(32, 18);
cout << "   casillero libre.";
rlutil::locate(55,21);
cout << "  ENTER para volver ";

                     cin.get();
                      rlutil::cls();
}
void estrategia(){
   rlutil::locate(50, 12);
cout << " ESTRATEGIA";
rlutil::locate(32, 13);
cout << " - Poner la cuarta carta de una fila le da al rival la posibilidad";
rlutil::locate(32, 14);
cout << "   de cerrarla, pero no siempre es un regalo.";
rlutil::locate(32, 15);
cout << " - Ejemplo: una fila de 4 cartas que suma 34 solo se cierra bien con";
  rlutil::locate(32, 16);
cout << "   un As o una carta de 2 a 5. Con cualquier otra, quien la cierre";
 rlutil::locate(32, 17);
cout << "   llega a 40 o mas y le regala los puntos al rival.";
 rlutil::locate(32, 18);
cout << " - Si las tres filas tienen 4 cartas, el jugador esta obligado a";
 rlutil::locate(32, 19);
cout << "   completar una, y ahi pesa mas la crisis de los 40.";
rlutil::locate(55, 22 );
cout << "  ENTER para volver " << endl;
                      cin.get();
                      rlutil::cls();
}
void menuPrincipal(){
 rlutil::locate(50, 12);

cout << " MENU PRINCIPAL";
rlutil::locate(32, 13);
cout << " 1 - JUGAR";
rlutil::locate(32, 14);
cout << "     - Inicia una nueva partida.";
rlutil::locate(32, 15);
cout << "     - Pide los nombres de los jugadores y sortea quien empieza.";
rlutil::locate(32, 16);
cout << " 2 - ESTADISTICAS";
rlutil::locate(32, 17);
cout << "     - Muestra nombre y puntaje del mejor jugador humano.";
rlutil::locate(32, 18);
cout << "     - Se guardan solo en memoria, no en disco.";
rlutil::locate(32, 19);
cout << " 3 - REGLAS DEL JUEGO";
rlutil::locate(32, 20);
cout << "     - Muestra un resumen del reglamento.";
rlutil::locate(32, 21);
cout << " 0 - SALIR";
rlutil::locate(32, 22);
cout << "     - Finaliza el programa.";
 rlutil::locate(55, 25 );
cout << "  ENTER para volver " << endl;
                      cin.get();
                      rlutil::cls();

 }
