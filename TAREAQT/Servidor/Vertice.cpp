#include "Vertice.h"

/**
 * @brief Constructor de vertices
 *
 * @param Numero que tendra el vertice como nombre
 */
Vertice::Vertice(int n) {
    numero = n;
}
/**
 * @brief Devuelve un string con las aristas del vertice
 * @return String con aristas del vertice
 */
string Vertice::imprimirAristas(){

    string resultado = "";

    for(int i = 0; i < this->cantAristas; i++){
        resultado += to_string(aristas.at(i)) + " ";
    }
    return resultado;
}





