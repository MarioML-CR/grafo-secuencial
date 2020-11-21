//
// Created by Mario Martinez on 17/11/20.
//

#include "Arista.h"

Arista::Arista(int ady, int peso, Arista *siguiente) {
    setAdy(ady);
    setPeso(peso);
    setSiguiente(siguiente);
}

Arista::~Arista() {

}

int Arista::getAdy() const {
    return ady;
}

void Arista::setAdy(int ady) {
    Arista::ady = ady;
}

int Arista::getPeso() const {
    return peso;
}

void Arista::setPeso(int peso) {
    Arista::peso = peso;
}

Arista *Arista::getSiguiente() const {
    return siguiente;
}

void Arista::setSiguiente(Arista *siguiente) {
    Arista::siguiente = siguiente;
}
