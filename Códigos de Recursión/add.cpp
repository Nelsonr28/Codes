//DESARROLLADO POR LUIYIT HERNÁNDEZ - PARA WIDGET PC - VENEZUELA
//RECURSIVIDAD - 2011
//TODOS LOS DERECHOS RESERVADOS - WWW.WIDGET-PC.COM

#include <stdio.h>
#include <iostream>
using namespace std;

int addNumbers( int num ){
	if( num == 1 )return 1;						//CASO BASE
	return num + addNumbers( num - 1 );			//SUBPROCESO
}

int factorial(int num ){
	if ( num==0 ) return 1;						//CASO BASE
	return num*factorial( num-1 );				//SUBPROCESO
}

int firstNumber( int num ){
	if( num < 10 )return num;
	return firstNumber( num - ( num % 10 ) );	
}

/*REALIZA LAS VALIDACIONES NECESARIAS PARA USAR FACTORIAL O FIRSTNUMER*/

int main(){

	int num = 0;
	cout << "Number? ";
	cin >> num;

	//CONDICION DE PARTIDA. NUMERO > 1
	if( num > 1 ) cout << "Answer: " << addNumbers( num );	

	//CASO TRIVIAL
	else if( num == 1 || num == 0 )cout << "Answer: " << num;	

	//CASO DE ERROR
	else cout << "The number is not positive.";	
		
	return 0;
}
