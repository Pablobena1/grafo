


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
    T traerInformacion();
    int traerEstado();
    ListaEncadenada<int>* traerListaAdyacencia();



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
T Vertice<T>::traerInformacion()
{
    return informacion;
}

template <typename T>
int Vertice<T>::traerEstado()
{
    return estado;
}

template <typename T>
ListaEncadenada<int>* Vertice<T>::traerListaAdyacencia()
{
    return &listaAdyacencia;
}
