//
// Created by Mario Martinez on 17/11/20.
//

#include "Lista.h"


Lista::Lista(Nodo *primero) {
    setPrimero(nullptr);
}

Nodo *Lista::getPrimero() const {
    return primero;
}

void Lista::setPrimero(Nodo *primero) {
    Lista::primero = primero;
}
/**
 * Método:              insertarVertice
 * Descripción:         Método que permite insertar un vértice
 * @param v             variable que representa el valor de vértice
 */
void Lista::insertarVertice(int v) {
    Nodo *anterior;
    if (listavVacia()) {
        setPrimero(new Nodo(v));
    } else { if(v <= getPrimero()->getVertice()){
            setPrimero(new Nodo(v));
        } else {
            anterior = getPrimero();
            while ( (anterior->getSiguiente()) && (anterior->getSiguiente()->getVertice() <= v)){
                anterior = anterior->getSiguiente(); }
            anterior->setSiguiente(new Nodo(v));
        }
    }
}
/**
 * Método:              listavVacia
 * Descripción:         Método que permite verificar si la lista de vértices está vacía
 * @return              variable de tipo bool, true si está vacía, falso lo inverso.
 */
bool Lista::listavVacia() const { //función booleana.
    return getPrimero() == nullptr;
}
/**
 * Método:              buscarv
 * Descripción:         Método que permite retorna el nodo correspondiente al vértice, si
 * este no existe el nodo retornado es null
 * @param v             variable que representa el valor de vértice
 * @return              varibale de tipo nodo que representa el nodo del valor pasado por parámetro
 */
Nodo *Lista::buscarv(int v) const { //función para buscar valores dentro de nuestro grafo
    int z;
    Nodo *indice;
    indice = getPrimero();
    while(indice != nullptr){
        if(v == indice->getVertice()){
            return indice;
        }
        indice = indice->getSiguiente();
    }
    return indice;
}
/**
 * Método:              existeVertice
 * Descripción:         Método que permite verificar si existen los vértices que se pasan por
 * parámetro
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @return              variable de tipo bool, false si no existen, falso lo inverso.
 */
bool Lista::existeVertice(int i, int f) const {
    return (buscarv(i) != nullptr && buscarv(f) != nullptr);
}
/**
 * Método:              crearArcoManual
 * Descripción:         Método que permite crear un arco entre los dos vértices pasados
 * por parámetro
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @param peso          variable de tipo entero que representa el peso del arco
 */
void Lista::crearArco(int i, int f, int peso) const { //función para crear un nuevo arco
    Nodo *pos;
    pos = getPrimero();
    if(existeVertice(i, f)){
        while(pos != nullptr){
            if(i == pos->getVertice() ){
                if(pos->getPuntero() == nullptr){
                    pos->setPuntero(new NodoArco(f, peso));
                } else {
                    NodoArco *temp = pos->getPuntero();
                    while(temp->getSiguiente() != nullptr) {
                        temp = temp->getSiguiente();
                    }
                    temp->setSiguiente(new NodoArco(f, peso));
                    temp = nullptr;
                    delete temp;
                }
            }
            pos = pos->getSiguiente();//guerdamos los datos.
        }
    }
}
/**
 * Método:              cargarMatrizAdy
 * Descripción:         Método que permite cargar la matriz de adyacencia
 */
void Lista::cargarMatrizAdy() {
    Nodo *nodo = getPrimero(), *nodotemp;
    int i, j;
    int cant = cantidadVertices();
    for(i = 0; i < cant; i++){
        nodotemp = getPrimero();
        for(j = 0; j < cant; j++){
            matrizAdyacente[i][j] = existeArco(nodo->getVertice(), nodotemp->getVertice());
            nodotemp = nodotemp->getSiguiente();
        }
        nodo = nodo->getSiguiente();
    }
    delete nodo;
    delete nodotemp;
}
/**
 * Método:              cargarMatrizCostos
 * Descripción:         Método que permite cargar la matriz de costos
 */
void Lista::cargarMatrizCostos() {
    Nodo *nodo = getPrimero(), *nodotemp;
    int i, j;
    int cant = cantidadVertices();
    for(i = 0; i < cant; i++){
        nodotemp = getPrimero();
        for(j = 0; j < cant; j++){
            matrizCostos[i][j] = costoArco(nodo->getVertice(), nodotemp->getVertice());
            nodotemp = nodotemp->getSiguiente();
        }
        nodo = nodo->getSiguiente();
    }
    delete nodo;
    delete nodotemp;
}
/**
 * Método:              mostrarMatrizVertices
 * Descripción:         Método que permite retornar la matriz de vértices
 * @return              variable de tipo string que contiene la matriz de adyacencia.
 */
