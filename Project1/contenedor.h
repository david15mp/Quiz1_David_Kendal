#ifndef CONTENEDOR_H
#define	CONTENEDOR_H

#include "std.h"
#include "iterador.h"

// Declaraci�n de la plantilla de clase contenedor
template <class T>
class contenedor {
public:
    // Constructor por defecto
    contenedor();

    // Destructor virtual
    virtual ~contenedor();

    // M�todo virtual puro para verificar si el contenedor est� vac�o
    virtual bool vacio() const = 0;

    // M�todo virtual puro para obtener el n�mero de elementos en el contenedor
    virtual int numElementos() const = 0;

    // M�todo virtual puro para agregar un elemento al contenedor
    virtual void agregar(T*) = 0;

    // M�todo virtual puro para eliminar un elemento del contenedor
    virtual void eliminar() = 0;

    // M�todo virtual puro para agregar un elemento al inicio del contenedor
    virtual void agregarInicio(T*) = 0;

    // M�todo virtual puro para agregar un elemento al final del contenedor
    virtual void agregarFinal(T*) = 0;

    // M�todo virtual puro para obtener un iterador del contenedor
    virtual iterador<T>* obtenerIterador() const = 0;

    // M�todo virtual puro para obtener una representaci�n en cadena del contenedor
    virtual string toString() const = 0;
};

// Implementaci�n del constructor por defecto de la clase contenedor
template<class T>
contenedor<T>::contenedor() {
}

// Implementaci�n del destructor virtual de la clase contenedor
template<class T>
contenedor<T>::~contenedor() {
}

#endif	/* CONTENEDOR_H */
