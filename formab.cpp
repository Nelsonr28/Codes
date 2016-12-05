#include <iostream>
#include <string>

using namespace std;

class Power_i
{
public:
  class power{
  public:
    string nom_po;
    int da_po;
    power * next_po;

    power (string nom_Po, int daPo)
    {
      next_po = NULL;
    }
  };

  power *pri_po;
  Power_i ()
  {
    pri_po = NULL;
  }

public:

  void InsertarPo (power po)
  {
    power *new_po = new power (po.nom_po, po.da_po);
    power *act_po = NULL;
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


class ListaDoble
{
public:
  class NodeGuerrero
  {
  public:
      string nombre;
      int poder;
      int edad;
      int num_po;
      Power_i pri_po;
      string descripcion;
      NodeGuerrero *pro;
      NodeGuerrero *ant;
  };
  NodeGuerrero *pri, *ult;
  int tam;

public:
  typedef NodeGuerrero *position;
  ListaDoble ();    //constructor
  ~ListaDoble ();    //destructor
  bool EsVacia ();   //retorna true si la lista está vacia
  int Tamano ();     //retorna el tamano de la lista
  void Imprimir ();              //imprime la lista
  void InsertList (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);    //inserta en la lista
  void InsertForma_P (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void ExtForma_P (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void InsertForma_C (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void ExtForma_C (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void InsertForma_D_pre (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void InsertForma_D_post (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void ExtForma_D_post (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void ExtForma_D_pre (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void OrdenarForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion); // Se ordena alfabeticamente.
  void InsertForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
};

ListaDoble::ListaDoble ()
{
  pri = ult = NULL;
  tam = 0;
}

ListaDoble::~ListaDoble ()
{
  position aux;
  while (pri != NULL)
    {
      aux = pri;
      pri = pri -> pro;
      delete aux;
    }
}

bool ListaDoble::EsVacia ()
{
  if (tam == 0)
    return true;
  else
    return false;
}

int ListaDoble::Tamano ()
{
  return (tam);
}

void ListaDoble::Imprimir ()
{
  position p;
  p = pri;
  while (p != NULL)
    {
      cout << p -> nombre << endl;
      cout << p -> poder << endl;
      cout << p -> edad << endl;
      cout << p -> num_po << endl;
      cout << p -> descripcion << endl;
      p = p -> pro;
    }
}

void ListaDoble::InsertList (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  position nuevo = new NodeGuerrero;
  nuevo -> nombre = nombre;
  nuevo -> poder = poder;
  nuevo -> edad = edad;
  nuevo -> num_po = num_po;
  nuevo -> descripcion = descripcion;
  position act;
  if (pri == NULL)
    {
      pri = nuevo;
      ult = nuevo;
    }
  else
    {
      act -> pro = nuevo;
      nuevo -> ant = act;
    }
    act = nuevo;
    ult = act;
    tam++;

}

void ListaDoble::InsertForma_P (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  position nuevo = new NodeGuerrero;
  nuevo -> nombre = nombre;
  nuevo -> poder = poder;
  nuevo -> edad = edad;
  nuevo -> num_po = num_po;
  nuevo -> descripcion = descripcion;
  nuevo -> pro = NULL;
  nuevo -> ant = NULL;

  if(EsVacia ())
    {
      pri = nuevo;
      ult = nuevo;
    }
  else
  {
    nuevo -> pro = pri;
    pri -> ant = nuevo;
    pri = nuevo;
  }
  tam++;
}

void ListaDoble::ExtForma_P (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  if (EsVacia ())
    {
      cout << "Lista vacia" << endl;
      return;
    }
  else
    {
      position aux = pri;
      pri = pri -> pro;
      delete aux;
      pri -> ant = NULL;
    }
    tam --;
}

void ListaDoble::InsertForma_C (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  position nuevo = new NodeGuerrero;
  nuevo -> nombre = nombre;
  nuevo -> poder = poder;
  nuevo -> edad = edad;
  nuevo -> num_po = num_po;
  nuevo -> descripcion = descripcion;
  nuevo -> pro = NULL;
  nuevo -> ant = NULL;
  if (EsVacia ())
    {
      pri = nuevo;
      ult = nuevo;
    }
  else
    {

      ult -> pro = nuevo;
      nuevo -> ant = ult;
      ult = nuevo;
      nuevo -> pro = NULL;
    }
    tam++;
}

void ListaDoble::ExtForma_C (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  position aux;
  if (EsVacia ())
    {
      cout << "No hay elementos que eliminar" << endl;
    }
  else
    {
      aux = pri;
      pri = aux -> pro;
      if (EsVacia ())
        ult = NULL;
        aux -> pro = NULL;
        delete aux;
        tam--;
    }
}

void ListaDoble::InsertForma_D_pre (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
    position nuevo = new NodeGuerrero;
    nuevo -> nombre = nombre;
    nuevo -> poder = poder;
    nuevo -> edad = edad;
    nuevo -> num_po = num_po;
    nuevo -> descripcion = descripcion;
    nuevo -> pro = NULL;
    nuevo -> ant = NULL;
    if (EsVacia ())
      {
        pri = nuevo;
        ult = nuevo;
      }
    else
      {
        pri -> ant = nuevo;
        nuevo -> pro = pri;
        nuevo -> ant = NULL;
        pri = nuevo;
      }
      tam++;
}

void ListaDoble::InsertForma_D_post (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
    position nuevo = new NodeGuerrero;
    nuevo -> nombre = nombre;
    nuevo -> poder = poder;
    nuevo -> edad = edad;
    nuevo -> num_po = num_po;
    nuevo -> descripcion = descripcion;
    nuevo -> pro = NULL;
    nuevo -> ant = NULL;
    if (EsVacia ())
      {
        pri = nuevo;
        ult = nuevo;
      }
    else
      {
        ult -> pro = nuevo;
        nuevo -> ant = ult;
        nuevo -> pro = NULL;
        ult = nuevo;
      }
      tam++;
}

void ListaDoble::ExtForma_D_post (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  if (EsVacia ()) return;
    position p = ult;
    ult = ult -> ant;
    if (ult == NULL)
      {
        delete p;
        pri = NULL;
      }
    else
      {
        delete p;
        ult -> pro = NULL;
      }
      tam--;
}

void ListaDoble::ExtForma_D_pre (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  if (EsVacia ()) return;
  position p = pri;
  pri = pri -> pro;
  if (pri == NULL)
    {
      delete p;
      ult = NULL;
    }
  else
    {
      delete p;
      pri -> ant = NULL;
    }
    tam--;
}

void ListaDoble::OrdenarForma_B(string &nombre, int &poder, int &edad, int &num_po, string &descripcion) // Se ordena alfabeticamente.
{
     if (EsVacia())
       {
         return ;
       }
      else
        {
          NodeGuerrero *p,*q,*min;
          p=pri;
          while (p->pro!=NULL)
            {
              q = p->pro;
              min= p;
             while(q!=NULL)
               {
                if (q->nombre.compare(min->nombre)<0)
                  {
                    min=q;
                  }
                q=q->pro;
              }
             swap (min -> nombre,p -> nombre);
             swap (min -> poder,p -> poder);
             swap (min -> edad,p -> edad);
             swap (min -> num_po,p -> num_po);
             swap (min -> descripcion,p -> descripcion);
              p = p -> pro;
            }
        }
}

/*void ListaDoble::InsertForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion) //este es el código para insertar ordenadamente
{
	int cont = 0;
	position aux = new NodeGuerrero;
	position aux2 = new NodeGuerrero;
	position aux3 = new NodeGuerrero;
	position op = new NodeGuerrero;
	aux = pri;
	aux2 = pri -> pro;
	op -> nombre = nombre;
	if (op -> nombre.compare (aux -> nombre) < 0)
    {
		  op -> pro = aux;
		  aux -> ant = op;
		  aux -> pro = aux2;
		  pri = op;
		  cont++;
	  }
	else
  {
		aux= pri -> pro;
		aux2 = aux -> ant;
			while (aux != NULL)
        {
				  if (op -> nombre.compare (aux -> nombre) < 0)
          {
				    op -> pro = aux;
				    aux -> ant = op;
				    aux = aux -> pro;
				    aux2 -> pro = op;
				    cont++;
				  }
				  aux3 = aux;
				  aux = aux -> pro;
			  }
	}

	if (cont == 0)
    {
		 aux3 -> pro = op;
	  }
}*/

void ListaDoble::InsertForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{
  position nuevo = new NodeGuerrero;
  nuevo -> nombre = nombre;
  nuevo -> poder = poder;
  nuevo -> edad = edad;
  nuevo -> num_po = num_po;
  nuevo -> descripcion = descripcion;
  nuevo -> ant = NULL;
  nuevo -> pro = NULL;
  if(EsVacia())
    pri = nuevo;

  else if (nombre < pri -> nombre)                           //Si no esta vacia entonces...
    {
      nuevo -> pro = pri;
      nuevo -> poder = pri -> poder;
      nuevo -> ant = NULL;
      pri = nuevo;
    }
    else
      {
        position aux, ant;
        ant = aux = pri;
        while ((aux -> pro != NULL) && (nombre > aux -> nombre))
          {
            ant = aux;
            aux = aux -> pro;
          }
          if (nombre < aux -> nombre)
            {
              ant = aux;
              nuevo = nuevo -> ant;
              ant = nuevo;
            }
      }

}

int main ()
{
  string name; int power; int age; int num_po; string descr;
  string po;
  int dm;
  string name2; int power2; int age2; int num_po2; string descr2;
  string name3; int power3; int age3; int num_po3; string descr3;
  string name4; int power4; int age4; int num_po4; string descr4;
  string name5; int power5; int age5; int num_po5; string descr5;

  ListaDoble L;
    cin >> name; cin >> power; cin>> age; cin >> num_po; cin>> descr;
    cin >> name2; cin >> power2; cin>> age2; cin >> num_po2; cin>> descr2;
    cin >> name3; cin >> power3; cin>> age3; cin >> num_po3; cin>> descr3;
//    cin >> name4; cin >> power4; cin>> age4; cin >> num_po4; cin>> descr4;
//    cin >> name5; cin >> power5; cin>> age5; cin >> num_po5; cin>> descr5;
  L.InsertList (name, power, age, num_po, descr);
  L.InsertList (name2, power2, age2, num_po2, descr2);
  L.InsertList (name3, power3, age3, num_po3, descr3);
//  L.InsertList (name4, power4, age4, num_po4, descr4);
//  L.InsertList (name5, power5, age5, num_po5, descr5);
  //L.OrdenarForma_B (name3, power3, age3, num_po3, descr3);
  //L.InsertForma_B (name3, power3, age3, num_po3, descr3);
  L.ExtForma_C (name2, power2, age2, num_po2, descr2);
  //L.InsertForma_D_pre (name2, power2, age2, num_po2, descr2);
  //L.InsertForma_D_post (name4, power4, age4, num_po4, descr4);

  L.Imprimir ();

  return 0;
}
