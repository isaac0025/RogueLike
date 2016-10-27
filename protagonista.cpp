#include "protagonista.hpp"


protagonista::protagonista(void){

  lifes=5;
  posicion=-1;

}

void protagonista::creaprota(int pos, char* v, int a, int b){
  m=a;
  n=b;
  posicion=pos;
  vector=v;
  prev=' ';
  p_acceso=pos;
  vector[posicion]='@';
}

int protagonista::vidas(void){

  return lifes;
}

void protagonista::movimiento(char m){

  mov=m;

  if ((mov=='w')&& vector[posicion-n]!='*'){
    if ((prev=='#')&&vector[posicion-n]==' '){

    }
    else{
    vector[posicion]=prev;
    posicion=posicion-n;
    prev=vector[posicion];
    }
  }

  if ((mov=='s')&& vector[posicion+n]!='*'){
    if ((prev=='#')&&vector[posicion+n]==' '){

    }
    else{
    vector[posicion]=prev;
    posicion=posicion+n;
    prev=vector[posicion];
    }

  }
  if ((mov=='a')&& vector[posicion-1]!='*'){
    if ((prev=='#')&&vector[posicion-1]==' '){

    }
    else{
    vector[posicion]=prev;
    posicion=posicion-1;
    prev=vector[posicion];
    }

  }
  if ((mov=='d')&& vector[posicion+1]!='*'){
    if ((prev=='#')&&vector[posicion+1]==' '){

    }
    else{
    vector[posicion]=prev;
    posicion=posicion+1;
    prev=vector[posicion];
    }

  }

  vector[posicion]='@';
  if (posicion!=p_acceso)
    vector[p_acceso]='X';


}

int protagonista::ubicacionprotagonista(void){

  return posicion;
}


void  protagonista::actualizavidas(void){
 if (vector[posicion+1]=='O'){
    vector[posicion+1]=' ';
    lifes--;
  }
  if (vector[posicion-1]=='O'){
    vector[posicion-1]=' ';
    lifes--;
  }
  if (vector[posicion+n]=='O'){
    vector[posicion+n]=' ';
    lifes--;
  }
  if (vector[posicion-n]=='O'){
    vector[posicion-n]=' ';
    lifes--;
  }
}
