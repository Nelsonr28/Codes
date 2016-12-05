/*
Victor Arica C,I, 23073737Secc. C3
Jorge Gavidia C.I. 18836874 Secc. C1 
Proyecto 3 
*/
#include <iostream>
#include <FreeImage.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fstream>
#include <sstream> 

using namespace std;

//Variable Global:
int Arreglo[1024];
int altura, anchog, altog;
bool Cargada=false;
bool consultada=false;
int contando=0;
int contando2;
int matriz [1024][1024];//imagen 

//---------------------------------------------------CLASE QUADTREE--------------------------------------------------------------------------------------

class Nodo {
  //Atributos Clase Nodo
  private: 
  int valor;
  Nodo *Hijo[3]; 
  friend class QuadTree;
}; 

class QuadTree {
  //Atributos Clase QuadTree
  public: 
    typedef Nodo *TipoPosicion;
    int tam;
    
  private:
  TipoPosicion raiz, paux;
  
  //Métodos de la Clase QuadTree
public:

  QuadTree() {
    raiz=NULL;
    tam=0;
  }
  

  //Prototipo Función Es Vacío
  bool EsVacio();
  
  //Prototipo Acción Insertar Primer Nodo
  void InsertarPrimero(int Arr, int indice);
  
  //Prototipo Acción Insertar Resto de Nodos
  void InsertarResto(int resto);
  
  //Prototipo Acción Arbolizacion1 (Insertar Raiz Principal)
  void Arbolizacion1(/*int vector[]*/int conta);
   
  //Prototipo Acción Arbolizacion2 (Insertar el Resto)
  void Arbolizacion2(Nodo *A, int &ini, int contan);
  
    //Prototipo Acción Destructor
  void Destructor (int cont);
  
  //Prototipo Función Consultar Raiz
  Nodo* ConsultarRaiz ();
  
  //Prototipo Función Altura de Árbol
  int Altura(Nodo* mir);
  
 //Prototipo Accion Invertir Colores
 void InvertirC(TipoPosicion B);
 
 //Prototipo Accion Imprimir Nodos
 void ImprimirN(int &contn, int &contb, int &contg, TipoPosicion C);
 
 //Prototipo Accion Imprimir Preorden
 void ImprimirPre(TipoPosicion D);
 
 //Prototipo Accion Flip Horizontal
 void FlipH(TipoPosicion E);
  
};

//Accion Flip Horizontal
void QuadTree::FlipH(TipoPosicion E){
	if (E!=NULL){
		TipoPosicion aux1, aux2;
		
		if (E->valor==2){
			aux1=E->Hijo[0];
			E->Hijo[0]=E->Hijo[3];
			E->Hijo[3]=aux1;
	    
	        aux2=E->Hijo[1];
	        E->Hijo[1]=E->Hijo[2];
	        E->Hijo[2]=aux2;
	       
	        
	        for (int y=0; y<4; y++){
	        FlipH(E->Hijo[y]);
	        
			}//for
	      
		}//if
		
	}//if
	
}//void Flip	
	
//Accion Imprimir Preorden
void QuadTree::ImprimirPre(TipoPosicion D){
	
	if (D!=NULL) {
		cout<<(D->valor);
		for (int c=0; c<4; c++) {
			ImprimirPre(D->Hijo[c]);
		}//for
		
	}//if 
		
}

//Acción Imprimir Nodos
void QuadTree::ImprimirN(int &contn, int &contb, int &contg, TipoPosicion C){
	
	if (C!=NULL) {
		
		if (C->valor==0){
			contn++;
		} 
		if (C->valor==1) {
			contb++;
		} 
		if (C->valor==2) {
			contg++;
		
			for (int z=0; z<4; z++) {
				ImprimirN(contn, contb, contg, C->Hijo[z]);
			}//for
		}//if 
	}//if	
}//imprimirN
	
//Accion Invertir Colores
void QuadTree::InvertirC(TipoPosicion B){
	
	if (B!=NULL) {
		if (B->valor==0){
			B->valor=1;
		} else {
			if (B->valor==1) {
				B->valor=0;
			}else {
				for (int ji=0; ji<4; ji++) {
					InvertirC(B->Hijo[ji]);
				}//for
			}//else	
		}//else
	}//if
}//InvertirC
		
