#include <iostream>

using namespace std;

class NodoLista
{
public:
  int info;
  NodoLista *sig;
  NodoLista (int n, NodoLista *next)
  {
    info = n;
    sig = next;
  }
};

class Lista
{
public:
  NodoLista *pri;
  NodoLista *actual;
  Lista ()
  {
    pri = NULL;
    actual = NULL;
  }

  bool esVacia ()
  {
    return pri == NULL;
  }

  void insert (int n)
  {
    NodoLista *nuevo = new NodoLista (n, NULL);

    if (esVacia ())
      {
        pri = nuevo;
      }
    else
      {
        actual -> sig = nuevo;
      }
      actual = nuevo;
  }


  void eliminar (int n)
  {
    if (!esVacia ())
      {
        NodoLista *aux, *act;
        aux = NULL;
        act = pri;
        while (act -> sig != NULL)
          {
            if (act -> info == n)
              {
                aux -> sig = act -> sig;
                act = aux -> sig;
                delete aux;
              }
            else
              {
                aux = act;
                act = act -> sig;
              }
          }
      }
  }


  void print ()
  {
    if (!esVacia ())
      {
        NodoLista *aux;
        aux = pri;
        while (aux != NULL)
          {
            cout << aux -> info << " -> ";
            aux = aux -> sig;
          }
          cout << "NULL" << endl;

      }

  }
};


int main ()
{
  Lista L;
  L.insert (4);
  L.insert (7);
  L.insert (3);
  L.insert (9);
  //L.insert (3);
  L.print ();
  L.eliminar (7);
  cout << "eliminar" << endl;
  L.print ();
}
