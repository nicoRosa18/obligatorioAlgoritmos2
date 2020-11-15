#include <iostream>
#include "GenericGraph.h"
#include "GenericHeap.h"
#include "Mfs.h"
using namespace std;

struct Vertex {
  int value;
  int distance;
  bool visited;
  int path;

  Vertex() {}
  Vertex(int v): value(v) {}

  bool operator==(Vertex v) {
    return value == v.value;
  }
};

class Edge {
  public:
    int from;
    int to;
    int weight;

    Edge() {}
    Edge(int f, int t, int w): from(f), to(t), weight(w) {}

    bool operator==(Edge &e) {
      return e.weight == weight;
    }

    bool operator<(Edge &e) {
      return weight < e.weight;
    }
};

int kruskal(GenericGraph<Vertex, int>* graph) {
  int costo=0;
  unsigned int count = graph->getVerticesCount();
  GenericHeap<Edge> *heap = new GenericHeap<Edge>();
  Mfs *mfs=new Mfs(count+1);

   int setFrom=mfs->find(1);
    int setTo=mfs->find(2);
     setFrom=mfs->find(5);
     setTo=mfs->find(2);
   Vertex* vertices = graph->getVertices();
 // GenericGraph<Vertex, int>* result = new GenericGraph<Vertex, int>();

  for (unsigned int i = 0; i < count; i++) {
   // result->addVertex(vertices[i]);

    for (unsigned int k = i + 1; k < count; k++) {
      if (graph->hasEdge(vertices[i], vertices[k])) {
        heap->insert(Edge(i, k, graph->getEdge(vertices[i], vertices[k])));
      }
    }
  }

  unsigned int edgesAccepted = 0;
  while (edgesAccepted <= count - 1 && !heap->isEmpty()) {
    Edge e = heap->min();
    heap->deleteMin();

    int setFrom=mfs->find(e.from);
    int setTo=mfs->find(e.to);

    if(setFrom==setTo){
      
    }else{
      edgesAccepted++;
      mfs->merge(setFrom,setTo);
      costo=costo+ e.weight;
    }

  }
  return costo;
}


int main(){
    int cantVertices;
    int cantAristas;
    cin>>cantVertices;
        GenericGraph<Vertex, int>* grafo = new GenericGraph<Vertex, int>();
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

  int valor=  kruskal(grafo);
  cout<<valor<<endl;
  }
