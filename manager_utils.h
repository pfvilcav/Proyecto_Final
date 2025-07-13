//header utils
#ifndef MANAGER_UTILS_H
#define MANAGER_UTILS_H
#include <iostream>

using namespace std;
string fecha_hora() {
    time_t t = time(nullptr);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return buffer;
}

struct info {
    string nomb, fecha, marca, autor, genero, cat;
    double precio;
    int cant;
} PRODUCTOS[250];

#endif