//
// Created by Mario Martinez on 17/11/20.
//

#include "Vertice.h"

Vertice::Vertice(int valor, Arista *ady, Vertice *next) : valor(valor), ady(ady), next(next) {
    setValor(valor);
}

Vertice::~Vertice() {

}

int Vertice::getValor() const {
    return valor;
}

void Vertice::setValor(int valor) {
    Vertice::valor = valor;
}

Arista *Vertice::getAdy() const {
    return ady;
}

void Vertice::setAdy(Arista *ady) {
    Vertice::ady = ady;
}

Vertice *Vertice::getNext() const {
    return next;
}

void Vertice::setNext(Vertice *sig) {
    Vertice::next = sig;
}


