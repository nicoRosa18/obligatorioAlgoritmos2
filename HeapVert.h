#ifndef HEAP_VERTICE_H
#define HEAP_VERTICE_H

#include <iostream>
//#include "Graph.h"
using namespace std;


struct EdgeListNode {
      int toVertex;
      int weight;
      EdgeListNode* nextEdge;
      EdgeListNode(){}
    };

struct Vertex {
  int vertex;
  int grado;
  int nivel;
  bool visited;
  int distance;
  int path;
  EdgeListNode* list;

  Vertex() {}
  Vertex(int v): vertex(v) {}

  bool operator== (Vertex v) {
    return vertex == v.vertex;
  }
};

class HeapVertice {
  public:
    HeapVertice(int cantV) {
      size = cantV;
      array = new Vertex*[size];
      items = 0;
    }

    void insert(Vertex* v) {
      items++;
      unsigned int hole = items;
      array[hole] = v;
      percolateUp(hole);
    }

    bool isEmpty() {
      return items==0;
    }

    // PRE: heap is not empty
    void deleteMin() {
      unsigned int hole = 1;
      array[hole] = array[items];
      items--;
       cont++;
      percolateDown(hole);
    }

    // PRE: heap is not empty
    Vertex* min() {
      return array[1];
    }


  private:
    Vertex** array;
      int cont;
    unsigned int size;
    unsigned int items;

 void percolateUp(unsigned int hole)
    {
      while(hole>1 && (array[hole]->nivel<array[hole/2]->nivel||(array[hole]->nivel==array[hole/2]->nivel&&array[hole]->vertex<array[hole/2]->vertex))){
          swap(array[hole], array[hole / 2]);
          hole /= 2;
        }
      }

  void percolateDown(unsigned int hole) {
      while (hole * 2 <= items) {
        unsigned int child = hole * 2;
        if(child + 1 <=items&& (array[child+1]->nivel <array[child]->nivel||((array[child+1]->nivel ==array[child]->nivel)&&(array[child+1]->vertex < array[child]->vertex))))
        child++;
        int nivelchild=array[child]->nivel;
        int nivelhole=array[hole]->nivel;
        int chi=array[child]->vertex;
        int hol=array[hole]->vertex;
        if(array[child]->nivel<array[hole]->nivel||(array[hole]->nivel==array[child]->nivel&&array[child]->vertex<array[hole]->vertex)){
        swap(array[child], array[hole]);
        hole = child;
        } else break;
      }

    }
};

#endif
