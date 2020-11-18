//
// Created by Mario Martinez on 17/11/20.
//

#include "Lista.h"


Lista::Lista() {
    setPrimero(nullptr);
}

Nodo *Lista::getPrimero() const {
    return primero;
}

void Lista::setPrimero(Nodo *primero) {
    Lista::primero = primero;
}

void Lista::Insertarv(int v) {
    Nodo *anterior;   //creamos un nuevo puntero
    if (ListavVacia()) { // Si la lista está vacía
        setPrimero(new Nodo(v)); //creamos un nuevo nodo
    } else { if(v <= getPrimero()->getVertice()){ //si el valor a insertar es menor que el
            setPrimero(new Nodo(v));       //se inserta el nodo antes del primer dato de la lista
        } else { //en caso contrario se busca el nodo que tenga un dato menor a valor
            anterior = getPrimero(); // Avanzamos hasta que el siguiente tenga un valor mayor que valor
            while ( (anterior->getSiguiente()) && (anterior->getSiguiente()->getVertice() <= v)){
                anterior = anterior->getSiguiente(); }
            // Creamos un nuevo nodo después del nodo anterior, y cuyo siguiente
            // es el siguiente del anterior
            anterior->setSiguiente(new Nodo(v));
        }
        //función para insertar los datos a nuestro grafo
    }
}

bool Lista::ListavVacia() { //función booleana.
    return getPrimero() == nullptr; //verificamos si nuestro grafo esta vacio.
    //función para verificar si nuestro grafo tiene vertices o nodos.
}

Nodo *Lista::Buscarv(int v) { //función para buscar valores dentro de nuestro grafo
    int z;
    Nodo *indice;
    Nodo *n; //creamos un nuevo nodo e igualamos a la varible n a NULL
    indice = getPrimero(); //igualamos nuestro
    while(indice != nullptr){ // se recorre la lista  hasta encontrar el valor buscado
        if(v == indice->getVertice()){
            return indice; // al encontar el valor  lo retorna
        }
        indice = indice->getSiguiente(); //igualamos nuestros nodos para que verifiquen nuestros datos
    }
    cout<<"\n\n\tEL VALOR BUSCADO NO ESTA EN EL GRAFO";
    return n; // si el valor buscado no esta en la lista retorna nulo
}

bool Lista::listavexiste(int i, int f) { //función booleana
//    if(Buscarv(i) != nullptr && Buscarv(f) != nullptr){ //sentencia if.
//        return true; //retornamos verdadero o 1
//    } else{ //sino
//        return false; //retornamos falso o 0.
//    }
    return (Buscarv(i) != nullptr && Buscarv(f) != nullptr);
// función para verificar si nuestro grafo tiene arcos.
}

void Lista::creararco(int i, int f, int peso) { //función para crear un nuevo arco
    Nodo *pos; // creamos un nuevo puntero
    pos = getPrimero();
    if(listavexiste(i,f)){
        while(pos != nullptr){ // se recorre la lista  hasta encontrar el valor buscado
            if(i == pos->getVertice() ){
                if(pos->getPuntero() == nullptr){	//sentencia if para verificar
                    pos->setPuntero(new NodoArco(f, peso)); //creamos un nuevo constructor
                } else {
                    NodoArco *temp = pos->getPuntero(); //creamos un nuevo puntero y lo igualamos
                    while(temp->getSiguiente() != nullptr) { //ciclo mientras
                        temp = temp->getSiguiente(); //guardamos los datos.
                    }
                    temp->setSiguiente(new NodoArco(f, peso)); //creamos un nuevo constructor
                    temp = nullptr; //lo igualamos a NULL
                    delete temp; //eliminamos el
                }
            }
            pos = pos->getSiguiente();//guerdamos los datos.
        }
    }
//terminamos nuestra función para crear los arcos  de nuestro grafo.
}

