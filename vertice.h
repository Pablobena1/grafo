


#include "ListaEncadenada.h"
#include <iostream>


using namespace std; 

// DefiniciÃ³n de la clase Lista Encadenada
template <typename T>
class Vertice
{
public:
    Vertice();
    Vertice(T e);  
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
Vertice<T>::Vertice()
{
    estado = 0;
}


template <typename T>
Vertice<T>::Vertice(T e)
{
    informacion = e;
    estado = 0;
}


template <typename T>
void Vertice<T>::asignaInformacion(T info)
{
    informacion = info;
}

template <typename T>
void Vertice<T>::asignaEstado(int edo)
{
    estado = edo;
}

template <typename T>
T Vertice<T>::traeInformacion()
{
    return informacion;
}

template <typename T>
int Vertice<T>::traeEstado()
{
    return estado;
}

template <typename T>
ListaEncadenada<int> Vertice<T>::traeListaAdyacencia()
{
    return listaAdyacencia;
}

