#include <iostream>
#include "Graph.h"
#include <string>
using namespace std;


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
    while(i<cantAristas){
        cin>>de;
        cin>>hacia;
        grafo->addEdge(de,hacia,0);
        i++;
    }
    
   while (grafo->getVerticesCount()>0){
       int d=grafo->eliminarMinVertice();
       cout<<d<<endl;
    }
}