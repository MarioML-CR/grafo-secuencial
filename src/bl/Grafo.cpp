//
// Created by Mario Martinez on 17/11/20.
//

#include "Grafo.h"

Grafo::Grafo(Vertice *head, Vertice *tail, int tam) : head(head), tail(tail), tam(tam) {
}

Vertice *Grafo::getHead() const {
    return head;
}

void Grafo::setHead(Vertice *head) {
    Grafo::head = head;
}

Vertice *Grafo::getTail() const {
    return tail;
}

void Grafo::setTail(Vertice *tail) {
    Grafo::tail = tail;
}

int Grafo::getTam() const {
    return tam;
}

void Grafo::setTam(int tam) {
    Grafo::tam = tam;
}

/**
 * Método:              insertarVertice
 * Descripción:         Método que permite insertar un vértice
 * @param v             variable que representa el valor de vértice
 */
void Grafo::insertarVertice(int v) {
    if (esListaVacia()) {
        setHead(new Vertice(v));
        setTail(getHead());
        setTam(getTam() + 1);
    } else {
        if(getHead()->getValor() >= v){ // inserta al inicio
            insertarAlIincio(v);
        } else if(getTail()->getValor() <= v) { // insertar al final
            insertarAlFinal(v);
        } else {
            Vertice *aux = getHead();
            do {
                if (aux->getValor() <= v && aux->getNext()->getValor() >= v){
                    Vertice *nuevo = new Vertice(v);
                    nuevo->setNext(aux->getNext());
                    aux->setNext(nuevo);
                    setTam(getTam() + 1);
                    break;
                }
                aux =aux->getNext();
            } while (aux->getNext() != nullptr);
        }
    }
}
/**
 * Método:              insertarAlIincio
 * Descripción:         Método privado que permite insertar un vértice a la lista de vértices al inicio
 * @param v             variable de tipo int que representa el valor del vértice a insertar
 */
void Grafo::insertarAlIincio(int v) {
    Vertice *nuevo = new Vertice(v);
    nuevo->setNext(getHead());
    setHead(nuevo);
    setTam(getTam() + 1);
}
/**
 * Método:              insertarAlFinal
 * Descripción:         Método privado que permite insertar un vértice a la lista de vértices al final
 * @param v             variable de tipo int que representa el valor del vértice a insertar
 */
void Grafo::insertarAlFinal(int v) {
    Vertice *nuevo = new Vertice(v);
    getTail()->setNext(nuevo);
    setTail(nuevo);
    setTam(getTam() + 1);
}

/**
 * Método:              esListaVacia
 * Descripción:         Método que permite verificar si la lista de vértices está vacía
 * @return              variable de tipo bool, true si está vacía, falso lo inverso.
 */
bool Grafo::esListaVacia() const { //función booleana.
    return getHead() == nullptr;
}
/**
 * Método:              buscarVertice
 * Descripción:         Método que permite retornar el nodo correspondiente al vértice, si
 * este no existe el nodo retornado es null
 * @param v             variable que representa el valor de vértice
 * @return              varibale de tipo nodo que representa el nodo del valor pasado por parámetro
 */
Vertice *Grafo::buscarVertice(int v) const { //función para buscar valores dentro de nuestro grafo
    Vertice *aux = getHead();
    while(aux != nullptr){
        if(v == aux->getValor()){
            return aux;
        }
        aux = aux->getNext();
    }
    return aux;
}
/**
 * Método:              existeVertice
 * Descripción:         Método que permite determinar si un vértice existe
 * @param i             variable que representa el valor de vértice
 * @return              variable de tipo bool, true = existe y false lo contrario.
 */
bool Grafo::existeVertice(int i) {
    Vertice *aux = buscarVertice(i);
    if (aux == nullptr){
        return false;
    } else {
        return true;
    }
}
/**
 * Método:              existeArco
 * Descripción:         Método que permite verificar si existen los vértices que se pasan por
 * parámetro
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @return              variable de tipo bool, false si no existen, falso lo inverso.
 */
bool Grafo::existeArco(int i, int f) const {
    return (buscarVertice(i) != nullptr && buscarVertice(f) != nullptr);
}
/**
 * Método:              crearArcoManual
 * Descripción:         Método que permite crear un arco entre los dos vértices pasados
 * por parámetro
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @param peso          variable de tipo entero que representa el peso del arco
 */
