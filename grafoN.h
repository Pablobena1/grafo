

#include <iostream>
#include <string>
#include <fstream>
#include "vertice.h"
#include "ListaEncadenada.h"
#include <algorithm>

using namespace std; 

template <class T>
class Grafo
{
    public:
        bool insertarVertice(T info);
        bool insertarArco(int origen, int destino);
        bool borraVertice(int posicion);
        bool borraArco(int origen, int posicion);
        void despliegaInfo();
        void cargarDesdeArchivo(string nombreArchivo);
        int funcionDispersa(string texto);
        string decodificar(string textoCodificado, int valorDisperso);
        void recorridoAnchura();
        void recorridoProfundidad();
        void dfs(int v, ListaEncadenada<bool>& visitado);


    private:
        ListaEncadenada<Vertice<T>*> vertice;


};

template <class T>
bool Grafo<T>::insertarVertice(T info)
{
    Nodo<T>* nuevo;
    bool bandera;
    Vertice<T>* auxiliar = new Vertice<T>(info);

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
        Vertice<T>* auxiliar = *(vertice.traerDatosPosicion(origen));
        ListaEncadenada<int>* ady = auxiliar->traerListaAdyacencia();
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
        ListaEncadenada<int>* ady = auxiliar->traerListaAdyacencia();
        bandera = ady->borrarElemento(posicion);
    }
    else
    {
        bandera = false;
    }

    return bandera;
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
        cout << "Informacion del vertice " << i << ": " << auxiliar->traerInformacion() << endl;
        ady = auxiliar->traerAdyacencia();
        tamAdy = ady->tamanio();

        for (int j = 1; j <= tamAdy; j++)
        {
            cout << "Arco con vertice no " << *(ady->traerDatosPosicion(j)) << endl;
        }
    }
}




template <class T>
void Grafo<T>::cargarDesdeArchivo(string nombreArchivo) {
    ifstream archivo(nombreArchivo);
    string linea;


    getline(archivo, linea);
    int valorDisperso = funcionDispersa(linea);

    //Leer los vertices
    while (getline(archivo, linea)) {

        if (linea == "---------------------") break;

        T infoVertice = decodificar(linea, valorDisperso);


        insertarVertice(infoVertice);
    }

    // Leer los arcos
    while (getline(archivo, linea)) {

        int posEspacio = linea.find(' ');
        string origenStr = linea.substr(0, posEspacio);
        string destinoStr = linea.substr(posEspacio + 1);
        int origen = stoi(origenStr);
        int destino = stoi(destinoStr);

        insertarArco(origen, destino);
        }
   
    archivo.close();
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
        char decodificado = c - valorDisperso;
        textoDecodificado += decodificado;
    }
    return textoDecodificado;
}



template <class T>
void Grafo<T>::recorridoAnchura()
{
    // Crear listas
    ListaEncadenada<int> lista;
    ListaEncadenada<bool> visitado;

    for (int i = 0; i <= vertice.tamanio(); i++) {
        visitado.insertarElementoFinal(false);
    }

    
    lista.insertarElementoFinal(1);
    *(visitado.traerDatosPosicion(1)) = true;

    while (!lista.estaVacia()) {
        // Tomar el próximo vértice de la lista
        int v = lista.traerDatosInicio();
        lista.borrarElementoInicio();

        // Procesar el vértice v
        Vertice<T>* verticeV = *vertice.traerDatosPosicion(v);
        cout << "Visitando el vertice " << v << ": " << verticeV->traerInformacion() << endl;

        // Agregar todos los vecinos no visitados de v a la lista
        ListaEncadenada<int>* adyacencia = verticeV->traerListaAdyacencia();
        for (int i = 1; i <= adyacencia->tamanio(); i++) {
            int w = *(adyacencia->traerDatosPosicion(i));
            if (!*(visitado.traerDatosPosicion(w))) {
                lista.insertarElementoFinal(w);
                *(visitado.traerDatosPosicion(w)) = true;
            }
        }
    }
}

template <class T>
void Grafo<T>::recorridoProfundidad()
{
    // Crear una lista para marcar los vértices visitados
    ListaEncadenada<bool> visitado;
    for (int i = 0; i <= vertice.tamanio(); i++) {
        visitado.insertarElementoFinal(false);
    }

    // Comenzar desde el vértice 1
    dfs(1, visitado);
}


// verdadera funcion de recorrido en profundidad
template <class T>
void Grafo<T>::dfs(int v, ListaEncadenada<bool>& visitado)
{
    
    *(visitado.traerDatosPosicion(v)) = true;

    
    Vertice<T>* verticeV = *vertice.traerDatosPosicion(v);
    cout << "Visitando el vertice " << v << ": " << verticeV->traerInformacion() << endl;

    
    ListaEncadenada<int>* adyacencia = verticeV->traerListaAdyacencia();
    for (int i = 1; i <= adyacencia->tamanio(); i++) {
        int w = *(adyacencia->traerDatosPosicion(i));
        if (!*(visitado.traerDatosPosicion(w))) {
            dfs(w, visitado);
        }
    }
}