//Función Altura de Arbol
int QuadTree::Altura(Nodo *mir){
	
	if (mir!=NULL) {
		int retorno, max;
		max=0;
		
		for (int im=0; im<4; im++){
			retorno=Altura(mir->Hijo[im]);
			if (retorno>max) {
				max=retorno;
			}//if
		}//for
		return max+1;
	} else {
		return -1;
	}//else
}//Altura
	
//Función EsVacio
bool QuadTree::EsVacio() {
  return raiz==NULL;
}

//Funcion Consultar Raiz
Nodo* QuadTree::ConsultarRaiz() {
	return raiz;
}
 
//Acción Destructor QuadTree
void QuadTree::Destructor(int cont) {
	
	TipoPosicion aux;
	
	if (cont==0) {
		aux=raiz;
	}//if 
	
	cont++;

	if ((raiz != NULL)&&((raiz->valor==1)||(raiz->valor==0))) {
		delete raiz;
		raiz = NULL;
	}else{
		if (aux!=NULL) {
			if (((raiz->Hijo[0]->valor)==0) || ((raiz->Hijo[0]->valor)==1)) {
				delete (raiz->Hijo[0]);
			} else {
				if (raiz->Hijo[0]!=NULL) {						
					raiz=raiz->Hijo[0];
					Destructor(0);
					raiz = aux;
				}//if
								
				if (raiz->Hijo[1]!=NULL){	
					raiz=raiz->Hijo[1];
					Destructor(0);
					raiz = aux;
				}//if
	
				if (raiz->Hijo[2]!=NULL) {
					raiz=raiz->Hijo[2];
					Destructor(0);
					raiz = aux;
				}//if
			
				if (raiz->Hijo[3]!=NULL) {
					raiz=raiz->Hijo[3];
					Destructor(0);
					raiz = aux;
				}//if
		
			}//else
		}//if
	}//else
	
	raiz=NULL;	
	aux=NULL;
	//cout<<endl;
}//fin destructor

//Acción Arbolizacion2 (Insertar Resto de los Nodos)
void QuadTree::Arbolizacion2 (Nodo *A, int &ini, int contan) {
	
	if (ini<contan) {
								
		if (Arreglo[ini]==2) { //Revisamos el Primer Hijo de Nuestra Raiz
			Nodo *nuevo= new Nodo();
			nuevo->valor=Arreglo[ini];
			nuevo->Hijo[0]=NULL;
			nuevo->Hijo[1]=NULL;
			nuevo->Hijo[2]=NULL;
			nuevo->Hijo[3]=NULL;
			A->Hijo[0]=nuevo;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
			Arbolizacion2(nuevo, ini, contan);
		} else {
			Nodo *nuevo= new Nodo();
			nuevo->valor=Arreglo[ini];
			nuevo->Hijo[0]=NULL;
			nuevo->Hijo[1]=NULL;
			nuevo->Hijo[2]=NULL;
			nuevo->Hijo[3]=NULL;
			A->Hijo[0]=nuevo;
			//cout<<"Insertando Nodo" <<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
		}//else
	
		if (Arreglo[ini]==2) {//Revisamos el Segundo Hijo
			Nodo *nuevo1= new Nodo();
			nuevo1->valor=Arreglo[ini];
			nuevo1->Hijo[0]=NULL;
			nuevo1->Hijo[1]=NULL;
			nuevo1->Hijo[2]=NULL;
			nuevo1->Hijo[3]=NULL;
			A->Hijo[1]=nuevo1;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
			Arbolizacion2(nuevo1, ini, contan);
		} else {
			Nodo *nuevo1= new Nodo();
			nuevo1->valor=Arreglo[ini];
			nuevo1->Hijo[0]=NULL;
			nuevo1->Hijo[1]=NULL;
			nuevo1->Hijo[2]=NULL;
			nuevo1->Hijo[3]=NULL;
			A->Hijo[1]=nuevo1;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
		}//else
	
		if (Arreglo[ini]==2) {//Revisamos el Tercer Hijo
			Nodo *nuevo2= new Nodo();
			nuevo2->valor=Arreglo[ini];
			nuevo2->Hijo[0]=NULL;
			nuevo2->Hijo[1]=NULL;
			nuevo2->Hijo[2]=NULL;
			nuevo2->Hijo[3]=NULL;
			A->Hijo[2]=nuevo2;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
			Arbolizacion2(nuevo2, ini, contan);
		} else {
			Nodo *nuevo2= new Nodo();
			nuevo2->valor=Arreglo[ini];
			nuevo2->Hijo[0]=NULL;
			nuevo2->Hijo[1]=NULL;
			nuevo2->Hijo[2]=NULL;
			nuevo2->Hijo[3]=NULL;
			A->Hijo[2]=nuevo2;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
		}//else
		
		if (Arreglo[ini]==2) {//Revisamos el Cuarto Hijo
			Nodo *nuevo3= new Nodo();
			nuevo3->valor=Arreglo[ini];
			nuevo3->Hijo[0]=NULL;
			nuevo3->Hijo[1]=NULL;
			nuevo3->Hijo[2]=NULL;
			nuevo3->Hijo[3]=NULL;
			A->Hijo[3]=nuevo3;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
			Arbolizacion2(nuevo3, ini, contan);
		} else {
			Nodo *nuevo3= new Nodo();
			nuevo3->valor=Arreglo[ini];
			nuevo3->Hijo[0]=NULL;
			nuevo3->Hijo[1]=NULL;
			nuevo3->Hijo[2]=NULL;
			nuevo3->Hijo[3]=NULL;
			A->Hijo[3]=nuevo3;
			//cout<<"Insertando Nodo "<<ini<<" :"<<Arreglo[ini]<<endl;
			ini++;
		}//else
		 
	}//if
}//Arbolizacion2
	
