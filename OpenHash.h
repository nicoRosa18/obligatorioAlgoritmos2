#ifndef OPEN_HASH_H
#define OPEN_HASH_H

#include <iostream>
#include <string>
using namespace std;

#define LOAD_FACTOR 0.75

class OpenHash {
  public:
    OpenHash(unsigned int expectedItems) {
      tableSize = nextPrime(expectedItems);
      items = 0;
      table = new Node*[tableSize];
      for (unsigned int i = 0; i < tableSize; i++)
        table[i] = NULL;
    }

    void insert(string data) {
      if (shouldExpand()) {
        expandTable();
      }

      unsigned int key = hashFunction(data, tableSize);
      if (insert(table[key], data))
        items++;
    }

    bool pertenece(string data){
        int key=hashFunction(data, tableSize);
      return pertenece(table[key],data);
    }

  private:
    struct Node {
      string data;
      Node* next;
    };

    Node** table;
    unsigned int tableSize;
    unsigned int items;

    unsigned int hashFunction(string data, unsigned int size) {
      return ascii(data) % size;
    }

    int ascii (string data){
              int suma=0;
              for(int i=0;i<data.length();i++){
             suma+= data.at(i);
              }
              return suma;
          }

    bool shouldExpand() {
      return ((float) items / tableSize) > LOAD_FACTOR;
    }

    void expandTable() {
      unsigned int newSize = nextPrime(tableSize + 1);
      Node** newTable = new Node*[newSize];
      for (unsigned int i = 0; i < newSize; i++)
        newTable[i] = NULL;

      for (unsigned int i = 0; i < tableSize; i++) {
        Node* node = table[i];
        while (node) {
          unsigned int key = hashFunction(node->data, newSize);
          insert(newTable[key], node->data);

          Node* toDelete = node;
          node = node->next;
          delete toDelete;
        }
      }

      delete[] table;
      table = newTable;
      tableSize = newSize;
    }

    bool  pertenece(Node* &node, string data){
        if(!node) return false;
        else{
            if(node->data==data) return true;
            else{
                return pertenece(node->next, data);
            }
        }
    }

    bool insert(Node* &node, string data) {
      if (!node) {
        node = new Node;
        node->data = data;
        node->next = NULL;
        return true;
      } else if (node->data == data) {
        node->data = data;
      } else {
        return insert(node->next, data);
      }

      return false;
    }

    int nextPrime(unsigned int n) {
      if (n <= 3) return n;

      unsigned int current = n;
      bool isPrime = false;
      while (!isPrime) {
        for (unsigned int i = 2; i <= current / 2; i++) {
          if (current % i == 0) {
            current++;
            continue;
          }
        }
        isPrime = true;
      }

      return current;
    }
};

#endif
