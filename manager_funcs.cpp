//funcs :D
#include <iostream>
#include <fstream>
#include <iomanip> 

#include "termcolor.hpp"
#include "manager_funcs.h"
#include "manager_utils.h"

using namespace std;
using namespace color;
extern int total;
extern int suma;


void save(){

    fstream archivo("data.txt", ios::out | ios::trunc);
    if (!archivo) {
        cout <<red<< "[DEBUG indo]"<<reset<<green<<"No se encontro archivo anterior." <<reset<< endl;
        return;
    }
    for (int i = 0; i < total; i++) {
        archivo << "Nombre: " << (PRODUCTOS[i].nomb.empty() ? "empty" : PRODUCTOS[i].nomb) << endl;
        archivo << "Fecha: " << (PRODUCTOS[i].fecha.empty() ? "empty" : PRODUCTOS[i].fecha) << endl;
        archivo << "Marca: " << (PRODUCTOS[i].marca.empty() ? "empty" : PRODUCTOS[i].marca) << endl;
        archivo << "Autor: " << (PRODUCTOS[i].autor.empty() ? "empty" : PRODUCTOS[i].autor) << endl;
        archivo << "Genero: " << (PRODUCTOS[i].genero.empty() ? "empty" : PRODUCTOS[i].genero) << endl;
        archivo << "Categoria: " << (PRODUCTOS[i].cat.empty() ? "empty" : PRODUCTOS[i].cat) << endl;
        archivo << "Precio: " << PRODUCTOS[i].precio << endl;
        archivo << "Cantidad: " << PRODUCTOS[i].cant << endl;
        archivo << "==================" << endl;
    }
    archivo.close();
}

void load() {
    fstream archivo("data.txt", ios::in);
    if (!archivo) {
        cout <<red<< "[DEBUG indo]"<<reset<<green<<"No se encontro archivo anterior." <<reset<< endl;
        return;
    }
    total = 0;
    string linea;
    while (getline(archivo, linea)) {
        if (linea.find("Nombre: ") == 0)
            PRODUCTOS[total].nomb = linea.substr(8);
        getline(archivo, linea);
        if (linea.find("Fecha: ") == 0)
            PRODUCTOS[total].fecha = linea.substr(7);
        getline(archivo, linea);
        if (linea.find("Marca: ") == 0)
            PRODUCTOS[total].marca = linea.substr(7);
        getline(archivo, linea);
        if (linea.find("Autor: ") == 0)
            PRODUCTOS[total].autor = linea.substr(7);
        getline(archivo, linea);
        if (linea.find("Genero: ") == 0)
            PRODUCTOS[total].genero = linea.substr(8);
        getline(archivo, linea);
        if (linea.find("Categoria: ") == 0)
            PRODUCTOS[total].cat = linea.substr(11);
        getline(archivo, linea);
        if (linea.find("Precio: ") == 0)
            PRODUCTOS[total].precio = stod(linea.substr(8));
        getline(archivo, linea);
        if (linea.find("Cantidad: ") == 0)
            PRODUCTOS[total].cant = stoi(linea.substr(10));

        getline(archivo, linea); // ===
        if (PRODUCTOS[total].nomb != "empty") {
            total++;
        }
    }

    save();
    archivo.close();
    return;
}

//FUNCION AGREGAR PRODUCTO OPCION 1:

