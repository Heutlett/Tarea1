/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "Grafo.h"
#include<stdio.h>


int main(){
    
    
    Grafo  grafo;

    grafo.agregarVertice();
    grafo.agregarVertice();
    grafo.agregarVertice();
    grafo.agregarVertice();
    grafo.agregarVertice();
    
    grafo.agregarArista(0,0,0);
    grafo.agregarArista(0,1,1);
    grafo.agregarArista(0,2,0);
    grafo.agregarArista(0,3,3);
    grafo.agregarArista(0,4,7);
    
    grafo.agregarArista(1,0,1);
    grafo.agregarArista(1,1,0);
    grafo.agregarArista(1,2,5);
    grafo.agregarArista(1,3,0);
    grafo.agregarArista(1,4,0);
    
    grafo.agregarArista(2,0,0);
    grafo.agregarArista(2,1,5);
    grafo.agregarArista(2,2,0);
    grafo.agregarArista(2,3,2);
    grafo.agregarArista(2,4,1);
    
    grafo.agregarArista(3,0,3);
    grafo.agregarArista(3,1,0);
    grafo.agregarArista(3,2,2);
    grafo.agregarArista(3,3,0);
    grafo.agregarArista(3,4,6);
    
    grafo.agregarArista(4,0,7);
    grafo.agregarArista(4,1,0);
    grafo.agregarArista(4,2,1);
    grafo.agregarArista(4,3,6);
    grafo.agregarArista(4,4,0);
    

    grafo.imprimirGrafo();
    
    cout << endl << endl;
    
    grafo.dijkstra(2);
    
 }

 