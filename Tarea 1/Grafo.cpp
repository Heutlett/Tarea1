/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Grafo.cpp
 * Author: heutlett
 * 
 * Created on February 29, 2020, 10:04 PM
 */

#include "Grafo.h"
#include "Vertice.h"

Grafo::Grafo() {
    
    //cantVertices = 0;
}

void Grafo::agregarVertice(){
    
    Vertice v(1);
    
    vertices.push_back(v);
    
}

void Grafo::imprimirVertices(){
    
    //for(int i = 0; i < cantVertices; i++){
        
        //cout << vertices.at(i).getNumero();
        
    //}
    
}
