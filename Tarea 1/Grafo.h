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

#include <vector>
#include <iostream>
#include "Vertice.h"

using namespace std;

class Grafo {
    
    static int cantVertices;
    
public:
    
    Grafo();
    
    vector<Vertice> vertices;
    
    void agregarVertice();
    void imprimirVertices();
    

private:

};

#endif /* GRAFO_H */

