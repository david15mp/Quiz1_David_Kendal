#include "listaLibros.h"


// Constructor por defecto de la lista de clientes
listaLibros::listaLibros() : lista<libro>() {
}

// Destructor de la lista de clientes
listaLibros::~listaLibros() {
}

// Constructor de la lista de clientes que recibe un archivo de entrada
listaLibros::listaLibros(ifstream& entrada) : lista<libro>() {
    deserialize(entrada, this);
}

// Método para guardar la lista de clientes en un archivo de salida
bool listaLibros::guardar(ofstream& salida) {
    return serialize(salida, (listaLibros*)this);
}

// Este método deserializa (lee) la información de los clientes desde el archivo de entrada
// y utiliza el constructor de cliente para crear los objetos correspondientes.
void listaLibros::deserialize(ifstream& entrada, listaLibros* g) {
    int cantLi = -1;
    int i = 0;
    entrada.read((char*)&cantLi, sizeof(cantLi));

    while (entrada.good() && i < cantLi) {
        try {
            libro* li = NULL;

            if (!entrada.good())
                throw - 1;

            li = new libro(entrada);

            if (li != NULL)
                g->agregarFinal(li);
        }
        catch (int) {
            cout << "Ocurrió un error de lectura en el archivo" << endl;
        }
        i++;
    }
}

// Método para buscar un cliente en la lista por su número de cédula
libro* listaLibros::buscarLibro(string id) const {
    iterador<libro>* i = this->obtenerIterador();
    libro* li = NULL;
    while (i->masElementos()) {
        li = (libro*)i->proximoElemento();

        if (li->getId() == id) {
            return li;
        }
    }
    return NULL;
}

// Método que retorna el total de clientes en la lista
int listaLibros::totalLibros() const {
    int cantLibros = 0;
    iterador<libro>* i = this->obtenerIterador();
    while (i->masElementos()) {
        libro* li = (libro*)i->proximoElemento();

        if (li != NULL) {
            cantLibros++;
        }
    }
    return cantLibros;
}

// Método para serializar (guardar) la información de cada cliente en el archivo de salida
bool listaLibros::serialize(ofstream& salida, listaLibros* g) {
    int cantLibros = 0;
    iterador<libro>* i = g->obtenerIterador();
    cantLibros = g->totalLibros();

    salida.write((char*)&cantLibros, sizeof(cantLibros));

    while (i->masElementos() && salida.good()) {
        libro* li = (libro*)i->proximoElemento();
        li->guardar(salida);
    }
    return salida.good();
}

// Método para obtener una representación en formato de cadena de la lista de clientes
string listaLibros::toString() const {
    stringstream r;
    iterador<libro>* i = this->obtenerIterador();
    while (i->masElementos()) {
        libro* li = (libro*)i->proximoElemento();
        r << li->toString() << "\n";
    }
    return r.str();
}
