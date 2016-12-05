#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

//*********************************************************//
typedef struct imagen{
 char Nombre_Imagen; // Indica el Nombre de la imagen
 int ancho;// Indica el ancho de la Imagen
 int largo;// Indica el largo de
} DatoImagen;
//***************************************************************//

class atlas {
	public:
			int cantidad_de_imagenes; //# cantidad de imagenes
			char Matriz [20][20]; // matriz solucion
			DatoImagen arreglo_DatoImagen[6];// arreglo que contiene la informacion de cada una de las imagenes
			
			void pedir_cantidad_de_imagenes (); // Se lee la cantidad de imagenes 
			void llenar_arreglo_DatoImagen ();// Se llena las caracteristicas de la imagen.
			void inicializar_matriz (); // Inicializa la matriz con el valor nulo 
			void mostrar_matriz();// muestra la matriz 
			void Backtraking ();
			void incluir_alternativa (DatoImagen alternativa);
			bool comprobarancho(int ancho, int punteroancho,int punterolargo);
};
//*********************Constructor*********************************//





//*********************Metodos************************************//
void atlas::pedir_cantidad_de_imagenes (){
	cout << "\n Introduzca el numero de imagenes: "; 
	cin >> cantidad_de_imagenes; 
			 
	if ( (cantidad_de_imagenes>7) || (cantidad_de_imagenes<1)){
			
		 while ((cantidad_de_imagenes>7)||(cantidad_de_imagenes<1))
 		{ 
 			cout << endl << "El numero de imagenes debe estar comprendido entre 1 y 7 incluyendolos : "; 
 			cin >> cantidad_de_imagenes; 
 		} 
 				
 	}		 
	
}
	
void atlas::llenar_arreglo_DatoImagen()  {
int i,c;
bool repetido;
	for (i=0; i<cantidad_de_imagenes; i++)
	{
		cout << "\n Introduzca nombre de la imagen # "<<i ; 
		repetido=false;
		 	 do 
 				{ 
 					if (repetido==false)
					{
						cout << endl << "C puede ser cualquier caracter ASCII comprendido en A-Z y '0'-'9' : "; 
					}	
					else 
						cout << endl << "C es un caracter que identifica a la imagen univocamente no se puede repetir : ";
					
 					cin >> arreglo_DatoImagen [i].Nombre_Imagen;
 					c=arreglo_DatoImagen [i].Nombre_Imagen; // (((c>=65)&&(c<=90))||((c>=48)&&(c=<57)))
					cout << c;
					repetido=false;
										
					if (i>0) //siemre que i>0 verificamos que no se repita el nombre
					{
						for (int j=0; j==(i-1); j++)	
						{
							if (c==arreglo_DatoImagen [j].Nombre_Imagen) //Son nombres iguales 
							{
								repetido=true;
								c=0;
							}
						}
					}				 				 
				} 	 		
 			 while (!((c>=65)&&(c<=90))&& !((c>=48)&&(c<=57)))	;
 					
		cout << "\n Introduzca ancho de la imagen # "<<i ; 
			do 
 				{ 
					cout << endl << "El ancho debe ser 1<= ancho <=3 : "; 
					cin >> arreglo_DatoImagen [i].ancho;
				}
			while ((arreglo_DatoImagen [i].ancho<1)|| (arreglo_DatoImagen [i].ancho>3) )	;
			
		cout << "\n Introduzca largo de la imagen # "<<i ; 
			do 
	 				{ 
						cout << endl << "El largo debe ser 1<= largo <=3 : "; 
						cin >> arreglo_DatoImagen [i].largo;		
					}
			while ((arreglo_DatoImagen [i].largo<1)|| (arreglo_DatoImagen [i].largo>3));
		
	}
}

void atlas::inicializar_matriz()  { //Inicializamos la Matriz en #
int i,j;
	for (i=0; i<22 ; i++)
	{
		for (j=0; j<21 ; j++)
		{
			atlas::Matriz [i][j]='#';
		}
	}

}

void atlas::mostrar_matriz()  { //Inicializamos la Matriz en #
int i,j;
	for (i=1; i=7 ; i++)
	{
		for (j=1; j=(7) ; j++)
		{
			cout << Matriz [i][j];
		}
	}

}

void atlas::incluir_alternativa (DatoImagen alternativa){

int punteroalto,punteroancho;
bool comprobarancho;

	for (punteroalto=0; (((atlas::cantidad_de_imagenes)*3)-1); punteroalto ++)
	{
			for (punteroancho=0; (((atlas::cantidad_de_imagenes)*3)-1); punteroancho ++)
			{
				if (Matriz[punteroancho][punteroalto]=='#') {
				
					comprobarancho= atlas::comprobarancho(alternativa.ancho, punteroancho, punteroalto);// comprueba q donde voy a poner la imagen se puede
				
				}
			}
				
	}
}

bool atlas::comprobarancho(int ancho, int punteroancho,int punterolargo) {

bool verificador;
int i;
 	
	for (i=0; i==(ancho); i++)
	{
		if ( (Matriz [punteroancho+i][punterolargo]) == '#' ){
			verificador=true;
		}
		else 
		i=ancho;//sale
	}
return (verificador);	
}

void atlas::Backtraking () {
DatoImagen alternativa;
int ialter;  
ialter=(-1);
	alternativa= arreglo_DatoImagen[ialter];		//iniciar alternativa, es escoger cada uno de las imagenes para meter. 

	do{
		alternativa= arreglo_DatoImagen[ialter+1];	//obtener sig alternativa;
			
		incluir_alternativa(alternativa);	//incluir_alternativa ()//IncluirAlternativa(alternativa, solucionParcial);
		
	} 
	while (ialter=2);
	
}


//********************Main**************************************//
int main (){

atlas trabajo;
trabajo.inicializar_matriz(); 


/*************************************menu*******************************/

int opcion=0;
menu:
 while( opcion != 3) 
 { 
 //muestra el  menu 
 cout << endl << " Menu: " << endl; 
 cout << "___________________________________________" << endl; 
 cout << " 1. Cantidad de Imagenes \n 2. Llenar datos de imagenes \n 3. Salir\n"; 
 
 //leemos de teclado
 cout << "\n\n\n Que desea hacer: "; 
 cin >> opcion; 
 
  	switch (opcion) 
 	{ 
 		case 1: //leer cantidad de imagenes  
		 
			trabajo.pedir_cantidad_de_imagenes ();
		 		   
 		break; 
 		
		 case 2: //llenar arreglo de imagenes 
			
				trabajo.llenar_arreglo_DatoImagen();
 		break; 
 		
		 case 3: //Salir 
		 
		 
		 break; 
 
		 default: 
 			cout << "Solo se puede introducir opciones validas comprendidas entre (1-3) !!!"; 
 			goto menu; 
 		}

}

return(0);
}



