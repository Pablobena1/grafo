//  Olivia Maricela BarrÃ³n Cano
//  CreaciÃ³n: 13/octubre/2023
//  Ãšltima modificaciÃ³n: 17/Octubre/2023
//

#ifndef NODO_H
#define NODO_H

//  Olivia Maricela Barrón Cano
//  Creación: 19/septiembre/2023
//  Última modificación: 6/octubre/2023
//

// Para que reconozca que la clase amiga usa template
template <typename T> class ListaEncadenada;

// Definición de la clase nodo

template <class T>
class Nodo
{ 
    friend class ListaEncadenada<T>; // clase amiga para poder acceder directo a los atributos

public:
    Nodo(const T &e);            // constructor

private:
    T informacion;             // datos almacenados en este nodo
    Nodo<T>* siguiente;        // ptr a otro objeto del mismo tipo
};

template <class T>
Nodo<T>::Nodo(const T &e)      // Se pasa el parámetro por referencia para que no haga copia de objetos en el stack
{                              // Y se pone const porque en realidad no le vamos a cambiar el contenido al parámetro
    informacion = e; 
    siguiente = nullptr;
}; 

#endif /* NODO_H */