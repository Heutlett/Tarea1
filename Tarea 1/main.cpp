/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "linked_list.h"


int main(){
    //Grafo * grafo;
    
    //Vertice * v = new Vertice(1);
    //cout << v->numero;
    
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.add_node(3);
    a.add_node(4);
    a.add_node(5);
    a.imprimir();
    cout << endl<< a.getSize();
    return 0;
   
    
    
}