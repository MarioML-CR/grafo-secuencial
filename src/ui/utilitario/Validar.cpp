//
// Created by Mario Martinez on 17/11/20.
//

#include "Validar.h"
int Validar::ingresarInt(string pValor) {
    try {
        return stoi(pValor);
    } catch (exception e) {
//        cout << e.what();
        return -1;
    }
}
/**
 * Método:              nPrimoMenorQue
 * Descripción:         Método que permite obtener el número primo menor al valor
 * pasado por argumento
 * @param pValor        variable de tipo int que representa el valor base para
 * calcular el valor primo menor que este.
 * @return              variable de tipo int que representa el valor del número
 * primo menor que el valor ingresado
 */
int Validar::nPrimoMenorQue(int pValor) {
    if (pValor < 0){
        return 0;
    } else {
        int i = 0;
        while (!esPrimo(pValor)) {
            i++;
            pValor -= 1;
        }
        return pValor;
    }
}
/**
 * Método:              esPrimo
 * Descripción:         Método que permite verificar si un número es primo
 * @param pValor        variable de tipo int que representa el número a verificar
 * @return              variabla de tipo bool, true si es primo y false caso contrario.
 */
bool Validar::esPrimo(int pValor) {
    int i = 2, j = 0;
    while (j < 2 && i <= pValor){
        if (pValor % i == 0){
            j += 1;
        }
        i ++;
    }
    if (j == 1){
        return true;
    } else {
        return false;
    }
}
