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

void Grafo::imprimirGrafo(){
    
    node * tmp = vertices.gethead();
    
    while(tmp != NULL){
        
        tmp->data->imprimirAristas();
        tmp = tmp->next;
        
    }
    
    
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

void Grafo::dijkstra(int inicio){
    
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
   for(i=0;i<vertices.getSize();i++)
   if(i!=inicio) {
      cout<<"\nDistance of node"<<i<<"="<<distance[i];
      cout<<"\nPath="<<i;
      j=i;
      do {
         j=pred[j];
         cout<<"<-"<<j;
      }while(j!=inicio);
   }
    
    
}

