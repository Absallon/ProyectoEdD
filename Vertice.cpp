#include "Vertice.h"

Vertice::Vertice(){
    nom = "";
    visitado = false;
}
Vertice::Vertice(string info){
    nom = info;
    visitado = false;
}
string Vertice::getNom(){
    return nom;
}

bool Vertice::getVisitado(){
    return visitado;
}

void Vertice::setVisitado(){
    visitado = !visitado;
}

void Vertice::setVisitado(bool v){
    visitado = v;
}