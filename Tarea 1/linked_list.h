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
    linked_list()
    {
        head = NULL;
        tail = NULL;
    }

    void add_node(int n)
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

    node* gethead()
    {
        return head;
    }

    static void display(node *head)
    {
        if(head == NULL)
        {
            cout << "NULL" << endl;
        }
        else
        {
            cout << head->data->numero << endl;
            display(head->next);
        }
    }


};


#endif /* LINKED_LIST_H */

