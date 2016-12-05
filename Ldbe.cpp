#include <iostream>

using namespace std;

class NodeDoble
{
public:
  int  info;
  NodeDoble *sig, *ant;

public:
  NodeDoble ();
  ~NodeDoble ();
};

NodeDoble:: NodeDoble ()
{
  sig = ant = NULL;
  info = 0;
}

NodeDoble:: ~NodeDoble ()
{

}

class ListaDoble
{
public:
  NodeDoble *pri;
  ListaDoble ()
  {
    pri = NULL;
  }

  ~ListaDoble ()
  {

  }
  void Insert (int valor)
  {
    NodeDoble *nuevo = new NodeDoble ();
    NodeDoble *ult, *act;
    if (pri == NULL)
      {
        pri = nuevo;
        pri -> info = valor;
        ult = pri;
        act = pri;
      }
    else
      {
        act -> sig = nuevo;
        nuevo -> ant = act;
        nuevo -> info = valor;
      }
      act = nuevo;

  }
  void Print ()
  {
    NodeDoble *aux = pri;
    while (aux)
      {
        cout << aux -> info << " -> ";

        aux = aux -> sig;
      }
      cout << endl;
  }
};

int main ()
{
  ListaDoble L;
  L.Insert (1);
  L.Insert (6);
  L.Insert (4);
  L.Insert (4);
  L.Insert (5);
  L.Insert (9);
  L.Print ();
}
