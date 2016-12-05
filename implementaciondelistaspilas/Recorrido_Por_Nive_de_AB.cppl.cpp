#include <cstdio>
#include <iostream>
using namespace std;

class nodo{
	public:
    	int valor;
    	nodo *izq, *der;
    	
		nodo(int n){
			izq = der = NULL;
			valor = n;
		}
};

typedef nodo *Arbin;

	bool EsVacio(Arbin A){
    	return A == NULL;
	}

	Arbin Izq(Arbin A){
    	return A->izq;
	}
	Arbin Der(Arbin A){
    	return A->der;
	}

	int Acceder(Arbin A){
    	return A->valor;
	}

class nodoC{
	public:
    	Arbin dato;
    	nodoC *sig;
    	
		nodoC(Arbin d){
			sig = NULL;
			dato = d;
		}
};

class Cola{
	public:
    	nodoC *primero;
    	nodoC *ultimo;
    
		Cola(){
			primero = ultimo = NULL;
		}
		
    	bool EsVacia(){
			return !primero;
		}
    
		void encolar(Arbin d){
        	if(EsVacia()){
            	primero = new nodoC(d);
        	}
        	else{
            	if(ultimo==NULL){
                	ultimo = new nodoC(d);
                	primero->sig = ultimo;
            	}
            	else{
                	nodoC *aux = new nodoC(d);
                	ultimo->sig = aux;
                	ultimo = aux;
            	}
        	}
    	}
    	void desencolar(){
        	if(!EsVacia()){
            	primero = primero->sig;
        	}
    	}
    
		Arbin Primero(){
        	if(!EsVacia()){
            	return primero->dato;
        	}
        	return NULL;
    	}
};

void Nivel(Arbin A){ //BFS = busqueda por anchura
    char k;
    Cola *C = new Cola();
    C->encolar(A);//se encola el origen
    while(!C->EsVacia()){
        Arbin actual = C->Primero();
        C->desencolar();
        cout<<Acceder(actual)<<endl; //procesar(acceder)
        if(actual->izq != NULL) //Se encolan adyacentes, es decir hijo izquierdo y drecho
            C->encolar(actual->izq);
        if(actual->der != NULL)
            C->encolar(actual->der);
    }
}

void insertar(Arbin &A, int n){
    if(!EsVacio(A)){
        if(n>Acceder(A)){
            if(EsVacio(Der(A)))
                A->der = new nodo(n);
            else
                insertar(A->der,n);
        }
        else if(n<Acceder(A)){
            if(EsVacio(Izq(A)))
                A->izq = new nodo(n);
            else
                insertar(A->izq,n);
        }
    }
    else
        A = new nodo(n);
}

int main(){
    Arbin A = NULL;
    insertar(A,4);
    insertar(A,6);
    insertar(A,8);
    insertar(A,1);
    insertar(A,7);
    insertar(A,2);
    cout<<"Recorrido por nivel: "<<endl;
    Nivel(A);

return 0;
}
