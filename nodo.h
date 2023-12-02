//  Olivia Maricela BarrÃ³n Cano
//  CreaciÃ³n: 13/octubre/2023
//  Ãšltima modificaciÃ³n: 17/Octubre/2023
//

#ifndef NODO_H
#define NODO_H

// DefiniciÃ³n de la clase nodo

template <typename T>
class Nodo
{ 

public:
    Nodo(T info);            // constructor
    void asignaInformacion(T info);
    void asignaIzquierda(Nodo* izq);
    void asignaDerecha(Nodo* der);
    T obtieneInformacion();
    Nodo* obtieneIzquierda();
    Nodo* obtieneDerecha();
    



private:
    T informacion;             // datos almacenados en este nodo
    Nodo<T>* izquierda;         // ptr al hijo izquierdo
    Nodo<T>* derecha;         // ptr al hijo derecho
};

template <class T>
Nodo<T>::Nodo(T info) 
{ 
    informacion=info; 
    izquierda = nullptr;
    derecha = nullptr;
}; 

template <class T>
void Nodo<T>::asignaInformacion(T info)
{
    informacion = info;
}
    
template <class T>
void Nodo<T>::asignaIzquierda(Nodo* izq)
{
    izquierda = izq;
}
    
template <class T>
void Nodo<T>::asignaDerecha(Nodo* der)
{
    derecha = der;
}
   
template <class T>
 T Nodo<T>::obtieneInformacion()
 {
    return informacion;
 }
    
template <class T>
Nodo<T>* Nodo<T>::obtieneIzquierda()
{
    return izquierda;
}
   
template <class T>
 Nodo<T>* Nodo<T>::obtieneDerecha()
 {
    return derecha;
 }

#endif /* NODO_H */