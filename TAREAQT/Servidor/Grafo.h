/**
  * @file Grafo.h
  * @date 3/2/2020
  * @author Carlos Adrian Araya Ramirez 2018319701
  * @title Clase vertice
  * @brief Estructura necesaria para la funcionalidad del grafo
  */

#ifndef GRAFO_H
#define GRAFO_H

#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

using namespace std;

class Grafo {

public:
    /**
     * @brief Constructor del grafo
     */
    Grafo();

    linked_list vertices;
    /**
     * @brief Agrega un vertice al grafo
     */
    void agregarVertice();
    /**
     * @brief Agrega una arista al grafo
     * @param Numero del vertice inicial
     * @param Numero del vertice final
     * @param Peso de la arista
     */
    void agregarArista(int, int, int);
    /**
     * @brief Devuelve un string con los datos del grafo
     * @return String con datos de grafo
     */
    string imprimirGrafo();
    /**
     * @brief Calcula la ruta mas corta del vertice pasado por parametro y lo devuelve en un string
     * @param Numero del vertice de inicio
     * @return String con la ruta mas corta
     */
    string dijkstra(int);
    /**
     * @brief Importa un grafo a partir de un string
     * @param String que contiene el grafo en modo texto
     */
    void crearGrafoString(string);



private:

};

#endif /* GRAFO_H */

