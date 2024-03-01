#include "listaPersonas.h"

// Constructor por defecto de la lista de clientes
listaPersonas::listaPersonas() : lista<persona>() {
}

// Destructor de la lista de clientes
listaPersonas::~listaPersonas() {
}

// Constructor de la lista de clientes que recibe un archivo de entrada
listaPersonas::listaPersonas(ifstream& entrada) : lista<persona>() {
    deserialize(entrada, this);
}

// M�todo para guardar la lista de clientes en un archivo de salida
bool listaPersonas::guardar(ofstream& salida) {
    return serialize(salida, (listaPersonas*)this);
}

// Este m�todo deserializa (lee) la informaci�n de los clientes desde el archivo de entrada
// y utiliza el constructor de cliente para crear los objetos correspondientes.
void listaPersonas::deserialize(ifstream& entrada, listaPersonas* g) {
    int cantPe = -1;
    int i = 0;
    entrada.read((char*)&cantPe, sizeof(cantPe));

    while (entrada.good() && i < cantPe) {
        try {
            persona* pe = NULL;

            if (!entrada.good())
                throw - 1;

            pe = new persona(entrada);

            if (pe != NULL)
                g->agregarFinal(pe);
        }
        catch (int) {
            cout << "Ocurri� un error de lectura en el archivo" << endl;
        }
        i++;
    }
}

// M�todo para buscar un cliente en la lista por su n�mero de c�dula
persona* listaPersonas::buscarPersona(string nom) const {
    iterador<persona>* i = this->obtenerIterador();
    persona* pe = NULL;
    while (i->masElementos()) {
        pe = (persona*)i->proximoElemento();

        if (pe->getNombre() == nom) {
            return pe;
        }
    }
    return NULL;
}

// M�todo que retorna el total de clientes en la lista
int listaPersonas::totalPersonas() const {
    int cantPersonas = 0;
    iterador<persona>* i = this->obtenerIterador();
    while (i->masElementos()) {
        persona* pe = (persona*)i->proximoElemento();

        if (pe != NULL) {
            cantPersonas++;
        }
    }
    return cantPersonas;
}

// M�todo para serializar (guardar) la informaci�n de cada cliente en el archivo de salida
bool listaPersonas::serialize(ofstream& salida, listaPersonas* g) {
    int cantPersonas = 0;
    iterador<persona>* i = g->obtenerIterador();
    cantPersonas = g->totalPersonas();

    salida.write((char*)&cantPersonas, sizeof(cantPersonas));

    while (i->masElementos() && salida.good()) {
        persona* pe = (persona*)i->proximoElemento();
        pe->guardar(salida);
    }
    return salida.good();
}

// M�todo para obtener una representaci�n en formato de cadena de la lista de clientes
string listaPersonas::toString() const {
    stringstream r;
    iterador<persona>* i = this->obtenerIterador();
    while (i->masElementos()) {
        persona* pe = (persona*)i->proximoElemento();
        r << pe->toString() << "\n";
    }
    return r.str();
}
