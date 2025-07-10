#include<iostream>
#include <cstdint> 
#include "termcolor.hpp"

using namespace std;
using namespace termcolor;

struct info{
    string nomb;
    int precio, cant;
} PRODUCTOS[250];

int menu() { //menu (modularizar)
    int opcion;
    system("cls");
    cout<<on_green<<"//////////////////////////////////////////////////////////"<<endl;
    cout<<"/              GESTOR DE PRODUCTOS Y ALMACEN             /"<<reset<<endl;
    cout<<on_green<<"//////////////////////////////////////////////////////////"<<reset<<endl;
    cout<<on_blue<<"1) Agregar producto."<<endl<<"2) Editar producto."<<endl<<"3) Eliminar producto."<<endl;
    cout<<"4) Buscar producto por nombre."<<endl<<"5) Ver lista de productos."<<endl<<"6) Ver resumen del inventario"<<endl;
    cout<<"7) Filtrar productos por categoria o proveedor."<<endl<<"8) Guardar productos."<<endl<<"9) Salir."<<reset<<endl;
    cout<<on_yellow<<"Ingrese la opcion que usted desee realizar:"<<reset<<endl;
    cin>>opcion;
    return opcion;
}

int main() {
    int n, catAa=0, catBb=0, catCc=0, catDd=0;
    int A, B, C, D; //A: PAPELERIA // B: ELECTRONICOS // C:ALIMENTOS // D: LIBROS 
    string catA[50], catB[50], catC[50], catD[50]; // categorias
    do {
        n=menu();
        system("cls");
        switch (n) {
            case 1: //agregar
            int k;
            char cat;
            cout<<green<<"*Cuantos tipos de productos quieres ingresar?"<<reset<<endl; cin>>k;
            cout<<endl<<on_yellow<<"Ingrese los productos:"<<reset<<endl;
            for (int i=0; i<k; i++) { // luego para almacenar en .txt se debe crear variable que almacene el total.
                cin.ignore();
                cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb);
                cout<<"\nCategoria: "<<red<<"Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS"<<endl; cin>>cat;
                switch(cat) {
                    case 'A': case 'a':
                        catA[i]=PRODUCTOS[i].nomb;
                        catAa++;
                    break;

                    case 'B': case 'b':
                        catB[i]=PRODUCTOS[i].nomb;
                        catBb++;
                    break;

                    case 'C': case 'c':
                        catC[i]=PRODUCTOS[i].nomb;
                        catCc++;
                    break;

                    case 'D': case 'd':
                        catD[i]=PRODUCTOS[i].nomb;
                        catDd++;
                    break;
                }
                cout<<green<<"\nPrecio:"; cin>>PRODUCTOS[i].precio;
                cout<<"\nCantidad:"; cin>>PRODUCTOS[i].cant;
                if (i==k-1) {
                    cout<<reset<<on_blue<<"\nHecho!";
                    system("pause");
                }
                else {
                    cout<<reset<<on_yellow<<"==================================="<<reset<<endl;
                }

            }

            break;
            case 2: // editar

            break;
            case 3: // eliminar

            break;
            case 4: // buscar por nombre

            break;
            case 5: // lista de productos


            break;
            case 6: // resumen inventario

            break;
            case 7: // filtrar por categoria o proveedor
            cout<<blue<<"Que categoria quiere ver? \n A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS "<<reset<<endl;
            cin>>cat;
            switch(cat) {
                case 'A': case 'a':
                    for(int i=0; i<catAa; i++) {
                        cout<<i+1<<") "<<catA[i]<<endl;
                    }
                    system("pause");
                break;
                case 'B': case 'b':
                    for(int i=0; i<catBb; i++) {
                        cout<<i+1<<") "<<catB[i]<<endl;
                    }
                    system("pause");
                break;
                case 'C': case 'c':
                    for(int i=0; i<catCc; i++) {
                        cout<<i+1<<") "<<catC[i]<<endl;
                    }
                    system("pause");
                break;
                case 'D': case 'd':
                    for(int i=0; i<catDd; i++) {
                        cout<<i+1<<") "<<catD[i]<<endl;
                    }
                    system("pause");
                break;
            } 

            break;
            case 8: // guardar productos

            break;
            default:
            cout<<on_red<<"Opcion no valida..."<<reset<<endl;
                system("pause");
                break;
        }
    }
    while (n!=9); //salir
    return 0;
}
