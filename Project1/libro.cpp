#include "libro.h"
#include "sstring.h"

// Constructor que inicializa el objeto cliente con nombre y c�dula
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

// Constructor que carga un cliente desde un archivo utilizando la deserializaci�n
libro::libro(ifstream& entrada) {
    deserialize(entrada, this);
}

// M�todo que guarda la informaci�n del cliente en un archivo mediante la serializaci�n
bool libro::guardar(ofstream& salida) {
    return serialize(salida, (libro*)this);
}

// M�todo que realiza la deserializaci�n de un cliente desde un archivo
void libro::deserialize(ifstream& entrada, libro* l) {
    l->titulo = sstring::deserialize(entrada);
    l->id = sstring::deserialize(entrada);

    if (!entrada.good())
        throw - 1;
}

// M�todo que realiza la serializaci�n (guardado) de la informaci�n del cliente en un archivo
bool libro::serialize(ofstream& salida, libro* l) {
    sstring::serialize(salida, l->titulo);
    sstring::serialize(salida, l->id);
    return salida.good();
}

// M�todo para establecer el nombre del cliente
void libro::setTitulo(string ti) {
    titulo = ti;
}

// M�todo para establecer la c�dula del cliente
void libro::setId(string i) {
    id = i;
}

// M�todo para obtener el nombre del cliente
string libro::getTitulo() const {
    return this->titulo;
}

// M�todo para obtener la c�dula del cliente
string libro::getId() const {
    return this->id;
}

// M�todo que devuelve una representaci�n en cadena de la informaci�n del cliente
string libro::toString() const {
    stringstream r;
    r << "Titulo: " << this->getTitulo() << endl;
   
    r << "Id: " << this->getId() << endl;
    
    return r.str();
}
