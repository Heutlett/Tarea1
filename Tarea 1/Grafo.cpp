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


Grafo::Grafo() {
    
    
}

void Grafo::imprimirGrafo(){
    
    node * tmp = vertices.gethead();
    
    while(tmp != NULL){
        
        tmp->data->imprimirAristas();
        tmp = tmp->next;
        
    }
    
    
}

void Grafo::agregarVerticeSolo(){
    
    vertices.add_node();
}

void Grafo::agregarVertice(){
    
    vertices.add_node();
    
    for(int i = 0; i < vertices.getSize(); i++){
        
        while(vertices.getVertice(i)->cantAristas < vertices.getSize()){
            
            vertices.getVertice(i)->aristas.push_back(9999);
            vertices.getVertice(i)->cantAristas++;
            
        }
        
    }
}

void Grafo::agregarArista(int verticeIni, int verticeFin, int peso){
    
    Vertice * tmp = this->vertices.getVertice(verticeIni);
    
    tmp->aristas.at(verticeFin) = peso;
    
}

