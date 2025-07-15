//header utils
#ifndef MANAGER_UTILS_H
#define MANAGER_UTILS_H
#include <iostream>
#include <string>
using namespace std;

string fecha_hora();

struct info {
    string nomb, fecha, marca, autor, genero, cat;
    double precio;
    int cant;
};
extern info PRODUCTOS[250]; //declaracion de arreglo PRODUCTOS

#endif