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
void crearArco();
void mostrarMatrizAd();
void buscarVertice();

int main() {
    insertVertice();
    menu();
    return 0;
}
void menu() {
    bool salir;
    string valor;
    int opcion = 0;
    do {
        cout << "\nMenú Árbol\n\nElija una opción\n" <<
             "01 Crear arco\n" <<
             "02 Mostrar matriz adyacente\n" <<
             "03 Buscar vértice\n" <<
             "04 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            crearArco();
            break;
        case 2:
            mostrarMatrizAd();
            break;
        case 3:
            buscarVertice();
            break;
        case 4:
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
    for (int i = 1; i <= 5; ++i) {
        gestor.insertVertice(i);
    }
}
void crearArco(){
//    string msg1 = "Ingrese el vértice origen\n";
//    string msg2 = "Ingrese el vértice destino\n";
//    string msg3 = "Ingrese el peso del vértice\n";
//    string msg4 = "Ingrese 0 si desea salir\n";
//    int verticeOrigen, verticeDestino, peso;
//    int salir = 1;
//    while (salir != 0) {
//        verticeOrigen = ingresarNum(msg1);
//        verticeDestino = ingresarNum(msg2);
//        peso = ingresarNum(msg3);
//        gestor.crearArco(verticeOrigen,verticeDestino,peso);
//        gestor.crearArco(verticeDestino,verticeOrigen,peso);
//        salir = ingresarNum(msg4);
//    }
    gestor.crearArco(1,2,1);
    gestor.crearArco(2,1,1);
    gestor.crearArco(1,4,2);
    gestor.crearArco(4,1,2);
    gestor.crearArco(4,3,3);
    gestor.crearArco(3,4,3);
    gestor.crearArco(3,2,4);
    gestor.crearArco(2,3,4);
    gestor.crearArco(4,5,5);
    gestor.crearArco(5,4,5);
    gestor.crearArco(5,2,6);
    gestor.crearArco(2,5,6);

}
void mostrarMatrizAd(){
    gestor.crearMatrizAdyacente();
    string matriz = gestor.mostrarMartrizAdyacente();
    cout << matriz << endl;
}
void buscarVertice(){
    string msg = "Ingrese el vértice que desea buscar\n";
    int vertice = ingresarNum(msg);
    gestor.buscarVertice(vertice);
}