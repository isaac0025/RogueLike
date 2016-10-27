#pragma once
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "mazmorra.hpp"
#include "ncurses.h"

using namespace std;
//vamos a intentar generar el tablero a partir de un tamaño ya prefijado.

struct positions{
  int alto_1;
  int alto_2;
  int alto_3;
  int ancho_1;
  int ancho_2;
  int ancho_3;
  int mazmorra_1;
  int mazmorra_2;
  int mazmorra_3;
};

class tablero{

private:
  char* vector;
  bool flag;
  int m;
  int n;
  int ancho1, alto1 ,ancho2 , alto2 ,ancho3 , alto3;
  int mazmorra1;
  int mazmorra3;
  int mazmorra2;
public:
  tablero(void);
  ~tablero(void);
  void creatablero(int a, int b, int op);
  void puerta1 (void);
  void puerta2 (void);
  void puerta3 (void);
  void habitacion1(void);
  void habitacion2(void);
  void habitacion3(void);
  int posicion(int a, int b);
  void mostrar(void);
  int getposa(int x);
  int getposb(int x);
  positions pos(void);
  char* v(void);


};
