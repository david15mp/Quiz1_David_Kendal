#pragma once
#include "std.h"
#include "lista.h"
#include "persona.h"

class listaPersonas : public lista<persona> {
public:
    listaPersonas();
    virtual ~listaPersonas();
    listaPersonas(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, listaPersonas*);
    static bool serialize(ofstream&, listaPersonas*);
    persona* buscarPersona(string) const;
    int totalPersonas() const;
    virtual string toString() const;


};



