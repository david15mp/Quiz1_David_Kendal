#include "libro.h"
#include "sstring.h"

// Constructor que inicializa el objeto cliente con nombre y cédula
libro::libro(string ti, string i) : titulo(ti), id(i) {

}

// Constructor de copia que crea un nuevo objeto cliente a partir de otro
libro::libro(const libro& orig) {
    this->titulo = orig.getTitulo();
    this->id = orig.getId();
}

// Destructor por defecto
libro::~libro() {
}

// Constructor que carga un cliente desde un archivo utilizando la deserialización
libro::libro(ifstream& entrada) {
    deserialize(entrada, this);
}

// Método que guarda la información del cliente en un archivo mediante la serialización
bool libro::guardar(ofstream& salida) {
    return serialize(salida, (libro*)this);
}

// Método que realiza la deserialización de un cliente desde un archivo
void libro::deserialize(ifstream& entrada, libro* l) {
    l->titulo = sstring::deserialize(entrada);
    l->id = sstring::deserialize(entrada);

    if (!entrada.good())
        throw - 1;
}

// Método que realiza la serialización (guardado) de la información del cliente en un archivo
bool libro::serialize(ofstream& salida, libro* l) {
    sstring::serialize(salida, l->titulo);
    sstring::serialize(salida, l->id);
    return salida.good();
}

// Método para establecer el nombre del cliente
void libro::setTitulo(string ti) {
    titulo = ti;
}

// Método para establecer la cédula del cliente
void libro::setId(string i) {
    id = i;
}

// Método para obtener el nombre del cliente
string libro::getTitulo() const {
    return this->titulo;
}

// Método para obtener la cédula del cliente
string libro::getId() const {
    return this->id;
}

// Método que devuelve una representación en cadena de la información del cliente
string libro::toString() const {
    stringstream r;
    r << "Titulo: " << this->getTitulo() << endl;
   
    r << "Id: " << this->getId() << endl;
    
    return r.str();
}
