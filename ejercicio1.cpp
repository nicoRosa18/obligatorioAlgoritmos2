#include <iostream>
#include  "AVL.h"
using namespace std;


int main (){
    AVL* av= new AVL();
    int cantE=0;
    int cont=0;
    cin>>cantE;
    int val=0;
    while(cont<cantE){
        cin>>val;
        av->add(val);
        cont++;
    }
    int valor;
    while(av->cantEl>0){
   valor= av->darMin();
   cout << valor<<endl;
    av->borrar(valor);
    }
cout<<"final";
}