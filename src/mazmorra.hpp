#pragma once
#include <iostream>
using namespace std;

//EL OBJETO MAZMORRA CREA LAS DIFERENTES HABITACIONES. HAY QUE PASARLE POR PARÁMETROS
//EL PUNTO DE INICIO DE LA HABITACIÓN Y EL TAMAÑO.


class mazmorra {

private:
    int pos;
    int alto;//alto
    int ancho;//ancho
    char pared;
    char puerta;
    

public:
    mazmorra(int posicion, int alt, int anch, char* vector, int n); //le pasas la posición de inicio de la mazmorra y el tamaño.
    ~mazmorra(void){}
};
