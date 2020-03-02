
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

void iniciarCliente();

void recibir(){

    valread = read( sock , buffer, 1024);
    printf("Recibido: %s\n",buffer );

}

void enviar(string msg){

    send(sock , msg.data() , msg.size() , 0 );
    printf("Enviado: %s\n",msg.c_str());

}

void actualizarGrafo(){

    iniciarCliente();
    enviar("1");
    recibir();
    string mensaje = b->abrirGrafoTXT("texto.txt");
    enviar(mensaje);
    //send(sock , mensaje.data() , mensaje.size() , 0 );
    recibir();
    close(sock);

}

void obtenerDijkstra(string msg){


    //
    //actualizarGrafo();
    iniciarCliente();
    enviar("3"); //1
    recibir(); //2
    enviar(msg); //3
    recibir();//4
    printf("%s\n",buffer );
    close(sock);
    //return buffer;

}



void crearSocket(){

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
    }

}

void atributos(){

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

}

void hostName(){

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
    }

}

void conectar(){

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
    }

}

void iniciarCliente()
{

    //actualizarGrafo();

    crearSocket();
    atributos();
    hostName();
    conectar();

    //actualizarGrafo();

    /*
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return buffer;
    */
}




#endif // COMUNICARSERVER_H
