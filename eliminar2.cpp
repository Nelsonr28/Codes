#include <iostream>
using namespace std;

struct nodo 
{
  int valor;
  nodo *sgte;
};
nodo *pi, *pa, *pf, *paux;
void insertar (int numero){
if (pi==NULL) 
{
	pi= new (nodo);
	pi->valor=numero;
	pf=pi;
}
else
{
	pa=new (nodo);
	pf->sgte=pa;
	pa->valor=numero;
	pf=pa;
}
			   }
	void eliminar() {
	int numm;
	cout<<"Ingrese el numero que desea eliminar"<<endl;
	cin>>numm;
	pa=pi;
	while (pa!= NULL){
	if ((pa->valor)== numm)
	     {
		if(pa==pi)
		{	pi=pi->sgte;
			
		}
	    
		else {
		pf->sgte=pa->sgte;
		     }
		delete (pa);
	    }
		pf=pa;
		pa=pa->sgte;
				}}
	void mostrar(){
	pa=pi;
	while (pa!= NULL) {
	cout<< "NUMERO: "<<pa->valor<<endl;
			   pa=pa->sgte;
			 }
		      }

	int main(){
	string s; int num;
	s:
	cout<<"Desea ingresar numero"<<endl;
	cin>>s;
	if (s =="s"){
		
		cout<<"Ingrese Numero"<<endl;
		cin>>num;
		insertar(num);
		goto s;
		}
	
	else {
		
		eliminar();
		mostrar();
		}
}
	

		
		
			
		
		
