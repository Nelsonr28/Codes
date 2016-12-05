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
        aux = pri;
        act = pri;
        while (aux -> sig != NULL)
          {
            if (aux -> info == n)
              {
                pri = aux -> sig;
                act = aux;
                aux = aux -> sig;
                delete act;

              }
            else
              {
                aux = aux -> sig;
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
  L.insert (8);
  L.insert (2);
  L.insert (6);
  L.insert (8);
  L.insert (9);
  L.print ();
  L.eliminar (8);
  L.print ();
}
