//  Olivia Maricela Barrón Cano
//  Creación: 19/septiembre/2023
//  Última modificación: 6/octubre/2023

#ifndef LISTAENCADENADA_H
#define LISTAENCADENADA_H

# include <iostream>
# include "nodo.h"

using namespace std;

// Definición de la clase Lista Encadenada
template <class T>
class ListaEncadenada 
{
public:
    ListaEncadenada();            // constructor
    ~ListaEncadenada();           // destructor
    bool estaVacia();
    bool insertarElementoInicio(const T &info);
    bool insertarElementoFinal(const T &info);
    int tamanio();
    int encontrarPosicionElemento(const T &info);
    void borrarElementoInicio();
    void borrarElementoFinal();
    void desplegarLista(ostream &out);
    void borrarElemento(int posicion);
    T traerDatosInicio();
    T* traerDatosPosicion(int posicion);

private:       
    Nodo<T>* inicio, *final;        // ptrs a objeto inicial y final de la lista

};

template <class T>
ListaEncadenada<T>::ListaEncadenada()
{
    inicio = final = nullptr;
}

template <class T>
ListaEncadenada<T>::~ListaEncadenada()
{
    Nodo<T>* auxiliar;

    while (inicio != nullptr)
    {
        auxiliar = inicio->siguiente;
        delete inicio;
        inicio = auxiliar;
    }

}

template <class T>
bool ListaEncadenada<T>::estaVacia()
{
    return inicio == nullptr;
}

template <class T>
bool ListaEncadenada<T>::insertarElementoInicio(const T &info)
{
    Nodo<T>* nuevo;
    bool bandera;

    nuevo = new Nodo<T>(info);
    bandera = (nuevo != nullptr);

    if (bandera)
    {
        if (inicio == nullptr)
        {
          inicio = nuevo;
          final = nuevo;
        }
        else
        {
            nuevo->siguiente = inicio;
            inicio = nuevo;
        }
    }

    return bandera;
}

template <class T>
bool ListaEncadenada<T>::insertarElementoFinal(const T &info)
{
    Nodo<T>* nuevo;
    bool bandera;

    nuevo = new Nodo<T>(info);
    bandera = (nuevo != nullptr);

    if (bandera)
    {
        if (inicio == nullptr)
        { 
          inicio = nuevo;
          final = nuevo;
        }
        else
        {
           final->siguiente = nuevo;
           final = nuevo;
        }
    }

    return bandera;
}

template <class T>
void ListaEncadenada<T>::desplegarLista(ostream &out)
{
    Nodo<T>* auxiliar = inicio;
    int indice = 0;

    if (inicio != nullptr)
        do
        {
            indice = indice + 1;
            out << "La informacion del nodo "<<indice<<" es "<<auxiliar->informacion<<endl;
            auxiliar = auxiliar ->siguiente;
        }while(auxiliar != nullptr);
    else
        out << "La lista esta vacia"<<endl;
    
}

template <class T>
int ListaEncadenada<T>::tamanio()
{
    Nodo<T>* auxiliar = inicio;
    int indice = 0;

    if (inicio != nullptr)
        do
        {   
            indice = indice + 1;
            auxiliar = auxiliar ->siguiente;
        }while(auxiliar != nullptr);
    
    return indice;
    
}

template <class T>
void ListaEncadenada<T>::borrarElementoFinal()
{
    Nodo<T> *auxiliar = inicio;
    
    if (inicio != nullptr)
    {
        if (inicio->siguiente == nullptr)
        {  
            delete inicio;
            inicio = nullptr;
            final = nullptr;
        }
        else
        {   while( auxiliar->siguiente != final)
                auxiliar = auxiliar->siguiente;
            delete auxiliar->siguiente;
            auxiliar->siguiente = nullptr;
            final = auxiliar;
        }
    }

}

template <class T>    
int ListaEncadenada<T>::encontrarPosicionElemento(const T &info)
{
    Nodo<T>* auxiliar = inicio;
    int indice = 1;

 
    while ( (auxiliar != nullptr) and (auxiliar->informacion != info))
    {   
        indice = indice + 1;
        auxiliar = auxiliar ->siguiente;
    };

    if (auxiliar == nullptr)
        indice = 0;

    return indice;
 
}

template <class T>  
void ListaEncadenada<T>::borrarElementoInicio()
{
  Nodo<T>* auxiliar;

  if (inicio != nullptr)
  {
    auxiliar = inicio -> siguiente;
    delete inicio;
    inicio = auxiliar;
    if (inicio == nullptr)
     final = nullptr;
  }
}

template <class T>     
T ListaEncadenada<T>::traerDatosInicio()
{
  Nodo<T>* auxiliar;

  if (inicio != nullptr)
    return inicio -> informacion;
  else
    return T();
}

template <class T>     
T* ListaEncadenada<T>::traerDatosPosicion(int posicion)
{
  Nodo<T>* auxiliar  = inicio;

  if (posicion == 1)
    return &(inicio -> informacion);
  else if (posicion <= tamanio())
  {
    for (int i=1; i<tamanio(); i++)
        auxiliar = &(auxiliar ->siguiente);
    return auxiliar ->informacion;

  }
  else
    return nullptr;
}

template <class T>     
void ListaEncadenada<T>::borrarElemento(int posicion)
{
  Nodo<T>* auxiliar  = inicio;
  Nodo<T>* anterior = nullptr;
  int tamanio = this->tamanio();

  if (posicion == 1)
  {
    inicio = auxiliar->siguiente;
    delete auxiliar;
  }
  else if (posicion <= tamanio)
  {
    for (int i=1; i<posicion; i++)
    {  
        anterior = auxiliar;
        auxiliar = auxiliar ->siguiente;
    }
    anterior->siguiente = auxiliar->siguiente;
    delete auxiliar;
    if (posicion == tamanio)
        final = anterior;
  }     
}



#endif // LISTAENCADENADA_H