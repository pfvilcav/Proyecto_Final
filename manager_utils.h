//header utils
#ifndef MANAGER_UTILS_H
#define MANAGER_UTILS_H

#include <string>
#include <ctime>

using namespace std;

struct info {
    string nomb, fecha, marca, autor, genero, cat;
    double precio;
    int cant;
};
extern info PRODUCTOS[250];

inline string fecha_hora() {
    time_t t = time(nullptr);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return texto_fecha;
}
#endif