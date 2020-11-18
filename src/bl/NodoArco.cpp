//
// Created by Mario Martinez on 17/11/20.
//

#include "NodoArco.h"

NodoArco::NodoArco(int ady, int peso, NodoArco *siguiente) {
    setAdy(ady);
    setPeso(peso);
    setSiguiente(siguiente);
}

NodoArco::~NodoArco() {

}

int NodoArco::getAdy() const {
    return ady;
}

void NodoArco::setAdy(int ady) {
    NodoArco::ady = ady;
}

int NodoArco::getPeso() const {
    return peso;
}

void NodoArco::setPeso(int peso) {
    NodoArco::peso = peso;
}

NodoArco *NodoArco::getSiguiente() const {
    return siguiente;
}

void NodoArco::setSiguiente(NodoArco *siguiente) {
    NodoArco::siguiente = siguiente;
}
