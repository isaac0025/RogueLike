#pragma once
#include <iostream>
#include "tablero.hpp"
using namespace std;

class monstruo{
private:
  positions datos;
  char*  vector;
  int m;
  int n;
public:
  monstruo(positions c, char* v, int a, int b);
  void creamonstruos(void);
  void actualizamonstruos(void);
  ~monstruo(void){}

};