//Acción Arbolizacion1 (Insertar Raiz Principal)
void QuadTree::Arbolizacion1 (int conta) {
	
	if (raiz==NULL){
	raiz=new Nodo();
	raiz->valor=Arreglo[0];
	raiz->Hijo[0]=NULL;
	raiz->Hijo[1]=NULL;
	raiz->Hijo[2]=NULL;
	raiz->Hijo[3]=NULL;
	//cout<<endl;
	//cout<<"Insertando Raiz: "<<raiz->valor<<endl;
	int i=1;
	Arbolizacion2 (raiz, i, conta);
	}//if
}//Arbolizacion1
 
//-------------------------------------------------FIN CLASE QUADTREE-------------------------------------------------------------------------------------

QuadTree Arbol;  
//**********************************************************//  
  
void Insercion (int numerito, int mayorcito) {
    
    Arreglo[mayorcito]=numerito;
    
 }//Insercion
  
//Acción Convertir
void Convertir (int **MyArray, int l1, int l2, int R, int C, bool active)
{
  int li1, li2;
  li1=l1; li2=l2; //li1=0; li2=0;
  bool certeza;
  int ayu;
  int k=0, l=0;
  
  if ((R==1) || (C==1) || (li1==1) || (li2==1)) { //R=limite=C;

  } else {
	for (k=li1; k<R; k++) {
		for (l=li2; l<C; l++) {
			if ((k==li1) && (l==li2)) {
				ayu=MyArray[k][l];
				continue;
			}//if
			if (MyArray[k][l]==ayu) {
			certeza=true;
				if ((k==R-1) && (l==C-1) && (certeza==true)) {
	 				Insercion(ayu, contando);
					contando++;
					break;
				}//if
			} else {
				certeza=false;
				Insercion(2, contando);
				contando++;
				
				Convertir(MyArray,li1, li2, (li1+R)/2, (li2+C)/2, active); 
				Convertir(MyArray,li1, (li2+C)/2, (li1+R)/2, C, active);
				Convertir(MyArray,(li1+R)/2, (li2+C)/2, R, C, active);
				Convertir(MyArray,(li1+R)/2, li2, R, (li2+C)/2, active);
	
				break;
			}//else
		}//for
		
		if (certeza==false) {
			break;
		}//if
	}//for	
  }//else 
}//convertir

