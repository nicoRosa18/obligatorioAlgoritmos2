#include <iostream>
#include "Graph.h"
#include "HeapVert.h"
using namespace std;


void dijkstra(Graph<int, int>* graph, Vertex* v) {
  unsigned int count = graph->getVerticesCount();
  Vertex** vertices = graph->getVertices();
  for (unsigned int i = 1; i <= count; i++) {
    vertices[i]->visited = false;
    vertices[i]->distance = 999;
    if (vertices[i]->vertex == v->vertex) {
      vertices[i]->distance = 0;
    }
  }

  for (unsigned int i = 1; i <= count; i++) {
    int position = -1;
    for (unsigned int k = 1; k <= count; k++) {
      if (!vertices[k]->visited && 
        (position == -1 || vertices[k]->distance < vertices[position]->distance)) {
        position = k;
      }
    }

    vertices[position]->visited = true;
    for (unsigned int k = 1; k <= count; k++) {
      if (!graph->hasEdge(vertices[position]->vertex, vertices[k]->vertex)) continue;
      if (vertices[k]->visited) continue;

      int weight = graph->getEdge(vertices[position]->vertex, vertices[k]->vertex);
      int newDistance = vertices[position]->distance + weight;
      if (newDistance < vertices[k]->distance) {
        vertices[k]->distance = newDistance;
        vertices[k]->path = vertices[position]->vertex;
      }
    }
  }

  for (unsigned int i = 1; i <= count; i++) {
    int dist= vertices[i]->distance;
    if(dist==0||dist==999){
      cout<<"-1"<<endl;
    }else{
      cout<<vertices[i]->distance<<endl;
    }  
  }
}

int main(){
    int cantVertices;
    int cantAristas;
    cin>>cantVertices;
        Graph<int, int>* grafo = new Graph<int, int>(cantVertices);
    int i=1;
    while (i<=cantVertices){
        grafo->addVertex(i);
        i++;
    }
    cin>>cantAristas;
    i=0;
    int de;
    int hacia;
    int costo;
    while(i<cantAristas){
        cin>>de;
        cin>>hacia;
        cin>>costo;
        grafo->addEdge(de,hacia,costo);
        i++;
    }
    
    Vertex** vertices =grafo->getVertices();
    int count =grafo->getVerticesCount();
    
    for(int i=1;i<=count;i++){
        Vertex* v= vertices[i];
        dijkstra(grafo,v);
    }
}