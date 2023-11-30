
#include "ListaEncadenada.h"
#include <iostream>
#include <string>
#include <fstream>
#include "vertice.h"
#include "nodi.h"

using namespace std; 

template <class T>
class Grafo
{
    public:
        bool insertarVertice(T info);
        bool insertarArco(int origen, int destino);
        bool borraVertice(int posicion);
        bool borraArco(int origen, int posicion);
        void recorridoAnchura();
        void recorridoProfundidad();
        void despliegaInfo();
        void cargarDesdeArchivo(string nombreArchivo);
};

template <class T>
bool Grafo<T>::insertarVertice(T info)
{
    Nodo<T>* nuevo;
    bool bandera;

    bandera->insertarElementoFinal(auxiliar);

    return bandera;
}
    
template <class T>
bool Grafo<T>::insertarArco(int origen, int destino)
{
    Vertice<T>* auxiliar;
    bool bandera;
    int tamanio;
    ListaEncadenada<int>* ady;

    tamanio = vertices.tamanio();

    if ((origen <= tamanio) && (destino <= tamanio) && (tamanio != 0))
    {
        auxiliar = vertices.traerDatosPosicion(origen);
        ady = auxiliar->traerAdyacencias();
        bandera = ady->insertarElementoFinal(destino);
    }
    else
    {
        bandera = false;
    }

    return bandera;
}


template <class T>
bool Grafo<T>::borraVertice(int posicion)
{
bool bandera;
int tamanio;

tamanio = vertices.tamanio();

if (posicion <= tamanio)
{
    bandera = true;
    vertices.borrarElemento(posicion);
}
else
{
    bandera = false;
}

return bandera;
}

template <class T>
bool Grafo<T>::borraArco(int origen, int posicion)
{
    Vertice<T>* auxiliar;
    bool bandera;
    int tamanio;
    ListaEncadenada<int>* ady;

    tamanio = vertices.tamanio();

    if ((origen <= tamanio) && (posicion <= tamanio) && (tamanio != 0))
    {
        auxiliar = vertices.traerDatosPosicion(origen);
        ady = auxiliar->traerAdyacencias();
        bandera = ady->borrarElemento(posicion);
    }
    else
    {
        bandera = false;
    }

    return bandera;
}

template <class T>
void Grafo<T>::recorridoAnchura()
{
    int 
}

template <class T>
void Grafo<T>::recorridoProfundidad()
{
    
}

int funcionDispersa(string texto) {
    int sumaAscii = 0;
    for (char c : texto) {
        sumaAscii += c;
    }
    int sumaDigitos = 6 + 2 + 1 + 3 + 8 + 8;
    return sumaAscii % sumaDigitos;
}


/*template <class T>
void Grafo<T>::cargarDesdeArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    // Leer los vértices
    while (getline(archivo, linea)) {
        // Detenerse cuando se encuentre la línea de separación
        if (linea == "-----------------------------") break;

        // Insertar el vértice en el grafo
        insertarVertice(linea);
    }

    // Leer los arcos
    while (getline(archivo, linea)) {
        // Dividir la línea en origen y destino
        int posEspacio = linea.find(' ');
        int origen = stoi(linea.substr(0, posEspacio));
        int destino = stoi(linea.substr(posEspacio + 1));

        // Insertar el arco en el grafo
        insertarArco(origen, destino);
    }

    archivo.close();
}*/


template <class T>
void Grafo<T>::cargarDesdeArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;

    // Leer el valor disperso
    getline(archivo, linea);
    int valorDisperso = funcionDispersa(linea);

    // Leer los vértices
    while (getline(archivo, linea)) {
        // Detenerse cuando se encuentre la línea de separación
        if (linea == "-----------------------------") break;

        // Decodificar la información del vértice
        T infoVertice = decodificar(linea, valorDisperso);

        // Insertar el vértice en el grafo
        insertarVertice(infoVertice);
    }

    // Leer los arcos
    while (getline(archivo, linea)) {
        // Dividir la línea en origen y destino
        int posEspacio = linea.find(' ');
        int origen = stoi(linea.substr(0, posEspacio));
        int destino = stoi(linea.substr(posEspacio + 1));

        // Insertar el arco en el grafo
        insertarArco(origen, destino);
    }

    archivo.close();
}




template <class T>
void Grafo<T>::despliegaInfo()
{
    Vertice<T>* auxiliar;
    int tamanio;
    ListaEncadenada<int>* ady;
    int tamAdy;

    tamanio = vertices.tamanio();

    for (int i = 1; i <= tamanio; i++)
    {
        auxiliar = vertices.traerDatosPosicion(i);
        cout << "Informacion del vertice " << i << ": " << auxiliar->traeInformacion() << endl;
        ady = auxiliar->traerAdyacencias();
        tamAdy = ady->tamanio();

        for (int j = 1; j <= tamAdy; j++)
        {
            cout << "Arco con vertice no " << *(ady->traerDatosPosicion(j)) << endl;
        }
    }
}


// Función de dispersión
int funcionDispersa(string texto) {
    int sumaAscii = 0;
    for (char c : texto) {
        sumaAscii += c;
    }
    int sumaDigitos = 6 + 2 + 1 + 3 + 8 + 8;
    return sumaAscii % sumaDigitos;
}

// Función de decodificación
string decodificar(string textoCodificado, int valorDisperso) {
    string textoDecodificado;
    for (char c : textoCodificado) {
        char decodificado = c - valorDisperso; // Resta el valor disperso al valor ASCII del carácter codificado
        textoDecodificado += decodificado;
    }
    return textoDecodificado;
}


