#include "linked_list.h"
/**
 * @brief Constructor de la clase
 */
linked_list::linked_list()
{
    head = NULL;
    tail = NULL;
}
/**
 * @brief Agrega un nodo a la lista
 */
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
/**
 * @brief Devuelve la ultima posicion de la lista
 * @return Ultimo elemento de la lista
 */
node* linked_list:: gethead()
{
    return head;
}
/**
 * @brief Imprime la lista en consola
 */
void linked_list:: imprimir()
{
    node * tmp = head;

    while(tmp != NULL){

        cout << tmp->data->numero << endl;
        tmp = tmp->next;

    }
}
/**
 * @brief Devuelve el vertice con el nombre n
 * @param Nombre del vertice buscado
 * @return Vertice buscado
 */
Vertice * linked_list::getVertice(int n){

    node * tmp = head;

    while(tmp != NULL){

        if(tmp->data->numero == n){

            return tmp->data;

        }
        tmp = tmp->next;

    }

}
/**
 * @brief Devuelve el tamano de la lista
 * @return Tamano de la lista
 */
int linked_list::getSize(){

    node * tmp = head;
    int n = 0;

    while(tmp != NULL){

        n++;
        tmp = tmp->next;

    }

    return n;
}

