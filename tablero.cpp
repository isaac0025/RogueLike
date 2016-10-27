#include "tablero.hpp"

tablero::tablero(void){
  m=0;
  n=0;
  flag=true;
  ancho1=0;
  alto1=0;
  ancho2=0;
  alto2=0;
  ancho3=0;
  alto3=0;
  mazmorra1=-1;
  mazmorra3=-1;
  mazmorra2=-1;

}
tablero::~tablero(void){
  vector=NULL;
}

void tablero::creatablero(int a, int b, int op){
  m=a;
  n=b;

  if (op==1){
    while (flag==true){
      vector = new char [m*n];
      for (int i=0; i<m*n; i++)
        vector[i]=' ';

    habitacion1();// límites de la habitación 1.
    habitacion2();//límites de la habitación 2.
    habitacion3();

    puerta1();
    if(flag==false)
      puerta2();
    if (flag==false)
      puerta3();

    }
  }
  else{
    vector = new char [m*n];
    char nombre[50];
    char c;
    cout<<"Introduca el nombre del archivo: ";
    cin >> nombre;
    ifstream entrada;
    entrada.open(nombre);
    for (int i=1; i<=m; i++){
      for (int j=1; j<=n; j++){
        entrada.get(c);
        vector[posicion(i,j)]=c;
        if (c=='\n'){
          entrada.get(c);
          vector[posicion(i,j)]=c;
        }
        if ((c=='*') && (mazmorra1==-1) &&(j<n/2))
            mazmorra1=posicion(i,j);
        if ((c=='*') && (mazmorra2==-1) &&(j>n/2))
            mazmorra2=posicion(i,j);
        if ((c=='*') && (mazmorra3==-1) &&(i>m/2))
              mazmorra3=posicion(i,j);
      }
    }
    entrada.close();

    while(vector[mazmorra1+ancho1]=='*')
      ancho1++;
    while(vector[mazmorra2+ancho2]=='*')
      ancho2++;
    while(vector[mazmorra3+ancho3]=='*'|| vector[mazmorra3+ancho3]=='+')
      ancho3++;

    while(vector[mazmorra1+n*alto1]=='*')
      alto1++;
    while(vector[mazmorra2+n*alto2]=='*'|| vector[mazmorra2+n*alto2]=='+')
      alto2++;
    while(vector[mazmorra3+n*alto3]=='*')
      alto3++;
    }
}


int tablero::posicion(int a, int b){ //devuelve la poscion dentro del tablero.
  return ((a-1)*n+b-1);
}

void tablero::mostrar(void){

  //system ("clear");
  move(0,0);
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++)//recorre los elementos de la fila
      printw("%2c",vector[posicion(i,j)]);
      printw("\n");
      //cout<<setw(2)<<vector[posicion(i,j)];
      //cout<<endl;
  }

  ofstream salida("salida.txt");
  for (int i=1; i<=m; i++){
    for (int j=1; j<=n; j++)//recorre los elementos de la fila
      salida<<vector[posicion(i,j)];
      salida<<endl;
  }




}


void tablero::habitacion1(void){ // x e y determinan los limites del primer cuadrante
  int a,b;
  //LIMITES DEL PRIMER CUADRANTE
  int limx=n/2;
  int limy=m/2;
  //ANCHO Y ALTO ALEATORIO PARA LA HABITACION
  ancho1 = rand() % (limx-4) + 4;
  alto1 = rand() % (limy-4) + 4;
  //POSICIONES POSIBLES
  b = rand() % (limx-ancho1) + 1;
  a = rand() % (limy-alto1) + 1;
  mazmorra1 = posicion(a,b);
  mazmorra A(mazmorra1, alto1, ancho1, vector, n);

}

void tablero::habitacion2(void){ // x e y determinan los limites del primer cuadrante
  int a,b;
  //LIMITES DEL SEGUNDO CUADRANTE.
  int limx=n/2;
  int limy=m/2;
  //ANCHO Y ALTO ALEATORIO PARA LA HABITACION
  ancho2 = rand() % (limx-4) + 4;
  alto2 = rand() % (limy-4) + 4;
  //POSICIONES POOSIBLES
  b = rand() % (limx-ancho2) + 1;
  a = rand() % (limy-alto2) + 1;
  mazmorra2 = posicion(a,b+limx+1);
  mazmorra A(mazmorra2, alto2, ancho2, vector, n);

}

