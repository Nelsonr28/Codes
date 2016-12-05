#include <iostream>

using namespace std;

class nodo{ // Clase Nodo de la lista
	public:
		int valor; // Valor adentro del nodo.
		nodo *prox; // Próximo valor de la lista.
		nodo(int a,nodo* b){ // Constructor de la clase nodo (usado para hacer new nodo ( blabla )
			valor=a;
			prox=b;
		}
};

class lista{
	public:
		nodo *primero; // Primer nodo de la lista
		lista(){
			primero=NULL; // Inicializo la lista (la hago vacía)
		}
		bool Vacia(){return !primero;} // Funcion de la lista, aqui, el !primero significa que retornara un valor de verdad equivalente a !primero, si primero no existe, retornara verdadero.
		void Insertar(int a){ // Acción de inserción
			if(Vacia()) primero=new nodo(a,NULL); // Si, en c++ puedes poner una funcion sin llaves siempre y cuando ejecute solo una instruccion
			else{ //Si no esta vacia entonces...
				nodo *aux=primero;
				if(aux->valor >= a){ // Verifico si el primer nodo de la lista es menor al valor de la nueva insercion (estamos insertando ordenadamente de mayor a menor)
					primero=new nodo(a,aux); // Si es verdadero, entonces el primer nodo de la lista sera un nuevo nodo que apuntara a lo que antes era el primero.
            }
				else{
					while(aux->prox && aux->prox->valor <= a) aux=aux->prox; // Voy recorriendo la lista hasta encontrar lo que quiero, que el proximo valor sea menor al valor insertado
					aux->prox=new nodo(a,aux->prox);
				}
			}
		}
		void Mostrar(){ //Accion de mostrar
			if(!Vacia()){ //Chequeo si la lista esta vacia para prevenir SEGMENTATION
				nodo *aux=primero; // Si no esta vacia, existe un primer nodo ¿Verdad?
				while(aux){ // Mientras exista, muestro.
					cout << aux->valor << " -> ";
					aux=aux->prox;
				}
			}
		}
		void Eliminar(int a){ //Accion de eliminar
			if(!Vacia()){
				nodo *aux=primero; // Si no esta vacia, existe un primer nodo
				if(!aux->prox && aux->valor==a){ // Si es un unico nodo en toda la lista...
					primero=NULL;
				}
				else if(aux->prox && aux->valor==a){ //Si existe otro nodo en la lista, pero es el primero quien debe ser eliminado.
					primero=aux->prox;
					delete aux;
				}
				else{
					nodo *act=aux->prox;
					while(act && act->valor!=a){ // Voy recorriendo hasta que encuentre el nodo que quiero eliminar
						act=act->prox;
						aux=aux->prox;
					}
					if(act && act->valor==a){
						aux->prox=act->prox;
						delete act;
					}
				}
			}
		}
};

int main(){
	lista Tutorial;
	cout << "Introduce una secuencia de numeros, para terminar introduzca 0 " << endl << "(Para eliminar, introduzca -numero)" << endl;
	int a;
	cin >> a;
	while(a!=0){
	if(a>0){
		Tutorial.Insertar(a);
	}
	else{
		Tutorial.Eliminar(a*-1);
	}
	Tutorial.Mostrar();
	cout << endl;
	cin >> a;
	}
	return 0;
}
