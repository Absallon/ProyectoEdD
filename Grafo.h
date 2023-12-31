#ifndef GRAFO_H
#define GRAFO_H
#include "Vertice.h"
#include <fstream>
#include "Cola.h"

class Grafo{
    //int **matAdj;
    double **matAdj;
    Vertice *ListaV;
    int numV;
    fstream arch;
    Cola c;
    int buscar(string s);
    public:
        Grafo(string nomArch);
        void generaListaVertices();
        void generaMatrizAdj();
        void muestraListaVertices();
        void muestraMatrizAdj();
        void busquedaProf(Vertice vi);
        void recorridoAnch(Vertice vi);
        void recorridos();
        void recorridoProf(int i);
        void Prim(Vertice vi); //Prim iterativo
};

#endif
