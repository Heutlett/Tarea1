/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Grafo.cpp
 * Author: heutlett
 *
 * Created on February 29, 2020, 10:04 PM
 */

#include "Grafo.h"

#define INFINITY 9999
#define max 5

Grafo::Grafo() {


}

string Grafo::imprimirGrafo(){

    node * tmp = vertices.gethead();
    string resultado = "";

    while(tmp != NULL){

        resultado += tmp->data->imprimirAristas() + "\n";
        //tmp->data->imprimirAristas();
        tmp = tmp->next;

    }

    return resultado;

}

void Grafo::agregarVerticeSolo(){

    vertices.add_node();
}

void Grafo::agregarVertice(){

    vertices.add_node();

    for(int i = 0; i < vertices.getSize(); i++){

        while(vertices.getVertice(i)->cantAristas < vertices.getSize()){

            vertices.getVertice(i)->aristas.push_back(0);
            vertices.getVertice(i)->cantAristas++;

        }

    }
}

void Grafo::agregarArista(int verticeIni, int verticeFin, int peso){

    Vertice * tmp = this->vertices.getVertice(verticeIni);

    tmp->aristas.at(verticeFin) = peso;

}

string Grafo::dijkstra(int inicio){

   int cost[max][max],distance[max],pred[max];
   int visited[max],count,mindistance,nextnode,i,j;
   for(i=0;i<vertices.getSize();i++)
      for(j=0;j<vertices.getVertice(i)->cantAristas;j++)
   if(vertices.getVertice(i)->aristas.at(j)==0)
      cost[i][j]=INFINITY;
   else
      cost[i][j]=vertices.getVertice(i)->aristas.at(j);
   for(i=0;i<vertices.getSize();i++) {
      distance[i]=cost[inicio][i];
      pred[i]=inicio;
      visited[i]=0;
   }
   distance[inicio]=0;
   visited[inicio]=1;
   count=1;
   while(count<vertices.getSize()-1) {
      mindistance=INFINITY;
      for(i=0;i<vertices.getSize();i++)
         if(distance[i]<mindistance&&!visited[i]) {
         mindistance=distance[i];
         nextnode=i;
      }
      visited[nextnode]=1;
      for(i=0;i<vertices.getSize();i++)
         if(!visited[i])
      if(mindistance+cost[nextnode][i]<distance[i]) {
         distance[i]=mindistance+cost[nextnode][i];
         pred[i]=nextnode;
      }
      count++;
   }

   string resultado = "Dijkstra from v" + to_string(inicio) + " to all nodes:\n";

   for(i=0;i<vertices.getSize();i++)
   if(i!=inicio) {
       int dist = distance[i];
       resultado += "\nDistance of node" + to_string(i) + "=" + to_string(dist);
       resultado += "\nPath=" + to_string(i);
      printf("\n\nDistance of node%i=%dist");
      printf("\nPath=%i",i);
      j=i;
      do {
         j=pred[j];
         printf("<-%j");
         resultado += "<-" + to_string(j);
      }while(j!=inicio);
   }

   return resultado;

}

void Grafo::crearGrafoString(string texto2){


    //Agregando vertices

    int mayor = 0;

    for(int i = 0; i < texto2.length()-1; i++){

        if(texto2.at(i) == 'v'){

            if(texto2.at(i+1)-'0' > mayor){
                mayor  = texto2.at(i+1)-'0';
            }

        }

    }

    for(int i = 0; i <= mayor; i++){

        agregarVertice();

    }

    //Agregando aristas

    int vini = -1, vfin = -1, peso;
    string texto3 = "";


    for(int i = 0; i < texto2.length()-1; i++){

        if(texto2.at(i) != '\n'){

            texto3 += texto2.at(i);

        }else{

            if(texto3.length() > 5){

                vini = texto3.at(1)-'0';
                vfin = texto3.at(5)-'0';
                peso = texto3.at(9)-'0';

                agregarArista(vini,vfin,peso);

                texto3 = "";

            }
        }
    }


    cout << endl;

    imprimirGrafo();



}
