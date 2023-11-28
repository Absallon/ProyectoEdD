#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(string nomArch){
    //ifstream arch(nomArch);
    arch.open(nomArch,ios::in);
    string cad;
    if(arch.fail()){
        cout <<"Error al abrir el archivo..."<<endl;
        exit(1);
    }    
    //Obtener el numero de vertices
    getline(arch,cad);
    numV = stoi(cad);
    //Crear lista de vertices
    ListaV = new Vertice[numV];
    //crear la matriz e inicializar
    matAdj = new int*[numV];
    for(int i = 0;i<numV;i++){
        matAdj[i] = new int[numV];
        for(int j=0;j<numV;j++){
            matAdj[i][j]=0;
        }
    }
    generaListaVertices();
    generaMatrizAdj();
}
void Grafo::generaListaVertices(){
    string cad;
    for(int i = 0;i<numV;i++){
        getline(arch,cad);
        ListaV[i]=cad;
    }
}
int Grafo::buscar(string s){
    int i=0;
    while((i<numV) && (ListaV[i].getNom()!=s)){
        i++;        
    }
    if(i<numV) return i;
    else return -1;
}
void Grafo::generaMatrizAdj(){
    string cad;
    int i=0,peso,posAsterisco=0,j;
    string origen,destino,p,temp;
    while(!arch.eof()){
        getline(arch,cad);
        posAsterisco=0;
        //Forma que nos guio la maestra
        origen = cad.substr(posAsterisco,cad.find("*"));
        //cout <<"Origen: "<<origen<<endl;
        posAsterisco=cad.find("*")+1;//posAsterisco = posAsterisco+1;
        //cout <<posAsterisco<<endl;
        destino = cad.substr(posAsterisco,cad.find("*",posAsterisco)-posAsterisco);
        //cout <<"Destino: "<<destino<<endl;
        posAsterisco=cad.find("*",posAsterisco)+1;        
        peso=stoi(cad.substr(posAsterisco));
        //cout <<"Peso: "<<peso<<endl;
        i=buscar(origen);
        //cout <<"I: "<<i<<endl;
        j=buscar(destino);
        //cout <<"J: "<<j<<endl;
        if(i>=0 && j>=0) matAdj[i][j]=peso;
        else {
            cout <<"Error en nombres de vertices"<<endl;
            exit(1);
        }
        //origen = destino = peso = cad = "";

        /*
        //Otra posible forma para hacerlo
        for(i=0;i<cad.length();i++){
            if(cad[i]!='*'){
                temp += cad[i];
            }
            else{
                numA++;
                switch(numA){
                    case 1:
                        origen = temp;
                        temp = "";
                        break;
                }
            }
        }
        p = temp;
        */
        /*
        //Forma en que lo estaba haciendo yo
        for(int j=0;cad.substr(posAsterisco,cad.find("*",posAsterisco)-posAsterisco)=="";j++){
            if(i==0){
                posAsterisco=cad.find("*");
                origen = cad.substr(0,posAsterisco-1);
                matAdj[i][j]=posAsterisco;
            }
            else if (i==1){
                destino = cad.substr(posAsterisco,cad.find("*",posAsterisco+1)-posAsterisco-1);
                posAsterisco = cad.find("*",posAsterisco+1);
                matAdj[i][j]=posAsterisco;
            }
            else{
                peso = stoi(cad.substr(posAsterisco));
                posAsterisco=cad.find("0");
                matAdj[i][j]=peso;
            }
            i++;
            if(cad.substr(posAsterisco)=="0"){
                i=0;
            }    
        } 
        */               
    }
}
void Grafo::muestraListaVertices(){
    for(int i = 0;i<numV;i++)
        cout<<ListaV[i].getNom()<<endl;
}
void Grafo::muestraMatrizAdj(){
    for(int i = 0;i<numV;i++){
        //cout <<ListaV[i].getNom() <<"\t";
        for(int j=0;j<numV;j++){
            cout<<matAdj[i][j]<<"\t";
        }
        cout <<endl;
    }
}

void Grafo::busquedaProf(Vertice vi){
    int i,j;
    vi.setVisitado(); //Altera su valor por el contrario
    //vi.setVisitado(true); //Asigna con sobrecarga
    /*
    buscar posicion de vi
    ir a renglon en matAdj y buscar un valor
    diferente de 0
    si lo encuentra verificar si no visitado
    */
    i=buscar(vi.getNom());
    j=0;
    bool salir = false;
    do{
        while(((matAdj[i][j] == 0)) && (j<numV)){
            j++;
            if(j<numV){
                cout <<"j = "<<j<<", visitado = "<<ListaV->getVisitado()<<endl;
                if(ListaV[j].getVisitado()!=true) busquedaProf(ListaV[j]);
                else return ListaV[j].setVisitado();
            }
            else salir = true;
        }
    }while(!salir);
}

void Grafo::recorridoAnch(Vertice vi){
    int i = buscar(vi.getNom());
    ListaV[i].setVisitado();
    c.enqueue(ListaV[i]);
    while(c.first().getNom() != ""){
        vi = c.dequeue();
        cout << vi.getNom() << endl;
        //cout << c.dequeue().getNom() << endl;
        i = buscar(vi.getNom());
        for(int k = 0;k<numV;k++){ //&& matAdj[i][k]!=0;k++){
            if(matAdj[i][k]!=0){
            //if(k<numV){
                if(ListaV[k].getVisitado() != true){
                    ListaV[k].setVisitado();
                    c.enqueue(ListaV[k]);
                }
            }
        }
    }
}

void Grafo::recorridos(){
    Vertice v = ListaV[0];
    recorridoAnch(v);
}
void Grafo::Prim(){
   
}


    
}
