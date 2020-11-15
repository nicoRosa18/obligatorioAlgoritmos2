#include <iostream>
#include "Graph.h"
#include <string>
#include "HeapVert.h"
using namespace std;


int main(){
    int cantVertices;
    int cantAristas;
    cin>>cantVertices;
    Graph<int, int>* grafo = new Graph<int, int>(cantVertices);
    HeapVertice* heapVert= new HeapVertice(cantVertices);
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
    
    Vertex** vertices =grafo->getVertices();
    int count =grafo->getVerticesCount();
    
    for(int i=1;i<=count;i++){
        Vertex* v= vertices[i];
        if(v->grado==0){
            v->nivel=0;
            heapVert->insert(v);
        }
    }


    while(!heapVert->isEmpty()){
        Vertex* v= heapVert->min();
        HeapVertice* listaVertices= grafo->getVerticesAdyacentes(v);
        while(!listaVertices->isEmpty()){
           Vertex* vertAdj= listaVertices->min();
           listaVertices->deleteMin();
           vertAdj->grado--;
           vertAdj->nivel=v->nivel+1;
            if(vertAdj->grado==0){
                heapVert->insert(vertAdj);
            }
        }
        heapVert->deleteMin();
        cout<<v->vertex<<endl;
    }
}


