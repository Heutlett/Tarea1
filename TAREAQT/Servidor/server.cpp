#include <unistd.h>
#include <sys/socket.h>
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

/**
 * @brief Limpia el buffer utilizado para intercambiar mensajes
 */
void limpiarBuffer(){

    for(int i = 0; i < 1024; i++){

        buffer[i] = NULL;

    }

}
/**
 * @brief Crea el socket de servidor
 */
void crearSocket(){

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

}
/**
 * @brief Ata el servidor al puerto 8080
 */
void attachSocket(){

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt)))
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

}
/**
 * @brief Define los atributos del servidor
 */
void attributes(){

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );

}
/**
 * @brief Hace el bind del servidor
 */
void socketName(){

    if (bind(server_fd, (struct sockaddr *)&address,
                                 sizeof(address))<0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

}
/**
 * @brief Pone el servidor a la escucha
 */
void listen(){
    \
    if (listen(server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

}
/**
 * @brief Acepta un cliente
 */
void accept(){

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                       (socklen_t*)&addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }

}
/**
 * @brief Recibe mensajes del cliente
 */
void recibir(){

    valread = read( new_socket , buffer, 1024);
    printf("Recibi: %s\n",buffer );

}
/**
 * @brief Envia un mensaje al cliente
 * @param Mensaje a enviar al cliente
 */
void enviar(string e){

    send(new_socket , e.data() , e.size() , 0 );
    printf("Mensaje enviado: %s\n",e.c_str());

}

int main(int argc, char const *argv[])
{

    crearSocket();
    attachSocket();
    attributes();
    socketName();
    listen();

    Grafo g;

    while(1){

        close(new_socket);

        accept();

        if(!fork()){

            recibir();

            //Recibe el grafo en string y lo crea en memoria
            if(strcmp(buffer, "1") == 0){

                enviar("Recibido: 1, creando grafo");
                recibir();
                Grafo g;

                g.crearGrafoString(buffer);
                printf("EL GRAFO RESULTANTE ES\n\n\n");
                enviar(g.imprimirGrafo());
                close(new_socket);
                limpiarBuffer();
            }

            //Devuelve el dijkstra
            if(strcmp(buffer, "3") == 0){ //1

                limpiarBuffer();

                enviar("Generando dijkstra\n"); //2

                recibir(); //3

                Grafo g;

                printf("intentando imprimir grafo vacio = %s", g.imprimirGrafo().c_str());

                g.crearGrafoString(buffer);

                enviar("Grafo regenerado\n"); //4

                limpiarBuffer();

                recibir(); //5

                int i = stoi(buffer);

                printf("numero recibido %i\n",i);

                string e = g.dijkstra(i);

                printf("dijsktra resultante %s\n",e.c_str());

                enviar(e); //6

                close(new_socket);
                limpiarBuffer();
            }

        }

        close(new_socket);
        limpiarBuffer();

    }
}
