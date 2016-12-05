#include <iostream>

uing namespace std;

class NodeDoble
{
public:
  NodeDoble *sig, *ant;
  int  info;

  NodeDoble ();
  ~NodeDoble ();

};

NodeDoble:: NodeDoble (int ne)
{
  sig = ant = NULL;
  info = ne;
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
