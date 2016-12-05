#include <iostream>
#include <string>

using namespace std;

class nodo{ //Clase Nodo
	public:
		string valor;
		nodo *prox;
		nodo(string a,nodo *b){ // Constructor de la clase nodo
			valor=a;
			prox=b;
		}
};

class pila{
	public:
		nodo *primero;
		pila(){ //Constructor de la clase pila (inicializada en vacio)
			primero=NULL;
		}
		bool Vacia(){return !primero;} // Funcion que retorna si la lista es vacia o no dada la existencia del primer elemento
		void Apilar(string a){ //Apila, es decir, el primer elemento en la pila será el nuevo elemento.
			nodo *aux=primero;
			primero=new nodo(a,aux);
		}
		void Desapilar(){ //Desapilar, es decir, eliminará el primer elemento de la pila.
			nodo *aux=primero;
			primero=aux->prox;
			delete aux;
		}
		string Tope(){ //Función que devuelve el valor del que esta de primero en la lista
			return primero->valor;
		}
};

main(){
	pila Tutorial;
	cout << "Introduce frases para invertirlas (introduce punto para terminar la frase)" << endl;
	string a;
	cin >> a;
	while(a!="."){
		Tutorial.Apilar(a);
		cin >> a;
	}
	while(!Tutorial.Vacia()){
		cout << Tutorial.Tope() << endl;
		Tutorial.Desapilar();
	}
}
