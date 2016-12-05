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
    pi->valor=n;
    pi->sgte=NULL;
  }

   else {
     pa->sgte=pa;
   }


}
    int mostrar ()
    {
      nodo* aux;
      aux=pi;
      while (aux!=NULL)
        {
          cout<<aux->valor<<endl;
          aux=aux->sgte;
        }
        }
  int main()
   {
	   
	   int n;
	   pi = NULL;
	   
	   cin>>n;
	   
	   while (n!=0) {
		   insertar(n);
		   cin>>n;
	   }

      mostrar();
  }
