#ifndef COLA_H
#define COLA_H
#include "Nodo.h"

class Cola{
    private:
        Nodo *primero, *ultimo;
    public:    
        Cola();
        void enqueue(Vertice v);
        Vertice first();
        Vertice dequeue();
        
};
#endif