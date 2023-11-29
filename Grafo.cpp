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
    //crear la matriz e inicializar si los valores son enteros
    /*
    matAdj = new int*[numV];
    for(int i = 0;i<numV;i++){
        matAdj[i] = new int[numV];
        for(int j=0;j<numV;j++){
            matAdj[i][j]=0;
        }
    }
    */
    //crear la matriz e inicializar si los valores son decimales
    
    matAdj = new double*[numV];
    for(int i = 0;i<numV;i++){
        matAdj[i] = new double[numV];
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
    int i=0,/*peso,*/posAsterisco=0,j;
    double peso;
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
        //peso=stoi(cad.substr(posAsterisco));
        peso=stod(cad.substr(posAsterisco));
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
        i = buscar(vi.getNom());
        for(int k = 0;k<numV;k++){ 
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
void Grafo::Prim(Vertice vi){
   if(vi.getNom() == ""){
        cout << "El vertice origen no existe" << endl;
        return;
    }
    while(vi.getNom()!=""){
        //Declaro los arreglos de las aristas y los vertices que conforman al recorrido, ademas de inicializar algunas variables
        double pesoTotal=0,listaPesos[6],listaAristas[7],auxiliar=0;
        string NombreVerticesAristas[7];
        int entrada,posArista=0,indiceVisitado,ultimoindice;
        //Obtener indice del vertice de entrada
        for(int a=0;a<numV;a++){
            if(vi.getNom()==ListaV[a].getNom()){
                entrada=a;                
            }
        }
        //Asignamos el vertice del argumento a los arreglos de los vertices que conforman al recorrido
        NombreVerticesAristas[0]=vi.getNom();
        listaAristas[0]=entrada;
        ListaV[entrada].setVisitado(); //Ponemos al vertice inicial como visitado
        indiceVisitado=entrada; //Movemos el indice al del vertice inicial
        while(posArista<numV-1){
            for(int j=0;j<numV;j++){            
                //if((ListaV[j].getVisitado()==false && matAdj[indiceVisitado][j]<auxiliar && matAdj[indiceVisitado][j]!=0) || (auxiliar == 0 && matAdj[indiceVisitado][j]!=0 && ListaV[j].getVisitado()==false)){ 
                if((matAdj[indiceVisitado][j]<auxiliar || auxiliar == 0) && matAdj[indiceVisitado][j]!=0 && ListaV[j].getVisitado()==false){ 
                    /*
                    Este if tiene un OR para cuando se ingrese con el primer valor de la variable auxiliar o si el valor dentro de la matriz de adyacencias en i,j es menor al de la variable auxiliar
                    las condiciones AND son por si trata de agarrar el valor de 0 dentro de la matriz de adyacencias y para verificar que el vertice no ha sido visitado
                    debido a su funcionamiento nos quedaremos con el valor que cumpla dichas caracteristicas al final
                    */                    
                    auxiliar=matAdj[indiceVisitado][j]; //Tomamos el ultimo valor que cumple con las condiciones
                    listaPesos[posArista]=matAdj[indiceVisitado][j]; //Asigno el ultimo valor encontrado a la lista de pesos de las aristas
                    ultimoindice=j; //Tomamos el ultimo indice del vertice que cumplio con las condiciones
                }
            }
            indiceVisitado=ultimoindice; //Movemos el indice del ultimo vertice al nuevo valor
            NombreVerticesAristas[posArista+1]=ListaV[indiceVisitado].getNom(); //Agregamos el nombre del vertice al arreglo del nombre de los vertices que conforman a las aristas de menor valor
            listaAristas[posArista+1]=indiceVisitado; //Agregamos el indice del vertice al arreglo de las aristas de menor valor
            ListaV[indiceVisitado].setVisitado(); //Hago que el vertice en la posicion del indice, sea visitado
            posArista++; //Con 'posArista' recorremos todo el arreglo de las aristas de menor valor
            auxiliar=0; //Reiniciamos el valor de la variable auxiliar a 0
        }
        //Impresion de resultados
        //Peso de cada arista
        for(int i = 0;i<numV-1;i++){
            cout<<"El peso de la lista de aristas en la posicion "<<i<<" es: "<<listaPesos[i]<<endl;
            pesoTotal+=listaPesos[i];
        }
        //Peso total
        cout<<"El peso total del recorrido de Prim es: "<<pesoTotal<<endl;
        //Numero de vertices en orden del recorrido
        cout<<"El numero de las vertices de la lista de aristas de acuerdo al recorrido es: "<<endl;
        for(int i = 0;i<numV;i++){
            if(i==numV-1) cout<<listaAristas[i]+1<<endl;
            else cout<<listaAristas[i]+1<<" - ";
        }
        //El nombre de los vertices en orden del recorrido
        cout<<"El nombre de los vertices de la lista de aristas de acuerdo al recorrido es: "<<endl;
        for(int i = 0;i<numV;i++){
            if(i==numV-1) cout<<NombreVerticesAristas[i]<<endl;
            else cout<<NombreVerticesAristas[i]<<" - ";            
        }
    }
    //int* pesoMin=new int [];
}
