#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <sstream>
using namespace  std;

//Aqui se crea la tabla que me ayudara a descomprimir 
struct table{

	string palabra;//palabra a codificar.
	char data;//caracteres a descomprimir
	string binarycode;//codigo en binario

};
//FIN TABLA////////////////////////
int main(){
	
	struct table *arreglo;
	int tamano,i=0,convertir,j=0,k=0,base2=0,tamanopalabra,aux,n;
	string concatenado,cadenafinal,concatenaraux;
	stringstream stream;
	
	
	cout<<"ingrese el tamano del arreglo"<<endl;
	cin>>tamano;
	arreglo = new struct table[tamano];//Creacion del arreglo dinamico
	cout<<"indique palabra,caracter,y codigo binario asociado"<<endl;
	//Se inicia el llenado del arreglo.

	do{
		cin>>arreglo[i].palabra;
		cin>>arreglo[i].data;
		cin>>arreglo[i].binarycode;
		i++;

	}while(i<tamano);
	//Se finaliza el llenado del arreglo.
	
	for(i=0;i<tamano;i++){
	
		cout<<arreglo[i].palabra<<arreglo[i].data<<arreglo[i].binarycode<<endl;//Para mostrar la tabla.

	}
	
	for(i=0;i<tamano;i++){
		tamanopalabra=arreglo[i].palabra.size();
		for(j=0;j<tamanopalabra;j++){
			//n=arreglo[i].palabra[j].size();
			base2=0;
			k=0;
			convertir=arreglo[i].palabra[j];
			convertir=convertir-32;
			//Se procede a convertir el decimal en binario, la variable en decimal.
			while(convertir>=1){
				base2=base2 + (convertir%2)*pow(10,k);
				convertir=convertir/2;
				k++;
			}
			
			cout<<"la letra es: "<<arreglo[i].palabra[j]<<"  y el numero en binario es: "<<base2<<endl;
			stream<<base2;
			concatenado=stream.str();
			n=concatenado.size();
			
			if(n%7!=0){
				aux=n%7;//cantidad de bits a restar;
				aux=7-aux;
				//cantidad de bits que faltan para completar;
				//cout<<"CANTIDAD DE BITS FALTANTES"<<endl;
				if(aux==1)cadenafinal="0";
				if(aux==2)cadenafinal="00";
				if(aux==3)cadenafinal="000";
				if(aux==4)cadenafinal="0000";
				if(aux==5)cadenafinal="00000";
				if(aux==6)cadenafinal="000000";
				
				concatenaraux=
				cadenafinal=cadenafinal+concatenado;
				cout<<"CADENA RESULTANTE"<<endl;
				cout<<cadenafinal<<endl;
			}
			
			
			
			
			//antes de substring hay que concatenar.
			
			
		}
	}
	
return 0;
}







