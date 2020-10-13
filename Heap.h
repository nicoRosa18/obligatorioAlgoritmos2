#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include "Node.h"
using namespace std;

#define INITIAL_SIZE 10

class Heap {
  public:
  
    Heap(int cantElements) {
      array = new Node*[cantElements];
      items = 0;
    }

    void insert(Node* data) {
      items++;
      unsigned int hole = items;
      array[hole] = data;

      percolateUp(hole);
    }

    // PRE: heap is not empty
    void deleteMin() {
      unsigned int hole = 1;
      array[hole]=array[hole]->sig;
      if(!array[hole]){
      array[hole] = array[items];
      items--;
      }

      percolateDown(hole);
    }

    // PRE: heap is not empty
    int min() {
      return array[1]->data;
    }

    int elements(){
        return items;
    }

  private:
    Node** array;
    unsigned int items;

    // filtrado hacia arriba
    void percolateUp(unsigned int hole) {
      while (hole > 1 && array[hole]->data < array[hole / 2]->data) {
        swap(array[hole], array[hole / 2]);
        hole /= 2;
      }
    }

    // filtrado hacia abajo
    void percolateDown(unsigned int hole) {
      while (hole * 2 <= items) {
        unsigned int child = hole * 2;
        if (child + 1 <= items && array[child + 1]->data < array[child]->data)
          child++;

        if (array[child]->data < array[hole]->data) {
          swap(array[child], array[hole]);
          hole = child;
        } else break;
      }
    }
};

#endif