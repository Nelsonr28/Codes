//DESARROLLADO POR LUIYIT HERNÁNDEZ - PARA WIDGET PC - VENEZUELA
//RECURSIVIDAD - 2011
//TODOS LOS DERECHOS RESERVADOS - WWW.WIDGET-PC.COM

#include <stdio.h>
#include <iostream>
using namespace std;

void myPascal( int *arrayOfNum, int row, int column, int currentLevel ){
	
	//INICIAMOS NUESTRO ARREGLO PARA EL NUEVO NIVEL
	int *newArray = new int [ currentLevel + 1 ];		

	//CALCULAMOS EL NUEVO NIVEL
	for( int i=currentLevel-1; i>0; i-- )	
		newArray[ i ] = arrayOfNum[ i ] + arrayOfNum[ i - 1 ];

	//COMPLETAMOS LOS VALORES
	newArray[ 0 ] = newArray[ currentLevel ] = 1;

	//ACTUALIZAMOS NUESTRO CONTADOR
	currentLevel++;

	//CASO BASE
	if( row == currentLevel ) cout << "Answer: " << newArray[ column - 1 ];
	//PROCESO RECURSIVO
	else myPascal( newArray, row, column, currentLevel );	

}

int main(){
	//OBTENEMOS LOS DATOS
	int row = 0, column = 0;
	cout << "Row? "; cin >> row;
	cout << "Column? "; cin >> column;
	int arrayOfNumebers[] = {1,1};

	//VALIDACIONES Y LLAMADA RECURSIVA
	if( row <= 0 || column <= 0 )cout << "The numbers must be greater than zero.";	
	else if( column > row ) cout << "The row must be less than or equal to the column.";	
	else if( row == 1 || row == 2 )  "Answer: 1";
	else myPascal( arrayOfNumebers, row, column, 2 );

	return 0;
}