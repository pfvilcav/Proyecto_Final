#include<iostream>
#include<cstdint> // para que termcolor.hpp funcione
#include<ctime> // fecha y hora
#include<iomanip> // para hacer cuadros ordenados
#include"termcolor.hpp" //color

using namespace std;
using namespace termcolor;

string fecha_hora() { //funcion string para hallar fecha y hora actual
    time_t t = time(nullptr);
    char buffer[30];
    strftime(buffer, sizeof(buffer), "%d/%m/%Y %H:%M:%S", localtime(&t));
    return buffer;
}

struct t_alimento{
    string tipo; //fecha de caducidad 
};

struct electronicos{
    string marca;
};

struct libros{
    string autor, genero;
};

struct info{
    string nomb, fecha;
    t_alimento alimento;
    libros libro;
    electronicos marcas;
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
    int n, catAa=0, catBb=0, catCc=0, catDd=0, total=0, indice=0;
    int A, B, C, D; //A: PAPELERIA // B: ELECTRONICOS // C:ALIMENTOS // D: LIBROS 
    string catA[50], catB[50], catC[50], catD[50]; // elementos en categorias
    do {
        n=menu();
        system("cls");
        switch (n) {
            case 1: //////agregar
                int k;
                char cat;
                cout<<green<<"*Cuantos tipos de productos quieres ingresar?"<<reset<<endl; cin>>k;
                cout<<endl<<on_yellow<<"Ingrese los productos:"<<reset<<endl;

                for (int i=0; i<k; i++) {
                    indice=total;
                    PRODUCTOS[indice].fecha=fecha_hora(); //halla la fecha y hora exacta
                    cout<<"\nCategoria: "<<red<<"Elija entre: A) PAPELERIA | B) ELECTRONICOS | C) ALIMENTOS | D) LIBROS"<<endl; cin>>cat;
                    cin.ignore();
                    switch(cat) { //categorias
                        case 'A': case 'a':
                            cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[indice].nomb);
                            catA[catAa]=PRODUCTOS[indice].nomb;
                            catAa++;
                            break;

                        case 'B': case 'b':
                            cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[indice].nomb);
                            cout<<green<<"\nMarca del producto: "; getline(cin,PRODUCTOS[indice].marcas.marca);
                            catB[catBb]=PRODUCTOS[indice].nomb;
                            catBb++;
                            break;

                        case 'C': case 'c':
                            cout<<green<<"Nombre del producto:"; getline(cin, PRODUCTOS[indice].nomb);
                            cout<<green<<"\nTipo de alimento: "; cin>>PRODUCTOS[indice].alimento.tipo;
                            catC[catCc]=PRODUCTOS[indice].nomb;
                            catCc++;
                            break;

                        case 'D': case 'd':
                            cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[indice].nomb);
                            cout<<green<<"\nAutor: "; getline(cin,PRODUCTOS[indice].libro.autor);
                            cout<<"\nGenero: "; cin>>PRODUCTOS[indice].libro.genero;
                            catD[catDd]=PRODUCTOS[indice].nomb;
                            catDd++;
                            break;
                    }
                    //cout<<green<<"Nombre del producto:"; getline(cin,PRODUCTOS[i].nomb); //nombre
                    cout<<green<<"\nPrecio:"; cin>>PRODUCTOS[indice].precio;
                    cout<<"\nCantidad:"; cin>>PRODUCTOS[indice].cant;
                    cout<<"\nFecha de ingreso: "<<PRODUCTOS[indice].fecha;
                    if (i==k-1) { //termina el case A en funcion de k=cantidad de productos, si no, lo resetea
                        cout<<reset<<on_blue<<"\nHecho!";
                        system("pause");
                    }
                    else {
                        cout<<reset<<on_yellow<<"\n==================================="<<reset<<endl;
                    }
                    total++;
                }
            break;
            case 2: {
                int op, nump, edit;
                string YN;
                if(total==0) {
                    cout<<on_red<<"No hay productos registrados."<<reset<<endl;
                    system("pause");
                    break;
                }
                cout<<left; //menu
                cout<<setw(5)<<"NUM"
                <<setw(25)<<"Nombre"
                <<setw(22)<<"Fecha"
                <<setw(10)<<"Precio"<<endl;
                cout<<string(70,'-')<<endl;
                for(int i=0; i<total; i++) { 
                    cout<<setw(5)<<i+1;
                    cout<<setw(25)<<PRODUCTOS[i].nomb;
                    cout<<setw(25)<<PRODUCTOS[i].fecha;
                    cout<<setw(10)<<PRODUCTOS[i].precio<<endl;
                }// ubica productos
                cout<<"Numero de productos a editar: "; cin>>op;
                for(int i=0; i<op;i++){ //cantidad de procutos para editar
                    cout<<"-----------------------------------"<<endl;
                    cout<<"\nNumero de producto: "; cin>>nump;
                    do{
                        cin.ignore();
                        cout<<"__________________________________________________________________________________________________________________________________________"<<endl;
                        cout<<"\nEditar: "<<red<<" 1) Nombre | 2) Precio | 3) Genero (libros) | 4) Autor (libros) | 5) Marca (electronicos) | 6) Tipo (alimentos) "<<endl; cin>>edit;
                        cin.ignore();
                        switch (edit){
                        case 1:
                            cout<<"Nuevo Nombre: "; getline(cin, PRODUCTOS[nump-1].nomb);
                            break;
                        case 2:
                            cout<<"\nNuevo Precio: "; cin>>PRODUCTOS[nump-1].precio;
                            break;
                        case 3:
                            cout<<"\nNuevo Genero: "; getline(cin,PRODUCTOS[nump-1].libro.genero);
                        case 4:
                            cout<<"\nNuevo Autor: "; getline(cin, PRODUCTOS[nump-1].libro.autor);
                            break;
                        case 5: 
                            cout<<"\nNueva Marca: "; getline(cin, PRODUCTOS[nump-1].marcas.marca);
                            break;
                        case 6:
                            cout<<"\nNuevo Tipo: "; getline(cin, PRODUCTOS[nump-1].alimento.tipo);
                            break;
                        default:
                            cout<<"Opcion no valida";
                            break;
                        }
                        cout<<"Desea editar algo mas?? (y para continuar n para detener)"; cin>>YN;
                    } while(YN=="y" || YN=="Y");
                }
                break;
            }
            case 3: // eliminar

                break;
            case 4: // buscar por nombre

                break;
            case 5: // lista de productos
                if(total==0) {
                    cout<<on_red<<"No hay productos registrados."<<reset<<endl;
                    system("pause");
                    break;
                }
                cout<<left; //menu
                cout<<setw(5)<<"NUM"
                <<setw(25)<<"Nombre"
                <<setw(22)<<"Fecha"
                <<setw(10)<<"Precio"<<endl;
                cout<<string(70,'-')<<endl;
                for(int i=0; i<total; i++) { // ubica productos
                    cout<<setw(5)<<i+1;
                    cout<<setw(25)<<PRODUCTOS[i].nomb;
                    cout<<setw(25)<<PRODUCTOS[i].fecha;
                    cout<<setw(10)<<PRODUCTOS[i].precio<<endl;
                }
                system("pause");
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
    } while (n!=8); //salir
    return 0;
}
