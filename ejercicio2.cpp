#include <iostream>
#include "OpenHash.h"
#include <string>
using namespace std;



int main(){
    int cantPal;
    int cantCons;
    int cont=0;
    string pal;

    cin>>cantPal;
     OpenHash* hash = new OpenHash(cantPal);
    while (cont<cantPal)
    {
        cin>>pal;
        hash->insert(pal);
        cont++;
    }
    cont=0;
    cin>>cantCons;
    while(cont<cantCons){
        cin>>pal;
    if(hash->pertenece(pal)){
        cout<<pal<<" 1"<<endl;
    }else{
           cout<<pal<<" 0"<<endl;
    }
    cont++;
}
}