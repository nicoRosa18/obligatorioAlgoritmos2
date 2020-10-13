#ifndef GRAPH_H
#define GRAPH_H
#include "HeapVert.h"
#include <iostream>
using namespace std;




template <class V, class W>
class Graph {
  public:
    Graph(int cantV) {
      listSize = cantV;
      vertices = 0;
      adjacencyList = new Node*[listSize];
      verticeOrdenadoxEnt= new Node*[listSize];
      nivel0= new HeapVertice();    
      for (unsigned int i = 0; i < listSize; i++){
        adjacencyList[i] = NULL;
        verticeOrdenadoxEnt[i]=NULL;
      }
    }

    // PRE: vertex does not belong to graph
    void addVertex(V vertex) {
      Node* node = new Node;
      node->vertex = vertex;
      node->list = NULL;
      vertices++;
      node->pos=vertices;
      adjacencyList[vertices] = node;
      verticeOrdenadoxEnt[vertices]=node;
    }

    // PRE: edge between from and to does not exist in the graph
    //      from, to vertices belong to the graph
    void addEdge(V from, V to, W weight) {
      Node* node = adjacencyList[from];
      Node* nodoTo=adjacencyList[to];
      EdgeListNode* edgeNode = new EdgeListNode;
      edgeNode->toVertex = to;
      nodoTo->gradoEntrada++;
      percolateDown(nodoTo->pos);
      edgeNode->weight = weight;
      edgeNode->nextEdge = node->list;
      node->list = edgeNode;
    }

    unsigned int getVerticesCount() {
      return vertices;
    }

    V* getVertices() {
      V* verticesVec = new V[vertices];
      for (unsigned int i = 1; i < vertices; i++)
        verticesVec[i] = adjacencyList[i]->vertex;     
      return verticesVec;
    }

    bool hasEdge(V from, V to) {
      Node* node = getVertexNode(from);
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
      Node* node = getVertexNode(from);
      EdgeListNode *edgeNode = node->list;

      while (edgeNode != NULL) {
        if (edgeNode->toVertex == to)
          return edgeNode->weight;
        edgeNode = edgeNode->nextEdge;
      }

      return 0;
    }

   int eliminarMinVertice(){
     if(nivel0->isEmpty()){
       int mmin=nivel0->min();
       Node* aEliminar=adjacencyList[mmin];
     }else{
      Node* aEliminar= verticeOrdenadoxEnt[1];
     }
      int vert=aEliminar->vertex;
      EdgeListNode* listaE= aEliminar->list;
      bool nivelVacio=nivel0->isEmpty();
      while(listaE){
        Node* aVertice= adjacencyList[listaE->toVertex];
        aVertice->gradoEntrada--;
        if(nivelVacio){
          nivel0->insert(aVertice);
        }
        percolateUp(aVertice->pos);
        listaE=listaE->nextEdge;
     }
     verticeOrdenadoxEnt[1]=verticeOrdenadoxEnt[vertices];
     vertices--;
     return vert; 
    }

  private:
    struct EdgeListNode {
      V toVertex;
      W weight;
      EdgeListNode* nextEdge;
    };
  
    struct Node {
      V vertex;
      int pos;
      int gradoEntrada;
      EdgeListNode* list;
    };
    HeapVertice* nivel0;
    Node** adjacencyList;
    Node** verticeOrdenadoxEnt;
    unsigned int listSize;
    unsigned int vertices;


    void percolateUp(unsigned int hole) {
      while (hole > 1 && verticeOrdenadoxEnt[hole]->gradoEntrada < verticeOrdenadoxEnt[hole / 2]->gradoEntrada) {
        swap(verticeOrdenadoxEnt[hole], verticeOrdenadoxEnt[hole / 2]);
        hole /= 2;
      }
    } 

  void percolateDown(unsigned int hole) {
      while (hole * 2 <= vertices) {
        unsigned int child = hole * 2;
        if (child + 1 <= vertices && verticeOrdenadoxEnt[child + 1]->gradoEntrada < verticeOrdenadoxEnt[child]->gradoEntrada)
          child++;

        if (verticeOrdenadoxEnt[child]->gradoEntrada < verticeOrdenadoxEnt[hole]->gradoEntrada||((verticeOrdenadoxEnt[child]->gradoEntrada == verticeOrdenadoxEnt[hole]->gradoEntrada)&&(verticeOrdenadoxEnt[child]->vertex < verticeOrdenadoxEnt[hole]->vertex))) {
          swap(verticeOrdenadoxEnt[child], verticeOrdenadoxEnt[hole]);
          int aux=verticeOrdenadoxEnt[child]->pos;
          verticeOrdenadoxEnt[child]->pos=verticeOrdenadoxEnt[hole]->pos;
          verticeOrdenadoxEnt[hole]->pos=aux;
          hole = child;
        } else break;
      }
    }
};

#endif
