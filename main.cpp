#include <iostream>
#include <fstream>
#include <string>
#include "Grafo.h"

using namespace std;

int main(){
    Grafo g("SubestacionesCFE.txt");
    //Vertice v("Queretaro");
    g.muestraListaVertices();
    g.muestraMatrizAdj();
    //vertice de partida
    string verticePartida="EzequelMontes";
    Vertice v(verticePartida);
    //g.Prim(verticePartida);



    
    /*g.busquedaProf(v);
    g.muestraListaVertices();
    g.recorridos();
    /*
    string s;
    int numVertices=0;
    int **matAdj;
    //Crea objeto para abrir archivo de lectura
    ifstream arch("prueba.txt");
    //ifstream arch("prueba1.txt"); //Probar con un archivo que no existe
    if(arch.fail()){
        cout << "Error al abrir el archivo..."<<endl;
        exit(1);
    }
    
    //Leer el numero de vertices
    getline(arch,s);
    numVertices = stoi(s);
    matAdj = new int*[numVertices];
    //Crear las columnas para cada renglon

    //Leer información del archivo
    while(!arch.eof()){ //Leer todo el archivo
        getline(arch,s);
        //arch >> s; //Muestra palabra por palabra debido a delimitadores
        cout <<s<<endl;
    }
    /*getline(arch,s);
    cout <<"Cadena leida: "<<s<<endl;
    getline(arch,s);
    cout <<"Cadena leida: "<<s<<endl; * /
    arch.close(); //Cerrar el archivo
    */
    return 0;
}
