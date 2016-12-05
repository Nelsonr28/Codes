#include <iostream>
#include <string>

using namespace std;

class nodo
{
public:
  int info;
  nodo *sig;
  nodo (int valor, nodo *next)
  {
    info = valor;
    sig = next;
  }
};

class lista
{
public:
  nodo *pri;
  lista ()
  {
    pri = NULL;
  }

void insertarUlt (int valor)
{
  nodo *nuevo = new nodo (valor, NULL);
  nodo *act;
  if (pri == NULL)
  {
    pri = nuevo;
    act = pri;
  }
  else
  {
    act -> sig = nuevo;
    nuevo -> info = valor;
    act = act -> sig;
  }
}

void mostrar ()
{
  nodo *aux = pri;
  while (aux)
    {
      cout << aux -> info << "--";
      aux = aux -> sig;
    }
    cout << endl;
}
};

int main ()
{
  lista L;
  L.insertarUlt (3);
  L.insertarUlt (14);
  L.insertarUlt (10);
  L.insertarUlt (1);
  L.insertarUlt (9);
  L.mostrar ();
};
