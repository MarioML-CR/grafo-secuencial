//
// Created by Mario Martinez on 17/11/20.
//

#include "Nodo.h"

Nodo::Nodo(int vertice, NodoArco *puntero, Nodo *siguiente) {
    setVertice(vertice);
    setPuntero(nullptr);
    setSiguiente(nullptr);
}

Nodo::~Nodo() {

}

int Nodo::getVertice() const {
    return vertice;
}

void Nodo::setVertice(int vertice) {
    Nodo::vertice = vertice;
}

NodoArco *Nodo::getPuntero() const {
    return puntero;
}

void Nodo::setPuntero(NodoArco *puntero) {
    Nodo::puntero = puntero;
}

Nodo *Nodo::getSiguiente() const {
    return siguiente;
}

void Nodo::setSiguiente(Nodo *siguiente) {
    Nodo::siguiente = siguiente;
}
