#include "amuleto.hpp"

amuleto::amuleto(positions c, char* j, int a, int b){

  datos = c;
  vector=j;
  m=a;
  n=b;

  int* v;
  int k;
  k=0;


for (int i=1; i<datos.alto_3-1; i++)
  for (int j=1; j<datos.ancho_3-1; j++)
      if(vector[datos.mazmorra_3+n*i+j]!= '@' && vector[datos.mazmorra_3+n*i+j]!= 'X')
        k++;

v= new int [k];
k=0;
for (int i=1; i<datos.alto_3-1; i++)
  for (int j=1; j<datos.ancho_3-1; j++){
      if(vector[datos.mazmorra_3+n*i+j]!= '@' && vector[datos.mazmorra_3+n*i+j]!= 'X' && vector[datos.mazmorra_3+n*i+j]!= '&'){
        vector[datos.mazmorra_3+n*i+j]=' ';
        v[k]=datos.mazmorra_3+n*i+j;
        k++;
      }
    }
posicion=(v[rand() % k]);
vector[posicion]='&';

}

int amuleto::ubicacionamuleto(void){
  return posicion;
}
