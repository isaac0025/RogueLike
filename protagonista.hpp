#pragma once
#include <iostream>


using namespace std;


class protagonista{
private:
  char mov;
  char prev;
  int p_acceso;
  int posicion;
  char* vector;
  int lifes;
  int n;
  int m;
public:
  protagonista(void);
  void creaprota(int pos, char* v, int a, int b);
  ~protagonista(void){}
  int vidas(void);//devuelve el numero de vidas que le quedan
  void movimiento (char m);
  int ubicacionprotagonista(void);
  void actualizavidas(void);
};
