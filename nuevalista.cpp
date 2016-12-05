#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

struct nodo
{
	int nro;
	nodo *sgte;
};
nodo *pi, *pa, *pf;

    void insertar (int numero)
   {
	if (pi == NULL)
		{
			pi = new (nodo);
			pi -> nro =  numero;
			pf = pi;
		}
	else
		{
			pa = new (nodo);
			pf -> sgte = pa;
			pa -> nro = numero;
			pf = pa;
		}
   }

	void mostrar()  
        {
	     pa = pi;
	     while (pa != NULL)
		 {
			cout << "---->NUMERO: " << pa -> nro << endl;
			pa = pa -> sgte;
		 }
         }


	void buscar ()
	{
	pa=pi;
	int nro_buscar, band=0;
	cout<<"--->Ingrese elemento a buscar:"<<endl;  
		cin>>nro_buscar;
  	        while (pa!= NULL)
 	        {
		    if (nro_buscar== pa->nro)
		           {
		    		  cout<< "VALOR ENCONTRADO"<<": "<<pa->nro<< endl;
	            		  band=1;
	            	   }
	             		  pa=pa->sgte;
	         }  
		     if (band==0) 
			   {
	                	  cout<<"--->El elemento no fue Encontrado"<<endl;
		           }
}
	void modificar ()
   {
		pa=pi;
		int nro_buscar, band=0;
		cout<<"--->Ingrese el elemento a modificar:"<<endl;  
		cin>>nro_buscar;
	 	          while (pa!= NULL)
 		             {
				  if (nro_buscar== pa->nro)
				      {
					cout<< "VALOR ENCONTRADO"<<"  :"<<pa->nro<< endl;
					cout<<" Ingrese Nuevo Valor"<<endl;
					cin>>pa->nro;
					band=1;
		                      }
	       			        pa=pa->sgte;
	   		      }  
				   if (band==0)
				      {
	          			cout<<"--->El elemento no fue Encontrado"<<endl;
		        		      
				      }

		mostrar();
   } 
		void eliminar()
		{
 			pa=pi;
			int nro_eliminar, band=0;
			cout<<"--->Ingrese el elemento que desea eliminar:"<<endl;  
			cin>>nro_eliminar;
	 	          while (pa!= NULL)
 		             {
				  if ((nro_eliminar== pa->nro) && band==0)
				      {
					if(pa==pi) 
					{
					   pi=pi->sgte;
				        }
					     else {
						pf->sgte=pa->sgte;
						  }
						   delete(pa);	
					           band=1;
		                                  }
						   pf=pa;
	       			       		   pa=pa->sgte;
	   		      }  
				   if (band==1)
				      {
	          			cout<<"--->El elemento ha sido eliminado"<<endl;
				      }
		        	 else { 
					cout<<"El numero no ha sido ingresado a la lista"<<endl;
					}	      
				      

					mostrar();
		}


		int main()
   	{
		string n; int numero;
		si:
		cout<<"Desea ingresar numero?"<<endl;
		cin>>n;
			if (n == "s")
			{
				cout << "Ingrese numero" << endl;
				cin >> numero;
				insertar (numero);
				goto si;
		         }
				else
			       {
				
				  mostrar();
		 		}
	                          buscar();
		                  modificar();
				  eliminar();
		       
   }
