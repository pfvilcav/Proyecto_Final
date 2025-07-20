//header utils
#ifndef MANAGER_UTILS_H
#define MANAGER_UTILS_H

#include <string>
#include <ctime>

using namespace std;

struct categoria {
    string PAPELERIA, ELECTRONICOS, ALIMENTOS, LIBROS;
};

struct electronico{
    string marca;
};

struct libro{
    string genero, autor;
};

struct info {
    string nomb, fecha;
    double precio;
    int cant;
    electronico mark;
    libro lib;
    categoria cat;
};
extern info PRODUCTOS[250];

#endif