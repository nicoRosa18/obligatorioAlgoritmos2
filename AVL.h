#include <iostream>
using namespace std;

class AVL
{
public:
    int cantEl;

    AVL()
    {
        root = NULL;
        cantEl = 0;
    };

    void add(int dato)
    {
        add(root, dato);
          cantEl++;
    }

    int darMin()
    {
        return darMin(root);
    }

    void borrar(int num)
    {
        remove(root, num);
    }

private:
    struct Nodo
    {
        int dato;
        int altura;
        Nodo *izq;
        Nodo *der;
    };
    Nodo *root;

    int darMin(Nodo *nodo)
    {
        if (nodo->izq == NULL)
        {
            return nodo->dato;
        }
        else
        {
            return darMin(nodo->izq);
        }
    }

    void remove(Nodo *&node, int data)
    {
        if (!node)
            return;

        if (data < node->dato)
        {
            remove(node->izq, data);
        }
        else if (data > node->dato)
        {
            remove(node->der, data);
        }
        else if (node->izq && node->der)
        {
            node->dato = darMin(node->der);
            remove(node->der, node->dato);
        }
        else
        {
            Nodo *toRemove = node;
            node = node->izq ? node->der : node->der;
            delete toRemove;
            cantEl--;
        }

        balancear(node);
    };

    void add(Nodo *&nodo, int dato)
    {
        if (!nodo)
        {
            nodo = new Nodo;
            nodo->dato = dato;
            nodo->altura = 1;
            nodo->der = NULL;
            nodo->izq = NULL;
        }
        else if (dato < nodo->dato)
        {
            add(nodo->izq, dato);
        }
        else if (dato > nodo->dato)
        {
            add(nodo->der, dato);
        }
        balancear(nodo);
    }

    void balancear(Nodo *&nodo)
    {
        if (!nodo)
            return;

        if (altura(nodo->izq) - altura(nodo->der) > 1)
        {
            if (altura(nodo->izq->izq) >= altura(nodo->izq->der))
            {
                // rotar derecha
                rotarADerecha(nodo);
            }
            else
            {
                // doble rotacion izq-der
                rotarAizquierda(nodo->izq);
                rotarADerecha(nodo);
            }
        }
        else if (altura(nodo->der) - altura(nodo->izq) > 1)
        {
            if (altura(nodo->der->der) >= altura(nodo->der->izq))
            {
                // rotar izq
                rotarAizquierda(nodo);
            }
            else
            {
                // doble rotacion der-izq
                rotarADerecha(nodo->der);
                rotarAizquierda(nodo);
            }
        }

        actualizarAltura(nodo);
    }

    void rotarADerecha(Nodo *&nodo)
    {
        Nodo *aux = nodo->izq;
        nodo->izq = aux->der;
        aux->der = nodo;

        actualizarAltura(nodo);
        actualizarAltura(aux);

        nodo = aux;
    }

    void rotarAizquierda(Nodo *&nodo)
    {
        Nodo *aux = nodo->der;
        nodo->der = aux->izq;
        aux->izq = nodo;

        actualizarAltura(nodo);
        actualizarAltura(aux);

        nodo = aux;
    }

    void actualizarAltura(Nodo *&nodo)
    {
        if (!nodo)
            return;
        nodo->altura = max(altura(nodo->izq), altura(nodo->der)) + 1;
    }

    int altura(Nodo *nodo)
    {
        if (nodo)
            return nodo->altura;
        else
            return 0;
    }

};

//void main(){
//  AVL av= new AVL;

//}
