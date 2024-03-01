#pragma once
#include "std.h"
#include "libro.h"
class persona
{
private:
    string nombre;
    string apellido;
    libro* libroAsignado;

public:
    persona(string = "", string = "");
    persona(const persona& orig);
    virtual ~persona();
    persona(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, persona*);
    static bool serialize(ofstream&, persona*);

    virtual void setNombre(string);
    virtual void setApellido(string);
    virtual string getNombre() const;
    virtual string getApellido() const;
    virtual string toString() const;
    virtual void asignarLibro(libro* li);
};

