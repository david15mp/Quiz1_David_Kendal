#include "std.h"
#include "persona.h"
#include "listaPersonas.h"
#include "libro.h"
#include "listaLibros.h"


class PersonaLibro
{
public:
    PersonaLibro(const string& nombre, const string& apellido, const string& id, const string& titulo);//'Nombre, Apellido, Id' <-- Relacion (case 4)
    PersonaLibro(const PersonaLibro& orig);
    virtual ~PersonaLibro();
    PersonaLibro(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, PersonaLibro*);
    static bool serialize(ofstream&, PersonaLibro*);
    virtual void agregarPersona(persona*);
    persona* buscarPersonas(string ) const;
    virtual void agregarLibro(libro*);
    libro* buscarLibros(string ) const;



    virtual string getId() const;//Libro
    virtual string getNombre() const;
    virtual string getApellido() const;
    virtual string getTitulo() const;
    virtual listaPersonas* getPersonas() const;
    virtual listaLibros* getLibros() const;
    virtual string toString() const;
    virtual void agregarPersonaLibro(string, string);
private:
    string nombre;//persona
    string apellido;//persona
    string id;//libro
    string titulo;
    listaPersonas* personas;
    listaLibros* libros;

};

