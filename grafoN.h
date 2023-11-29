
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