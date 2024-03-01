
#include "interfaz.h"

int main() {
    interfaz* i = new interfaz();
    i->mostrarMenu();


    /*string archivo = "..\\datos.txt";


    cliente* cl1 = new cliente("Luciana","123");
    cliente* cl2 = new cliente("Mauricio","456");

    banco* b = new banco("Nacional","Heredia");

    b->agregarCliente(cl1);
    b->agregarCliente(cl2);


   cout<<"Antes de guardar en el archivo "<<endl;
   cout<<"Informacion del Banco"<<endl;
   cout<<b->toString()<<endl;

    ofstream salida(archivo.c_str());
    b->guardar(salida);
    salida.close();


    ifstream entrada(archivo.c_str());
    banco* bAux = new banco(entrada);
    entrada.close();

    cout<<"Despues de guardar en el archivo "<<endl;
    cout<<"Informacion del Banco"<<endl;
    cout << bAux->toString() << endl;

    delete b, bAux;*/
    cin.get();
    return 0;
}