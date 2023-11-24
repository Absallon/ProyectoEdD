#ifndef NODO_H
#define NODO_H
#include "Vertice.h"

using namespace std;

class Nodo{
    private:
        //string cadena;
        Vertice vert;
    public:
        Nodo *sig;
	    Nodo();
	    Nodo(Vertice v);
	    Vertice getVertice();
        void setVertice(Vertice v);
};

#endif