void tablero::habitacion3(void){ // x e y determinan los limites del primer cuadrante
  int a,b;
  //LIMITES DEL SEGUNDO CUADRANTE.
  int limy=m/2;
  //ANCHO Y ALTO ALEATORIO PARA LA HABITACION
  ancho3 = rand() % (n-4) + 4;
  alto3 = rand() % (limy-4) + 4;
  //POSICIONES POOSIBLES
  b = rand() % (n-ancho3) + 1;
  a = rand() % (limy-alto3) + 1;
  mazmorra3 = posicion(a+limy+1,b);
  mazmorra A(mazmorra3, alto3, ancho3, vector, n);

}

int tablero::getposa(int x){

  return (x/n+1);

}

int tablero::getposb(int x){

  return (x%n+1);

}

void tablero::puerta1 (void){ //crea la puerta 1 y 2 además del pasillo.
  int esquina=mazmorra1+ancho1-1; //nos situamos en la esquina derecha de la hab. 1
  int k=0;
  int* v;
  int puerta;

  for(int i=1; i<alto1-1; i++)//Empieza en 1 y le restamos 1 para no tener en cuenta las esquinas
    for (int j=1; j<alto2-1; j++){
      if (getposa(esquina+(n*i))==getposa(mazmorra2+(n*j)))
        k++;
    }
  if (k==0)
    flag=true;
  else{
    flag=false;
    v = new int [k];
    k=0;

    for(int i=1; i<alto1-1; i++)//Empieza en 1 y le restamos 1 para no tener en cuenta las esquinas
      for (int j=1; j<alto2-1; j++){
        if (getposa(esquina+(n*i))==getposa(mazmorra2+(n*j))){
          v[k]=getposa(esquina+(n*i));
          k++;
        }
      }
    puerta=v[rand() % k];
    vector[posicion(puerta, getposb(esquina))]= '+';
    vector[posicion(puerta, getposb(mazmorra2))]= '+';
    int s=1;
    while(vector[(posicion(puerta, getposb(esquina))+s)] != '+'){
      vector[posicion(puerta, getposb(esquina))+s]='#';
      s++;
    }
  }
}

void tablero::puerta2(void){

  int esquina=mazmorra1+n*(alto1-1); //nos situamos en la esquina derecha de la hab. 1

  int k=0;
  int* v;
  int puerta;

  for(int i=1; i<ancho1-1; i++)//Empieza en 1 y le restamos 1 para no tener en cuenta las esquinas
    for (int j=1; j<ancho3-1; j++){
      if (getposb(esquina+i)==getposb(mazmorra3+j))
        k++;
    }
  if (k==0)
    flag=true;
  else{
    flag=false;
    v = new int [k];
    k=0;

    for(int i=1; i<ancho1-1; i++)//Empieza en 1 y le restamos 1 para no tener en cuenta las esquinas
      for (int j=1; j<ancho3-1; j++){
        if (getposb(esquina+i)==getposb(mazmorra3+j)){
          v[k]=getposb(esquina+i);
          k++;
        }
      }

    puerta=v[rand() % k];
    vector[posicion(getposa(esquina), puerta)]= '+';
    vector[posicion(getposa(mazmorra3), puerta)]= '+';
    int s=1;
    while(vector[posicion(getposa(esquina+n*s), puerta)] != '+'){
      vector[posicion(getposa(esquina+n*s),puerta)]='#';
      s++;
    }
  }






}

void tablero::puerta3(void){

  int esquina=mazmorra2+n*(alto2-1); //nos situamos en la esquina derecha de la hab. 1

  int k=0;
  int puerta;
  int s=1;

  for(int i=1; i<ancho2-1; i++)//Empieza en 1 y le restamos 1 para no tener en cuenta las esquinas
      if (getposb(esquina+i)==getposb(mazmorra3+ancho3))
        k=getposb(mazmorra3+ancho3);

  if (k==0)
    flag=true;
  else{
    flag=false;

    puerta=rand() %(alto3-2)+ 1;
    vector[posicion(getposa(esquina), k)]= '+';
    vector[posicion(getposa(mazmorra3+n*puerta), k-1)]= '+';

    while(getposa(esquina+n*s) <= getposa(mazmorra3+n*puerta)){
      vector[posicion(getposa(esquina+n*s),k)]='#';
      s++;
    }
  }
}

positions tablero::pos(void){
  positions A;
  A.alto_1 = alto1;
  A.alto_2 = alto2;
  A.alto_3 = alto3;
  A.ancho_1 = ancho1;
  A.ancho_2 = ancho2;
  A.ancho_3 = ancho3;
  A.mazmorra_1 = mazmorra1;
  A.mazmorra_2 = mazmorra2;
  A.mazmorra_3 = mazmorra3;
  return A;
}

char* tablero::v(void){

  return vector;


}
