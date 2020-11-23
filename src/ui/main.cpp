#include <iostream>
#include "../tl/Gestor.h"
#include "utilitario/Validar.h"

using namespace std;

Gestor gestor;
Validar validar;
void menu();
void procesarMenu(int &, bool &);
int ingresarNum(string);
void insertVertice();
void crearArcoManual();
void crearArcoDefault();
void mostrarMatrizAd();
void mostrarMatrizCostos();
void exiteVertice();
void existeArco();
void cantidadVertices();
void eliminarGrafo();

int main() {
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú Árbol\n\nElija una opción\n" <<
             "01 Crear vértices automático\n" <<
             "02 Crear arco manual\n" <<
             "03 Crear arco default\n" <<
             "04 Eliminar grafo\n" <<
             "05 Mostrar matriz adyacente\n" <<
             "06 Mostrar matriz de Costos\n" <<
             "07 Mostrar número de vértices\n" <<
             "08 Existe vértice\n" <<
             "09 Existe arco\n" <<
             "10 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            insertVertice();
            break;
        case 2:
            crearArcoManual();
            break;
        case 3:
            crearArcoDefault();
            break;
        case 4:
            eliminarGrafo();
            break;
        case 5:
            mostrarMatrizAd();
            break;
        case 6:
            mostrarMatrizCostos();
            break;
        case 7:
            cantidadVertices();
            break;
        case 8:
            exiteVertice();
            break;
        case 9:
            existeArco();
            break;
        case 10:
            salir = true;
            break;
        default:
            cout << "Opción inválida\n";
    }
}
int ingresarNum(string msg){
    int num;
    string valor;
    do {
        cout << msg << endl;
        cin >> valor;
        num = validar.ingresarInt(valor);
        if (num == -1){
            cout << "El valor ingresado es incorrecto\nVuelva a intentarlo\n";
        }
    } while (num == -1);
    return num;
}
void insertVertice(){
    /*
     * Se ingresar vértices en desorden y se insertan en orden
     */
    gestor.insertVertice(5);
    gestor.insertVertice(8);
    gestor.insertVertice(3);
    gestor.insertVertice(2);
    gestor.insertVertice(4);
    gestor.insertVertice(6);
    gestor.insertVertice(7);
    gestor.insertVertice(1);
}
void crearArcoManual(){
    string msg1 = "Ingrese el vértice origen\n";
    string msg2 = "Ingrese el vértice destino\n";
    string msg3 = "Ingrese el peso del vértice\n";
    string msg4 = "Ingrese 0 si desea salir\n";
    int verticeOrigen, verticeDestino, peso;
    int salir = 1;
    while (salir != 0) {
        verticeOrigen = ingresarNum(msg1);
        verticeDestino = ingresarNum(msg2);
        peso = ingresarNum(msg3);
        cout << gestor.crearArco(verticeOrigen,verticeDestino,peso);
        salir = ingresarNum(msg4);
    }
    gestor.crearMatrizAdyacente();
    gestor.crearMatrizCostos();
}
void crearArcoDefault(){
    cout << gestor.crearArco(1,2,1);
    cout << gestor.crearArco(2,1,1); // 1-2
    cout << gestor.crearArco(1,4,3);
    cout << gestor.crearArco(4,1,3); // 1-4
    cout << gestor.crearArco(2,3,5);
    cout << gestor.crearArco(3,2,5); // 2-3
    cout << gestor.crearArco(2,5,2);
    cout << gestor.crearArco(5,2,2); // 2-5
    cout << gestor.crearArco(3,5,2);
    cout << gestor.crearArco(5,3,2); // 3-5
    cout << gestor.crearArco(3,6,3);
    cout << gestor.crearArco(6,3,3); // 3-6
    cout << gestor.crearArco(4,5,1);
    cout << gestor.crearArco(5,4,1); // 4-5
    cout << gestor.crearArco(4,7,5);
    cout << gestor.crearArco(7,4,5); // 4-7
    cout << gestor.crearArco(5,8,4);
    cout << gestor.crearArco(8,5,4); // 5-8
    cout << gestor.crearArco(7,8,2);
    cout << gestor.crearArco(8,7,2); // 7-8
    cout << gestor.crearArco(6,8,1);
    cout << gestor.crearArco(8,6,1); // 6-8
    gestor.crearMatrizAdyacente();
    gestor.crearMatrizCostos();
}
void mostrarMatrizAd(){
    if (gestor.cantidadVertices() > 0){
        string matriz = gestor.mostrarMartrizAdyacente();
        cout << matriz << endl;
    } else {
        cout << "No existe grafo" << endl;
    }

}
void exiteVertice(){
    if (gestor.cantidadVertices() > 0) {
        string msg = "Ingrese el vértice que desea buscar\n";
        int vertice = ingresarNum(msg);
        string msg2 = gestor.existeVertice(vertice);
        cout << msg2 << endl;
    } else {
        cout << "No existe grafo" << endl;
    }

}
void mostrarMatrizCostos(){
    string matriz = gestor.mostrarMartrizCostos();
    cout << matriz << endl;
}
void cantidadVertices() {
    cout << gestor.cantidadVertices();
}
void existeArco(){
    if (gestor.cantidadVertices() > 0){
        string msg = "Ingrese el vértice origen\n";
        int origen = ingresarNum(msg);
        msg = "Ingrese el vértice destino\n";
        int destino = ingresarNum(msg);
        msg = gestor.existeArco(origen, destino);
        cout << msg << endl;
    } else {
        cout << "No existe grafo" << endl;
    }

}
void eliminarGrafo(){
    if (gestor.cantidadVertices() > 0){
        cout << gestor.eliminarGrafo() << endl;
    } else {
        cout << "No existe grafo" << endl;
    }
}