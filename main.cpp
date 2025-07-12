#include <iostream>
#include <ctime>            // fecha y hora
#include <iomanip>          // para hacer cuadros ordenados
#include "termcolor.hpp"    // color

using namespace std;
using namespace termcolor;

string fecha_hora() { // funcion string para hallar fecha y hora actual
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

int menu() { // menu (modularizar)
    int opcion;
    system("cls");
    cout << on_green << "//////////////////////////////////////////////////////////" << endl;
    cout << "/              GESTOR DE PRODUCTOS Y ALMACEN             /" << reset << endl;
    cout << on_green << "//////////////////////////////////////////////////////////" << reset << endl;
    cout << blue << "1) Agregar producto." << endl << "2) Editar producto." << endl << "3) Eliminar producto." << endl;
    cout << "4) Buscar producto por nombre." << endl << "5) Ver lista de productos." << endl << "6) Ver resumen del inventario" << endl;
    cout << "7) Filtrar productos por categoria o proveedor." << endl << "8) Salir." << reset << endl;
    cout << on_yellow << "Ingrese la opcion que usted desee realizar:" << reset << endl;
    cin >> opcion;
    return opcion;
}

int main() {
    char rpta;
    int n, catAa = 0, catBb = 0, catCc = 0, catDd = 0, total = 0, indice = 0, suma = 0;
    int A, B, C, D; // A: PAPELERIA // B: ELECTRONICOS // C: ALIMENTOS // D: LIBROS 
    string catA[50], catB[50], catC[50], catD[50]; // nombre productos en categorias

    do {
        n = menu();
        system("cls");

        switch (n) {
            case 1: ////// agregar
                int k;
                char cat;
                cout << green << "*Cuantos tipos de productos quieres ingresar?" << reset << endl;
                cin >> k;
                cout << endl << on_yellow << "Ingrese los productos:" << reset << endl;

                for (int i = 0; i < k; i++) {
                    indice = total;
                    PRODUCTOS[indice].fecha = fecha_hora(); // halla la fecha y hora exacta
                    cout << "\nCategoria: " << red << "Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS" << endl;
                    cin >> cat;
                    cin.ignore();

                    switch (cat) { // categorias
                        case 'A': case 'a':
                            cout << green << "Nombre del producto:";
                            getline(cin, PRODUCTOS[indice].nomb);
                            catA[catAa] = PRODUCTOS[indice].nomb;
                            PRODUCTOS[indice].cat = "PAPELERIA";
                            catAa++;
                            break;

                        case 'B': case 'b':
                            cout << green << "Nombre del producto:";
                            getline(cin, PRODUCTOS[indice].nomb);
                            cout << green << "\nMarca del producto: ";
                            cin >> PRODUCTOS[indice].marca;
                            catB[catBb] = PRODUCTOS[indice].nomb;
                            PRODUCTOS[indice].cat = "ELECTRONICOS";
                            catBb++;
                            break;

                        case 'C': case 'c':
                            cout << green << "Nombre del producto:";
                            getline(cin, PRODUCTOS[indice].nomb);
                            catC[catCc] = PRODUCTOS[indice].nomb;
                            PRODUCTOS[indice].cat = "ALIMENTOS";
                            catCc++;
                            break;

                        case 'D': case 'd':
                            cout << green << "Nombre del producto:";
                            getline(cin, PRODUCTOS[indice].nomb);
                            cout << green << "\nAutor: ";
                            getline(cin, PRODUCTOS[indice].autor);
                            cout << "\nGenero: ";
                            cin >> PRODUCTOS[indice].genero;
                            catD[catDd] = PRODUCTOS[indice].nomb;
                            PRODUCTOS[indice].cat = "LIBROS";
                            catDd++;
                            break;
                    }

                    cout << green << "\nPrecio:";
                    cin >> PRODUCTOS[indice].precio;
                    cout << "\nCantidad:";
                    cin >> PRODUCTOS[indice].cant;
                    suma = suma + PRODUCTOS[indice].cant;  ////////////////////////// CANTIDAD TOTAL(SUMA)
                    cout << "\nFecha de ingreso: " << PRODUCTOS[indice].fecha;

                    if (i == k - 1) {
                        cout << reset << on_blue << "\nHecho!";
                        system("pause");
                    } else {
                        cout << reset << on_yellow << "\n===================================" << reset << endl;
                    }

                    total++;
                }

                break;

            case 2: // editar
                break;

            case 3: // eliminar
                break;

            case 4: // buscar por nombre
                break;

            case 5: // lista de productos
                if (total == 0) {
                    cout << on_red << "No hay productos registrados." << reset << endl;
                    system("pause");
                    break;
                }

                cout << left;
                cout << setw(5) << "NUM"
                     << setw(25) << "Nombre"
                     << setw(22) << "Fecha"
                     << setw(10) << "Precio" << endl;
                cout << string(70, '-') << endl;

                for (int i = 0; i < total; i++) {
                    cout << setw(5) << i + 1;
                    cout << setw(25) << PRODUCTOS[i].nomb;
                    cout << setw(25) << PRODUCTOS[i].fecha;
                    cout << setw(10) << PRODUCTOS[i].precio << endl;
                }

                system("pause");
                break;

            case 6: // resumen inventario
                cout << left;
                // papeleria
                cout << yellow << string(50, '-') << endl;
                cout << "PRODUCTOS DE PAPELERIA:" <<endl;
                cout << string(50, '-') << endl << reset;
                for (int i = 0; i < total; i++) {
                    if (PRODUCTOS[i].cat == "PAPELERIA") {
                            cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
                            << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;
                    }
                }
                   
                //electronicos
                cout << blue << string(50, '-') << endl;
                cout << "PRODUCTOS ELECTRONICOS:" <<endl;
                cout << string(50, '-') << endl << reset;
                for (int i = 0; i < total; i++) {
                    if (PRODUCTOS[i].cat == "ELECTRONICOS") {
                            cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
                            << setw(10) << PRODUCTOS[i].cant << "unidades" << endl; 
                    }
                }
                   
                //alimentos
                cout << green << string(50, '-') << endl;
                cout << "PRODUCTOS ALIMENTICIOS:" <<endl;
                cout << string(50, '-') << endl << reset;
                for (int i = 0; i < total; i++) {
                    if (PRODUCTOS[i].cat == "ALIMENTOS") {
                    cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
                    << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;;
                    }
                }
                    
                //libros
                cout << red << string(50, '-') << endl;
                cout << "PRODUCTOS BIBLIOGRAFICOS:" <<endl;
                cout << string(50, '-') << endl << reset;
                for (int i = 0; i < total; i++) {
                    if (PRODUCTOS[i].cat == "LIBROS") {
                    cout << "Nombre: " << setw(20) << PRODUCTOS[i].nomb
                    << setw(10) << PRODUCTOS[i].cant << "unidades" << endl;
                    }
                }
                cout << on_white << "La cantidad de productos es igual a: " << suma << reset << endl;
                system("pause");
                break;

            case 7: // filtrar nombrepor categoria
                cout << blue << "Que categoria quiere ver? \n" << yellow << "A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS " << green << endl;
                cin >> cat;
                system("cls");

                switch (cat) {
                    case 'A': case 'a':
                    cout << yellow << string(50, '-') << endl;
                    cout << "CATEGORIA PAPELERIA:" <<endl;
                    cout << string(50, '-') << endl << reset;
                        for (int i = 0; i < catAa; i++) {
                            cout << i + 1 << ") " << catA[i] << endl;
                        }
                        system("pause");
                        break;

                    case 'B': case 'b':
                    cout << blue << string(50, '-') << endl;
                    cout << "CATEGORIA ELECTRONICOS:" <<endl;
                    cout << string(50, '-') << endl << reset;
                        for (int i = 0; i < catBb; i++) {
                            cout << i + 1 << ") " << catB[i] << endl;
                        }
                        system("pause");
                        break;

                    case 'C': case 'c':
                    cout << green << string(50, '-') << endl;
                    cout << "CATEGORIA ALIMENTOS:" <<endl;
                    cout << string(50, '-') << endl << reset;
                        for (int i = 0; i < catCc; i++) {
                            cout << i + 1 << ") " << catC[i] << endl;
                        }
                        system("pause");
                        break;

                    case 'D': case 'd':
                    cout << red << string(50, '-') << endl;
                    cout << "CATEGORIA LIBROS:" <<endl;
                    cout << string(50, '-') << endl << reset;
                        for (int i = 0; i < catDd; i++) {
                            cout << i + 1 << ") " << catD[i] << endl;
                        }
                        system("pause");
                        break;
                }

                break;

            case 8: // cerrar
                return 0;
                break;

            default:
                cout << on_red << "Opcion no valida..." << reset << endl;
                system("pause");
                break;
        }
    } while (n != 8); // salir

    return 0;
}