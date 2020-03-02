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

void linked_list::add_node()
{
    node *tmp = new node;
    tmp->data = new Vertice(this->getSize());
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

Vertice * linked_list::getVertice(int n){

    node * tmp = head;

    while(tmp != NULL){

        if(tmp->data->numero == n){

            return tmp->data;

        }
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

