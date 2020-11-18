//
// Created by Mario Martinez on 17/11/20.
//

#ifndef GRAFO_SECUENCIAL_VALIDAR_H
#define GRAFO_SECUENCIAL_VALIDAR_H
#include <iostream>
using namespace std;

class Validar {
public:
    int ingresarInt(string);

    int nPrimoMenorQue(int); // retorna el número primo menor al valor pasado por argumento

    bool esPrimo(int); // Analiza si un número es primo
};

#endif //GRAFO_SECUENCIAL_VALIDAR_H
