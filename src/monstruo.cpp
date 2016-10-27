#include "monstruo.hpp"


monstruo::monstruo(positions c, char* v, int a, int b){

  datos = c;
  vector=v;
  m=a;
  n=b;
}

void monstruo::creamonstruos(void){

//HABITACION 1.
    int* v;
    int k;
    int p1,p2,p3;
    k=0;

    for (int i=1; i<datos.alto_1-1; i++)
      for (int j=1; j<datos.ancho_1-1; j++)
          if(vector[datos.mazmorra_1+n*i+j]!= '@')
            k++;

    v= new int [k];
    k=0;
    for (int i=1; i<datos.alto_1-1; i++)
      for (int j=1; j<datos.ancho_1-1; j++){
          if(vector[datos.mazmorra_1+n*i+j]!= '@'){
            vector[datos.mazmorra_1+n*i+j]=' ';
            v[k]=datos.mazmorra_1+n*i+j;
            k++;
          }
        }
    p1=1;
    p2=1;
    p3=1;

    while (p1==p2||p1==p3||p2==p3){
      p1=v[rand() % k];
      p2=v[rand() % k];
      p3=v[rand() % k];
    }
    vector[p1]='O';
    vector[p2]='O';
    vector[p3]='O';


  //Habitacion 2.

  for (int i=1; i<datos.alto_2-1; i++)
    for (int j=1; j<datos.ancho_2-1; j++)
        if(vector[datos.mazmorra_2+n*i+j]!= '@')
          k++;

  v= new int [k];
  k=0;
  for (int i=1; i<datos.alto_2-1; i++)
    for (int j=1; j<datos.ancho_2-1; j++){
        if(vector[datos.mazmorra_2+n*i+j]!= '@'){
          vector[datos.mazmorra_2+n*i+j]=' ';
          v[k]=datos.mazmorra_2+n*i+j;
          k++;
        }
      }
      p1=1;
      p2=1;
      p3=1;

      while (p1==p2||p1==p3||p2==p3){
        p1=v[rand() % k];
        p2=v[rand() % k];
        p3=v[rand() % k];
      }
      vector[p1]='O';
      vector[p2]='O';
      vector[p3]='O';

  //Habitacion 3.

  for (int i=1; i<datos.alto_3-1; i++)
    for (int j=1; j<datos.ancho_3-1; j++)
        if(vector[datos.mazmorra_3+n*i+j]!= '@' && vector[datos.mazmorra_3+n*i+j]!= '&')
          k++;

  v= new int [k];
  k=0;
  for (int i=1; i<datos.alto_3-1; i++)
    for (int j=1; j<datos.ancho_3-1; j++){
        if(vector[datos.mazmorra_3+n*i+j]!= '@' && vector[datos.mazmorra_3+n*i+j]!= '&'){
          vector[datos.mazmorra_3+n*i+j]=' ';
          v[k]=datos.mazmorra_3+n*i+j;
          k++;
        }
      }
      p1=1;
      p2=1;
      p3=1;

      while (p1==p2||p1==p3||p2==p3){
        p1=v[rand() % k];
        p2=v[rand() % k];
        p3=v[rand() % k];
      }
      vector[p1]='O';
      vector[p2]='O';
      vector[p3]='O';
}




void monstruo::actualizamonstruos(void){
  int mov;
  bool valido;
  int m;
  char antes;
  int m1[3];
  int s;
  bool flag1, flag2, flag3, flag4;

  flag1=false;
  flag2=false;
  flag3=false;
  flag4=false;



   for (int k=0; k<3; k++){
     //Buscamos los monstruos en la habitacion 1;
     if (k==0){
       s=0;
       for (int i=1; i<datos.alto_1-1; i++)
         for (int j=1; j<datos.ancho_1-1; j++)
             if(vector[datos.mazmorra_1+n*i+j]== 'O'){
                m1[s]=datos.mazmorra_1+n*i+j;
                s++;
               }
      }
    //Buscamos los monstruos en la habitacion 2;
     if (k==1){
       s=0;
       for (int i=1; i<datos.alto_2-1; i++)
         for (int j=1; j<datos.ancho_2-1; j++)
             if(vector[datos.mazmorra_2+n*i+j]== 'O'){
               m1[s]=datos.mazmorra_2+n*i+j;
               s++;
             }
      }

    //Buscamos los monstruos en la habitacion 3;
     if (k==2){
       s=0;
       for (int i=1; i<datos.alto_3-1; i++)
         for (int j=1; j<datos.ancho_3-1; j++)
             if(vector[datos.mazmorra_3+n*i+j]== 'O'){
                m1[s]=datos.mazmorra_3+n*i+j;
                s++;
              }
      }

    for (int i=0; i<s; i++){
    if (vector[m1[i]]=='O'){
     valido=false;
     while (valido==false){

       mov=rand() % 4;
       switch (mov){
         case 0: //se mueve a la derecha
          m=m1[i]+1;
          if(vector[m]!='@'&&vector[m]!='X'&&vector[m]!='&'&&vector[m]!='*'&&vector[m]!='*'&&vector[m]!='O'&&vector[m]!='&'&&vector[m]!='+'){
            valido=true;
            antes=vector[m1[i]];
            vector[m1[i]]=' ';
            m1[i]++;
            vector[m1[i]]=antes;


          }
          flag1=true;
         break;
         case 1: //se mueve a la izquierda
         m=m1[i]-1;
         if(vector[m]!='@'&&vector[m]!='X'&&vector[m]!='&'&&vector[m]!='*'&&vector[m]!='*'&&vector[m]!='O'&&vector[m]!='&'&&vector[m]!='+'){
           valido=true;
           antes=vector[m1[i]];
           vector[m1[i]]=' ';
           m1[i]--;
           vector[m1[i]]=antes;



         }
         flag2=true;
         break;
         case 2: //se mueve  hacia abajo
         m=m1[i]+n;
         if(vector[m]!='@'&&vector[m]!='X'&&vector[m]!='&'&&vector[m]!='*'&&vector[m]!='*'&&vector[m]!='O'&&vector[m]!='&'&&vector[m]!='+'){
           valido=true;
           antes=vector[m1[i]];
           vector[m1[i]]=' ';
           m1[i]+=n;
           vector[m1[i]]=antes;

         };
         flag3=true;
         break;
         case 3: //se mueve hacia arriba
         m=m1[i]-n;
         if(vector[m]!='@'&&vector[m]!='X'&&vector[m]!='&'&&vector[m]!='*'&&vector[m]!='*'&&vector[m]!='O'&&vector[m]!='+'){
           valido=true;
           antes=vector[m1[i]];
           vector[m1[i]]=' ';
           m1[i]-=n;
           vector[m1[i]]=antes;

         }
         flag4=true;
         break;
         }
         //si los tres flags son true quiere decir que hay un monstruo que no se puede mover en ninguna direccion
         // por tanto ese monstruo no se mueve.
         if(flag1==true && flag2==true && flag3==true && flag4==true)
          valido=true;
       }

      flag1=false;
      flag2=false;
      flag3=false;
      flag4=false;
     }
   }
 }
}
