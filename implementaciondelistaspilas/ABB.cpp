#include <iostream>
#include <cstdio>
using namespace std;

int abs(int valor){
	if(valor<0) return -valor;
	return valor;
}

class Nodo{
	  public:
	  		 int info, altura, factor;
	  		 Nodo *izq, *der;
	  		 Nodo(){
			 		izq = der = NULL;
					}
	  		 Nodo(int elem){
	 		        info = elem;
	  		 		izq = der = NULL;
			 }
};

class Arbin{
	public:
		Nodo *raiz;
		
		Arbin(){
			raiz=NULL;
		}
		
	  	bool EsVacio(Nodo *a){
			 	  if(a == NULL)
				      return true;
				  return false;
		 }
		 
		bool EsHoja(Nodo *a){
			if(a->izq == NULL && a->der == NULL)
		   		return true;
			return false;
		}
		
		//calcula la altura maxima de 2 nodo o subarboles
		int Max(Nodo *a, Nodo *b){
			if(!EsVacio(a) && EsVacio(b))
				  	return a->altura;
			if(EsVacio(a) && !EsVacio(b))
				 	return b->altura;
			if(a->altura > b->altura)
				 	return a->altura;
			if(a->altura <= b->altura)
				 	return b->altura;
		}
				 
		//calcula la altura de un arbol
		void Altura(Nodo *a){
			if(!EsVacio(a)){
 				if(EsHoja(a)){
	  				a->altura = 1;
	  				    return;
				}
				else{
					Altura(a->izq);
					Altura(a->der);
					a->altura = Max(a->izq, a->der) + 1;
				}
			}
	    }
	    
	    void Insertar(Nodo *a, int elem){
			if(EsVacio(a)){
	  		   raiz=new Nodo(elem);
			}
			else{
				if(a->info > elem){
	 			    if(!a->izq){
              			a->izq = new Nodo(elem);
              			return;
					}
 			        Insertar(a->izq, elem);
				}
	 			if(a->info < elem){
	 			    if(!a->der){
              			a->der = new Nodo(elem);
              			return;
					}
					Insertar(a->der, elem);
				}
			}
		}
		    
		void PreOrden(Nodo *a){
			if(!EsVacio(a)){
				cout << a->info << " -> ";
				cout << a->altura << endl;
				PreOrden(a->izq);
				PreOrden(a->der);
			}
		}
		    
		void InOrden(Nodo *a){
			if(!EsVacio(a)){
				PreOrden(a->izq);
				cout << a->info << " -> ";
				cout << a->altura << endl;
				PreOrden(a->der);
			}
		}
		    
		void PostOrden(Nodo *a){
			if(!EsVacio(a)){
				PreOrden(a->izq);
				PreOrden(a->der);
				cout << a->info << " -> ";
				cout << a->altura << endl;
			}
		}
		
		//calcula cual es el factor de balanceo del un arbol binario
		int Balanceado(Nodo *act){
			if(!act) return -1;
			int Izq=Balanceado(act->izq)+1;
			int Der=Balanceado(act->der)+1;
			return Izq-Der;
		}
}ARBIN;

int main(){
	ARBIN.Insertar(ARBIN.raiz, 15);
	ARBIN.Insertar(ARBIN.raiz, 21);
	ARBIN.Insertar(ARBIN.raiz, 27);
	ARBIN.Insertar(ARBIN.raiz, 34);
	ARBIN.Altura(ARBIN.raiz);
	ARBIN.PreOrden(ARBIN.raiz);
	int Balance=ARBIN.Balanceado(ARBIN.raiz);
	if(Balance<=1 && Balance>=-1){
		cout<<"El arbol esta balanceado, con un factor de "<<Balance<<endl;
	}
	else{
		cout<<"El arbol no esta balanceado, tiene factor de "<<Balance<<endl;
	}
	
	return 0;
}
