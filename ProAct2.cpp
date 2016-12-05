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

    power (string nomPo, int daPo)
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
      Power_i *pri_po;
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
  void OrdenarForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void InsertForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
  void ExtForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion);
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
      cout << p -> pri_po << endl;
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
}

void ListaDoble::ExtForma_B (string &nombre, int &poder, int &edad, int &num_po, string &descripcion)
{

}


int main ()
{
  string name; int power; int age; int num_po; string po; int dm; string descr;
  string forma; int cantFor;
  //cin >> name; cin >> power; cin>> age; cin >> num_po; cin>> descr;

  ListaDoble L;
  int n;
  cin>>n;
  for(int i=0;i<n;++i){
    cin >> name >> power >> age >> num_po;

    //Inserto en la lista de poderes
    Power_i p;
    cout<<"vamos a ver "<<num_po<<endl;
    for(int j=0;j<num_po;++j){
      cin>>po>>dm;
cout<<"debug   "<<po<<"  "<<dm<<endl;
      Power_i::power pw(po,dm);
      p.InsertarPo(pw);
    }
    cin>> descr;
    L.InsertForma_C (name, power, age, num_po, descr);
  }
    L.Imprimir ();
    cin>> cantFor;
    for (int i = 0; i < cantFor; ++i)
      {
        string forma;
        cin >> forma;
        if (forma == "Forma_P")
          {
            int cantP;
            cin >> cantP;
            for (int j = 0; i < cantP; ++j)
              {
                char ie;
                cin >> ie;
                switch (ie)
                {
                  case 'i':
                  L.InsertForma_P (name, power, age, num_po, descr);
                  break;

                  case 'e':
                  L.ExtForma_P (name, power, age, num_po, descr);
                  break;
                }
              }
        }
        if (forma == "Forma_C")
          {
            int cantC;
            cin >> cantC;
            for (int k = 0; k < cantC; ++k)
              {
                char iec;
                cin >> iec;
                switch (iec)
                {
                  case 'i':
                  L.InsertForma_C (name, power, age, num_po, descr);
                  break;

                  case 'e':
                  L.ExtForma_C (name, power, age, num_po, descr);
                  break;
                }
              }
          }
          if (forma== "Forma_D")
            {
              int cantD;
              cin >> cantD;
              for (int m = 0; m < cantD; ++m)
                {
                  char ied;
                  string in, ext;
                  cin >> ied;
                  switch (ied)
                  {
                    case 'i':
                    cin>>in;
                    if(in == "pre")
                    {
                      L.InsertForma_D_pre (name, power, age, num_po, descr);
                    }
                  else
                    {
                      L.InsertForma_D_post (name, power, age, num_po, descr);
                    }
                    break;

                    case 'e':
                    cin>>ext;
                    if(ext == "pre")
                    {
                      L.ExtForma_D_pre (name, power, age, num_po, descr);
                    }
                  else
                    {
                      L.ExtForma_D_post (name, power, age, num_po, descr);
                    }
            if (forma== "Forma_B"){
              L.OrdenarForma_B(name, power, age, num_po, descr);
            {
              int cantB;
              cin >> cantB;
              for (int b = 0; b < cantB; ++b)
                {
                  char ieb;
                  cin >> ieb;
                  switch (ieb)
                  {
                    case 'i':
                    L.InsertForma_B (name, power, age, num_po, descr);
                    break;

                    case 'e':
                    L.ExtForma_B (name, power, age, num_po, descr);
                    break;
                  }
               }
             }
            }
          }
        }
      }

  return 0;
}