string Lista::mostrarMatrizVertices() {
    string msg;
    int i,j,cant;
    Nodo *nodo = getPrimero();
    cant = cantidadVertices();
    msg =+ "   "; //espacios
    for(i=0;i<cant;i++){ //ciclo for.
        msg += "\t" + to_string(nodo->getVertice()) + " ";
        nodo=nodo->getSiguiente();
    }
    nodo = getPrimero();
    msg += "\n"; //saltos de linea.
    for( i = 0;i < cant; i++){ //ciclo for.
        msg += to_string(nodo->getVertice()); //mostramos los vertices de nuestro grafo.
        for(j = 0; j < cant; j++){ //ciclo for
            msg += "\t" + to_string(matrizAdyacente[i][j]); //mostramos los datos guardados en la matriz.
        }
        nodo = nodo->getSiguiente(); //igualamos los punteros para que muestre todos los datos.
        msg += "\n"; //salto de linea.
    }
    return msg;
}
/**
 * Método:              mostrarMatrizCostos
 * Descripción:         Método que permite retorna la matriz de costos
 * @return
 */
string Lista::mostrarMatrizCostos() {
    string msg;
    int i,j,cant; //creamos varibales enteras
    Nodo *nodo = getPrimero(); //creamos un nuevo puntero.
    cant = cantidadVertices();
    msg =+ "   "; //espacios
    for(i=0;i<cant;i++){
        msg += "\t" + to_string(nodo->getVertice()) + " ";
        nodo=nodo->getSiguiente();
    }
    nodo = getPrimero();
    msg += "\n"; //saltos de linea.
    for( i = 0;i < cant; i++){
        msg += to_string(nodo->getVertice()); //mostramos los vertices de nuestro grafo.
        for(j = 0; j < cant; j++){ //ciclo for
            msg += "\t" + to_string(matrizCostos[i][j]); //mostramos los datos guardados en la matriz.
        }
        nodo = nodo->getSiguiente();
        msg += "\n"; //salto de linea.
    }
    return msg;
}

/**
 * Método:              cantidadVertices
 * Descripción:         Método que permite retornar la cartidad de vértices
 * @return              variable de tipo int que representa el número de vértices.
 */
int Lista::cantidadVertices() const {
    Nodo *nodo = getPrimero();
    int i=0;
    while(nodo != nullptr){
        i++;
        nodo = nodo->getSiguiente();
    }
    return i;
}
/**
 * Método:              existeArco
 * Descripción:         Método que retorna 1 si existe arco, y 0 si no
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @return              variable de tipo int que representa si existe arco (1) o no (0)
 */
int Lista::existeArco(int i, int f) {
    Nodo *nodo;
    nodo = buscarv(i);
    if(nodo){
        if(buscarAdy(*nodo, f)){
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/**
 * Método:              buscarAdy
 * Descripción:         Método que retorna true si existe vértice adyacente
 * @param aux           variable de tipo nodo que representa el nodo origen
 * @param ad            variable de tipo int que representa el vertice final
 * @return              variable de tipo bool, true si existe vértice adyacente
 */
bool Lista::buscarAdy(Nodo aux, int ad) {
    NodoArco *temp = aux.getPuntero();
    while(temp){
        if(ad == temp->getAdy()){
            return true;
        }
        temp=temp->getSiguiente();
    }
    return false;
}
/**
 * Método:              buscarAdy
 * Descripción:         Método que retorna el costo del arco
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @return              variable de tipo int que representa el costo del arco
 */
int Lista::costoArco(int i, int f) {
    Nodo *nodo = buscarv(i);
    return buscarCosto(*nodo, f);
}
/**
 * Método:              buscarCosto
 * Descripción:         Método que retorna el costo del archo
 * @param aux           variable de tipo nodo que representa el nodo origen
 * @param ad            variable de tipo int que representa el vertice final
 * @return              variable de tipo int que representa el costo del arco.
 */
int Lista::buscarCosto(Nodo aux, int ad) {
    NodoArco *temp = aux.getPuntero();
    while (temp) {
        if (ad == temp->getAdy()) {
            return temp->getPeso();
        }
        temp = temp->getSiguiente();//igualamos nuestro puntero para que verifique todos los valores.
    }
    return 999;
}