/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   linked_list.cpp
 * Author: heutlett
 * 
 * Created on February 29, 2020, 10:52 PM
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
    tmp->data = n;
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

node* linked_list::gethead()
{
    return head;
}



void linked_list::front(int n)
{
    node *tmp = new node;
    tmp -> data = n;
    tmp -> next = head;
    head = tmp;
}

void linked_list::after(node *a, int value)
{
    node* p = new node;
    p->data = value;
    p->next = a->next;
    a->next = p;
}