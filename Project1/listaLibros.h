#pragma once
#include "std.h"
#include "lista.h"
#include "libro.h"

class listaLibros : public lista<libro> {
public:
    listaLibros();
    virtual ~listaLibros();
    listaLibros(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, listaLibros*);
    static bool serialize(ofstream&, listaLibros*);
    libro* buscarLibro(string) const;
    int totalLibros() const;
    virtual string toString() const;


};



