#include<iostream>
#include<string>
using namespace std;

/*
	Funcion: esvalido
	Descripcion: Se encarga de validar si dada una una posicion i,j es valida en el tablero revisando la fila, la columna y las diagonales
	bool tablero[][8]: tablero de ajedrez
	int i: numero de fila de la posicion a validar
	int j: numero de columna de la posicion a validar

*/
bool esvalido(bool tablero[][8],int i,int j){
	
	//ciclo para validar la fila y la columna de la posicion actual
	//El i y el j se mantienen fijos mientras se va variando el k que es el recorre la fila y la columna
	// si encuentra una posicion ya marcada entonces retorna falso ya que las reinas se atacarian entre si y no seria valido
	for(int k=0;k<8;k++){
		//Valida la fila
		if(tablero[i][k]==true){
			return false;
		}
		
		//Valida la columna
		if(tablero[k][j]==true){
			return false;
		}
		
	}
	
	
	//validaciones de las diagonales
	/*
		Son 4 diagonales si se tiene en cuenta la posicion i,j actual
		primero la diagonal hacia la esquina inferior derecha que se puede recorrer sumando en i y en j 
		segundo la diagonal superior izquierda que se recorre restando en i y en j 
		tercero la diagonal superior derecha que se recorre sumandole al j y restandole al i
		cuarto  la diagonal inferior izquierda que se recorre sumandole al i y restandole al j
		
		estas operaciones se hacen a la vez es decir en en una misma iteracion se hace la suma y/o resta de ambas posiciones
		para esto usamos una variable k que sirva para llevar el paso a validar

	*/
	
	
	int k=0;
	//validacion de la primera diagonal
	//se debe validar que ninguna posicion salga del limite del tablero
	// se va aumentando el k para ir a la siguiente posicion de la diagonal
	// si alguna posicion es true entonces ya hay una reina y retornamos falso
	while(i+k<8 && j+k<8){
		if(tablero[i+k][j+k]==true){
			return false;
		}
		k++;
	}
	
	k=0;
	//Validacion de la segunda diagonal
	while(i-k>=0 && j-k>=0){
		if(tablero[i-k][j-k]==true){
			return false;
		}
		k++;
	}
	
	k=0;
	//validacion de la tercera diagonal
	while(i-k>=0 && j+k<8){
		if(tablero[i-k][j+k]==true){
			return false;
		}
		k++;
	}
	
	k=0;
	//validacion de la cuarta diagonal
	while(i+k<8 && j-k>=0){
		if(tablero[i+k][j-k]==true){
			return false;
		}
		k++;
	}
	
	//si la funcion llega a este punto quiere decir que la posicion es valida,
	//esto debido a que verifico todos los posibles movimientos de la reina y si ninguna posicion es true entonces la posicion es valida y retorna true
	
	return true;
}


/*
	Funcion: mostrar_tablero
	Descripcion: muestra el tablero con el resultado
	bool tablero[][8]: tablero de ajedrez

*/
void mostrar_tablero(bool tablero[][8]){
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(tablero[i][j]==true){
				cout<<1<<" ";
			}else{
				cout<<0<<" ";
			}
		}
		cout<<endl;
	}
	
	
}

/*
	Funcion: colocar_reinas
	Descripcion: realiza el backtraking que va probando posiciones validas, hasta que coloque las 8 reinas en el tablero
	Tipo de backtraking: La primera solucion
	bool tablero[][8]: tablero de ajedrez
	int can: cantidad de reinas que estan colocadas en el tablero
	bool &termino: variable que indica si ya encontro una solucion se marca en true cuando la encuentra

*/
void colocar_reinas(bool tablero[][8], int can, bool &termino){
	
	//Caso base cuando la cantidad de reinas colocadas sean 8
	if(can==8){
		//se muestra el tablero resultado y se marca la variable termino en true
		mostrar_tablero(tablero);
		termino=true;
		
		//esto es solo para que el programa pare y se pueda ver la solucion actual
		string g;
		cout<<"Introduzca un caracter cualquiera para continuar"<<endl;
		cin>>g;
		
	}else{
		
		//con este doble ciclo probamos cada posicion del tablero para ver si una posicion es valida y colocar la reina
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				//validamos que sea una posicion valida
				if(esvalido(tablero,i,j)){
					//marcamos la reina es decir la colocamos en el tablero
					tablero[i][j]=true;
					//llamamos al backtraking para que coloque la siguiente reina
					colocar_reinas(tablero,can+1,termino);
					//borramos el paso anterior es decir volvemos a poner la reina en falso para seguir buscando una solucion en caso de no haberla encontrado
					tablero[i][j]=false;
				}
				//condicional para forzar a terminar el ciclo mas interno (el del j) si ya encontro solucion y asi no siga buscando
				//Si se quieren todas las soluciones entonces hay que quitar este condicional
				if(termino==true){
					break;
				}
				
			}
			//condicional para forzar a terminar el ciclo del i en caso de que ya haya encontrado solucion
			//Si se quieren todas las soluciones entonces hay que quitar este condicional
			if(termino==true){
				break;
			}
		}
		
	
	}

}



int main(){
	// se declara el tablero de ajedrez 8x8
	bool tablero[8][8];
	
	//inicializamos el tablero en falso (no hemos colocado ninguna reina)
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			tablero[i][j]=false;
		}
	}
	//inicializamos la variable que nos indica si encontro solucion
	bool termino=false;
	//llamamos al backtraking con el tablero y 0 reinas colocadas
	colocar_reinas(tablero,0,termino);

}