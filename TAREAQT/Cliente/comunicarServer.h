/**
  * @file comunicarServer.h
  * @date 3/2/2020
  * @author Carlos Adrian Araya Ramirez 2018319701
  * @title Socket de cliente
  * @brief Se manejan las funciones del cliente.
  */


#ifndef COMUNICARSERVER_H
#define COMUNICARSERVER_H

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

// Client side C/C++ program to demonstrate Socket programming

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "ManejoArchivos.h"

#define PORT 8081

int sock = 0, valread;
struct sockaddr_in serv_addr;
char *hello = "Hello from client";
char buffer[1024] = {0};
ManejoArchivos * b;

/**
 * @brief
 *
 */
void iniciarCliente();
/**
 * @brief Limpia el buffer que se utiliza para comunicarse con el servidor
 */
void limpiarBuffer(){

    for(int i = 0; i < 1024; i++){

        buffer[i] = NULL;

    }

}
/**
 * @brief Recibe un mensaje del servidor y lo almacena en el buffer
 */
void recibir(){

    valread = read( sock , buffer, 1024);
    printf("Recibido: %s\n",buffer );

}
/**
 * @brief Envia un string al servidor
 * @param string con mensaje a enviar
 */
void enviar(string msg){

    send(sock , msg.data() , msg.size() , 0 );
    printf("Enviado: %s\n",msg.c_str());

}
/**
 * @brief Actualiza el grafo del servidor
 * @return Devuelve el grafo en modo string
 */
string actualizarGrafo(){

    limpiarBuffer();

    iniciarCliente();
    enviar("1");
    recibir();
    string mensaje = b->abrirGrafoTXT("texto.txt");
    enviar(mensaje);
    recibir();
    close(sock);
    return buffer;

}
/**
 * @brief Pide al servidor el algoritmo dijkstra de un nodo en especifico pasado por parametro
 * @param string que contiene el numero del vertice que se quiere analizar la ruta mas corta
 * @return Devuelve la ruta mas corta del vertice pasado por parametro
 */
string obtenerDijkstra(string msg){

    limpiarBuffer();

    iniciarCliente();
    enviar("3"); //1
    recibir(); //2

    string mensaje = b->abrirGrafoTXT("texto.txt");
    enviar(mensaje);//3

    recibir(); //4

    enviar(msg); //5

    recibir();//6
    close(sock);
    return buffer;

}
/**
 * @brief Crea el socket del cliente
 */
void crearSocket(){

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

}
/**
 * @brief Define los atributos del socket
 */
void atributos(){

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

}
/**
 * @brief Convierte direcciones IPv4 y IPv6 de texto a forma binaria
 */
void hostName(){

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
    }

}
/**
 * @brief Se conecta con el servidor
 */
void conectar(){

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }

}
/**
 * @brief Inicia el socket del cliente
 */
void iniciarCliente()
{
    crearSocket();
    atributos();
    hostName();
    conectar();
}

#endif // COMUNICARSERVER_H
