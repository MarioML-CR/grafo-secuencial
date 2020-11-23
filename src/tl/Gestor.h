//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_GESTOR_H
#define GRAFO_SECUENCIAL_GESTOR_H


#include "../bl/Grafo.h"

class Gestor {
public:
    Gestor();

    Grafo *getLista() const;

    void setLista(Grafo *lista);

    void insertVertice(int valor); // insertar valor

    string crearArco(int origen, int destino, int peso); // se crear el arco

    void crearMatrizAdyacente(); // se crea la matriz de ady

    void crearMatrizCostos();

    string mostrarMartrizAdyacente();

    string mostrarMartrizCostos();

    string existeArco(int i, int f);

    string existeVertice(int i);

    int cantidadVertices() const;

    string eliminarGrafo();

private:
    Grafo *lista;
};


#endif //GRAFO_SECUENCIAL_GESTOR_H
