//header funcs
#ifndef MANAGER_FUNCS_H
#define MANAGER_FUNCS_H
#include <iostream>
#include <string>
#include "termcolor.hpp"    // color update

using namespace color;
using namespace std;

void save();
void load();
void eliminar_producto(int num);

void agregar_producto(int cantidad, int &indice, int &total, int &suma);

//DECLARACION FUNCION EDITAR:

void editar_producto(int op);

//DECLARACION FUNCION LISTA:

void lista(int total);

//DECLARACION FUNCION FILTRAR POR CATEGORIA:

void filtrar_cat(char cat);

//DECLARACION DE FUNCION MENU:
int menu();

#endif