//Función Es Potencia
bool EsPotencia (int n) {
 
  if (n<=0) {
    return false;
  } else {
		if ((n==1)||(n==2)) {
		return true;
		} else {
			if (n%2==0) {
			int aux;
			aux=n/2;
			if (aux%2!=0) {
			return false;
			} else {
				return EsPotencia(aux); 
			}
	} else {
		return false;
	}//else 
	}//else
	}//if
}//Espotencia

//Función Cargar Imágen
unsigned char* CargarImagen (const char * NombreI, int &width, int &height) 
{
  //Se obtiene el formato de la imágen.
  FREE_IMAGE_FORMAT formatImage = FreeImage_GetFileType(NombreI);
  
  //Se carga la imágen utilizando FreeImage.
  FIBITMAP* FIbitmap = FreeImage_Load(formatImage, NombreI, 0);
  FIbitmap = FreeImage_ConvertToStandardType(FIbitmap);
  
  //Se obtiene el ancho y el alto de la imágen.
  width = FreeImage_GetWidth(FIbitmap);
  height = FreeImage_GetHeight(FIbitmap);
  anchog=width;
  altog=height;
  
  
  if (width!=height) {
    unsigned char *c = NULL;
    return c;
  } else {
    bool certeza;
    certeza= EsPotencia(width);
    if (certeza==false) {
       unsigned char *d = NULL;
       return d;
    } else {
		  
		  //Se crea la matriz de colores.
		  unsigned char *b = new unsigned char[width * height];
		  
		  //Se copian los colores a la matriz creada.
		  FreeImage_ConvertToRawBits(b, FIbitmap, width, 8, FI_RGBA_RED_MASK, 0, 0, TRUE);
		  
		  //Se cierra el bitmap
		  FreeImage_Unload(FIbitmap);
		  
		  return b;
	  }//else
	}//else
}//cargar Imagen

void cambiar_colores (){
	
	//cout<< "cambiar colores "<<endl;
	//cout<<anchog<<" "<<altog<<endl;
	for (int i=0;i<altog;i++) {
			
			for(int j=0;j<anchog;j++) {
				if (matriz[i][j]==0){
					matriz[i][j]=1;
				}else{
					matriz[i][j]=0;
				}
				//cout<<matriz[i][j];
			}
			//cout<<endl;
		}	
}//cambiar Colores	

void flip (){
	
	//cout<< "flip"<<endl;
	//cout<<anchog<<" "<<altog<<endl;
	int aux;
	for (int i=0;i<altog;i++) { // y
			
			for(int j=0;j<(anchog/2);j++) { // me muevo de 0 a n/2 //x
				aux=matriz[i][j];
				matriz[i][j]=matriz[i][(anchog-1)-j];
				matriz[i][(anchog-1)-j]=aux;
			}
	}//for	
}//flip

void imprime_matriz () {//imprime matriz 
		
	//cout<< "imprime matriz "<<endl;
	//cout<<anchog<<" "<<altog<<endl;
	for (int i=0;i<altog;i++) {
			
			for(int j=0;j<anchog;j++) {
				
				cout<<matriz[i][j];
			}
			cout<<endl;
		}	
}

char archivo[100];

