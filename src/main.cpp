#include "tablero.hpp"
#include "mazmorra.hpp"
#include "protagonista.hpp"
#include "monstruo.hpp"
#include "amuleto.hpp"
#include "ncurses.h"


tablero tablero;
int m,n;
void clearme() {
    // CSI[2J clears screen, CSI[H moves the cursor to top-left corner
    std::cout << "\x1B[2J\x1B[H";
}

int puntodeacceso(void){

  int* v;
  int k;
  k=0;

  for (int i=1; i<tablero.pos().alto_1-1; i++)
    for (int j=1; j<tablero.pos().ancho_1-1; j++)
        k++;
  v= new int [k];
  k=0;
  for (int i=1; i<tablero.pos().alto_1-1; i++)
    for (int j=1; j<tablero.pos().ancho_1-1; j++){
        v[k]=tablero.pos().mazmorra_1+n*i+j;
        k++;
      }
  return (v[rand() % k]);
}

int main (void){

  srand(time(0));
  int op;
  char * vector;
  int acceso;
  int posesionamuleto;
  bool fin;
  posesionamuleto=0;
  fin=false;

  protagonista protagonista;
  clearme();
  cout<<"BIENVENIDO AL ROGUELIKE.\n\n";
  cout<<"1. Crear tablero aleatoriamente.\n2. Leer desde un fichero.\nElija una opción: ";
  cin>>op;
  cout<<"Introduzca alto del tablero: ";
  cin>> m;
  cout<<"Introduzca el ancho del tablero: ";
  cin>> n;

  switch (op){
    case 1:
      tablero.creatablero(m, n, op);
      vector=tablero.v();
      break;
    case 2:
      tablero.creatablero(m, n, op);
      vector=tablero.v();
      break;
  }
  monstruo monstruo(tablero.pos(), vector, m, n);
  amuleto amuleto(tablero.pos(), vector, m, n);

  acceso=puntodeacceso();
  protagonista.creaprota(acceso, vector, m, n);
  monstruo.creamonstruos();
  clearme();
  initscr();
  tablero.mostrar();
  printw("Vidas: ");
  for (int i=0; i<protagonista.vidas(); i++)
    printw("* ");


  printw("       Amuleto: No conseguido\n");
  protagonista.actualizavidas();


  while(fin==false){

    if (protagonista.vidas()==0)
      fin=true;
    if (fin==false){
    char mov;


    printw ("Use las teclas de desplazamiento w,a,s,d: ");
    protagonista.movimiento(mov = getch());


    if (posesionamuleto==1)
      vector[amuleto.ubicacionamuleto()]=' ';
    monstruo.actualizamonstruos();

    if (protagonista.ubicacionprotagonista()==amuleto.ubicacionamuleto())
      posesionamuleto=1;



    if ((protagonista.ubicacionprotagonista()==acceso && posesionamuleto==1))
      fin=true;




    tablero.mostrar();

    protagonista.actualizavidas();
    printw ("Vidas: ");
    for (int i=0; i<protagonista.vidas(); i++)
      printw("* ");
    printw("       Amuleto: ");


    if (posesionamuleto==1)
      printw("Conseguido\n");
    else
      printw("No conseguido\n");

    }


    }
    endwin();
    if (protagonista.vidas()<=0){
     cout<<" #####                          #######"<<endl;
     cout<<"#     #   ##   #    # ######    #     # #    # ###### #####"<<endl;
     cout<<"#        #  #  ##  ## #         #     # #    # #      #    #"<<endl;
     cout<<"#  #### #    # # ## # #####     #     # #    # #####  #    #"<<endl;
     cout<<"#     # ###### #    # #         #     # #    # #      #####"<<endl;
     cout<<"#     # #    # #    # #         #     #  #  #  #      #   #"<<endl;
     cout<<" #####  #    # #    # ######    #######   ##   ###### #    #"<<endl;


  }




    else{
      cout<<"#####"<<endl;
      cout<<"#     #   ##   #    #   ##    ####  ##### ######"<<endl;
      cout<<"#        #  #  ##   #  #  #  #        #   #"<<endl;
      cout<<"#  #### #    # # #  # #    #  ####    #   #####"<<endl;
      cout<<"#     # ###### #  # # ######      #   #   #"<<endl;
      cout<<"#     # #    # #   ## #    # #    #   #   #"<<endl;
      cout<<" #####  #    # #    # #    #  ####    #   ######"<<endl;

    }








}
