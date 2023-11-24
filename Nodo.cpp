#include "Nodo.h"

Nodo::Nodo(){
    sig = NULL;
    //vert = new Vertice();
}

Nodo::Nodo(Vertice v){
    sig = NULL;
    vert = v;
}

Vertice Nodo::getVertice(){
    return vert;
}
void Nodo::setVertice(Vertice v){
    vert = v;
}