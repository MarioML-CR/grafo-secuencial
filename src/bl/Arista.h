//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_ARISTA_H
#define GRAFO_SECUENCIAL_ARISTA_H


class Arista {
public:
    Arista(int ady, int peso, Arista *siguiente = nullptr);

    virtual ~Arista();

    int getAdy() const;

    void setAdy(int ady);

    int getPeso() const;

    void setPeso(int peso);

    Arista *getSiguiente() const;

    void setSiguiente(Arista *siguiente);

private:
    int ady;
    int peso;  //nombramos variables enteras.
    Arista *siguiente; //creamos un ady.
};


#endif //GRAFO_SECUENCIAL_ARISTA_H
