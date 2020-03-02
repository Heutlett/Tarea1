/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
//#include <stdio.h>
#include <sys/socket.h>
//#include <stdlib.h>
#include <netinet/in.h>
#include "Grafo.h"
#include <iostream>

using namespace std;

#define PORT 8081

int server_fd, new_socket, valread;
struct sockaddr_in address;
int opt = 1;
int addrlen = sizeof(address);
char buffer[1024] = {0};
char *hello = "Hello from server";

void crearSocket(){

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

}

void attachSocket(){

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

}

void attributes(){

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

}

void socketName(){

    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

}

void listen(){
    \
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

}

void accept(){

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

}

void recibir(){

    valread = read( new_socket , buffer, 1024);
    printf("Recibi: %s\n",buffer );

}

void enviar(string enviar){

    send(new_socket , enviar.data() , enviar.size() , 0 );
    printf("Mensaje enviado: %s\n",enviar.c_str());

}

int main(int argc, char const *argv[])
{

    crearSocket();
    attachSocket();
    attributes();
    socketName();
    listen();


    Grafo g;
    string buffer2;

    while(1){

        accept();

        if(!fork()){

            recibir();

            //Recibe el grafo en string y lo crea en memoria
            if(strcmp(buffer, "1") == 0){

                enviar("Recibido: 1, creando grafo");
                recibir();
                g.crearGrafoString(buffer);
                buffer2 = buffer;
                printf("EL GRAFO RESULTANTE ES\n\n\n");
                g.imprimirGrafo();
                enviar("listo");
                close(new_socket);
            }
            //Devuelve el grafo en modo matriz
            if(strcmp(buffer, "2") == 0){



            }
            //Devuelve el dijkstra
            if(strcmp(buffer, "3") == 0){ //1

                printf("el string guardado es %s", buffer2.c_str());

                g.crearGrafoString(buffer2);

                enviar("Recibido, generando dijkstra"); //2
                recibir(); //3

                int i = stoi(buffer);

                printf("el entero recibido es %i\n", i);

                g.imprimirGrafo();

                string enviar = g.dijkstra(i);

                cout << "el dijkstra es: "<< endl <<enviar << endl;

                enviar = "estoy mamando";

                //printf("el dijsktra es: %s", enviar);

                send(new_socket , enviar.data() , enviar.size() , 0 );//4
                printf("Dijkstra enviado\n");
                close(new_socket);
            }

        }

        close(new_socket);

    }




    /*
    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );

    g.crearGrafoString(buffer);

    printf("EL GRAFO RESULTANTE ES\n\n\n");
    g.imprimirGrafo();

    string enviar = g.dijkstra(3);

    send(new_socket , enviar.data() , enviar.size() , 0 );
    printf("Dijkstra enviado\n");
    return 0;
    */
}
