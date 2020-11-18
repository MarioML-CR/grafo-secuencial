//
// Created by Mario Martinez on 17/11/20.
//

#include "Gestor.h"

Gestor::Gestor() {
    lista = new Lista();
}

Lista *Gestor::getLista() const {
    return lista;
}

void Gestor::setLista(Lista *lista) {
    Gestor::lista = lista;
}

void Gestor::insertVertice(int valor) {
    getLista()->Insertarv(valor);
}

void Gestor::crearArco(int origen, int destino, int peso) {
    getLista()->creararco(origen, destino, peso);
}

void Gestor::crearMatrizAdyacente() {
    getLista()->CrearMatriz();
}

string Gestor::mostrarMartrizAdyacente() {
    return getLista()->mostrarmatriz();
}

void Gestor::buscarVertice(int valor) {
    getLista()->Buscarv(valor);
}
