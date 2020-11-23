//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_GRAFO_H
#define GRAFO_SECUENCIAL_GRAFO_H
#include <iostream>
using namespace std;
#define Max 10
#include "Vertice.h"

class Grafo {
public:

    Grafo(Vertice *head = nullptr, Vertice *tail = nullptr, int tam = 0);

    Vertice *getHead() const;

    void setHead(Vertice *head);

    Vertice *getTail() const;

    void setTail(Vertice *tail);

    int getTam() const;

    void setTam(int tam);

    //nuestras funciones pincipales.

    void insertarVertice(int v); // función para insertar los datos.
    bool esVacio() const;  //función para revisar si nuestra lista esta vacio
    Vertice *buscarVertice(int v) const; //función para buscar.
    bool existeVertice(int i);
    string crearArco(int i, int f, int peso);//función para crear los arcos de nuestro grafo.
    void cargarMatrizAdy(); //función para crear nuestra matriz adyacente.
    void cargarMatrizCostos(); //función para crear nuestra matriz adyacente.
    string mostrarMatrizVertices();//función para mostrar nuestra matriz.
    string mostrarMatrizCostos();//función para mostrar nuestra matriz.
    int cantidadVertices() const;//función para contar nuestros vertices o nodos.
    bool existeArco(int i, int f);//función para  verificar si nuestro grafo tiene arcos
    int costoArco(int i, int f);//función para  verificar si nuestro grafo tiene arcos
    int buscarCosto(Vertice aux, int ad);//función booleana para verificar si nuestro grafo tiene arcos
    void eliminarGrafo();
private:
    Vertice *head;
    Vertice *tail;
    int tam;
    int matrizAdyacente[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
    int matrizCostos[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
    void insertarAlIincio(int v);
    void insertarAlFinal(int v);
};


#endif //GRAFO_SECUENCIAL_GRAFO_H
