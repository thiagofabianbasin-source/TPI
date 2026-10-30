#include <iostream>
#include <string>
using namespace std;
const int MAX_PARTIDAS = 100;
string ganadores [ MAX_PARTIDAS];
int puntajesGanadores [MAX_PARTIDAS];
int cantidadGanadores=0;

void guardarGanador (string nombre, int puntaje)´{
 if (cantidadGanadores>MAX_PARTIDAS){
    ganadores[cantidadGanadores]=nombre;
    puntajesGanadores[cantidadGanadores]=puntaje;
    cantidadGanadores++
 }
}
//esta funcion de abajo llamalo al final de una partida
// como los turnos
void registrarResultado(string nombre[2],int puntos[2]){
 cout<<"debug: "<< nombres[0]<< "=" << puntos[0]<<"/"<< nombres [1] << "=" <<puntos[1]<<endl;
 bool llego0=(puntos[0]>=50);
 bool llego1=(puntos[1]>=50);
 if (llego0 && llego1){
 if (puntos[0]>puntos[1]){
    guardarGanador(nombre[0], puntos[0]);
 }else (puntos[1]>puntos[0]){
   guardarGanador(nombre[1],puntos[1]);
 }
 }
}
void mostrarGanadores(){
if (cantidadGanadores==0){
    cout<<"todavia no hay ganadores"<<endl;
    return;
}
int mejor=0;
for (int i=1; i <cantidadGanadores; i++){
    if (puntajesGanadores[i]>puntajesGanadores[mejor]){
        mejor=i;
    }

}
cout<<"Mejor puntaje: "<<endl;
cout<<"================="<<endl;
cout<<"nombre: "<< ganadores[mejor]<<endl;
cout<<"puntaje: "<< puntajesGanadores[mejor]<<endl;
cout<<endl;

cout<<"Ganadores de esta sesion: "<<endl;
cout<<"============================="<<endl;
fot (int i=0; i< cantidadGanadores;i++){
cout<<i+1<<")"<<ganadores[i]<<" - " <<puntajesGanadores[i]<< "puntos"<<endl;
}
}
