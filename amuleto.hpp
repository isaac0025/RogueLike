#pragma once
#include <iostream>
#include "tablero.hpp"
using namespace std;

class amuleto{
private:
  positions datos;
  int posicion;
  char*  vector;
  int m;
  int n;
public:
  amuleto(positions c, char* v, int a, int b);
  ~amuleto(void){}
  int ubicacionamuleto(void);
};
