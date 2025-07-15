//header funcs
#ifndef MANAGER_FUNCS_H
#define MANAGER_FUNCS_H
#include <iostream>
#include <string>
using namespace std;

void save();
int load();
void agregar_producto(int cantidad, int &indice, int &total, int &suma);
#endif