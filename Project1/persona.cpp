#include "persona.h"
#include "sstring.h"

// Constructor que inicializa el objeto cliente con nombre y cédula
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

// Constructor que carga un cliente desde un archivo utilizando la deserialización
persona::persona(ifstream& entrada) {
    deserialize(entrada, this);
}

// Método que guarda la información del cliente en un archivo mediante la serialización
bool persona::guardar(ofstream& salida) {
    return serialize(salida, (persona*)this);
}

// Método que realiza la deserialización de un cliente desde un archivo
void persona::deserialize(ifstream& entrada, persona* p) {
    p->apellido = sstring::deserialize(entrada);
    p->nombre = sstring::deserialize(entrada);

    if (!entrada.good())
        throw - 1;
}

// Método que realiza la serialización (guardado) de la información del cliente en un archivo
bool persona::serialize(ofstream& salida, persona* p) {
    sstring::serialize(salida, p->apellido);
    sstring::serialize(salida, p->nombre);
    return salida.good();
}

// Método para establecer el nombre del cliente
void persona::setNombre(string n) {
    nombre = n;
}

// Método para establecer la cédula del cliente
void persona::setApellido(string n) {
    apellido = n;
}

// Método para obtener el nombre del cliente
string persona::getNombre() const {
    return this->nombre;
}

// Método para obtener la cédula del cliente
string persona::getApellido() const {
    return this->apellido;
}

void persona::asignarLibro(libro* li) {
    libroAsignado = li;
}

// Método que devuelve una representación en cadena de la información del cliente
string persona::toString() const {
    stringstream r;
    r << "Nombre: " << this->getNombre() << endl;
    
    r << "Apellido: " << this->getApellido() << endl;
    
    return r.str();
}
