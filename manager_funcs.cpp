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

void save() {
    fstream archivo("data.txt");
    archivo.close();
}

int load() {
    fstream archivo("data.txt");
    archivo.close();
}

//DEFINICION DE ARREGLO PRODUCTOS:

info PRODUCTOS[250];

//FUNCION FECHA ACTUAL:

string fecha_hora() {
    time_t t = time(nullptr);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return texto_fecha;
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

//FUNCION EDITAR OPCION 2:

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

//FUNCION RESUMEN DE INVENTARIO OPCION 6:

void res_inv() {
    cout << left;
    cout << yellow << string(50, '-') << endl;
    cout << "PRODUCTOS DE PAPELERIA:" << endl;
    cout << string(50, '-') << endl << reset;
    for (int i = 0; i < total; i++) {
        if (PRODUCTOS[i].cat == "PAPELERIA") {
            cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
            << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;
        }
    }
    cout << blue << string(50, '-') << endl;
    cout << "PRODUCTOS ELECTRONICOS:" << endl;
    cout << string(50, '-') << endl << reset;
    for (int i = 0; i < total; i++) {
        if (PRODUCTOS[i].cat == "ELECTRONICOS") {
            cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
            << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;
        }
    }
    cout << green << string(50, '-') << endl;
    cout << "PRODUCTOS ALIMENTICIOS:" << endl;
    cout << string(50, '-') << endl << reset;
    for (int i = 0; i < total; i++) {
        if (PRODUCTOS[i].cat == "ALIMENTOS") {
        cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
        << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;
        }
    }
    cout << red << string(50, '-') << endl;
    cout << "PRODUCTOS BIBLIOGRAFICOS:" << endl;
    cout << string(50, '-') << endl << reset;
    for (int i = 0; i < total; i++) {
        if (PRODUCTOS[i].cat == "LIBROS") {
            cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
            << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;
        }
    }
    cout << "\nTotal: " << suma << " unidades" << reset << endl;
    system("pause");
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
                     << "7) Filtrar productos por categoria." << endl 
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