void Menu (QuadTree &Arbol) {
 cout<<endl<<endl;
 cout<<"MENU:\n";
 cout<<"1. Cargar imágen.\n";
 cout<<"2. Salvar imágen en formato quadtree.\n";
 cout<<"3. Imprimir el número de nodos Blancos, Negros y Grises, y la altura del árbol.\n";
 cout<<"4. Invertir los colores.\n";
 cout<<"5. Imprimir en pre-orden.\n";
 cout<<"6. Flip horizontal.\n";
 cout<<"7. Mostrar imágen.\n";
 cout<<"8. Salir.\n";
 int op;
 cin>>op;
  
//------------------------------------------------ OPCIÓN 1: CARGAR IMÁGEN --------------------------------------------------------------------------------
  
  if (op==1) {
	Cargada=false;
	  contando2=0;
	  string narchivo, narchivo4, narchivo5;
	  cout<<endl;
	  cout<<"Introduza el nombre del archivo que desea procesar.\n";
	  cin>> narchivo;
	  cout<<"El archivo que usted desea procesar es: "<<narchivo<<endl;    
	  unsigned char *prueba;
	  int alto1, ancho1;
	  prueba=CargarImagen(narchivo.c_str(), ancho1, alto1);
    
    narchivo4= narchivo.substr(narchivo.length()-4, narchivo.length());
    narchivo5= narchivo.substr(narchivo.length()-3, narchivo.length());
    
    if ((narchivo4==".bmp") || (narchivo4==".jpg") || (narchivo4==".png") || (narchivo4==".qt")){
		
	if (prueba==NULL) {
	cout<<"Error. La imágen debe ser monocromática, cuadrada y sus dimensiones potencias de 2.\n";
    Menu(Arbol);
	} else {
					
		  freopen("salida.out", "wt", stdout);
		  unsigned char *imagen;
		  int alto2, ancho2;
		  imagen=CargarImagen(narchivo.c_str(), ancho2, alto2);
		  cout<<ancho2<<" "<<alto2<<endl;
		  for (int i=0; i<alto2; i++)
		  {
			for (int j=0; j<ancho2; j++)
			{
			  if (imagen[i*ancho2+j]>0){
				cout<<1<<" ";
				matriz[i][j]=1;
			  }else {
				cout<<0<<" ";
				matriz[i][j]=0;
				}
			}
				cout<<endl;
		  }
		fclose(stdout);//cerrar archivo
	}
	freopen ("/dev/tty", "w", stdout);//devuelve el mando al a consola

	ifstream Salida;
	string line, l1, l2;
	int num;
	Salida.open("salida.out", ios::in);

	if (Salida.fail()) {
	  cout<<"Error. El archivo no puede ser accedido correctamente.\n";
	} else {
		 getline(Salida, line);
		 stringstream linea (stringstream::in | stringstream::out);
		 linea<<line;
		 linea>>l1;
		 linea>>l2;
		 //cout<<l1<<" "<<l2<<endl;
		 int limite1;
		 limite1=atoi(l2.c_str());
		 int limite2;
		 limite2=limite1;
		 int m;
		 bool activo=false;;
	 	 int **Figura;
	 	 Figura=new int*[limite1];
		for(m=0;m<limite1;++m)
			Figura[m] = new int[limite2];
			int n, o;
			while ((!Salida.eof()) && (n!=limite1) && (o!=limite2)) {
	   			if (Salida.eof()) {
				break; 
				}
			   for (n=0; n<limite1; n++) {
				 for (o=0; o<limite2; o++) {
				   Salida>>num;
				   Figura[n][o]=num;
				 }
			   } 
			}//while
	 Salida.close();
	 
	 Convertir(Figura, 0, 0, limite1, limite2, activo);
	 
	 for (int ho=0; ho<contando; ho++) {
		 //cout<<Arreglo[ho]<<" ";
	 }//for
	 
	 if (consultada==true){
	 Arbol.Destructor(0);
	 }//if
	 consultada=true;
	 Arbol.Arbolizacion1(contando);
	 altura=Arbol.Altura(Arbol.ConsultarRaiz());
	 contando2=contando;
	 contando=0; 
	 Cargada=true;	 
}//Opcion 1
	
} else {
	cout<<"Los formatos válidos para esta imágen son: .bmp, .qt, .jpg, .png \n";
}
	Menu(Arbol);     
  
//------------------------------------------------ FIN DE OPCIÓN 1 ----------------------------------------------------------------------------------------
  
  }else {
	  
//-------------------------------------------------OPCION 2: SALVAR IMAGEN QUADTREE--------------------------------------------------------	  
    if (op==2) { 
	
		if (Cargada==true){
		
	 	string narchivo2, narchivo3;
		cout<<"Introduzca el nombre del archivo con extension: .qt que desea procesar.\n";
		cin>>narchivo2;
		//cout<<narchivo2<<endl;
		 narchivo3= narchivo2.substr(narchivo2.length()-3, narchivo2.length());
		// cout<<narchivo3<<endl;
		 if (narchivo3!=".qt"){
			 cout<<"Error. El archivo es inválido. Debe poseer extensión .qt\n";
		 } else {
		  
		 
		freopen(narchivo2.c_str(), "wt", stdout);
	    cout<<anchog<<" "<<altog<<endl;
	    Arbol.ImprimirPre(Arbol.ConsultarRaiz());
		
		fclose(stdout);
		
		freopen ("/dev/tty", "w", stdout);//devuelve el mando al a consola
	}
		
	} else {
		cout<<"Error. No hay ninguna imágen cargada en memoria.\n";
	}
		
      Menu(Arbol);
     
//-------------------------------------------------FIN OPCION 2----------------------------------------------------------------------------      
    } else {
		
//--------------------------------------------------OPCION 3: IMPRIMIR CARACTERISTICAS DEL ARBOL---------------------------------------------		
	if (op==3) {
		  
		  if (Cargada==true) {
		  int contn, contg, contb, alth;
		  contn=0; contg=0; contb=0;
			
			Arbol.ImprimirN(contn, contb, contg, Arbol.ConsultarRaiz());
			alth=(Arbol.Altura(Arbol.ConsultarRaiz()))-1;  
			
			cout<<"B="<<contb<<", N="<<contn<<", G="<<contg<<", H="<<alth<<endl;
			  
			} else {
				cout<<"No hay ninguna imágen cargada en memoria.\n";
			}//else
	Menu(Arbol);
      
 //----------------------------------------------------FIN OPCION 3-------------------------------------------------------------------------     
 } else {
		  
//--------------------------------------------------OPCION 4: INVERTIR COLORES---------------------------------------		  
	if (op==4) {
		
		
		if(Cargada==true){
		Arbol.InvertirC(Arbol.ConsultarRaiz());
		cambiar_colores();
		cout<<"Operacion exitosa.\n";
	} else {
		cout<<"Error. No hay ninguna imágen cargada en memoria.\n";
	}
	  Menu(Arbol);
	  
//-----------------------------------------------------FIN OPCION 4-----------------------------------------------------	  
	} else {
		
//---------------------------------------------------OPCION 5: IMPRIMIR EN PREORDEN----------------------------------------------------		
	  if (op==5) {
		  
		if (Cargada==true) {  
			
			cout<<endl;
			Arbol.ImprimirPre(Arbol.ConsultarRaiz());
		
		} else {
		
			cout<<"No hay ninguna imágen cargada en memoria.\n";
		}//else
	    Menu(Arbol);
	    
//-----------------------------------------------------FIN OPCION 5---------------------------------------------------------------------	    
	  } else {
		  
//---------------------------------------------------OPCION 6: FLIP HORIZONTAL---------------------------------------------		  
	if (op==6) {
	     if (Cargada==true){
			Arbol.FlipH(Arbol.ConsultarRaiz());
			//Arbol.ImprimirPre(Arbol.ConsultarRaiz());
			flip();
			cout<<"\n Operacion exitosa.\n";  
		  } else {
			  cout<<"Error. No hay ninguna imágen cargada en memoria.\n";
		  }
     Menu(Arbol);
	      
//------------------------------------------------------FIN OPCION 6-------------------------------------------------------
	} else {
//---------------------------------------------------OPCION 7: IMPRIMIR IMAGEN---------------------------------------------	
	if (op==7) {
		if (Cargada==true) {
		imprime_matriz();
	}else{
		cout<<"Error. No hay ninguna imagen cargada en memoria.\n";
	}
	    Menu(Arbol);
//------------------------------------------------------FIN OPCION 7--------------------------------------------------------
	 } else {
//----------------------------------------------------OPCION 8:SALIR Y DESTRUIR--------------------------------------------------------	
	if (op==8) {
		
			Arbol.Destructor(0);
//----------------------------------------------------FIN OPCION 8--------------------------------------------------------			
	} else {
    
		cout<<"Error.\n";
		Menu(Arbol);

	}//else opcion 8
	}//else opcion 7
	}//else opcion 6
	}//else opcion 5
	}//else opcion 4
    }//else opcion 3
	}//else opcion 2
	}//else opcion 1
}//void menu

int main() 
{

Menu(Arbol);
 
return 0;
}
