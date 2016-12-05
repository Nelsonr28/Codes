#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;

//Nodo de la pila
class nodo{
	public:
    	int dato;
    	nodo *sig;
    	
		nodo(int d){
			dato = d;
			sig = NULL;
		}
};
////////////////////////////////////////
//Implementacion de la Pila
class Pila{
	public:
    	nodo *primero;
    	
		Pila(){
			primero = NULL;
		}
   		
		bool EsVacia(){
		   return !primero;
		}
		
    	void Apilar(int d){
        	if(EsVacia()){
            	primero = new nodo(d);
        	}
        	else{
            	nodo *aux = new nodo(d);
            	aux->sig = primero;
            	primero = aux;
        	}
    	}
    	
    	void Desapilar(){
        	if(!EsVacia()){
            	if(primero->sig)
                	primero = primero->sig;
            	else
                	primero = NULL;
        	}
    	}
    	int Tope(){
        	if(!EsVacia()){
            	return primero->dato;
        	}
        	return 0;
    	}
    
		void Mostrar(){
        	nodo *aux = primero;
        	while(aux){
            	cout<<aux->dato<<endl;
            	aux  = aux->sig;
        	}
    	}

};
////////////////////////////////////////
void llenarPila(Pila *P){
    int n=1;
    while(n  < 6){
        P->Apilar(n);
        n++;
    }
}
////////////////////////////////////////////
void Invertir(Pila *P, int &cont, int &prim, int i, bool &listo){
    do{
        if(!P->EsVacia()){
            int x = P->Tope();
            if(i != cont){
                P->Desapilar();
                Invertir(P,cont,prim,i+1,listo);
                P->Apilar(x);
                if(i==1){
                    P->Apilar(prim);
                    cont++;
                }
            }
            else{
                prim = x;
                P->Desapilar();
                if(P->EsVacia()){
                    listo = true;
                }
            }
        }

    }while(i==1 && !listo);

}
//////////////////////////////////////////////
int main(){
    Pila *P;
    bool L = false;
    int cont = 2, prim = 0;
    P = new Pila();
    llenarPila(P);
    cout<<"Pila Ingresada:\n"<<endl;
    P->Mostrar();
    Invertir(P,cont,prim,1,L);
    cout<<"\nPila Invertida:\n"<<endl;
    P->Mostrar();
    return 0;
}
