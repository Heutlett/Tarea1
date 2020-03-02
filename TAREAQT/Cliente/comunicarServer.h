
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

string comuServer()
{

    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};


    ManejoArchivos * b;

    string mensaje = b->abrirGrafoTXT("texto.txt");


    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return "fail";
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0)
    {
        printf("\nInvalid address/ Address not supported \n");
        return "fail";
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        return "fail";
    }

    send(sock , mensaje.data() , mensaje.size() , 0 );
    printf("Hello message sent\n");
    valread = read( sock , buffer, 1024);
    printf("%s\n",buffer );
    return buffer;
}




#endif // COMUNICARSERVER_H
