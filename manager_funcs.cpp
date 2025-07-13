//funcs :D
#include <iostream>
#include <fstream>

using namespace std;
void save(){
    fstream archivo("data.txt");
    archivo.close();
}
int load(){
    fstream archivo("data.txt");
    archivo.close();
}