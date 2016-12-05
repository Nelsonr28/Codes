#include<iostream>
#include<cstdio>
using namespace std;

class nodo
{
	public:
	int informacion;
	nodo * siguiente;
	nodo()
	{
		informacion = 0;
		siguiente = NULL;
	}
};

class lista //los indices de la lista empiezan en 0, es decir el primero elemento esta en la posicion 0 y el ultimo en tamano-1
{
private: //declaramos los atributos como privados para que no puedan acceder a ellos fuera de la clase

	nodo * primero;
	int tamano;

public: //declaramos las funciones como publicas ya que de otra manera no podriamos tener acceso a ellas fuera de la clase.

	lista() //constructor esta funcion se llama cuando hacemos una declaracion del tipo lista nombre_variable;
	{
		primero = NULL;
		tamano = 0;
	}

	void insertar(int datos) //inserta al final de la lista
	{
		nodo * aux = primero;
		if(aux==NULL) //la lista esta vacia
		{
			primero = new nodo;					//creamos un nuevo nodo y lo colocamos como el primero de la lista
			tamano++;
			primero->informacion = datos;
			primero->siguiente = NULL;
		}
		else
		{
			//existe al menos un elemento
			tamano++;
			while(aux->siguiente!=NULL) 	//recorremos hasta el ultimo elemento, es decir, un elemento cuyo siguiente sea nulo
				aux = aux->siguiente;
			nodo * nuevo = new nodo; 		//creamos el nuevo nodo que queremos agregar a nuestra lista.
			nuevo->informacion = datos;  	//le damos el valor a los campos necesarios
			aux->siguiente = nuevo;			//finalmente al ultimo elemento que habiamos encontrado anteriormente le asignamos como siguiente el nuevo elemento que acabamos de crear
		}
	}

};

int main()
{

	lista l;
	for(int i=0;i<21;i++)
		l.insertar(i); //puedo acceder al miembro de la clase por ser publico
	
}
