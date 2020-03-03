/**
  * @file linked_list.h
  * @date 3/2/2020
  * @author Carlos Adrian Araya Ramirez 2018319701
  * @title Encabezado de la estructura de lista enlazada
  * @brief Estructura de lista enlazada simple
  */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include "Vertice.h"

using namespace std;

struct node
{
    Vertice * data;
    node *next;
};

class linked_list
{
private:
    node *head,*tail;
public:
    /**
     * @brief Constructor de la clase
     */
    linked_list();
    /**
     * @brief Agrega un nodo a la lista
     */
    void add_node();
    /**
     * @brief Devuelve la ultima posicion de la lista
     * @return Ultimo elemento de la lista
     */
    node* gethead();
    /**
     * @brief Imprime la lista en consola
     */
    void imprimir();
    /**
     * @brief Devuelve el tamano de la lista
     * @return Tamano de la lista
     */
    int getSize();
    /**
     * @brief Devuelve el vertice con el nombre n
     * @param Nombre del vertice buscado
     * @return Vertice buscado
     */
    Vertice * getVertice(int);

};


#endif /* LINKED_LIST_H */

