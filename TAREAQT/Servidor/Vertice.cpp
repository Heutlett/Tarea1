/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Vertice.cpp
 * Author: heutlett
 *
 * Created on February 29, 2020, 10:04 PM
 */

#include "Vertice.h"

Vertice::Vertice(int n) {

    numero = n;


}

string Vertice::imprimirAristas(){

    string resultado = "";

    for(int i = 0; i < this->cantAristas; i++){

        //cout << aristas.at(i) << " ";
        resultado += to_string(aristas.at(i)) + " ";

    }
    //cout << endl;

    return resultado;
}





