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
    Vertice(int valor, Arista *ady = nullptr, Vertice *sig = nullptr);

    virtual ~Vertice();

    int getValor() const;

    void setValor(int valor);

    Arista *getAdy() const;

    void setAdy(Arista *ady);

    Vertice *getSig() const;

    void setSig(Vertice *sig);

private:
    int valor; //creamos una varible entera.
    Arista * ady; //creamos un nuevo ady utilizando la clase anteriormente creada
    Vertice *sig; //creamos un nuevo ady
};


#endif //GRAFO_SECUENCIAL_VERTICE_H
