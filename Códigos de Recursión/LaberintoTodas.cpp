#include <iostream>
using namespace std;

#define F 7
#define C 8

bool existeSolucion=false;
int n=1;

void imprimir(char laberinto[F][C]){		//imprime el laberinto en el estado actual
	for(int i=0; i<F; i++){
		for(int j=0; j<C; j++)
			cout<<laberinto[i][j];
		cout<<endl;
	}
	cout<<endl;
}

void recorrer(char laberinto[F][C], int i, int j){		//función backtracking
	//comprueba si es solución
   	if(laberinto[i][j]=='S'){
		cout<<"Solución "<<n++<<"!\nLaberinto - estado final:"<<endl;
		imprimir(laberinto);
		laberinto[i][j]='S';
		existeSolucion=true;
		return;
	}

	laberinto[i][j]='.';			//marcar camino

	//imprimir(laberinto);

	if(i-1>=0 && i-1<F && (laberinto[i-1][j]==' ' ||    //arriba
       laberinto[i-1][j]=='S'))
		recorrer(laberinto, i-1, j);

	if(j+1>=0 && j+1<C && (laberinto[i][j+1]==' ' ||    //derecha
       laberinto[i][j+1]=='S'))
		recorrer(laberinto, i, j+1);

	if(i+1>=0 && i+1<F && (laberinto[i+1][j]==' ' ||    //abajo
       laberinto[i+1][j]=='S'))
		recorrer(laberinto, i+1, j);

	if(j-1>=0 && j-1<C && (laberinto[i][j-1]==' ' ||   //izquierda
       laberinto[i][j-1]=='S'))
		recorrer(laberinto, i, j-1);

	laberinto[i][j]=' ';								//desmarcar camino
}

int main(){
	char laberinto[F][C]={	{'#','#','#','#','#','#','#','#'},		//#=bloqueador
							{'#','.',' ',' ',' ',' ','#','#'},		//.=marca del recorrido
							{'#',' ','#','#',' ',' ','#','#'},		//S=salida
							{'#',' ','#','#','#',' ',' ','#'},
							{'#',' ','#',' ','#','#',' ','#'},
							{'#',' ',' ',' ',' ',' ',' ','#'},
							{'#','#','#','#','S','#','#','#'}	};

	cout<<"\nLaberinto - estado inicial:"<<endl;
	imprimir(laberinto);

	recorrer(laberinto, 1, 1);		//llama a la función backtracking pasandole como parámetro el laberinto, la posicion inicial en fila y en columna
	if(!existeSolucion)
		cout<<"No tiene solución\n"<<endl;
}
