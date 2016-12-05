//DESARROLLADO POR LUIYIT HERN�NDEZ - PARA WIDGET PC - VENEZUELA
//RECURSIVIDAD - 2011
//TODOS LOS DERECHOS RESERVADOS - WWW.WIDGET-PC.COM

#include <stdio.h>
#include <iostream>
using namespace std;

int invertNumber( int num, int count ){
	//CASO BASE
	if( num < 10 )return num;

	//SUBPROCESO. DIVIDIR DIGITO
	int rest = num % 10;

	int tempRes = rest;
	//SUBPROCESO. ESCALAR NUMERO HASTA LA UNIDAD CORRESPONDIENTE
	for(int i=count; i>0; i-- )
		tempRes *= 10;
		cout << tempRes << endl;

	return tempRes + invertNumber( num / 10, count - 1 );
}

int main(){
	int num = 0;
	cout << "Number? "; cin >> num;

	//NOS ASEGURAMOS QUE EL NUMERO SEA POSITIVO
	if( num < 0 ) num *= -1;

	int copyNum = num, conuter = 1;
	while( ( copyNum /= 10 ) >= 10 ) conuter++;

	cout << "Answer: " << invertNumber( num, conuter) << endl;
	return 0;
}
