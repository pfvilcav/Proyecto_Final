#include<iostream>
#include<cstdint> // para que termcolor.hpp funcione
#include<ctime>
#include<fstream>
#include"termcolor.hpp"

using namespace std;
using namespace termcolor;

string fecha_hora() { //funcion string para hallar fecha y hora actual
    time_t t = time(nullptr);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return buffer;
}

struct info{
    string nomb, fecha, t_alimento, marca, autor, genero;
    double precio;
    int cant;
} PRODUCTOS[250];

int menu() { //menu (modularizar)
    int opcion;
    system("cls");
    cout<<on_green<<"//////////////////////////////////////////////////////////"<<endl;
    cout<<"/              GESTOR DE PRODUCTOS Y ALMACEN             /"<<reset<<endl;
    cout<<on_green<<"//////////////////////////////////////////////////////////"<<reset<<endl;
    cout<<on_blue<<"1) Agregar producto."<<endl<<"2) Editar producto."<<endl<<"3) Eliminar producto."<<endl;
    cout<<"4) Buscar producto por nombre."<<endl<<"5) Ver lista de productos."<<endl<<"6) Ver resumen del inventario"<<endl;
    cout<<"7) Filtrar productos por categoria o proveedor."<<endl<<"8) Salir."<<reset<<endl;
    cout<<on_yellow<<"Ingrese la opcion que usted desee realizar:"<<reset<<endl;
    cin>>opcion;
    return opcion;
}

int main() {
    char rpta;
    int n, catAa=0, catBb=0, catCc=0, catDd=0;
    int A, B, C, D; //A: PAPELERIA // B: ELECTRONICOS // C:ALIMENTOS // D: LIBROS 
    string catA[50], catB[50], catC[50], catD[50]; // categorias
    do {
        n=menu();
        system("cls");
        switch (n) {
            case 1: //////agregar
            int k;
            char cat;
            cout<<green<<"*Cuantos tipos de productos quieres ingresar?"<<reset<<endl; cin>>k;
            cout<<endl<<on_yellow<<"Ingrese los productos:"<<reset<<endl;
            for (int i=0; i<k; i++) { // luego para almacenar en .txt se debe crear variable que almacene el total.
                PRODUCTOS[i].fecha=fecha_hora(); //halla la fecha y hora exacta
                cout<<"\nCategoria: "<<red<<"Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS"<<endl; cin>>cat;
                cin.ignore();
                switch(cat) { //categorias
                    case 'A': case 'a':
                        cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb);
                        catA[i]=PRODUCTOS[i].nomb;
                        catAa++;
                    break;

                    case 'B': case 'b':
                        cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb);
                        cout<<green<<"\nMarca del producto: "; cin>>PRODUCTOS[i].marca;
                        catB[i]=PRODUCTOS[i].nomb;
                        catBb++;
                    break;

                    case 'C': case 'c':
                        cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb);
                        cout<<green<<"\nTipo de alimento: "; cin>>PRODUCTOS[i].t_alimento;
                        catC[i]=PRODUCTOS[i].nomb;
                        catCc++;
                    break;

                    case 'D': case 'd':
                        cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb);
                        cout<<green<<"\nAutor: "; getline(cin,PRODUCTOS[i].autor);
                        cout<<"\nGenero: "; cin>>PRODUCTOS[i].genero;
                        catD[i]=PRODUCTOS[i].nomb;
                        catDd++;
                    break;
                }
                //cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb); //nombre
                cout<<green<<"\nPrecio:"; cin>>PRODUCTOS[i].precio;
                cout<<"\nCantidad:"; cin>>PRODUCTOS[i].cant;
                cout<<"\nFecha de ingreso: "<<PRODUCTOS[i].fecha;
                if (i==k-1) { //termina el case A en funcion de k=cantidad de productos, si no, lo resetea
                    cout<<reset<<on_blue<<"\nHecho!";
                    system("pause");
                    cout<<on_green<<"Desea guardar los productos que acaba de ingresar? (S/N): "; cin>>rpta;
                    if (rpta=='S' || rpta=='s') {
                        // falta
                    }
                    else {
                        // falta
                    }
                }
                else {
                    cout<<reset<<on_yellow<<"\n==================================="<<reset<<endl;
                }

            }
            break;

            case 2: // editar
                int op;
                cout<<"\nCategoria: "<<red<<"Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS"<<endl; cin>>cat;
                cin.ignore();
                switch(cat) { //categorias
                    case 'A': case 'a':
                        for(int i=0;i<k;i++){
                            cout<<green<<"Nombre del producto "<<i+1<<": "<<PRODUCTOS[i].nomb;
                            cout<<"--------------------------------------------------------------------"<<endl;
                        }
                        cout<<"Elija el numero del producto: "; cin>>op;
                        cout<<"Nuevo nombre: "; getline(cin, PRODUCTOS[op].nomb);
                    break;

                    case 'B': case 'b':
                        for(int i=0;i<k;i++){
                            cout<<green<<"Nombre del producto "<<i+1<<": "<<PRODUCTOS[i].nomb;
                            cout<<green<<"Marca del producto "<<i+1<<" : "<<PRODUCTOS[i].marca;
                            cout<<"--------------------------------------------------------------------"<<endl;
                        }
                        cout<<"Elija el numero del producto: "; cin>>op;
                        cout<<green<<"Nuevo nombre: "; getline(cin,PRODUCTOS[op].nomb);
                        cout<<green<<"\nNueva marca: "; getline(cin, PRODUCTOS[op].marca);
                    break;

                    case 'C': case 'c':
                        for(int i=0;i<k;i++){
                            cout<<green<<"Nombre del producto "<<i+1<<": "<<PRODUCTOS[i].nomb;
                            cout<<green<<"Tipo de alimento "<<i+1<<" : "<<PRODUCTOS[i].t_alimento;
                            cout<<"--------------------------------------------------------------------"<<endl;
                        }
                        cout<<"Elija el numero del producto: "; cin>>op;
                        cout<<green<<"Nuevo nombre: "; getline(cin,PRODUCTOS[op].nomb);
                        cout<<green<<"\nTipo de alimento: "; cin>>PRODUCTOS[op].t_alimento;
                    break;

                    case 'D': case 'd':
                        for(int i=0;i<k;i++){
                            cout<<green<<"Nombre del producto "<<i+1<<": "<<PRODUCTOS[i].nomb;
                            cout<<green<<"Autor: "<<PRODUCTOS[i].autor;
                            cout<<green<<"Genero: "<<PRODUCTOS[i].genero;
                            cout<<"--------------------------------------------------------------------"<<endl;
                        }
                        cout<<"Elija el numero del producto: "; cin>>op;
                        cout<<green<<"Nuevo nombre: "; getline(cin,PRODUCTOS[op].nomb);
                        cout<<green<<"\nNuevo autor: "; getline(cin,PRODUCTOS[op].autor);
                        cout<<"\nNuevo genero: "; cin>>PRODUCTOS[op].genero;
                    break;
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
            case 8: // cerrar
                return 0;
            break;

            default:
            cout<<on_red<<"Opcion no valida..."<<reset<<endl;
                system("pause");
                break;
        }
    }
    while (n!=8); //salir
    return 0;
}
