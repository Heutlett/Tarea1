/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Grafo.h"
#include "linked_list.h"


int main(){
    Grafo * grafo;
    
    linked_list a;
    a.add_node(1);
    a.add_node(2);
    a.front(3);
    linked_list::display(a.gethead());
    return 0;
    
    return 0;
    
    
}