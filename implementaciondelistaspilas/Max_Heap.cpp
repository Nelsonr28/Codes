#include <iostream>
using namespace std;
/* Implementar una clase MaxHeap que incluya un metodo para Mezclar dos heaps sin repeticiones.
Las primitivas del heap que deben ser implementadas como minimo son Insertar y Remover. Ejemplo
* Insertando los valores: 3,5,5,4 el Heap1 queda: 5 4 5 3
Insertando los valores: 2,4,2,3 el Heap 2 queda: 4 3 2 2
Heap resultado de mezclar Heap1 con Heap2: 5 4 3 2
*/

#define MAX 100															//Tamaño máximo que puede tener el heap
	
class MaxHeap{
	public:
		int A[MAX];														//Arreglo para los heap1 y heap2
		int pos;
		int M[MAX*2];													//Arreglo del heap resultado
		
		MaxHeap(){
			pos = -1;													//Inicializo pos con -1 para futuras inserciones
		}
		
		bool EsVacio(){													//Si es -1 entonces nunca se insertó o se
			return pos == -1;											//removieron todos sus elementos
		}
		
		int Tam(){														//Funcion que retorna el tamaño del heap
			int tam = 0;
			while(tam <= pos)
				tam++;
			return tam;
		}
		
		int Top(){
			if(!EsVacio())
				return A[0];
		}

		void Print(){													//Acción que imprime el heap
			if(!EsVacio()){
				for(int i = 0; i < Tam(); i++)
					cout << A[i] << " ";
				cout << "\n";
			}
		}
		
		void PrintM(){													//Print para el heap resultado
			if(!EsVacio()){
				for(int i = 0; i < Tam(); i++)
					cout << M[i] << " ";
				cout << "\n";
			}
		}
		
		bool EsRepetido(int elem){										//Funcion que indica si el elemento que se insertara es 
			if(!EsVacio())												//repetido
				for(int i = 0; i < Tam(); i++)
					if(M[i] == elem)
						return true;
			return false;
		}
		
		void Insert(int elem){
			if(Tam() < MAX){											//Si el tamaño del heap es menor al máximo de elementos
				A[++pos] = elem;										//Lo inserto en la última posición del heap
				int nuevo = pos;									
				while(nuevo > 0){										//Mientras que nuevo sea mayor que 0
					int padre=(nuevo-1)/2;								
					if(A[nuevo] > A[padre])								//Si nuevo es mayor a su padre
						swap(A[nuevo], A[padre]);						//Hago swap para "flotar" el nuevo elemento
					nuevo = padre;
				}
			}
		}
		
		void InsertM(int elem){											//Insert para el merge 
			M[++pos] = elem;										
			int nuevo = pos;										
			while(nuevo > 0){										
				int padre=(nuevo-1)/2;
				if(M[nuevo] > M[padre])
				//swap es una funcion de c++ o de iostream no me acuerdo muy bien
				// pero en lo que hace es invertir invertir los datos de 2 variables
					swap(M[nuevo], M[padre]);							
				nuevo = padre;
			}
		}
		
		void Remove(){
			if(!EsVacio()){
				MaxHeap *aux = new MaxHeap();						//Un heap auxiliar vacío
				for(int i = 1; i < Tam(); i++)
					aux->Insert(A[i]);								//Inserto los elementos que tenía el original a partir 
				for(int i = 0; i < aux->Tam(); i++)					//del segundo elemento ya que quiero remover el primero
					A[i] = aux->A[i];								//Luego le asigno al original el auxiliar
				pos--;												//Decremento pos ya que el heap ahora tiene un elemento menos
			}
		}

		void Merge(MaxHeap *H1, MaxHeap *H2){
			if(!H1->EsVacio() || !H2->EsVacio()){
				if(!H1->EsVacio() && H2->EsVacio()){
					while(!H1->EsVacio()){
						if(!EsRepetido(H1->Top()))
							InsertM(H1->Top());
						H1->Remove();
					}
				}
				else if(H1->EsVacio() && !H2->EsVacio()){
					while(!H2->EsVacio()){
						if(!EsRepetido(H2->Top()))
							InsertM(H2->Top());
						H2->Remove();
					}
				}
				else{												//Si ninguno es vacío
					while(!H1->EsVacio() && !H2->EsVacio()){
						if(!EsRepetido(H1->Top()))
							InsertM(H1->Top());
						if(!EsRepetido(H2->Top()))
							InsertM(H2->Top());
						H1->Remove();
						H2->Remove();
					}
					if(H1->Tam() > H2->Tam()){						//Si H1 tenía más elementos que H2
						while(!H1->EsVacio()){
							if(!EsRepetido(H1->Top()))
								InsertM(H1->Top());
						H1->Remove();
						}
					}
					else if(H1->Tam() < H2->Tam()){					//Si H2 tenía más elementos que H1
						while(!H2->EsVacio()){
							if(!EsRepetido(H2->Top()))
								InsertM(H2->Top());
						H2->Remove();
						}
					}
				}	//end if ninguno es vacío	
			}	//end if alguno no es vacío
		}	//end Merge
};

int main(){
	MaxHeap *Heap1 = new MaxHeap(), *Heap2 = new MaxHeap();
	MaxHeap *HeapRes = new MaxHeap();								
	
	Heap1->Insert(3);
	Heap1->Insert(5);
	Heap1->Insert(5);
	Heap1->Insert(4);
	
	Heap2->Insert(2);
	Heap2->Insert(4);
	Heap2->Insert(2);
	Heap2->Insert(3);
	
	cout << "Heap1: ";
	Heap1->Print();
	cout << "Heap2: ";
	Heap2->Print();
	
	HeapRes->Merge(Heap1, Heap2);
	cout << "Heap Resultado: " << "\n";
	HeapRes->PrintM();											//PrintM para el heap resultado
	
	return 0;
}
