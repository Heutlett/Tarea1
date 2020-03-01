/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "linked_list.h"

linked_list::linked_list()
    {
        head = NULL;
        tail = NULL;
    }

void linked_list::add_node(int n)
{
    node *tmp = new node;
    tmp->data = new Vertice(n);
    tmp->next = NULL;

    if(head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

node* linked_list:: gethead()
{
    return head;
}

void linked_list:: imprimir()
{
    node * tmp = head;
    
    while(tmp != NULL){
        
        cout << tmp->data->numero << endl;
        tmp = tmp->next;
        
    }
    
}


int linked_list::getSize(){
    
    node * tmp = head;
    int n = 0;
    
    while(tmp != NULL){
        
        n++;
        tmp = tmp->next;
        
    }
    
    return n;
    
}