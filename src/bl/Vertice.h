//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_VERTICE_H
#define GRAFO_SECUENCIAL_VERTICE_H

#include <string>
using namespace std;
#include "Arista.h"


class Vertice {
public:
    Vertice(int valor, Arista *ady = nullptr, Vertice *next = nullptr);

    virtual ~Vertice();

    int getValor() const;

    void setValor(int valor);

    Arista *getAdy() const;

    void setAdy(Arista *ady);

    Vertice *getNext() const;

    void setNext(Vertice *sig);

private:
    int valor;
    Arista * ady; // puntero adyacente
    Vertice *next; // puntero siguiente
};


#endif //GRAFO_SECUENCIAL_VERTICE_H
