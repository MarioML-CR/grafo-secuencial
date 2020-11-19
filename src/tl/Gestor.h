//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_GESTOR_H
#define GRAFO_SECUENCIAL_GESTOR_H


#include "../bl/Lista.h"

class Gestor {
public:
    Gestor();

    Lista *getLista() const;

    void setLista(Lista *lista);

    void insertVertice(int valor); // insertar vertice

    void crearArco(int origen, int destino, int peso); // se crear el arco

    void crearMatrizAdyacente(); // se crea la matriz de ady

    void crearMatrizCostos();

    string mostrarMartrizAdyacente();

    string mostrarMartrizCostos();

    string buscarVertice(int valor);

private:
    Lista *lista;
};


#endif //GRAFO_SECUENCIAL_GESTOR_H
