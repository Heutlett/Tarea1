/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.h
 * Author: heutlett
 *
 * Created on February 29, 2020, 10:04 PM
 */

#ifndef GRAFO_H
#define GRAFO_H

#include <iostream>
#include "linked_list.h"

using namespace std;

class Grafo {
    
public:
    
    Grafo();
    
    linked_list vertices;
    
    void agregarVertice();
    
    void agregarVerticeSolo();
    
    void agregarArista(int, int, int);
    
    void imprimirGrafo();
    
    

private:

};

#endif /* GRAFO_H */

