#include <iostream>
#include <string>

using namespace std;

class nodo{ //Clase Nodo
	public:
		int valor;
		nodo *prox;
		nodo(int a,nodo *b){ //Constructor de la clase nodo
			valor=a;
			prox=b;
		}
};

class cola{ //Clase Cola
	public:
		nodo *primero;
		cola(){ //Inicializo la cola
			primero=NULL;
		}
		bool Vacia(){return !primero;} // Funcion que me retorna si la cola existe o no existe dada la existencia del primer elemento
		void Encolar(int a){ //Encolar, es decir, introducirá al último elemento el nuevo elemento.
			if(Vacia()) primero=new nodo(a,NULL);
			else{
				nodo *aux=primero;
				while(aux->prox) aux=aux->prox;
				aux->prox=new nodo(a,NULL);
			}
		}
		void Desencolar(){ // Desencola, es decir, el primero de la cola lo borro.
			nodo *aux;
			if(!Vacia()){
				aux=primero;
				primero=NULL;
				if(aux->prox) primero=aux->prox;
			}
		}
		int Tope(){ //Funcion que devuelve el valor del primero en la cola.
			return primero->valor;
		}
};

int main(){
	cola Tutorial;
	cout << "Introduce elementos para una posible cola. Termina en cero (0)" << endl;
	int a;
	cin >> a;
	while(a!=0){
		Tutorial.Encolar(a);
		cin >> a;
	}
	while(!Tutorial.Vacia()){
		cout << Tutorial.Tope() << endl;
		Tutorial.Desencolar();
	}
}
