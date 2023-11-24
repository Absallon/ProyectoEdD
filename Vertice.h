#ifndef VERTICE_H
#define VERTICE_H
#include <string>

using namespace std;

class Vertice{
    string nom;
    bool visitado;
    public:
        Vertice();
        Vertice(string info);
        string getNom();
        bool getVisitado();
        void setVisitado();
        void setVisitado(bool v);
};

#endif