void agregar_producto(int cantidad, int &indice, int &total, int &suma) {
    char cat;
    for (int i = 0; i < cantidad; i++) {
        indice = total;
        PRODUCTOS[indice].fecha = fecha_hora();
        cout << "\nCategoria: " << red << "Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS" << endl;
        cin >> cat;
        cin.ignore();
        switch (cat) {
            case 'A': case 'a':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                PRODUCTOS[indice].cat = "PAPELERIA";
            break;
            case 'B': case 'b':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                cout << green << "\nMarca del producto: ";
                cin >> PRODUCTOS[indice].marca;
                PRODUCTOS[indice].cat = "ELECTRONICOS";
            break;
            case 'C': case 'c':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                PRODUCTOS[indice].cat = "ALIMENTOS";
            break;
            case 'D': case 'd':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                cout << green << "\nAutor: ";
                getline(cin, PRODUCTOS[indice].autor);
                cout << "\nGenero: ";
                cin >> PRODUCTOS[indice].genero;
                PRODUCTOS[indice].cat = "LIBROS";
            break;
        }
        cout << green << "\nPrecio:";
        cin >> PRODUCTOS[indice].precio;
        cout << "\nCantidad:";
        cin >> PRODUCTOS[indice].cant;
        suma += PRODUCTOS[indice].cant;

        cout << "\nFecha de ingreso: " << PRODUCTOS[indice].fecha << endl;

        if (i == cantidad - 1) {
            cout << reset << on_blue << "\nHecho!" << reset;
            system("pause");
            } else {
            cout << reset << on_yellow << "\n===================================" << reset << endl;
            }

        total++;
    }
}

//FUNCION Eliminar 3:
void eliminar_producto(int num) {
    if (num < 1 || num > total) {
        cout << on_red << "Numero invalido." << reset << endl;
        return;
    }
    suma -= PRODUCTOS[num - 1].cant;
    for (int i = num - 1; i < total - 1; i++) {
        PRODUCTOS[i] = PRODUCTOS[i + 1];
    }
    total--;
    cout << on_green << "Producto eliminado exitosamente." << reset << endl;
    save();
}
void editar_producto(int op) {
    int nump, edit;
    string SN;
    for (int i = 0; i < op; i++) {
        cout << blue << "\nNumero del producto: " << reset; 
        cin >> nump;
        do {
            system("cls");
            cout << blue << string(100,'=') << endl;
            cout << right << setw(56) << "[MENU DE EDICION]" << endl;
            cout << string(100,'=') << reset << endl;
            cout << red << " 1) Nombre | 2) Precio | 3) Genero (libros) | 4) Autor (libros) | 5) Marca (electronicos) " << reset << endl;
            cin >> edit;
            cin.ignore();
            switch (edit) {
                case 1:
                    cout << "\nNuevo Nombre: "; getline(cin, PRODUCTOS[nump - 1].nomb);
                    break;
                case 2:
                    cout << "\nNuevo Precio: "; cin >> PRODUCTOS[nump - 1].precio;
                    break;
                case 3:
                    if (PRODUCTOS[nump-1].cat == "LIBROS") {
                        cout << "\nNuevo Genero: "; getline(cin, PRODUCTOS[nump - 1].genero);
                    } else {
                        cout << red << "Este producto no admite un genero...\n" << reset;
                        system("pause");
                    }
                    break;
                case 4:
                    if (PRODUCTOS[nump-1].cat == "LIBROS") {
                        cout << "\nNuevo Autor: "; getline(cin, PRODUCTOS[nump - 1].autor);
                    } else {
                        cout << red << "Este producto no admite un autor..\n" << reset;
                        system("pause");
                    }
                    break;
                case 5:
                    if (PRODUCTOS[nump-1].cat == "ELECTRONICOS") {
                        cout << "\nNueva Marca: "; getline(cin, PRODUCTOS[nump - 1].marca);
                    } else {
                        cout << red << "Este producto no admite una marca..\n" << reset;
                        system("pause");
                    }
                    break;
                default:
                    cout << red << "Opcion no valida...\n" << reset;
                    break;
            }
            cout << green <<"Desea pasar al siguiente producto? " << yellow << "(S/N)" << reset;
            cin >> SN;
        } while (SN == "N" || SN == "n");
    }
    save();
}

//FUNCION LISTA OPCION 5:

