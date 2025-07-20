//header funcs
#ifndef MANAGER_FUNCS_H
#define MANAGER_FUNCS_H
#include <iostream>
#include <string>
using namespace std;

//DECLARACION FUNCIONES GUARDAR Y CARGAR DATOS:

void save();
void load();

//DECLARACION FUNCION FECHA Y HORA:

string fecha_hora();

//DECLARACION FUNCION AGREGAR:

void agregar_producto(int cantidad, int &indice, int &total, int &suma);

//DECLARACION FUNCION EDITAR:

void editar_producto(int op);

//DECLARACION ELIMINAR PRODUCTO:

void eliminar_producto(int num);

//DECLARACION FUNCION BUSCAR:

void buscar(int total);

//DECLARACION FUNCION LISTA:

void lista(int total);

//DECLARACION FUNCION RESUMEN DE INVENTARIO:

void res_inv();

//DECLARACION FUNCION FILTRAR POR CATEGORIA:

void filtrar_cat(char cat);

//DECLARACION DE FUNCION MENU:
int menu();

#endif