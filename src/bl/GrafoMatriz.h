//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_GRAFOMATRIZ_H
#define GRAFO_SECUENCIAL_GRAFOMATRIZ_H
#define max 5;

class GrafoMatriz {
public:
    GrafoMatriz();

private:
    int indice;             // 1..max
    int valorar;            // 1 ó 0 (booleana)
    char nombre[10];        // nombre del nodo
    int m[indice][indice];  // matriz
};


#endif //GRAFO_SECUENCIAL_GRAFOMATRIZ_H
