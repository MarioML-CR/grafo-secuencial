//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_GRAFO_H
#define GRAFO_SECUENCIAL_GRAFO_H
#include <iostream>
using namespace std;
#define Max 100

#include "Vertice.h"
//typedef Vertice *pnodo; //creamos un nuevo ady.
class Grafo {
public:
    Grafo(Vertice *primero = nullptr);

    Vertice *getPrimero() const;

    void setPrimero(Vertice *primero);

    //nuestras funciones pincipales.

    void insertarVertice(int v); // función para insertar los datos.
    bool listavVacia() const;  //función para revisar si nuestra lista esta vacio
    Vertice *buscarv(int v) const; //función para buscar.
    bool existeVertice(int i, int f) const;//función booleana para verificar si nuestro grafo esta vacio
    void crearArco(int i, int f, int peso) const;//función para crear los arcos de nuestro grafo.
    void cargarMatrizAdy(); //función para crear nuestra matriz adyacente.
    void cargarMatrizCostos(); //función para crear nuestra matriz adyacente.
    string mostrarMatrizVertices();//función para mostrar nuestra matriz.
    string mostrarMatrizCostos();//función para mostrar nuestra matriz.
    int cantidadVertices() const;//función para contar nuestros vertices o nodos.
    int existeArco(int i, int f);//función para  verificar si nuestro grafo tiene arcos
    bool buscarAdy(Vertice aux, int ad);//función booleana para verificar si nuestro grafo tiene arcos
    int costoArco(int i, int f);//función para  verificar si nuestro grafo tiene arcos
    int buscarCosto(Vertice aux, int ad);//función booleana para verificar si nuestro grafo tiene arcos
private:
    Vertice *primero; //creamos un nuevo ady de tipo nodo
    int matrizAdyacente[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
    int matrizCostos[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
};


#endif //GRAFO_SECUENCIAL_GRAFO_H