void Lista::CrearMatriz() { //función para crear nuestra matriz adyacente.
    Nodo *nodo = getPrimero(), *nodotemp; //creamos un nuevo puntero y lo igualamos.
    int i,j,inicio,fin; //creamos nuestras variables enteras.
    int cant = CantidadVertices(); //creamos un varibale entera y la igualamos a nuestra función cantidad de vertices.
    for(i=0;i<cant;i++){ //ciclo for
        nodotemp = getPrimero(); //igualamos nuestros punteros.
        for(j = 0; j < cant; j++){ //ciclos for
            //guardamos en la matriz creada anteriormente los datos de nuestra función existe arco.
            MatrizAdyacente[i][j] = ExisteArco(nodo->getVertice(),nodotemp->getVertice());
            nodotemp = nodotemp->getSiguiente(); //igualamos nuestros punteros para que verifiquen todos los datos.
        }
        nodo=nodo->getSiguiente();//igualamos nuestros punteros para que verifiquen todos los datos.
    }
    delete nodo; //eliminamos nodo  al terminar los ciclos for
    delete nodotemp;  //eliminamos nodotemp al terminar los ciclos for.

}

string Lista::mostrarmatriz() { //función para mostrar nuestra matriz adyacente.
    string msg;
    int i,j,cant; //creamos varibales enteras
    Nodo *nodo = getPrimero(); //creamos un nuevo puntero.
    cant = CantidadVertices(); //igulamos  la varibale creada anteriormente a la cantidad de vertices.
    msg =+ "   ";
//    cout<<"   "; //espacios
    for(i=0;i<cant;i++){ //ciclo for.
        msg += "\t" + to_string(nodo->getVertice()) + " ";
//        cout<<"\t"<<nodo->getVertice()<<" "; //mostramos los nodos o vertices del grafo.
        nodo=nodo->getSiguiente(); //igualamos los punteros para que muestre todos los vertices
    }
    nodo = getPrimero(); //igualamos los punteros
    msg += "\n";
//    cout<<"\n\n"; //saltos de linea.
    for( i = 0;i < cant; i++){ //ciclo for.
//        cout << nodo->getVertice(); //mostramos los vertices de nuestro grafo.
        msg += to_string(nodo->getVertice());
        for(j = 0; j < cant; j++){ //ciclo for
//            cout << "\t" << MatrizAdyacente[i][j] << " "; //mostramos los datos guardados en la matriz.
            msg += "\t" + to_string(MatrizAdyacente[i][j]);
        }
        nodo = nodo->getSiguiente(); //igualamos los punteros para que muestre todos los datos.
        msg += "\n";
//        cout<<"\n"; //salto de linea.
    }
    return msg;
}

int Lista::CantidadVertices() { //función para contar nuestro vertices o nodos
    Nodo *nodo = getPrimero(); //creamos un nuevo nodo y lo igualamos a otro.
    int i=0;//creamo una nueva variable entera y la igualamos a 0
    while(nodo != nullptr){//ciclo mientras, si nuestro nodo es distinto de NULL
        i++;//le sumamos 1 a nuestra variable.
        nodo=nodo->getSiguiente();  //igualamos nuestro nodos, para poder sumar la cantidad de los mismos
    }
    return i; //retornamos i.
}

int Lista::ExisteArco(int i, int f) { //función para poder realizar la matriz adyacente
    Nodo *nodo; //creamos un nuevo nodo.
    int a = 1;//creamos una variable entera, y la inicializamos en 1
    nodo = Buscarv(i);//igualamos nuestro nodo a la función buscar.
    if(nodo){ //sentencia if, utilizando el nodo creado.
        if(BuscarAdy(*nodo,f)){ //sentencia if, llamamos a nuestra función booleana.
            return a; //retornamos a
        }else{
            return a = 0; //retornamos a
        }
    }
}

bool Lista::BuscarAdy(Nodo aux, int ad) { //función booleana para poder realizar la matriz adyacente
    NodoArco *temp = aux.getPuntero(); //creamos un nuevo puntero.
    bool a;  //creamos un varible de tipo boolena.
    while(temp){ //ciclo while o mientras.
        if(ad == temp->getAdy()){ //sentencia if.
            return a = true;} //retornamos a verdadero.
        temp=temp->getSiguiente();//igualamos nuestro puntero para que verifique todos los valores.
    }
    return a=false;// sino retornamos a falso
}
