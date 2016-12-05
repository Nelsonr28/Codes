#include<iostream>
using namespace std;


/*
	Funcion: Mezcla
	Descripcion: Se encarga de mezclar 2 arreglos ya ordenados y guardarlo en otro arreglo.
	int A[]: Arreglo 1 para mezclar
	int B[]: Arreglo 2 para mezclar
	int C[]: Arreglo Resultado
	int N: Tamaño del arreglo A
	int M: Tamaño del arreglo B
	int i: Indice del arreglo A
	int j: Indice del arreglo B
	int k: Indice del arreglo C

*/
void mezcla(int A[],int B[],int C[],int N,int M,int i,int j,int k){
	// Si el indice de ambos arreglos ya pasaron sus limites entonces termina la mezcla (caso Base)
	if(i>=N && j>=M){           
		return;          
	// Si solo el indice del arreglo B ya excedio el limite entonces guardamos el del arreglo A
	}else if(i<N && j>=M){      
		C[k]=A[i];
		// aumentamos el indice del arreglo A y C (para guardar el siguiente en la proxima llamada recursiva)
		mezcla(A,B,C,N,M,i+1,j,k+1);
	// Caso analogo pero guardando solo el del arreglo B
	}else if(i>=N && j<M){      
		C[k]=B[j];
		// aumentamos el indice del arreglo B y C (para guardar el siguiente en la proxima llamada recursiva)
		mezcla(A,B,C,N,M,i,j+1,k+1);
	}else{
		// si tenemos valores en ambos arreglos vemos el menor de ellos y lo guardamos.
		if(A[i]<B[j]){
			C[k]=A[i];
			mezcla(A,B,C,N,M,i+1,j,k+1);
		}else{
			C[k]=B[j];
			mezcla(A,B,C,N,M,i,j+1,k+1);
		}
	}

}
/*
	Funcion: copiar
	Descripcion: se encarga de copiar una porcion del arreglo original al arreglo copia
	int copia[]: arreglo resultante
	int original[]: Arreglo que tendra los valores a copiar
	int ini: inicio del rango a copiar
	int fin: fin del rango a copiar
	Retorna: La cantidad exacta de valores que contiene el arreglo Copia

*/
int copiar(int copia[], int original[],int ini,int fin){
	int j=0;
	for(int i=ini;i<=fin;i++){
		copia[j]=original[i];
		j++;
	}
	return j;
	
}

/*
	Funcion: MergeSort
	Descripcion: ordena un arreglo subdividiendolo en 2 y aplicando el mismo procedimiento recursivamente para luego ir mezclando arreglos ordenados
	int A[]: Arreglo a ordenar
	int li: limite inferior del arreglo a ordenar
	int ls: limite superior del arreglo a ordenar

*/
void MergeSort(int A[],int li,int ls){
	
	//Caso Base cuando el limite inferior sea igual al superior (es decir que solo tenemos un arreglo de tamaño 1) mp hacemos nada
	// si li>ls no hacemos nada
	if(li>=ls ){ 
		return;
	}else{
		//Obtenemos la posicion central del arreglo o la mitad
		int mitad=(ls+li)/2;
		//declaramos los arreglos correspondientes al lado izq y der
		int mitadizq[mitad+2];
		int mitadder[mitad+2];
		//Declaramos los tamaños de los arreglos declarados
		int tamizq;
		int tamder;
		//Copiamos el lado izquierdo del arreglo A (es decir desde el limite inferior (li) hasta la mitad
		tamizq=copiar(mitadizq,A,li,mitad);
		//Copiamos el lado derecho del arreglo A (es decir desde la mitad+1 (puesto que el valor correspondiente a la mitad ya se incluyo en la primera llamada hasta el limite superior (ls)
		tamder=copiar(mitadder,A,mitad+1,ls);
		//llamada recursiva del lado izquierdo
		MergeSort(mitadizq,0,tamizq-1);
		//llamada recursiva del lado derecho
		MergeSort(mitadder,0,tamder-1);
		//En este punto ya ambos arreglos estan ordenados asi que los mezclamos
		mezcla(mitadizq,mitadder,A,tamizq,tamder,0,0,0);
		
	}
	
	

}




int main(){
	
	//declaramos y leemos el tamaño del arreglo
	int n;
	cout<<"introduzca el tamaño del arreglo"<<endl;
	cin>>n;
	cout<<"introduzca los valores del arreglo"<<endl;
	int arreglo[n];
	//leemos los valores del arreglo
	for(int i=0;i<n;i++){
		cout<<"Valor "<<i<<": ";
		cin>>arreglo[i];
		cout<<endl;
	}
	cout<<endl;
	//Imprimos el arreglo
	cout<<"Arreglo desordenado"<<endl;
	for(int i=0;i<n;i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
	//Llamada inicial a al ordenamiento
	MergeSort(arreglo,0,n-1);
	//Imprimimos el arreglo
	cout<<"Arreglo ordenado"<<endl;
	for(int i=0;i<n;i++){
		cout<<arreglo[i]<<" ";
	}
	cout<<endl;
	
	
	

}