#ifndef NODO_H
#define NODO_H

template <class T>
class nodo {
public:
    // Constructor que inicializa un nodo con la informaci�n dada y el siguiente nodo en la secuencia.
    nodo(T* nuevaInfo, nodo<T>* siguiente);

    // Destructor que se encarga de liberar los recursos asociados al nodo.
    virtual ~nodo();

    // M�todo para obtener la informaci�n almacenada en el nodo.
    virtual T* obtenerInfo() const;

    // M�todo para obtener el siguiente nodo en la secuencia.
    virtual nodo<T>* obtenerSiguiente() const;

    // M�todo para establecer el siguiente nodo en la secuencia.
    virtual void fijarSiguiente(nodo<T>* siguiente);

private:
    // Puntero a la informaci�n almacenada en el nodo.
    T* info;

    // Puntero al siguiente nodo en la secuencia.
    nodo<T>* siguiente;
};

// Implementaci�n del constructor de la clase nodo.
template <class T>
nodo<T>::nodo(T* nuevaInfo, nodo<T>* siguiente) {
    info = nuevaInfo;
    this->siguiente = siguiente;
}

// Implementaci�n del destructor de la clase nodo.
template <class T>
nodo<T>::~nodo() {
    // El destructor est� vac�o ya que no hay recursos adicionales para liberar.
}

// Implementaci�n del m�todo para obtener la informaci�n almacenada en el nodo.
template <class T>
T* nodo<T>::obtenerInfo() const {
    return info;
}

// Implementaci�n del m�todo para obtener el siguiente nodo en la secuencia.
template <class T>
nodo<T>* nodo<T>::obtenerSiguiente() const {
    return siguiente;
}

// Implementaci�n del m�todo para establecer el siguiente nodo en la secuencia.
template <class T>
void nodo<T>::fijarSiguiente(nodo<T>* siguiente) {
    this->siguiente = siguiente;
}

#endif	/* NODO_H */
