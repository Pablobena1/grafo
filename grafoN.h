

#include <iostream>
#include <string>
#include <fstream>
#include "vertice.h"
#include "ListaEncadenada.h"

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
        int funcionDispersa(string texto);
        string decodificar(string textoCodificado, int valorDisperso);


    private:
        ListaEncadenada<Vertice<T>*> vertice;


};

template <class T>
bool Grafo<T>::insertarVertice(T info)
{
    Nodo<T>* nuevo;
    bool bandera;
    Vertice<T>* auxiliar(info);

    bandera = vertice.insertarElementoFinal(auxiliar);

    return bandera;
}
    
template <class T>
bool Grafo<T>::insertarArco(int origen, int destino)
{
    Vertice<T>* auxiliar;
    bool bandera;
    int tamanio;
    ListaEncadenada<int>* ady;

    tamanio = vertice.tamanio();

    if ((origen <= tamanio) && (destino <= tamanio) && (tamanio != 0))
    {
        auxiliar = vertice.traerDatosPosicion(origen);
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

tamanio = vertice.tamanio();

if (posicion <= tamanio)
{
    bandera = true;
    vertice.borrarElemento(posicion);
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

    tamanio = vertice.tamanio();

    if ((origen <= tamanio) && (posicion <= tamanio) && (tamanio != 0))
    {
        auxiliar = vertice.traerDatosPosicion(origen);
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
    
}

template <class T>
void Grafo<T>::recorridoProfundidad()
{
    
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
        if (linea == "---------------------") break;

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

    tamanio = vertice.tamanio();

    for (int i = 1; i <= tamanio; i++)
    {
        auxiliar = vertice.traerDatosPosicion(i);
        cout << "Informacion del vertice " << i << ": " << auxiliar->traeInformacion() << endl;
        ady = auxiliar->traerAdyacencias();
        tamAdy = ady->tamanio();

        for (int j = 1; j <= tamAdy; j++)
        {
            cout << "Arco con vertice no " << *(ady->traerDatosPosicion(j)) << endl;
        }
    }
}

template <class T>
int Grafo<T>::funcionDispersa(string texto) {
    int sumaAscii = 0;
    for (char c : texto) {
        sumaAscii += c;
    }
    return sumaAscii % (1 + 2 + 3 + 0 + 3 + 2);
}

template <class T>
string Grafo<T>::decodificar(string textoCodificado, int valorDisperso) {
    string textoDecodificado;
    for (char c : textoCodificado) {
        char decodificado = c - valorDisperso; // Resta el valor disperso al valor ASCII del carácter codificado
        textoDecodificado += decodificado;
    }
    return textoDecodificado;
}


