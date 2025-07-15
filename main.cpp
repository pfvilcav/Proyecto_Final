#include <iostream>
#include <ctime>            // fecha y hora
#include <iomanip>          // para hacer cuadros ordenados
#include <string>           //fixed string

#include "manager_funcs.h"
#include "manager_utils.h"
#include "termcolor.hpp"    // color update

using namespace std;
using namespace color;

int menu() {
    int opcion;
    bool valido = false;
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
                     << "0) Salir." << reset << endl;
        cout << on_yellow << "Ingrese la opcion que usted desee realizar:" << reset << endl;

        if (cin >> opcion && opcion >= 1 && opcion <= 8) {
            valido = true;
        } else {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << on_red << "Opcion no valida. Presione una tecla para intentar nuevamente." << reset << endl;
            system("pause");
        }
    } while (!valido);
    return opcion;
}

int main() {
    char rpta;
    int n, total = 0, indice = 0, suma = 0;
    do {
        n = menu();
        system("cls");

        switch (n) {
            case 1: {
                int k;
                char cat;
                cout << green << "*Cuantos tipos de productos quieres ingresar?" << reset << endl;
                cin >> k;
                cout << endl << on_yellow << "Ingrese los productos:" << reset << endl;

                for (int i = 0; i < k; i++) {
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
                        default:
                        menu();
                        break;
                    }

                    cout << green << "\nPrecio:";
                    cin >> PRODUCTOS[indice].precio;
                    cout << "\nCantidad:";
                    cin >> PRODUCTOS[indice].cant;
                    suma += PRODUCTOS[indice].cant;

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
            }

            case 2: {
                int op, nump, edit;
                string SN;
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

                cout << "Numero de productos a editar: "; cin >> op;
                for (int i = 0; i < op; i++) {
                    cout << "-----------------------------------" << endl;
                    cout << "\nNumero de producto: "; cin >> nump;
                    do {
                        cin.ignore();
                        cout << "________________________________________________________________________________________________" << endl;
                        cout << "\nEditar: " << red << " 1) Nombre | 2) Precio | 3) Genero (libros) | 4) Autor (libros) | 5) Marca (electronicos)  " << reset << endl;
                        cin >> edit;
                        cin.ignore();
                        switch (edit) {
                            case 1:
                                cout << "Nuevo Nombre: "; getline(cin, PRODUCTOS[nump - 1].nomb);
                                break;
                            case 2:
                                cout << "\nNuevo Precio: "; cin >> PRODUCTOS[nump - 1].precio;
                                break;
                            case 3:
                                cout << "\nNuevo Genero: "; getline(cin, PRODUCTOS[nump - 1].genero);
                                break;
                            case 4:
                                cout << "\nNuevo Autor: "; getline(cin, PRODUCTOS[nump - 1].autor);
                                break;
                            case 5:
                                cout << "\nNueva Marca: "; getline(cin, PRODUCTOS[nump - 1].marca);
                                break;
                            default:
                                cout << "Opcion no valida";
                                break;
                        }
                        cout << "Desea editar algo mas?? (S para continuar N para detener): ";
                        cin >> SN;
                    } while (SN == "S" || SN == "N");
                }
                break;
            }

            case 3:
                break;

            case 4:
                break;

            case 5: {
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
            }

            case 6: {
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

                cout << on_white << "La cantidad de productos es igual a: " << suma << reset << endl;
                system("pause");
                break;
            }

            case 7:
                char cat;
                cout << blue << "Que categoria quiere ver? \n" << yellow << "A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS " << green << endl;
                cin >> cat;
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
            break;

            case 0:
                return 0;
            break;

            default:
                cout << on_red << "Opcion no valida..." << reset << endl;
                system("pause");
                break;
        }
    } while (n != 8);

    return 0;
}