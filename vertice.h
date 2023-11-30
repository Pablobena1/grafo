#include "Nodo.h"
#include "ListaEncadenada.h"
#include <iostream>

using namespace std; 

// DefiniciÃ³n de la clase Lista Encadenada
template <typename T>
class vertice
{
public:
    vertice();
    vertice(T e);  
    void asignaInformacion(T info);
    void asignaEstado(int edo);
    T traeInformacion();
    int traeEstado();
    ListaEncadenada<int> traeListaAdyacencia();



private:       
    T informacion;
    ListaEncadenada<int> listaAdyacencia;
    int estado;
};

template <typename T>
vertice<T>::vertice()
{
    estado = 0;
}


template <typename T>
vertice<T>::vertice(T e)
{
    informacion = e;
    estado = 0;
}


template <typename T>
void vertice<T>::asignaInformacion(T info)
{
    informacion = info;
}

template <typename T>
void vertice<T>::asignaEstado(int edo)
{
    estado = edo;
}

template <typename T>
T vertice<T>::traeInformacion()
{
    return informacion;
}

template <typename T>
int vertice<T>::traeEstado()
{
    return estado;
}

template <typename T>
ListaEncadenada<int> vertice<T>::traeListaAdyacencia()
{
    return listaAdyacencia;
}

