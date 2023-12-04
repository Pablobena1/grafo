//  Olivia Maricela BarrÃ³n Cano
//  CreaciÃ³n: 13/octubre/2023
//  Ãšltima modificaciÃ³n: 17/Octubre/2023
//


// DefiniciÃ³n de la clase Nodi

template <typename T>
class Nodi
{ 

public:
    Nodi(T info);            // constructor
    void asignaInformacion(T info);
    void asignaIzquierda(Nodi* izq);
    void asignaDerecha(Nodi* der);
    T obtieneInformacion();
    Nodi* obtieneIzquierda();
    Nodi* obtieneDerecha();
    



private:
    T informacion;             // datos almacenados en este Nodi
    Nodi<T>* izquierda;         // ptr al hijo izquierdo
    Nodi<T>* derecha;         // ptr al hijo derecho
};

template <class T>
Nodi<T>::Nodi(T info) 
{ 
    informacion=info; 
    izquierda = nullptr;
    derecha = nullptr;
}; 

template <class T>
void Nodi<T>::asignaInformacion(T info)
{
    informacion = info;
}
    
template <class T>
void Nodi<T>::asignaIzquierda(Nodi* izq)
{
    izquierda = izq;
}
    
template <class T>
void Nodi<T>::asignaDerecha(Nodi* der)
{
    derecha = der;
}
   
template <class T>
 T Nodi<T>::obtieneInformacion()
 {
    return informacion;
 }
    
template <class T>
Nodi<T>* Nodi<T>::obtieneIzquierda()
{
    return izquierda;
}
   
template <class T>
 Nodi<T>* Nodi<T>::obtieneDerecha()
 {
    return derecha;
 }