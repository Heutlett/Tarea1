/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linked_list.h
 * Author: heutlett
 *
 * Created on February 29, 2020, 10:52 PM
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
    linked_list();

    void add_node(int n);

    node* gethead();

    void imprimir();
    
    int getSize();
    


};


#endif /* LINKED_LIST_H */

