#include<iostream>
using namespace std;
//##############################################################################
class imagen         
{
	public:
		char caracter;
		int ancho,alto;          
	public:                    
		void rotar()        // ESTA CLASE ES PARA ALMACENAR LAS CARACTERISTICAS DE LAS IMAGENES
		{                   // ANCHO,ALTO, Y EL CARACTER QUE SE HA DE USAR ADEMAS, PERMITE
			int aux=ancho;   // UNA ACCCION PARA ROTAR LA IMAGEN, LO QUE HACE ES INTERCAMBIAR
			ancho=alto;     // LOS VALORES DEL ANCHO POR EL ALTO Y VICEVERSA
			alto=aux;
		}
		
};
//##############################################################################

imagen * imagenes[32]; //UN ARREGLO DE OBJETOS DE CLASE IMAGEN,PARA GUARDAR CADA UNA DE LAS IMAGENES QUE SE INGRESEN
bool imagenes_usadas[32],encontro=false,solucion=false; // MARCARA LAS IMAGENES QUE HAN SIDO INSERTADAS

int posicionj=0,posicioni=0,menor=1000,N=0,mejori=0,mejorj=0,pixeles=0;// ESTAS VARIABLES SON PARA LLEVAR LAS DIMENSIONES DE LA MATRIZ DE MI SOLUCION PARCIAL, DE LA MEJOR SOLUCION,LA CANTIDAD DE IMAGENES
	
char matriz[441][441],mejor_solucion[441][441];// UNA MATRIZ DE CARACTERES DONDE SE ALMACENARAN LOS CARACTERES DE LAS IMAGENES
void suma_dimensiones()
{
	
	for(int i=0;i<N;i++)
	{
		pixeles=pixeles+(imagenes[i]->ancho*imagenes[i]->alto);
	}
}

//##############################################################################
void mostrar()
{
	
	cout<<mejorj<< " "<<mejori<<endl<<endl;
    for(int i=0;i<mejori;i++)
	{
		for(int j=0;j<mejorj;j++)            // MUESTRA LA MEJOR SOLUCION DESPUES DEL BACKTRACKING
		{
			cout<<mejor_solucion[i][j];		
		}
		cout<<"\n";
	}
	cout<<endl;
	
}
//##############################################################################

void guardar_solucion(int i,int j)
{
	if(i*j<menor)
	{
		menor=i*j;
	
	mejori=i;
	mejorj=j;
	for(int i=0;i<mejori;i++) // GUARDA LA SOLUCION PARCIAL,COMPARANDO QUE SEA LA MEJOR
	{
		for(int j=0;j<mejorj;j++)
		{
			mejor_solucion[i][j]=matriz[i][j];
		}
	}

	}	
}
//##############################################################################

bool alternativa_valida(int i)
{
	if(!imagenes_usadas[i])
	{                       // COMPRUEBA QUE LA IMAGEN QUE SE DESEA TOMAR NO HAYA SIDO INSERTADA
		return true;
	}
	return false;
}
//##############################################################################
void marcar_opcion(int i)
{
	imagenes_usadas[i]=true;
}
void desmarcar_opcion(int i) // MARCA Y DESAMARCA LA IMAGEN QUE SE INSERTO O SE BORRO RESPECTIVAMENTE
{
	imagenes_usadas[i]=false;
}
//##############################################################################
bool insertadas_todas()
{
	for(int i=0;i<N;i++)
	{
		if(!imagenes_usadas[i]) // COMPRUEBA QUE TODAS LAS IMAGENES DE LAS QUE SE DISPONE HAYAN SIDO COLOCADAS EN EL ATLAS
		{
			return false;
		}
	}
	return true;
}
//##############################################################################
void actualizari()
{
	int i=0,j=0,acum=0,acum2=0;
	bool caracter=false;
	while(i!=21)
	{
		while(j!=21 && !caracter)
		{
			if(matriz[i][j]!='#')
			{
				acum++;
				caracter=true;
			}
			j++;      // COMO EL BACKTRACKING PRUEBA TODAS LAS POSIBILIDADES AL INSERTAR LAS IMAGENES
		}             // PARA HAYAR LA MEJOR COLOCACION, ESTA ACCION ME PERMITE ACTUALIZAR O MEJOR DICHO
		if(acum!=0)   // VERIFICAR QUE FILAS Y QUE COLUMNAS ESTAN LLENAS O ESTAN SIENDO USADAS
		{             // LAS ACCIONES DE ACTUALIZARI Y ACTUALIZARJ PERMITEN ESTO,PARA COMPROBAR QUE LA
			acum2++;  // DIMENSION DE UNA SOLUCION PARCIAL ES LA MEJOR O NO
		}
		i++;
		j=0;
		acum=0;
		caracter=false;
	}
	posicioni=acum2;
}

