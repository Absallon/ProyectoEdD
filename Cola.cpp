#include "Cola.h"

Cola::Cola(){
    primero = ultimo = NULL;
}

void Cola::enqueue(Vertice v){
    Nodo *c = new Nodo(v);
    if(primero==NULL){
        primero = c;
        ultimo = primero;
    }
    else{
        ultimo->sig=c;
        ultimo = c;
    }
}

Vertice Cola::first(){
    Vertice v;
    if(primero != NULL) v = primero->getVertice();
    return v;
}

Vertice Cola::dequeue(){
    Nodo *t;
    Vertice v;
    t = primero;
    if(primero != NULL){
        primero = t->sig;
        v = t->getVertice();
        delete(t);
    }
    return v;
}