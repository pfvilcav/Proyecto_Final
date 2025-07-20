//header utils
#ifndef MANAGER_UTILS_H
#define MANAGER_UTILS_H

#include <string>
#include <ctime>

using namespace std;

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
};
extern info PRODUCTOS[250];

inline string fecha_hora() {
    time_t t = time(nullptr);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return texto_fecha;
}
#endif