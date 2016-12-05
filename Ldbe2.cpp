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


void AddNode (NodeDoble *nue)
{
  if (pri == NULL)
    pri = nue;
  else
    {
      NodeDoble *temp;
      for (temp = pri; temp -> sig != NULL; temp = temp -> sig)
        temp -> sig = nue;
        nue -> ant = temp;
    }
};

int main ()
{
return 0;
}
