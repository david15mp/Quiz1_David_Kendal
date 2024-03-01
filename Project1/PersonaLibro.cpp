#include "PersonaLibro.h"
#include "sstring.h"
#include "persona.h"
#include "libro.h"

// Constructor de la clase banco
PersonaLibro::PersonaLibro(const string& nombre, const string& apellido, const string& id, const string& titulo)
    : nombre(nombre), apellido(apellido), id(id), titulo(titulo), personas(nullptr), libros(nullptr)
{
    // Aquí puedes inicializar cualquier otra variable miembro si es necesario.
}

// Constructor de copia de la clase banco
PersonaLibro::PersonaLibro(const PersonaLibro& orig) {
    this->nombre = orig.getNombre();
    this->apellido = orig.getApellido();
    this->id = orig.getId();
    this->libros = orig.getLibros();
    this->personas = orig.getPersonas();
}

// Destructor de la clase banco
PersonaLibro::~PersonaLibro() {
    personas->eliminar(); // Se eliminan todos los clientes en la lista
    delete personas; // Se libera la memoria de la lista de clientes
    libros->eliminar();
    delete libros;
}

// Constructor de la clase banco que toma un archivo de entrada para la deserialización
PersonaLibro::PersonaLibro(ifstream& entrada) {
    deserialize(entrada, this);
}

// Método para guardar la información del banco en un archivo (serialización)
bool PersonaLibro::guardar(ofstream& salida) {
    return serialize(salida, (PersonaLibro*)this);
}

// Método que deserializa un banco desde un archivo
void PersonaLibro::deserialize(ifstream& entrada, PersonaLibro* pL) {
    pL->nombre = sstring::deserialize(entrada);
    pL->apellido = sstring::deserialize(entrada);
    pL->personas = new listaPersonas(entrada); // Se crea una nueva lista de clientes desde el archivo
    pL->libros = new listaLibros(entrada);
    if (!entrada.good())
        throw - 1; // Lanza una excepción si la lectura del archivo no es exitosa
}

// Método que serializa la información del banco y la guarda en un archivo
bool PersonaLibro::serialize(ofstream& salida, PersonaLibro* pL) {
    sstring::serialize(salida, pL->nombre);
    sstring::serialize(salida, pL->apellido);
    sstring::serialize(salida, pL->id);
    pL->personas->guardar(salida); // Se guarda la lista de clientes en el archivo
    pL->libros->guardar(salida); // Se guarda la lista de clientes en el archivo
    return salida.good();
}

// Método para agregar una persona a la lista de personas del PersonaLibro
void PersonaLibro::agregarPersona(persona* pe) {
    personas->agregarFinal(pe);
}

// Método para agregar un libro a la lista de libros del PersonaLibro
void PersonaLibro::agregarLibro(libro* li) {
    libros->agregarFinal(li);
}

void PersonaLibro::agregarPersonaLibro(string nombre, string id) {
    // Buscar la persona por su nombre y el libro por su ID
    persona* pe = personas->buscarPersona(nombre);
    libro* li = libros->buscarLibro(id);

    // Si se encuentran tanto la persona como el libro, asignar el libro a la persona
    if (pe != nullptr && li != nullptr) {
        pe->asignarLibro(li);
    }
    else {
        cout << "No se pudo encontrar la persona o el libro." << endl;
    }
}
// Método para buscar un cliente por su número de identificación en la lista de clientes del banco
persona* PersonaLibro::buscarPersonas(string nom) const {
    return personas->buscarPersona(nom);
}

libro* PersonaLibro::buscarLibros(string id) const {
    return libros->buscarLibro(id);
}

// Métodos para obtener información sobre el banco
string PersonaLibro::getNombre() const {
    return this->nombre;
}

string PersonaLibro::getApellido() const {
    return this->apellido;
}

string PersonaLibro::getId() const {
    return this->id;
}

listaPersonas* PersonaLibro::getPersonas() const {
    return this->personas;
}

listaLibros* PersonaLibro::getLibros() const {
    return this->libros;
}

string PersonaLibro::getTitulo() const {
    return this->titulo;
}
// Método que devuelve una representación en cadena de la información del banco
string PersonaLibro::toString() const {
    stringstream r;
    r << "Persona:" << endl;
    r << "Nombre: " << this->getNombre() << endl;
    r << "Apellido: " << this->getApellido() << endl;
    r << endl;
    r << "Libro:" << endl;
    r << "ID: " << this->getId() << endl;
    r << "Titulo: " << this->getTitulo() << endl;
    r << endl;
    return r.str();
}