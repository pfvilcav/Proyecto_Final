#include <iostream>
#include <ctime>            // fecha y hora
#include <iomanip>          // para hacer cuadros ordenados
#include <string>           //fixed string

#include "manager_funcs.h"
#include "manager_utils.h"
#include "termcolor.hpp"    // color update

using namespace std;
using namespace color;

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
                agregar_producto(k, indice, total, suma);
                break;
            }

            case 2: {
                int op;
                lista(total);
                cout << green << "\nNumero de productos a editar: " << reset; 
                cin >> op;
                editar_producto(op);
                break;
            }
            case 3:
                break;

            case 4:
                break;

            case 5: {
                lista(total);
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

                cout << "Total: " << suma << " unidades" << reset << endl;
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

            case 0: {
                cout << on_green << "\nGracias por usar el gestor de productos. ¡Hasta pronto!" << reset << endl;
                system("pause");
                return 0;
            }

            default:
                cout << on_red << "Opcion no valida..." << reset << endl;
                system("pause");
                break;
        }
    } while (n != 0);

    return 0;
}