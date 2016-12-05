#include <iostream>
#include <string.h>

#include <stdlib.h>
using namespace std;
struct nodo{
int nro;
nodo *sgte;
};


struct nodo *pi, *pa, *pf;

void insertar (int numero){
if (pi ==NULL){
pi=new(nodo);
pi->nro=numero;
pf=pi;
	      }
else{
pa=new(nodo);
pf->sgte=pa;
pa->nro=numero;
pf = pa;
}

			   }
void mostrar(){
pa=pi;
while (pa!= NULL){
cout<<"--> Numero---->"<< pa->nro<<endl;
pa=pa->sgte;
}

		 }

int main(){
string n; int numero;
si:
cout<<"Desea ingresar numero"<<endl;
cin>>n;

if (n=="s"){
cout<<"Ingrese Numero"<<endl;
cin>>numero;
insertar(numero);
goto si;
            } else {

mostrar();
	           }
          }
