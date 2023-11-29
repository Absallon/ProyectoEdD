#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

int main(){
    /*
    ---PROYECTO---
    */
    Grafo CFE("SubestacionesCFE.txt");
    //Definicion del vertice de Partida en Ezequiel Montes
    Vertice vPartida("EzequielMontes");
    //Vertices de prueba
    //Vertice vPartida("ApaseoCelaya");
    //Vertice vPartida("VillasDelCimatario");
    //Vertice vPartida("BuenaVista");
    //Vertice vPartida("SEPoniente");
    //Vertice vPartida("Laborcilla");
    //Vertice vPartida("Tepeyac");
    CFE.muestraListaVertices();
    CFE.muestraMatrizAdj();
    CFE.Prim(vPartida);
    CFE.muestraListaVertices();
    return 0;
}
