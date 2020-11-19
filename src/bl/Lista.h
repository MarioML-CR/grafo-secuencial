//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_LISTA_H
#define GRAFO_SECUENCIAL_LISTA_H
#include <iostream>
using namespace std;
#define Max 100

#include "Nodo.h"
//typedef Nodo *pnodo; //creamos un nuevo puntero.
class Lista {
public:
    Lista(Nodo *primero = nullptr);

    Nodo *getPrimero() const;

    void setPrimero(Nodo *primero);

    //nuestras funciones pincipales.

    void insertarVertice(int v); // función para insertar los datos.
    bool listavVacia() const;  //función para revisar si nuestra lista esta vacio
    Nodo *buscarv(int v) const; //función para buscar.
    bool existeVertice(int i, int f) const;//función booleana para verificar si nuestro grafo esta vacio
    void crearArco(int i, int f, int peso) const;//función para crear los arcos de nuestro grafo.
    void cargarMatrizAdy(); //función para crear nuestra matriz adyacente.
    void cargarMatrizCostos(); //función para crear nuestra matriz adyacente.
    string mostrarMatrizVertices();//función para mostrar nuestra matriz.
    string mostrarMatrizCostos();//función para mostrar nuestra matriz.
    int cantidadVertices() const;//función para contar nuestros vertices o nodos.
    int existeArco(int i, int f);//función para  verificar si nuestro grafo tiene arcos
    bool buscarAdy(Nodo aux, int ad);//función booleana para verificar si nuestro grafo tiene arcos
    int costoArco(int i, int f);//función para  verificar si nuestro grafo tiene arcos
    int buscarCosto(Nodo aux, int ad);//función booleana para verificar si nuestro grafo tiene arcos
private:
    Nodo *primero; //creamos un nuevo puntero de tipo nodo
    int matrizAdyacente[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
    int matrizCostos[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
};


#endif //GRAFO_SECUENCIAL_LISTA_H
