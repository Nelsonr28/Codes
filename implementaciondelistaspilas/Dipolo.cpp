#include <iostream>
using namespace std;

class nodo{
	public:
		int valor;
		nodo *prox;
		nodo(int a,nodo *b){
			valor=a;
			prox=b;
		}
};



class Dipolo {
	public:
		nodo *Primero;
		nodo *Ultimo;
		
		Dipolo(){ 
			Primero=Ultimo=NULL;
		}
		
		bool Vacia(){
			return !Primero;
		}
		
		nodo* First(){
			if(Primero!= NULL){
				return Primero;
			}
			return NULL;
			
		}
		
		nodo* End(){
			if(Ultimo != NULL){
				return Ultimo;
			}
			return NULL;	
		}
		
		void PreAgregar(int x){
			nodo *Nuevo = new nodo(x,NULL);
			
			if(Primero==NULL){
				Primero=Ultimo=Nuevo;
			}
			else{
				Nuevo->prox=Primero;
				Primero=Nuevo;
			}
		}
		
		void PostAgregar(int x){
			if(Primero==NULL) Primero=new nodo(x,NULL);
			else{
				nodo *aux=Primero;
				while(aux->prox) aux=aux->prox;
				aux->prox=new nodo(x,NULL);
			}
		}
		
		void PreEliminar(){
			nodo *aux;
			if(Primero!=NULL){
				aux=Primero;
				Primero=NULL;
				if(aux->prox) Primero=aux->prox;
			}
		}
	
		void PostEliminar(){
			if(Primero!=NULL){
				if(Primero==Ultimo){
					delete Primero;
					Primero=Ultimo=NULL;
				}
				else{
					nodo *Aux=Primero;
					
					while(Aux->prox != Ultimo){
						Aux=Aux->prox;
					}
					delete Ultimo;
					Aux->prox=NULL;
					Ultimo=Aux;
				}
			}
		}
};
int main(){
	Dipolo A;
	A.PreAgregar(1);
	A.PostAgregar(2);
	A.PostAgregar(3);
	A.PreAgregar(4);
	while(!A.Vacia()){
		cout << (A.First())->valor << endl;
		A.PreEliminar();
	}
	
}
