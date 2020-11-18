//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_NODO_H
#define GRAFO_SECUENCIAL_NODO_H


#include "NodoArco.h"

class Nodo {
public:
    Nodo(int vertice, NodoArco *puntero = nullptr, Nodo *siguiente = nullptr);

    virtual ~Nodo();

    int getVertice() const;

    void setVertice(int vertice);

    NodoArco *getPuntero() const;

    void setPuntero(NodoArco *puntero);

    Nodo *getSiguiente() const;

    void setSiguiente(Nodo *siguiente);

private:
    int vertice; //creamos una varible entera.
    NodoArco * puntero; //creamos un nuevo puntero utilizando la clase anteriormente creada
    Nodo *siguiente; //creamos un nuevo puntero
};


#endif //GRAFO_SECUENCIAL_NODO_H
