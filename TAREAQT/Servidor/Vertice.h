/**
  * @file Vertice.h
  * @date 3/2/2020
  * @author Carlos Adrian Araya Ramirez 2018319701
  * @title Clase vertice
  * @brief Estructura necesaria para la funcionalidad del grafo
  */

#ifndef VERTICE_H
#define VERTICE_H

#include <vector>
#include <iostream>

using namespace std;

struct Vertice {

    public:
    /**
    * @brief Constructor de vertices
    *
    * @param Numero que tendra el vertice como nombre
    */
    Vertice(int);

    int numero;
    int cantAristas = 0;
    vector<int> aristas;

    /**
     * @brief Devuelve un string con las aristas del vertice
     * @return String con aristas del vertice
     */
    string imprimirAristas();

    private:

};

#endif /* VERTICE_H */

