//funcs :D
#include <iostream>
#include <fstream>
#include "termcolor.hpp"
#include "manager_funcs.h"
#include "manager_utils.h"

using namespace std;
using namespace color;
void save(){
    fstream archivo("data.txt");
    archivo.close();
}

int load(){
    fstream archivo("data.txt");
    archivo.close();
}

info PRODUCTOS[250]; // definicion de arreglo PRODUCTOS

string fecha_hora() {
    time_t t = time(nullptr);
    char texto_fecha[30];
    strftime(texto_fecha, sizeof(texto_fecha), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return texto_fecha;
}

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
            cout << reset << on_blue << "\nHecho!";
            system("pause");
            } else {
            cout << reset << on_yellow << "\n===================================" << reset << endl;
            }

        total++;
    }
}