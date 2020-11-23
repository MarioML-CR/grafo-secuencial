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

string Gestor::crearArco(int origen, int destino, int peso) {
    return getLista()->crearArco(origen, destino, peso);
}

void Gestor::crearMatrizAdyacente() {
    getLista()->cargarMatrizAdy();
}

string Gestor::mostrarMartrizAdyacente() {
    return getLista()->mostrarMatrizVertices();
}

string Gestor::existeArco(int origen, int destino) {
    if (getLista()->existeArco(origen, destino)) {
        return "existe";
    } else {
        return "no existe";
    }
}
string Gestor::existeVertice(int vertice) {
    if (getLista()->existeVertice(vertice)) {
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

int Gestor::cantidadVertices() const {
    return getLista()->cantidadVertices();
}

string Gestor::eliminarGrafo() {
    if (getLista()->esVacio()){
        return "El grafo no contiene elementos que eliminar";
    } else {
        getLista()->eliminarGrafo();
        return "El grafo fue eliminado";
    }
}


