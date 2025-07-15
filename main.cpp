#include <iostream>
#include <ctime>            // fecha y hora
#include <iomanip>          // para hacer cuadros ordenados
#include "termcolor.hpp"    // color

using namespace std;
using namespace termcolor;

string fecha_hora() {
    time_t ahora = time(nullptr);          // Tiempo actual en segundos desde 1970
    char texto[30];                        // Espacio para guardar el texto con fecha y hora
    strftime(texto, sizeof(texto), "%d/%m/%Y %H:%M:%S", localtime(&ahora));
    return texto;                          // Devuelve la fecha y hora como string
}

struct info {
    string nomb, fecha, marca, autor, genero, cat;
    double precio;
    int cant;
} PRODUCTOS[250];


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
                //catA[catAa] = PRODUCTOS[indice].nomb;
                PRODUCTOS[indice].cat = "PAPELERIA";
                //catAa++;
                break;
            case 'B': case 'b':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                cout << green << "\nMarca del producto: ";
                cin >> PRODUCTOS[indice].marca;
                //catB[catBb] = PRODUCTOS[indice].nomb;
                PRODUCTOS[indice].cat = "ELECTRONICOS";
                //catBb++;
                break;
            case 'C': case 'c':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                //catC[catCc] = PRODUCTOS[indice].nomb;
                PRODUCTOS[indice].cat = "ALIMENTOS";
                //catCc++;
                break;
            case 'D': case 'd':
                cout << green << "Nombre del producto:";
                getline(cin, PRODUCTOS[indice].nomb);
                cout << green << "\nAutor: ";
                getline(cin, PRODUCTOS[indice].autor);
                cout << "\nGenero: ";
                cin >> PRODUCTOS[indice].genero;
                //catD[catDd] = PRODUCTOS[indice].nomb;
                PRODUCTOS[indice].cat = "LIBROS";
                //catDd++;
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
            } else cout << reset << on_yellow << "\n===================================" << reset << endl;
        total++;
    }
}

void editar_producto(int op){
    int nump, edit;
    string SN;
    for (int i = 0; i < op; i++) {
        cout << "\nNumero del producto: "; cin >> nump;
        do {
            cout << "______________________________________________________________________________________________________________" << endl;
            cout << "\nEditar: " << red << " 1) Nombre | 2) Precio | 3) Genero (libros) | 4) Autor (libros) | 5) Marca (electronicos)  " << reset << endl;
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
            cout << "Pasar al siguiente producto (S / N para seguir editanto )";
            cin >> SN;
        } while (SN == "N" || SN == "n");
    }
}

int menu() {
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

void lista(int &total){
    if (total == 0) {
        cout << on_red << "No hay productos registrados." << reset << endl;
        system("pause");
    }
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

int main() {
    char rpta, cat;
    int n, total = 0, indice = 0, suma = 0;
    //int catAa = 0, catBb = 0, catCc = 0, catDd = 0;
    //string catA[50], catB[50], catC[50], catD[50];

    do {
        n = menu();
        system("cls");

        switch (n) {
            case 1:
                int k;
                cout << green << "*Cuantos tipos de productos quieres ingresar?" << reset << endl;
                cin >> k;
                cout << endl << on_yellow << "Ingrese los productos:" << reset << endl;
                agregar_producto(k, indice, total, suma);
                break;
            case 2: {
                int op;
                    lista(total);
                    cout <<"\nNumero de productos a editar: "; cin >> op;
                    editar_producto(op);
                break;
            }
            case 3:
                break;

            case 4:
                break;

            case 5:
                lista(total);
                system("pause"); // para que la funcion no desaparesca de forma rapida
                break;

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

            case 8:
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
