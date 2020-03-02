/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: heutlett
 *
 * Created on March 1, 2020, 12:51 PM
 */

#ifndef CLIENTE_H
#define CLIENTE_H


#include "Grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>

void cargarGrafoTXT(string texto2){
    

    
    //Agregando vertices
    
    int mayor = 0;
    
    for(int i = 0; i < texto2.length()-1; i++){
        
        if(texto2.at(i) == 'v'){
            
            if(texto2.at(i+1)-'0' > mayor){
                mayor  = texto2.at(i+1)-'0';
            }
            
        }
        
    }
    
    for(int i = 0; i <= mayor; i++){
        
        grafo.agregarVertice();
        
    }
    
    //Agregando aristas
    
    int vini = -1, vfin = -1, peso;
    string texto3 = "";

    
    for(int i = 0; i < texto2.length()-1; i++){
        
        if(texto2.at(i) != '\n'){
            
            texto3 += texto2.at(i);
            
        }else{
            
            if(texto3.length() > 5){
                
                vini = texto3.at(1)-'0';
                vfin = texto3.at(5)-'0';
                peso = texto3.at(9)-'0';

                grafo.agregarArista(vini,vfin,peso);

                texto3 = "";
                
            }
        }
    }
    
    archivo.close();
    
    cout << endl;
    
    grafo.imprimirGrafo();
    
    
    
}



#endif /* CLIENTE_H */