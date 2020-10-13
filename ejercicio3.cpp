#include <iostream>
#include "Heap.h"
#include"Node.h"
#include <string>
using namespace std;


    Node* crearListaOrdenada(Node* node ,int cantEl){
    if(cantEl>0){
        int valor;
        cin>>valor;
        if(!node){
            Node* nuevo=new Node();
            nuevo->data=valor;
            cantEl--;
            nuevo->sig=crearListaOrdenada(nuevo->sig,cantEl);
        }else{
            node->data=valor;
             cantEl--;
            node->sig=crearListaOrdenada(node->sig,cantEl);
        }
    }
}

int main(){
    int cantL=0;
    int cantEl=0;//cantidad de elementos de cada lista
    cin>>cantL;
    int contList=0;//contador de listas
    int contEl=0;//contador de elementos
    int elem=0;
    int totalElementos=0;
    Heap* heapListas=new Heap(cantL);
    while(contList<cantL){
        contEl=0;
        cin>>cantEl;
        totalElementos+=cantEl;
        Node* nodoC= new Node;
        Node* d= crearListaOrdenada(nodoC,cantEl);
        heapListas->insert(d);
        contList++;
    }
    int min;
    int* ret=new int[totalElementos];
    int i=0;
    cout<<"-------------------------"<<endl;
    while (heapListas->elements()!=0){
        min=heapListas->min();
        cout<<min<<endl;
        heapListas->deleteMin();
    }


}
