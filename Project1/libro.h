#pragma once
#include "std.h"


class libro
{
private:
    string titulo;
    string id;

public:
    libro(string = "", string = "");
    libro(const libro& orig);
    virtual ~libro();
    libro(ifstream&);
    virtual bool guardar(ofstream&);
    static void deserialize(ifstream&, libro*);
    static bool serialize(ofstream&, libro*);
    virtual void setTitulo(string);
    virtual void setId(string);
    virtual string getTitulo() const;
    virtual string getId() const;
    virtual string toString() const;
};

