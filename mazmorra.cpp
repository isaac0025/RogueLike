#include "mazmorra.hpp"



mazmorra::mazmorra(int posicion, int alt, int anch, char* vector, int m){
    pared='*';
    puerta='+';
    pos=posicion;
    alto=alt;
    ancho=anch;

  //ahora dibujamos la habitación 1.
  for (int i=0; i<ancho; i++){
      vector[pos+i]=pared;
      vector[pos+m*(alto-1)+i]=pared;
  }
  //vector[pos+(rand()%ancho)]=puerta;

  for (int i=0; i<alto; i++){
      vector[pos+m*i]=pared;
      vector[pos+ancho-1+m*i]=pared;
  }

}
