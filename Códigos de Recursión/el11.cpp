#include<iostream>
#include<algorithm>
using namespace std;


/*
	Funcion: Posicion_ordenada
	descripcion: Retorna la posicion del valor k del arreglo, como si estuviera ordenado
	int k: Posicion del valor en el arreglo desordenado
	int arr[]: arreglo
	int n: tamaño del arreglo
	
	Explicacion: Si contamos cada vez que se encuentre que la posicion arr[k] sea mayor que una posicion del arreglo, el total de este contador nos dara la posicion donde deberia estar ese valor al estar ordenado

*/

int posicion_ordenada(int k, int arr[],int n){
	
	int can=0;        //c1
	
	for(int i=0;i<n;i++){     //c2*(n+1)
		if(arr[k]>arr[i]){    //c3*n
			can++;            //c4*n
		}
	}
	return can;       //c5


}

//las variables ci es un tiempo constante

//complejidad en tiempo
/*

F(n)= c1+c2*(n+1)+c3*n+c4*n+c5; // Funcion de tiempo en base a n del algoritmo
F(n)= c1+c2*n+c2+c3*n+c4*n+c5   // Aplicamos propiedad distributiva en c2*(n+1)
c1+c2+c5=c6                     // Sumamos las constantes y la igualamos a otra constante
F(n)= c6 + n*(c2+c3+c4);        // Factor comun n
c2+c3+c4=c7;                    // Agrupamos de nuevo las constantes
F(n)=c6+n*c7                    // Funcion simplificada
O(F(n))=O(c6+n*c7)              // Aplicamos la funcion O (peor caso)
O(F(n))=O(n*c7)                 // Aplicamos regla de la suma
O(F(n))=O(n)                    // Aplicamos regla del producto
	
	Concluimos que la funcion es de orden de complejidad n
*/




 




int main(){
	
	int n;
	
	cout<<"Introduzca el tamaño del arreglo"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Introduzca los elementos del arreglo"<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	int k;
	cout<<"Introduzca el valor k"<<endl;
	cin>>k;
	
	
	cout<<"La posicion ordenada seria:"<<posicion_ordenada(k,arr,n)<<endl;
	
	
}
