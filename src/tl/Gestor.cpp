//
// Created by Mario Martinez on 17/11/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    lista = new Grafo();
}

Grafo *Gestor::getLista() const {
    return lista;
}

void Gestor::setLista(Grafo *lista) {
    Gestor::lista = lista;
}

void Gestor::insertVertice(int valor) {
    getLista()->insertarVertice(valor);
}

void Gestor::crearArco(int origen, int destino, int peso) {
    getLista()->crearArco(origen, destino, peso);
}

void Gestor::crearMatrizAdyacente() {
    getLista()->cargarMatrizAdy();
}

string Gestor::mostrarMartrizAdyacente() {
    return getLista()->mostrarMatrizVertices();
}

string Gestor::buscarVertice(int valor) {
    if (getLista()->buscarv(valor)) {
        return "existe";
    } else {
        return "no existe";
    }
}

void Gestor::crearMatrizCostos() {
    getLista()->cargarMatrizCostos();
}

string Gestor::mostrarMartrizCostos() {
    return getLista()->mostrarMatrizCostos();
}
