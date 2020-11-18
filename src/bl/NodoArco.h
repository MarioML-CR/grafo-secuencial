//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_NODOARCO_H
#define GRAFO_SECUENCIAL_NODOARCO_H


class NodoArco {
public:
    NodoArco(int ady, int peso, NodoArco *siguiente = nullptr);

    virtual ~NodoArco();

    int getAdy() const;

    void setAdy(int ady);

    int getPeso() const;

    void setPeso(int peso);

    NodoArco *getSiguiente() const;

    void setSiguiente(NodoArco *siguiente);

private:
    int ady;
    int peso;  //nombramos variables enteras.
    NodoArco *siguiente; //creamos un puntero.
};


#endif //GRAFO_SECUENCIAL_NODOARCO_H
