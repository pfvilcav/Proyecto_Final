//header utils
#ifndef MANAGER_UTILS_H
#define MANAGER_UTILS_H
#include <iostream>
#include <string>
using namespace std;

string fecha_hora();

//DECLARACION Y DEFINICION DE ESTRUCTURA INFO:

struct info {
    string nomb, fecha, marca, autor, genero, cat;
    double precio;
    int cant;
};

//DECLARACION DE ARREGLO PRODUCTOS:

extern info PRODUCTOS[250];

#endif