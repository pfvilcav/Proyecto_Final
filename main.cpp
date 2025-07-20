#include <iostream>
#include <ctime>            // fecha y hora
#include <iomanip>          // para hacer cuadros ordenados
#include <string>           //fixed string
#include <fstream>

#include "manager_funcs.h"
#include "manager_utils.h"
#include "termcolor.hpp"    // color update

using namespace std;
using namespace color;

//VARIABLES GLOBALES:

info PRODUCTOS[250];
int total = 0, suma = 0;

int main() {
    load();
    char rpta;
    int n, indice = 0;
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
                save();
                break;
            }

            case 2: {
                if (total == 0) {
                    cout << on_red << "No hay productos registrados." << reset << endl;
                    system("pause");
                    break;
                }
                int op;
                lista(total);
                cout << green << "\nNumero de productos a editar: " << reset; 
                cin >> op;
                editar_producto(op);
                save();
                break;
            }
            case 3:
                if (total == 0) {
                    cout << on_red << "No hay productos registrados." << reset << endl;
                    system("pause");
                    break;
                }
                lista(total);

                int num;
                cout << yellow << "Ingrese el numero del producto a eliminar: " << reset;
                cin >> num;

                eliminar_producto(num);
                system("pause");
                break;

            case 4: {
                string YN;
                do {
                    buscar(total);
                    cout<< red << "Seguir buscando? (S/N): "; 
                    cin>>YN;  
                } while(YN =="s" || YN =="S");

                break;
            }

            case 5: {
                if (total == 0) {
                    cout << on_red << "No hay productos registrados." << reset << endl;
                    system("pause");
                    break;
                }
                lista(total);
                system("pause");
                break;
            }

            case 6: {
                if (total == 0) {
                    cout << on_red << "No hay productos registrados." << reset << endl;
                    system("pause");
                    break;
                }
                res_inv();
                break;
            }
                     
            case 7:
                if (total == 0) {
                    cout << on_red << "No hay productos registrados." << reset << endl;
                    system("pause");
                    break;
                }
                char cat;
                cout << blue << "Que categoria quiere ver? \n" << yellow << "A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS " << green << endl;
                cin >> cat;
                filtrar_cat(cat);
                break;
            case 8: {
                fstream archivo("data.txt", ios::in);
                if (!archivo) {
                    cout << on_red << "Archivo no encontrado." << reset << endl;
                } else {
                    string linea;
                    while (getline(archivo, linea)) {
                        cout << linea << endl;
                    }
                    archivo.close();
                }
                system("pause");
                break;
            }

            case 0: {
                cout << on_green << "\nGracias por usar el gestor de productos. Hasta pronto!" << reset << endl;
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