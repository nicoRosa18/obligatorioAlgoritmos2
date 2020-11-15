#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "HeapVert.h"
using namespace std;


template <class V, class W>
class Graph {
 
  public:
    Graph(int cantV) {
      listSize = cantV;
      vertices = 0;
      cont=1;
      adjacencyList = new Vertex*[listSize];
      vertOrd= new Vertex*[listSize];
      for (unsigned int i = 0; i < listSize; i++){
        adjacencyList[i] = NULL;
        vertOrd[i]=NULL;
      }
    }

    // PRE: vertex does not belong to graph
    void addVertex(V vertex) {
      Vertex* node = new Vertex;
      node->vertex = vertex;
      node->list = NULL;
      node->nivel=999;
      vertices++;
      adjacencyList[vertices] = node;
    }

    // PRE: edge between from and to does not exist in the graph
    //      from, to vertices belong to the graph
    void addEdge(V from, V to, V cost) {
      Vertex* node = adjacencyList[from];
      Vertex* nodoTo=adjacencyList[to];
      EdgeListNode* edgeNode = new EdgeListNode;
      edgeNode->toVertex = to;
      nodoTo->grado++;
      edgeNode->weight=cost;
      edgeNode->nextEdge = node->list;
      node->list = edgeNode;
    }

    unsigned int getVerticesCount() {
      return vertices;
    }

    Vertex** getVertices() {
      Vertex** verticesVec = new Vertex*[vertices+1];
      for (unsigned int i = 1; i <= vertices; i++)
        verticesVec[i] = adjacencyList[i];     
      return verticesVec;
    }

    HeapVertice* getVerticesAdyacentes(Vertex* v){
      int cantVertAdy=0;
      EdgeListNode* vertAd= v->list;
      while(vertAd){
        cantVertAdy++;
        vertAd=vertAd->nextEdge;
      }
      HeapVertice* verticesAdyacentes= new HeapVertice(cantVertAdy);
     // Vertex** verticesAdyacentes= new Vertex*[cantVertAdy];
      vertAd= v->list;
      while (vertAd)
      {     
        verticesAdyacentes->insert(adjacencyList[vertAd->toVertex]);
        vertAd=vertAd->nextEdge;
      }    
    return verticesAdyacentes;
    }


    bool hasEdge(V from, V to) {
      Vertex* node = adjacencyList[from];
      EdgeListNode *edgeNode = node->list;

      while (edgeNode != NULL) {
        if (edgeNode->toVertex == to)
          return true;
        edgeNode = edgeNode->nextEdge;
      }

      return false;
    }

    // PRE: edge between from and to exists in graph
    W getEdge(V from, V to) {
      Vertex* node =adjacencyList[from];
      EdgeListNode *edgeNode = node->list;

      while (edgeNode != NULL) {
        if (edgeNode->toVertex == to)
          return edgeNode->weight;
        edgeNode = edgeNode->nextEdge;
      }

      return 0;
    }

    int cont;
    Vertex** adjacencyList;
    Vertex** vertOrd;
    unsigned int listSize;
    unsigned int vertices;
};
#endif
