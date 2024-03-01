#include "persona.h"
#include "sstring.h"

// Constructor que inicializa el objeto cliente con nombre y c�dula
persona::persona(string nom, string ape) : nombre(nom), apellido(ape) {

}

// Constructor de copia que crea un nuevo objeto cliente a partir de otro
persona::persona(const persona& orig) {
    this->nombre = orig.getNombre();
    this->apellido = orig.getApellido();
}

// Destructor por defecto
persona::~persona() {
}

// Constructor que carga un cliente desde un archivo utilizando la deserializaci�n
persona::persona(ifstream& entrada) {
    deserialize(entrada, this);
}

// M�todo que guarda la informaci�n del cliente en un archivo mediante la serializaci�n
bool persona::guardar(ofstream& salida) {
    return serialize(salida, (persona*)this);
}

// M�todo que realiza la deserializaci�n de un cliente desde un archivo
void persona::deserialize(ifstream& entrada, persona* p) {
    p->apellido = sstring::deserialize(entrada);
    p->nombre = sstring::deserialize(entrada);

    if (!entrada.good())
        throw - 1;
}

// M�todo que realiza la serializaci�n (guardado) de la informaci�n del cliente en un archivo
bool persona::serialize(ofstream& salida, persona* p) {
    sstring::serialize(salida, p->apellido);
    sstring::serialize(salida, p->nombre);
    return salida.good();
}

// M�todo para establecer el nombre del cliente
void persona::setNombre(string n) {
    nombre = n;
}

// M�todo para establecer la c�dula del cliente
void persona::setApellido(string n) {
    apellido = n;
}

// M�todo para obtener el nombre del cliente
string persona::getNombre() const {
    return this->nombre;
}

// M�todo para obtener la c�dula del cliente
string persona::getApellido() const {
    return this->apellido;
}

void persona::asignarLibro(libro* li) {
    libroAsignado = li;
}

// M�todo que devuelve una representaci�n en cadena de la informaci�n del cliente
string persona::toString() const {
    stringstream r;
    r << "Nombre: " << this->getNombre() << endl;
    
    r << "Apellido: " << this->getApellido() << endl;
    
    return r.str();
}
