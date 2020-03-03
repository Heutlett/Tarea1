#include "Vertice.h"


Vertice::Vertice(int n) {
    numero = n;
}

string Vertice::imprimirAristas(){

    string resultado = "";

    for(int i = 0; i < this->cantAristas; i++){
        resultado += to_string(aristas.at(i)) + " ";
    }
    return resultado;
}





