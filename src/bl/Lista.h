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
    Lista();

    Nodo *getPrimero() const;

    void setPrimero(Nodo *primero);

    //nuestras funciones pincipales.

    void Insertarv(int v); // función para insertar los datos.
    bool ListavVacia();  //función para revisar si nuestra lista esta vacio
    Nodo *Buscarv( int v); //función para buscar.
    bool listavexiste(int i,int f);//función booleana para verificar si nuestro grafo esta vacio
    void creararco(int i,int f,int peso);//función para crear los arcos de nuestro grafo.
    void CrearMatriz(); //función para crear nuestra matriz adyacente.
    string mostrarmatriz();//función para mostrar nuestra matriz.
    int CantidadVertices();//función para contar nuestros vertices o nodos.
    int ExisteArco(int i,int f);//función para  verificar si nuestro grafo tiene arcos
    bool BuscarAdy(Nodo aux,int ad);//función booleana para verificar si nuestro grafo tiene arcos
private:
    Nodo *primero; //creamos un nuevo puntero de tipo nodo
    int MatrizAdyacente[Max][Max]; //creamos una matriz para mostrar la matiz adyacente
};


#endif //GRAFO_SECUENCIAL_LISTA_H
