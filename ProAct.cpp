#include <iostream>
#include <string>

using namespace std;

class Power_i
{
public:
  string nom_po;
  int da_po;
  Power_i * next_po;
  Power_i (string nomPo, int daPo, Power_i *sig_po)
  {
    nom_po = nomPo;
    da_po = daPo;
    next_po = sig_po;
  }
};


class Guerrero
{
public:
    string nombre;
    int edad;
    int poder;
    int num_po;
    Power_i *pri_po;
    string descripcion;

    Guerrero (string name, int age, int power, int numPo, string des)  //constructor de la clase guerrero
    {
      nombre = name;
      edad = age;
      poder = power;
      num_po = numPo;
      pri_po = NULL;
      descripcion = des;
    }

    void InsertarPo (Power_i po)
    {
      Power_i *new_po = new Power_i (po.nom_po, po.da_po, NULL);
      Power_i *act_po = NULL;
      if (pri_po == NULL)
      {
        pri_po = new_po;

      }
      else
      {
        act_po = pri_po;
        while (act_po -> next_po != NULL)
          {
            act_po = act_po->next_po;
          }
          act_po->next_po = new_po;
      }
    }
};


class NodeDoble
{
public:
  NodeDoble *sig;
  NodeDoble *ant;
  Guerrero info;

  NodeDoble ();
  ~NodeDoble ();

};

NodeDoble:: NodeDoble (Guerrero ne)
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

public:
  void imprimir ();
  void AddNode (Guerrero *nue);
  void AddNodeP (Guerrero *nue, int pos);
  void DelUlt ();
  void DeleNode (int pos);
  void InsertForma_P (Guerrero);
  void ExtForma_P ();
  void InsertForma_C ();
  void ExtForma_C ();
  void InsertForma_D_post ();
  void InsertForma_D_pre ();
  void ExtForma_D_post ();
  void ExtForma_D_pre ();
};

void ListaDoble:: imprimir ()
{
  for (NodoDoble *aux = pri; aux != NULL; aux = aux -> sig)
    cout << aux -> info.nombre << endl;
}

void ListaDoble:: AddNode (NodeDoble *nue)
{
  if (pri == NULL)
    pri = nue;
  else
    {
      NodeDoble *temp;
      for (temp = pri; tem -> sig != NULL; temp = temp -> sig)
        tem -> sig = nue;
        nue -> ant = temp;
    }
}

void ListaDoble:: AddNodeP (NodeDoble *nue, int pos)
{
  if (pri == NULL)
    pri = nue;

    NodoDoble *tem = pri;
  if (pos == 0)
    {
      nue -> sig = pri;
      pri = nue;
      tem -> ant = pri;
      return;
    }
    for (int i = 0; i < pos-1; i++)
      {
        tem = tem -> sig;
        if (tem == NULL)
          return;
      }
      if ( tem -> sig != NULL)
        tem -> sig -> ant = nue;
        nue -> sig = tem -> sig;
        nue -> ant = tem;
        tem -> sig = nue;
}

void ListaDoble:: DelUlt ()
{
  NodoDoble *temp;
  for (temp = pri; temp -> sig != NULL; temp -> temp -> sig)
    {
      delete temp -> sig;
      temp -> sig = NULL;
    }
}

void ListaDoble:: DelNode (int pos)
{
  if (pri == NULL)
    cout << "Lista vacia" << endl;
    return;
    NodeDoble *tem = pri;
    if (pos == 0)
      {
        tem = pri -> sig;
        delete pri;
        pri = tem;
        pri -> ant = NULL;
      }
      for (int i = 0; i < pos; i++)
        {
          tem = tem -> sig;
          if (tem == NULL)
            return;
        }
        if (tem -> sig != NULL)
          tem -> sig -> ant = tem -> ant;
          tem -> ant -> sig = tem -> sig;
          delete tem;
}

void ListaDoble:: InsertForma_P (Guerrero info)
{
  NodeDoble *aux = new NodoDoble (info);
  if(pri == NULL) pri = aux;
else{
  aux->sig = pri;
  pri->ant = aux;
  pri = aux;

}


}
