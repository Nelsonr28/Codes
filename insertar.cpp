#include <iostream>
using namespace std;

	class nodo {
		public:
		int valor;
		nodo * sig;
		nodo(int a, nodo *pro)
		{
			valor= a;
			sig= pro;
		}
	};

	class Lista{

		public:
			nodo *prim;// primer nodo de la lista
			Lista()
			{
				prim= NULL;
			}

			bool vacia() // si la lista esta vacia
			{
				if (prim==NULL)
				{
					return true;
				}else
				{
					return false;
				}
			}

			void insertar (int a)

			{
				nodo * nuevo= new nodo (a, NULL); //no estabas pasando los parametros
				/*nuevo-> sig= NULL;
				nuevo-> valor= a;
				*/
				if ( prim== NULL)
				{
					prim= nuevo;
				}else
				{
					if (prim->valor > a)
					{
						nuevo->sig= prim;
						prim= nuevo;
					}else
					{
						nodo *aux= new nodo (a, NULL); //no estabas pasando los parametros

						while ( aux->sig != NULL && a >= aux-> sig -> valor)
						{
							aux= aux -> sig;
						}

						nuevo-> sig= aux->sig;
						aux -> sig= nuevo;
					}
				}

			}


	};

	int main(){
		Lista L;
		int a;
		cin >> a;

	return 0;

	}