void actualizarj()
{
	int i=0,j=0,acum=0,caracteres=0;
	bool caracter=false;
	while(i!=21)
	{
		while(j!=21 && !caracter)
		{
			if(matriz[j][i]!='#')
			{
				acum++;
				caracter=true;
			}
			j++;
		}
		if(acum!=0)
		{
			caracteres++;
		}
		acum=0;
		j=0;
		i++;
		caracter=false;
	}
	posicionj=caracteres;
}
//##############################################################################
void inicializar()
{
		for(int i=0;i<21;i++) 
	{                        
	                           
		for(int j=0;j<21;j++)
		{
		matriz[i][j]='#';          // RELLENA LAS MATRICES (matriz,mejor_solucion)
		mejor_solucion[i][j]='#'; //CON EL CARACTER '#' 	
		}                   
	}
	                        
		for(int j=0;j<32;j++)
		{
		imagenes[j]=new imagen();// INICIALIZA LOS OBJETOS DE CLASE IMAGEN
		imagenes_usadas[j]=false; // INICIALIZA EN FALSO EL ARREGLO DE BOOL	
		}                         // PARA DENOTAR QUE NINGUNA SE HA USADO
}
//##############################################################################

void eliminar_imagen(imagen*a_insertar)
{
	int i=0,j=0,aux1=0,aux2=0;
	bool listo=false;
	while(i!=21 && !listo)
	{
		while(j!=21 &&!listo)
		{
			if(matriz[i][j]==a_insertar->caracter)
			
			{   listo=true;
		
				int fila=i,columna=j;
				while(aux1!=a_insertar->alto)
				{
					while(aux2!=a_insertar->ancho)  //ELIMINA LA IMAGEN QUE SE INSERTO
					{                               // LO QUE HACE ES PONER UN '#' EN DONDE HABIA UN CARACTER
						matriz[fila][columna]='#'; 
						columna++;
						aux2++;
					}
					columna=j;
					fila++;
					aux2=0;
					aux1++;
				}
			}
			j++;
		}
		i++;
		j=0;
	}
	actualizari();
	actualizarj();

	
}
//##############################################################################
bool hay_espacio(int ancho,int alto,int j,int i=0)
{
	
int aux1=j,ancho2=0,alto2=0,aux2=i;
	while(alto2!=alto)
 	{
 		while(ancho2!=ancho)
 		{
 			if(matriz[aux2][aux1]!='#')
 			{
 				
 			return false;	
 			                 //VERIFICA QUE EN LA FILA Y COLUMNA DONDE SE VA A INSERTAR
 			}                // LA IMAGEN ESTA DESOCUPADO, RETORNA VERDADERO EN CASO AFIRMATIVO
 			aux1++;          // Y FALSO EN CASO CONTRARIO
 			ancho2++;
 		}
 		aux1=j;
 		ancho2=0;
 		aux2++;
 		alto2++;
 	}
 	return true;
}
//##############################################################################

void insertar_imagen_debajo(imagen*a_insertar)
{   
bool encajo_pieza=false;                
int i=0,parada=0,auxiliar=posicioni,filas=0,columnas=0,auxiliar_columnas=0;

while(filas!=posicioni && !encajo_pieza)
{
	while(columnas!=posicionj && !encajo_pieza)
	{
		
		if(hay_espacio(a_insertar->ancho,a_insertar->alto,columnas,filas)) //INSERTA LA IMAGEN DEBAJO DE OTRA QUE YA HAYA SIDO INSERTADA
		{
			
			
		auxiliar=filas;
		auxiliar_columnas=columnas;
		encajo_pieza=true;	
	
		}
		columnas++;
	}
	columnas=0;
	filas++;
}

int respaldo=auxiliar_columnas;
while(i!=a_insertar->alto)
{
while(parada!=a_insertar->ancho)
{
	matriz[auxiliar][auxiliar_columnas]=a_insertar->caracter;  
	                 
	parada++;
	auxiliar_columnas++;
}

auxiliar_columnas=respaldo;
auxiliar++;
parada=0;
i++;
}
actualizari();
actualizarj();
}
//##############################################################################

