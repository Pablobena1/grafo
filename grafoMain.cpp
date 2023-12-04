#include <iostream>
#include "grafoN.h"

using namespace std;

int main() {

    //declaracion de objeto
    Grafo<string> grafo;

    //carga de archivo
    grafo.cargarDesdeArchivo("entrada.txt");

    //despliegue de informacion
    cout << "Recorrido en anchura:" << endl;
    grafo.recorridoAnchura();
    cout << endl;

    cout << "Recorrido en profundidad:" << endl;
    grafo.recorridoProfundidad();
    cout << endl;


    //fin
    return 0;
}
