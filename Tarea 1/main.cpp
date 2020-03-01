/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Grafo.h"


int main(){
    Grafo  grafo;

    grafo.agregarVertice();
    grafo.agregarVertice();
    grafo.agregarVertice();
    grafo.agregarVertice();
    
    grafo.agregarArista(0,3,10);
    
    
    //grafo.vertices.imprimir();
    
    grafo.imprimirGrafo();
    
    
    
     /*
    linked_list a;
    a.add_node();
    a.add_node();
    a.add_node();
    a.add_node();
    a.add_node();
    a.imprimir();
    cout << endl<< a.getSize();
     */
     
    
    
    return 0;
     
    

   
    
    
    
    
}