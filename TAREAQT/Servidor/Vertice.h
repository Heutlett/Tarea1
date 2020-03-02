/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Vertice.h
 * Author: heutlett
 *
 * Created on February 29, 2020, 10:04 PM
 */

#ifndef VERTICE_H
#define VERTICE_H

#include <vector>
#include <iostream>

using namespace std;

struct Vertice {

    public:

        Vertice(int);

        int numero;

        int cantAristas = 0;

        vector<int> aristas;

        void imprimirAristas();

    private:

};

#endif /* VERTICE_H */

