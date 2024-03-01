#ifndef ITERADORLISTA_H
#define ITERADORLISTA_H

#include "std.h"
#include "iterador.h"
#include "nodo.h"

template <class T>
class iteradorLista : public iterador<T> {
public:
    // Constructor que recibe el primer nodo como par�metro
    iteradorLista(nodo<T>* primerNodo);

    // Destructor virtual
    virtual ~iteradorLista();

    // M�todo que verifica si hay m�s elementos en la lista
    virtual bool masElementos() const;

    // M�todo que devuelve el pr�ximo elemento en la lista
    virtual T* proximoElemento();

private:
    // Puntero al nodo actual en la lista
    nodo<T>* cursor;

};

template <class T>
iteradorLista<T>::iteradorLista(nodo<T>* primerNodo) : iterador<T>() {
    // Inicializa el puntero al primer nodo
    cursor = primerNodo;
}

template <class T>
bool iteradorLista<T>::masElementos() const {
    // Verifica si el cursor apunta a un nodo v�lido
    return (cursor != NULL);
}

template <class T>
T* iteradorLista<T>::proximoElemento() {
    T* r = NULL;
    // Verifica si hay m�s elementos en la lista
    if (masElementos()) {
        // Obtiene la informaci�n del nodo actual y avanza al siguiente nodo
        r = cursor->obtenerInfo();
        cursor = cursor->obtenerSiguiente();
    }
    return r;
}

template <class T>
iteradorLista<T>::~iteradorLista() {
    // No se realiza ninguna operaci�n en el destructor por el momento
}

#endif	/* ITERADORLISTA_H */
