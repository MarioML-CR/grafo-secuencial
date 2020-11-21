//
// Created by Mario Martinez on 17/11/20.
//

#include "Grafo.h"


Grafo::Grafo(Vertice *primero) {
    setPrimero(nullptr);
}

Vertice *Grafo::getPrimero() const {
    return primero;
}

void Grafo::setPrimero(Vertice *primero) {
    Grafo::primero = primero;
}
/**
 * Método:              insertarVertice
 * Descripción:         Método que permite insertar un vértice
 * @param v             variable que representa el valor de vértice
 */
void Grafo::insertarVertice(int v) {
    Vertice *nuevo = new Vertice(v);
    if (listavVacia()) {
        setPrimero(nuevo);
    } else {
        if(v <= getPrimero()->getValor()){
            setPrimero(nuevo);
        } else {
            Vertice *anterior = getPrimero();
            while ((anterior->getSig()) && (anterior->getSig()->getValor() <= v)){
                anterior = anterior->getSig();
            }
            anterior->setSig(nuevo);
        }
    }
}
/**
 * Método:              listavVacia
 * Descripción:         Método que permite verificar si la lista de vértices está vacía
 * @return              variable de tipo bool, true si está vacía, falso lo inverso.
 */
bool Grafo::listavVacia() const { //función booleana.
    return getPrimero() == nullptr;
}
/**
 * Método:              buscarv
 * Descripción:         Método que permite retorna el nodo correspondiente al vértice, si
 * este no existe el nodo retornado es null
 * @param v             variable que representa el valor de vértice
 * @return              varibale de tipo nodo que representa el nodo del valor pasado por parámetro
 */
Vertice *Grafo::buscarv(int v) const { //función para buscar valores dentro de nuestro grafo
    int z;
    Vertice *indice;
    indice = getPrimero();
    while(indice != nullptr){
        if(v == indice->getValor()){
            return indice;
        }
        indice = indice->getSig();
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
bool Grafo::existeVertice(int i, int f) const {
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
void Grafo::crearArco(int i, int f, int peso) const { //función para crear un nuevo arco
    Vertice *pos;
    pos = getPrimero();
    if(existeVertice(i, f)){
        while(pos != nullptr){
            if(i == pos->getValor() ){
                if(pos->getAdy() == nullptr){
                    pos->setAdy(new Arista(f, peso));
                } else {
                    Arista *temp = pos->getAdy();
                    while(temp->getSiguiente() != nullptr) {
                        temp = temp->getSiguiente();
                    }
                    temp->setSiguiente(new Arista(f, peso));
                    temp = nullptr;
                    delete temp;
                }
            }
            pos = pos->getSig();//guerdamos los datos.
        }
    }
}
/**
 * Método:              cargarMatrizAdy
 * Descripción:         Método que permite cargar la matriz de adyacencia
 */
void Grafo::cargarMatrizAdy() {
    Vertice *nodo = getPrimero(), *nodotemp;
    int i, j;
    int cant = cantidadVertices();
    for(i = 0; i < cant; i++){
        nodotemp = getPrimero();
        for(j = 0; j < cant; j++){
            matrizAdyacente[i][j] = existeArco(nodo->getValor(), nodotemp->getValor());
            nodotemp = nodotemp->getSig();
        }
        nodo = nodo->getSig();
    }
    delete nodo;
    delete nodotemp;
}
/**
 * Método:              cargarMatrizCostos
 * Descripción:         Método que permite cargar la matriz de costos
 */
void Grafo::cargarMatrizCostos() {
    Vertice *nodo = getPrimero(), *nodotemp;
    int i, j;
    int cant = cantidadVertices();
    for(i = 0; i < cant; i++){
        nodotemp = getPrimero();
        for(j = 0; j < cant; j++){
            matrizCostos[i][j] = costoArco(nodo->getValor(), nodotemp->getValor());
            nodotemp = nodotemp->getSig();
        }
        nodo = nodo->getSig();
    }
    delete nodo;
    delete nodotemp;
}
/**
 * Método:              mostrarMatrizVertices
 * Descripción:         Método que permite retornar la matriz de vértices
 * @return              variable de tipo string que contiene la matriz de adyacencia.
 */
string Grafo::mostrarMatrizVertices() {
    string msg;
    int i,j,cant;
    Vertice *nodo = getPrimero();
    cant = cantidadVertices();
    msg =+ "   "; //espacios
    for(i=0;i<cant;i++){ //ciclo for.
        msg += "\t" + to_string(nodo->getValor()) + " ";
        nodo= nodo->getSig();
    }
    nodo = getPrimero();
    msg += "\n"; //saltos de linea.
    for( i = 0;i < cant; i++){ //ciclo for.
        msg += to_string(nodo->getValor()); //mostramos los vertices de nuestro grafo.
        for(j = 0; j < cant; j++){ //ciclo for
            msg += "\t" + to_string(matrizAdyacente[i][j]); //mostramos los datos guardados en la matriz.
        }
        nodo = nodo->getSig(); //igualamos los punteros para que muestre todos los datos.
        msg += "\n"; //salto de linea.
    }
    return msg;
}
/**
 * Método:              mostrarMatrizCostos
 * Descripción:         Método que permite retorna la matriz de costos
 * @return
 */
string Grafo::mostrarMatrizCostos() {
    string msg;
    int i,j,cant; //creamos varibales enteras
    Vertice *nodo = getPrimero(); //creamos un nuevo ady.
    cant = cantidadVertices();
    msg =+ "   "; //espacios
    for(i=0;i<cant;i++){
        msg += "\t" + to_string(nodo->getValor()) + " ";
        nodo= nodo->getSig();
    }
    nodo = getPrimero();
    msg += "\n"; //saltos de linea.
    for( i = 0;i < cant; i++){
        msg += to_string(nodo->getValor()); //mostramos los vertices de nuestro grafo.
        for(j = 0; j < cant; j++){ //ciclo for
            msg += "\t" + to_string(matrizCostos[i][j]); //mostramos los datos guardados en la matriz.
        }
        nodo = nodo->getSig();
        msg += "\n"; //salto de linea.
    }
    return msg;
}

/**
 * Método:              cantidadVertices
 * Descripción:         Método que permite retornar la cartidad de vértices
 * @return              variable de tipo int que representa el número de vértices.
 */
int Grafo::cantidadVertices() const {
    Vertice *nodo = getPrimero();
    int i=0;
    while(nodo != nullptr){
        i++;
        nodo = nodo->getSig();
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
int Grafo::existeArco(int i, int f) {
    Vertice *nodo;
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
 * @param ad            variable de tipo int que representa el valor final
 * @return              variable de tipo bool, true si existe vértice adyacente
 */
bool Grafo::buscarAdy(Vertice aux, int ad) {
    Arista *temp = aux.getAdy();
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
int Grafo::costoArco(int i, int f) {
    Vertice *nodo = buscarv(i);
    return buscarCosto(*nodo, f);
}
/**
 * Método:              buscarCosto
 * Descripción:         Método que retorna el costo del archo
 * @param aux           variable de tipo nodo que representa el nodo origen
 * @param ad            variable de tipo int que representa el valor final
 * @return              variable de tipo int que representa el costo del arco.
 */
int Grafo::buscarCosto(Vertice aux, int ad) {
    Arista *temp = aux.getAdy();
    while (temp) {
        if (ad == temp->getAdy()) {
            return temp->getPeso();
        }
        temp = temp->getSiguiente();//igualamos nuestro ady para que verifique todos los valores.
    }
    return 999;
}