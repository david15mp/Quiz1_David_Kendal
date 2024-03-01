#ifndef ITERADOR_H
#define	ITERADOR_H

// Definici�n de la plantilla de clase iterador
template <class T>
class iterador {
public:
    // Constructor por defecto
    iterador();
    // Destructor virtual
    virtual ~iterador();
    // M�todo virtual puro para verificar si hay m�s elementos
    virtual bool masElementos() const = 0;
    // M�todo virtual puro para obtener el pr�ximo elemento
    virtual T* proximoElemento() = 0;

};

// Implementaci�n del constructor por defecto
template<class T>
iterador<T>::iterador() {
}

// Implementaci�n del destructor
template<class T>
iterador<T>::~iterador() {
}

#endif	/* ITERADOR_H */
