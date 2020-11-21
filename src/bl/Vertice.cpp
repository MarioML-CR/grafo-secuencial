//
// Created by Mario Martinez on 17/11/20.
//

#include "Vertice.h"

Vertice::Vertice(int valor, Arista *ady, Vertice *sig) {
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

Vertice *Vertice::getSig() const {
    return sig;
}

void Vertice::setSig(Vertice *sig) {
    Vertice::sig = sig;
}