string Grafo::crearArco(int i, int f, int peso) { //función para crear un nuevo arco
    string res = "";
    if (getTam() > 0){
        if(existeVertice(i) && existeVertice(f)){
            if (!existeArco(i, f)){
                Vertice *origen = getHead();
                while(origen != nullptr){
                    if(i == origen->getValor()){
                        if(origen->getAdy() == nullptr){
                            origen->setAdy(new Arista(f, peso));
                        } else {
                            Arista *temp = origen->getAdy();
                            if (temp != nullptr) {
                                while(temp->getSiguiente() != nullptr) {
                                    temp = temp->getSiguiente();
                                }
                            }
                            temp->setSiguiente(new Arista(f, peso));
                            temp = nullptr;
                            delete temp;
                        }
                        res = "El arco " + to_string(i) + "->" + to_string(f) + ": " + to_string(peso) + " fue creado...\n";
                        break;
                    }
                    origen = origen->getNext();//guerdamos los datos.
                }
            } else {
                res = "Ya existe arco entre los vértices ingresados\n";
            }
        } else {
            res = "Uno o ambos vértices ingresados no existen...\n";
        }
    } else {
        res = "Aún no se han ingresado vértices...\n";
    }
    return res;
}
/**
 * Método:              cargarMatrizAdy
 * Descripción:         Método que permite cargar la matriz de adyacencia
 */
void Grafo::cargarMatrizAdy() {
    Vertice *nodo = getHead(), *nodotemp;
    int i, j, k;
    int cant = cantidadVertices();
    for(i = 0; i < cant; i++){
        nodotemp = getHead();
        for(j = 0; j < cant; j++){
            if (existeArco(nodo->getValor(), nodotemp->getValor())) {
                k = 1;
            } else {
                k = 0;
            }
            matrizAdyacente[i][j] = k;
            nodotemp = nodotemp->getNext();
        }
        nodo = nodo->getNext();
    }
    delete nodo;
    delete nodotemp;
}
/**
 * Método:              cargarMatrizCostos
 * Descripción:         Método que permite cargar la matriz de costos
 */
void Grafo::cargarMatrizCostos() {
    Vertice *nodo = getHead(), *nodotemp;
    int i, j;
    int cant = cantidadVertices();
    for(i = 0; i < cant; i++){
        nodotemp = getHead();
        for(j = 0; j < cant; j++){
            matrizCostos[i][j] = costoArco(nodo->getValor(), nodotemp->getValor());
            nodotemp = nodotemp->getNext();
        }
        nodo = nodo->getNext();
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
    Vertice *nodo = getHead();
    cant = cantidadVertices();
    msg =+ "   "; //espacios
    for(i=0;i<cant;i++){ //ciclo for.
        msg += "\t" + to_string(nodo->getValor()) + " ";
        nodo= nodo->getNext();
    }
    nodo = getHead();
    msg += "\n"; //saltos de linea.
    for( i = 0;i < cant; i++){ //ciclo for.
        msg += to_string(nodo->getValor()); //mostramos los vertices de nuestro grafo.
        for(j = 0; j < cant; j++){ //ciclo for
            msg += "\t" + to_string(matrizAdyacente[i][j]); //mostramos los datos guardados en la matriz.
        }
        nodo = nodo->getNext(); //igualamos los punteros para que muestre todos los datos.
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
    Vertice *nodo = getHead(); //creamos un nuevo ady.
    cant = cantidadVertices();
    msg =+ "   "; //espacios
    for(i=0;i<cant;i++){
        msg += "\t" + to_string(nodo->getValor()) + " ";
        nodo= nodo->getNext();
    }
    nodo = getHead();
    msg += "\n"; //saltos de linea.
    for( i = 0;i < cant; i++){
        msg += to_string(nodo->getValor()); //mostramos los vertices de nuestro grafo.
        for(j = 0; j < cant; j++){ //ciclo for
            msg += "\t" + to_string(matrizCostos[i][j]); //mostramos los datos guardados en la matriz.
        }
        nodo = nodo->getNext();
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
    return getTam();
}
/**
 * Método:              existeArco
 * Descripción:         Método que retorna 1 si existe arco, y 0 si no
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @return              variable de tipo int que representa si existe arco (1) o no (0)
 */
bool Grafo::existeArco(int i, int f) {
    Vertice *nodo = buscarVertice(i);
    if (nodo != nullptr){
        Arista *temp = nodo->getAdy();
        while (temp != nullptr){
            if (temp->getAdy() == f){
                return true;
            }
            temp = temp->getSiguiente();
        }
        return false;
    } else {
        return false;
    }
}

/**
 * Método:              buscarAdy
 * Descripción:         Método que retorna el costo del arco
 * @param i             variable de tipo entero que representa el vértice inical
 * @param f             variable de tipo entero que representa el vértice final
 * @return              variable de tipo int que representa el costo del arco
 */
int Grafo::costoArco(int i, int f) {
    Vertice *nodo = buscarVertice(i);
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
    while (temp != nullptr) {
        if (ad == temp->getAdy()) {
            return temp->getPeso();
        }
        temp = temp->getSiguiente();//igualamos nuestro ady para que verifique todos los valores.
    }
    return 999;
}


