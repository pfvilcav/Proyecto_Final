#include <iostream>
#include <ctime>   // fecha y hora
#include <iomanip> // setw
#include <fstream> //load save data
#include "color.hpp" //color test

using namespace std;
string fecha_hora() {
    time_t t = time(nullptr);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return buffer;
}

struct info {
    string nomb, fecha, t_alimento, marca, autor, genero;
    double precio;
    int cant;
} PRODUCTOS[250];

int menu() {
    int opcion;
    system("cls");
    cout << color::bg_green << "//////////////////////////////////////////////////////////" << endl;
    cout << "/              GESTOR DE PRODUCTOS Y ALMACEN             /" << color::reset << endl;
    cout << color::bg_green << "//////////////////////////////////////////////////////////" << color::reset << endl;
    cout << color::bg_blue << "1) Agregar producto." << endl
         << "2) Editar producto." << endl
         << "3) Eliminar producto." << endl
         << "4) Buscar producto por nombre." << endl
         << "5) Ver lista de productos." << endl
         << "6) Ver resumen del inventario" << endl
         << "7) Filtrar productos por categoria o proveedor." << endl
         << "8) Salir." << color::reset << endl;
    cout << color::bg_yellow << "Ingrese la opcion que usted desee realizar:" << color::reset << endl;
    cin >> opcion;
    return opcion;
}

int main() {
    char rpta;
    int n, catAa = 0, catBb = 0, catCc = 0, catDd = 0, total = 0, indice = 0;
    string catA[50], catB[50], catC[50], catD[50];
    char cat;  // Declarado aquí para usar en varias partes

    do {
        n = menu();
        system("cls");
        switch (n) {
            case 1: { // Agregar producto
                int k;
                cout << color::green << "*Cuantos tipos de productos quieres ingresar?" << color::reset << endl; 
                cin >> k;
                cout << endl << color::bg_yellow << "Ingrese los productos:" << color::reset << endl;

                for (int i = 0; i < k; i++) {
                    indice = total;
                    PRODUCTOS[indice].fecha = fecha_hora();
                    cout << "\nCategoria: " << color::red << "Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS" << color::reset << endl; 
                    cin >> cat;
                    cin.ignore();
                    if (cat == 'A' || cat == 'a') {
                        cout << color::green << "Nombre del producto:"; getline(cin, PRODUCTOS[indice].nomb);
                        catA[catAa++] = PRODUCTOS[indice].nomb;
                    }
                    else if (cat == 'B' || cat == 'b') {
                        cout << color::green << "Nombre del producto:"; getline(cin, PRODUCTOS[indice].nomb);
                        cout << color::green << "\nMarca del producto: "; cin >> PRODUCTOS[indice].marca;
                        catB[catBb++] = PRODUCTOS[indice].nomb;
                        cin.ignore();
                    }
                    else if (cat == 'C' || cat == 'c') {
                        cout << color::green << "Nombre del producto:"; getline(cin, PRODUCTOS[indice].nomb);
                        cout << color::green << "\nTipo de alimento: "; cin >> PRODUCTOS[indice].t_alimento;
                        catC[catCc++] = PRODUCTOS[indice].nomb;
                        cin.ignore();
                    }
                    else if (cat == 'D' || cat == 'd') {
                        cout << color::green << "Nombre del producto:"; getline(cin, PRODUCTOS[indice].nomb);
                        cout << color::green << "\nAutor: "; getline(cin, PRODUCTOS[indice].autor);
                        cout << "\nGenero: "; cin >> PRODUCTOS[indice].genero;
                        catD[catDd++] = PRODUCTOS[indice].nomb;
                        cin.ignore();
                    }

                    cout << color::green << "\nPrecio:"; cin >> PRODUCTOS[indice].precio;
                    cout << "\nCantidad:"; cin >> PRODUCTOS[indice].cant;
                    cout << "\nFecha de ingreso: " << PRODUCTOS[indice].fecha;

                    if (i == k - 1) {
                        cout << color::reset << color::bg_blue << "\nHecho!";
                        system("pause");
                    }
                    else {
                        cout << color::reset << color::bg_yellow << "\n===================================" << color::reset << endl;
                    }
                    total++;
                    cin.ignore();
                }
            } 
            break;
            case 2:
                // editar
            break;
            case 3:
                // eliminar
            break;
            case 4:
                // buscar por nombre
            break;
            case 5:
                if (total == 0) {
                    cout << color::bg_red << "No hay productos registrados." << color::reset << endl;
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
            case 6:
                // resumen
            break;
            case 7:
                cout << color::blue << "Que categoria quiere ver? \n A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS " << color::reset << endl;
                cin >> cat;
                if (cat == 'A' || cat == 'a') {
                    for (int i = 0; i < catAa; i++)
                        cout << i + 1 << ") " << catA[i] << endl;
                    system("pause");
                }
                else if (cat == 'B' || cat == 'b') {
                    for (int i = 0; i < catBb; i++)
                        cout << i + 1 << ") " << catB[i] << endl;
                    system("pause");
                }
                else if (cat == 'C' || cat == 'c') {
                    for (int i = 0; i < catCc; i++)
                        cout << i + 1 << ") " << catC[i] << endl;
                    system("pause");
                }
                else if (cat == 'D' || cat == 'd') {
                    for (int i = 0; i < catDd; i++)
                        cout << i + 1 << ") " << catD[i] << endl;
                    system("pause");
                }
            break;

            case 8:
                return 0;
            break;

            default:
                cout << color::bg_red << "Opcion no valida..." << color::reset << endl;
                system("pause");
            break;
        }
    } while (n != 8);
    return 0;
}
//borra la cuenta UnU