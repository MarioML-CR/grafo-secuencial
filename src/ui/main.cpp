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
             "01 Crear arco manual\n" <<
             "02 Crear arco default\n" <<
             "03 Mostrar matriz adyacente\n" <<
             "04 Mostrar matriz de Costos\n" <<
             "05 Buscar vértice\n" <<
             "06 Salir\n";
        cin >> valor;
        opcion = validar.ingresarInt(valor);
        procesarMenu(opcion, salir);
    } while (!salir);
}
void procesarMenu(int & pOpcion, bool & salir) {
    switch (pOpcion) {
        case 1:
            crearArcoManual();
            break;
        case 2:
            crearArcoDefault();
            break;
        case 3:
            mostrarMatrizAd();
            break;
        case 4:
            mostrarMatrizCostos();
            break;
        case 5:
            buscarVertice();
            break;
        case 6:
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
    for (int i = 1; i <= 8; ++i) {
        gestor.insertVertice(i);
    }
//    gestor.insertVertice(5);
//    gestor.insertVertice(8);
//    gestor.insertVertice(3);
//    gestor.insertVertice(2);
//    gestor.insertVertice(4);
//    gestor.insertVertice(6);
//    gestor.insertVertice(7);
//    gestor.insertVertice(1);
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
        gestor.crearArco(verticeOrigen,verticeDestino,peso);
        gestor.crearArco(verticeDestino,verticeOrigen,peso);
        salir = ingresarNum(msg4);
    }
    gestor.crearMatrizAdyacente();
    gestor.crearMatrizCostos();
}
void crearArcoDefault(){
    gestor.crearArco(1,2,1);
    gestor.crearArco(2,1,1); // 1-2
    gestor.crearArco(1,4,3);
    gestor.crearArco(4,1,3); // 1-4
    gestor.crearArco(2,3,5);
    gestor.crearArco(3,2,5); // 2-3
    gestor.crearArco(2,5,2);
    gestor.crearArco(5,2,2); // 2-5
    gestor.crearArco(3,5,2);
    gestor.crearArco(5,3,2); // 3-5
    gestor.crearArco(3,6,3);
    gestor.crearArco(6,3,3); // 3-6
    gestor.crearArco(4,5,1);
    gestor.crearArco(5,4,1); // 4-5
    gestor.crearArco(4,7,5);
    gestor.crearArco(7,4,5); // 4-7
    gestor.crearArco(5,8,4);
    gestor.crearArco(8,5,4); // 5-8
    gestor.crearArco(7,8,2);
    gestor.crearArco(8,7,2); // 7-8
    gestor.crearArco(6,8,1);
    gestor.crearArco(8,6,1); // 6-8
    gestor.crearMatrizAdyacente();
    gestor.crearMatrizCostos();
}
void mostrarMatrizAd(){
    string matriz = gestor.mostrarMartrizAdyacente();
    cout << matriz << endl;
}
void buscarVertice(){
    string msg = "Ingrese el vértice que desea buscar\n";
    int vertice = ingresarNum(msg);
    string msg2 = gestor.buscarVertice(vertice);
    cout << msg2 << endl;
}
void mostrarMatrizCostos(){
    string matriz = gestor.mostrarMartrizCostos();
    cout << matriz << endl;
}