void lista(int total) {
    cout << left;
    cout << string(162, '-') << endl;
    cout <<"|"<< setw(9) << "  NUM"
         <<"|"<< setw(22) << "  Nombre"
         <<"|"<< setw(27) << "  Fecha"
         <<"|"<< setw(17) << "  Precio" 
         <<"|"<< setw(22) << "  Marca"
         <<"|"<< setw(22) << "  Autor"
         <<"|"<< setw(22) << "  Genero"
         <<"|"<< setw(9) << "  Cantidad  |" <<endl;
    cout << string(162, '-') << endl;
    for (int i = 0; i < total; i++) {
        cout <<"|"<< setw(9) << i + 1;
        cout <<"|"<< setw(22) <<PRODUCTOS[i].nomb;
        cout <<"|"<< setw(27) <<PRODUCTOS[i].fecha;
        cout <<"|"<< setw(17) <<PRODUCTOS[i].precio;
        cout <<"|"<< setw(22) <<PRODUCTOS[i].marca;
        cout <<"|"<< setw(22) <<PRODUCTOS[i].autor;
        cout <<"|"<< setw(22) <<PRODUCTOS[i].genero;
        cout <<"|"<< setw(7) <<PRODUCTOS[i].cant<< endl;
    }
}

//FUNCION FILTRADO POR CATEGORIA OPCION 7:

void filtrar_cat(char cat) {
    system("cls");
    switch (cat) {
        case 'A': case 'a':
            cout << yellow << string(50, '-') << endl;
            cout << "CATEGORIA PAPELERIA:" << endl;
            cout << string(50, '-') << endl << reset;
            for (int i = 0; i < total; i++) {
                if (PRODUCTOS[i].cat == "PAPELERIA") {
                    cout << i + 1 << ") " << PRODUCTOS[i].nomb << " - S/. " << PRODUCTOS[i].precio << endl;
                }
            }
        break;

        case 'B': case 'b':
            cout << blue << string(50, '-') << endl;
            cout << "CATEGORIA ELECTRONICOS:" << endl;
            cout << string(50, '-') << endl << reset;
            for (int i = 0; i < total; i++) {
                if (PRODUCTOS[i].cat == "ELECTRONICOS") {
                    cout << i + 1 << ") " << PRODUCTOS[i].nomb << " - S/. " << PRODUCTOS[i].precio << endl;
                }
            }
        break;

        case 'C': case 'c':
            cout << green << string(50, '-') << endl;
            cout << "CATEGORIA ALIMENTOS:" << endl;
            cout << string(50, '-') << endl << reset;
            for (int i = 0; i < total; i++) {
                if (PRODUCTOS[i].cat == "ALIMENTOS") {
                    cout << i + 1 << ") " << PRODUCTOS[i].nomb << " - S/. " << PRODUCTOS[i].precio << endl;
                }
            }
        break;

        case 'D': case 'd':
            cout << red << string(50, '-') << endl;
            cout << "CATEGORIA LIBROS:" << endl;
            cout << string(50, '-') << endl << reset;
            for (int i = 0; i < total; i++) {
                if (PRODUCTOS[i].cat == "LIBROS") {
                    cout << i + 1 << ") " << PRODUCTOS[i].nomb << " - S/. " << PRODUCTOS[i].precio << endl;
                }
            }
        break;
    }
    system("pause");
}

//DEFINICION DE FUNCION MENU:

int menu() {
    int opcion;
    do {
        system("cls");
        cout << on_green << "==========================================================" << endl;
        cout << "              [GESTOR DE PRODUCTOS Y ALMACEN]             " << reset << endl;
        cout << on_green << "==========================================================" << reset << endl;
        cout << blue << "1) Agregar producto." << endl 
                     << "2) Editar producto." << endl 
                     << "3) Eliminar producto." << endl 
                     << "4) Buscar producto por nombre." << endl 
                     << "5) Ver lista de productos." << endl 
                     << "6) Ver resumen del inventario" << endl 
                     << "7) Filtrar productos por categoria o proveedor." << endl 
                     << "8) Mostrar lista de productos." << endl 
                     << "0) Salir." << reset << endl;
        cout << on_yellow << "Seleccione una opcion:" << reset << endl;
        if (cin >> opcion) {
            break;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            system("cls");
            cout << on_red << "Entrada invalida. Por favor ingrese un numero." << reset << endl;
            system("pause");
        }
    } while (true);
    return opcion;
}