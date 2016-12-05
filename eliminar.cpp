#include <iostream>
using namespace std;
struct nodo{
int valor;
nodo *sgte;
};
nodo *pi, *pf, *pa;
void insertar(int n)
{
  pa= new nodo();

 if (pi== NULL)
   {

    pi=pa;
    pa->valor=n;
    pa=pa->sgte;
  }

   else {
     pa->sgte=pa;
   }


}
    int mostrar ()
    {
      nodo* aux;
      aux=pa;
      while (aux!=NULL)
        {
          cout<<pa->valor<<endl;
          aux=pa->sgte;
        }
        }
  int main()
   {int n;
     cin>>n;
      insertar(n);
      mostrar();
  }