void insertar_imagen(imagen*a_insertar)
{   
bool encajo=false;
int i=0,relleno_alto=0,aux=0;
while(i!=21 && !encajo)
{
	if(hay_espacio(a_insertar->ancho,a_insertar->alto,i))
	
	{
	
		
	int relleno_ancho=i;
		
while(relleno_alto!=a_insertar->alto)
{
	while(aux!=a_insertar->ancho)
	{
	matriz[relleno_alto][relleno_ancho]=a_insertar->caracter;// INSERTA LA IMAGEN A LA DERECHA DE OTRA IMAGEN
	relleno_ancho++;                                         //SI NO HAY IMAGENES AUN INSERTADAS ENTONCES
	aux++;                                                   //LA INSERTA EN EL PRIMER LUGAR QUE ESTE DISPONIBLE
    }
    relleno_ancho=i;
    aux=0;
    relleno_alto++;
    
} 
 
actualizari();
actualizarj();                                        
encajo=true;



}
i++;
}

}
//##############################################################################

void backtracking()  // BACTRACKING
{
	if(insertadas_todas())// VERIFICO QUE SI YA SE INSERTARON TODAS LAS IMAGENES (SOLUCION PARCIAL)
      	{
      	if(posicioni*posicionj==pixeles)// CUANDO ENCUENTRE UNA SOLUCION QUE USE TODOS LOS PIXELES PARA INTRODUCIR TODAS LAS IMAGENES DEJA DE BUSCAR OTRAS SOLUCIONES
      	{
      		solucion=true;
      	}
      	if((posicioni*posicionj)<menor);	// VERIFICO QUE LAS DIMENSIONES SEAN LAS MEJORES
      	{
      		
      	 guardar_solucion(posicioni,posicionj);//GUARDO LA SOLUCION PARCIAL
      	   
        }
      	
      	}
      	else
      	{
        int i=0;
      	while(i!=N && !solucion) // PRUEBO CON CADA IMAGEN Y VERIFICO SI YA CONSEGUI LA MEJOR SOLUCION
      	{
      	if(alternativa_valida(i))// verifico que la imagen no ha sido usada 
		{
		marcar_opcion(i);
		insertar_imagen(imagenes[i]); //inserto la imagen en el atlas tal como esta
		if(posicioni*posicionj<menor)
		{
		backtracking();
	    }
		eliminar_imagen(imagenes[i]);
	  //########################################################################
if(imagenes[i]->ancho!=imagenes[i]->alto) // LOS IF SON PARA EVITAR REDUNDANCIA EN LA RECURSIVIDAD
{
		imagenes[i]->rotar();// roto la imagen para
		insertar_imagen(imagenes[i]);// luego probar si con esa imagen rotada encuentro una mejor solucion
		if(posicioni*posicionj<menor)
		{
		backtracking(); 
	    }
		eliminar_imagen(imagenes[i]);
}
if(imagenes[i]->ancho!=imagenes[i]->alto)
		{
		imagenes[i]->rotar();
		} // deshago lo que hice anteriormente y pruebo con la imagen debajo
		insertar_imagen_debajo(imagenes[i]);
		if(posicioni*posicionj<menor)
		{
		backtracking();
	    }
		eliminar_imagen(imagenes[i]);
		
if(imagenes[i]->ancho!=imagenes[i]->alto)
      {
		imagenes[i]->rotar(); //roto la imagen y la inserto abajo y llamo a backtracking 
		insertar_imagen_debajo(imagenes[i]);
		if(posicioni*posicionj<menor)
		{
		backtracking();
	    }
		eliminar_imagen(imagenes[i]);
		imagenes[i]->rotar();
      }
		desmarcar_opcion(i);
	    
		}
		i++;
	}
}
	
} 
//##############################################################################
int main()
{
inicializar();
cin>>N;
for(int i=0;i<N;i++)
{
cin>>imagenes[i]->ancho;
cin>>imagenes[i]->alto;
cin>>imagenes[i]->caracter;	
}
suma_dimensiones();
cout<<endl;
for(int i=0;i<N;i++) 
{ 
marcar_opcion(i);
 insertar_imagen(imagenes[i]);

 backtracking();
 eliminar_imagen(imagenes[i]);
 //############################################################################## modificado
 if(imagenes[i]->ancho!=imagenes[i]->alto)
 {
 imagenes[i]->rotar();
 insertar_imagen(imagenes[i]);
 backtracking();
 eliminar_imagen(imagenes[i]);
 imagenes[i]->rotar();
 }
 //#############################################################################
 desmarcar_opcion(i);
}
mostrar();  // MUESTRO LA MEJOR SOLUCION ENCONTRADA
	
}
