#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
#include <math.h>
#include <stdlib.h>
using namespace  std;

//Esta parte se declara una arreglo Global para guardar los caracteres de codigo ASCII.

string ascii[254][1];
//ascii[][]=;


//-------------------------------------------------------------------------------------

class nodo{//Este es el nodo que trabaja la cola de prioridad y el arbol.
 public:
 	char let;
 	int can;
 	char marca;
 	string codigo;
 	nodo* sig;
 	nodo* ant;
 	nodo* der;
 	nodo* izq;
   nodo (){
 	 let=' ';
 	 can=0;
     codigo="2";
     marca=' ';
 	 sig=NULL;
 	 ant=NULL;
 	 der=NULL;
 	 izq=NULL;
 	}
};

class casilisto{//Es el nodo que guarda el texto y su cadena de bits.
 public:
 	string texto;
 	string cadena;
	casilisto(){
      texto=" ";
      cadena=" ";
	}
};

class auxiliar{//Tabla donde se tiene la letra y los bits correspondientes.
 public:
 	char letra;
 	string bits;
 	auxiliar* siguiente;
 	auxiliar* anterior;
	auxiliar(){
       letra=' ';
       bits=" ";
       siguiente=NULL;
       anterior=NULL;
	}
};

class lisprio{//Lista que maneja al nodo, la tabla y casilisto.
 public:
    int lon;
	nodo* pri;
	nodo* act;
	nodo* raiz;
	nodo* ult;
    auxiliar* primero;
    auxiliar* ultimo;
    casilisto* prime;
   lisprio(){
        pri=NULL;
        act=NULL;
        raiz=NULL;
        ult=NULL;
	    lon=0;
	    primero=NULL;
	    ultimo=NULL;
	    prime=NULL;
	}
   bool lisvacia(){//Verifica que la lista este vacia.
      return (pri==NULL);
    }
   bool lisvaciauxi(){//Verifica que la lista este vacia.
      return (primero==NULL);
    }
   void casilitexto(string l){//Se guarda una copia del texto en el nodo.
        casilisto* nuevo = new casilisto();
        prime=nuevo;
        prime->texto=l;
   }
  void casilistobits(string j){//Se guarda la cadena de bits del texto.
       prime->cadena=j;
    }
   void agregar (char x, int y){//Agrega el nodo en la cola de prioridad.
   	   nodo* nuevo = new nodo();
   	   nodo* auxi=nuevo;
   	   auxi->let=x;
   	   auxi->can=y;
       if (lisvacia()){
          pri=auxi;
          ult=auxi;
        }else{
           nodo* s;
           act=pri;
           while(act!=NULL){
           	 s=act->sig;
               if (pri->can>auxi->can){
               	   pri->ant=auxi;
                   auxi->sig=pri;
                   pri=auxi;
                   break;
                }
               if (act->can<auxi->can and s==NULL){
                   act->sig=auxi;
                   auxi->ant=act;
                   ult=auxi;
                   break;
                }
               if (act->can<auxi->can and s->can>auxi->can){
                   auxi->ant=act;
                   auxi->sig=s;
                   act->sig=auxi;
                   s->ant=auxi;
                   break;
                }
               if (act->can==auxi->can and s==NULL){
                   auxi->ant=act;
                   act->sig=auxi;
                   ult=auxi;
                   break;
                }
               if (act->can==auxi->can and s->can>auxi->can){
                   auxi->ant=act;
                   auxi->sig=s;
                   act->sig=auxi;
                   s->ant=auxi;
                   break;
                }
             act=act->sig;
            }
        }
    }
   void agregarauxi(char r, string g){//Aqui se crea la tabla con su letra y sus bits.
       auxiliar* nuevo = new auxiliar();
   	   auxiliar* auxi=nuevo;
   	   auxi->letra=r;
   	   auxi->bits=g;
       if (lisvaciauxi()){
         primero=auxi;
         ultimo=auxi;
        }else{
         ultimo->siguiente=auxi;
         ultimo=auxi;
        }
    }
   bool validar(char t){//Verifica que el caracter no se repita.
      nodo* tmp;
      int con=0;
      tmp=pri;
      while(tmp!=NULL){
           if (tmp->let==t){
             con=con+1;
             break;
            }
         tmp=tmp->sig;
        }
       if (con==0){
          return true;
        }else{
          return false;
        }
    }
   void longitud (int w){//Para saber cuando el la longitud del texto.
      lon=w;
    }
   void huffman(){//Donde se crea el arbol.
     nodo* eax, *ebx, *ecx;
     nodo* s;
     act=pri;
     int x=0;
       while(pri!=NULL){
         nodo* nuevo= new nodo();
         ecx=nuevo;
         eax=pri;
         ebx=eax->sig;
         pri=ebx->sig;
         x=eax->can+ebx->can;
         ecx->can=x;
           if (pri==NULL){
             ecx->izq=eax;
             ecx->der=ebx;
             eax->codigo="0";
             ebx->codigo="1";
             raiz=ecx;
             pri=ecx;
             break;
            }else{
             ecx->izq=eax;
             ecx->der=ebx;
             eax->codigo="0";
             ebx->codigo="1";
           while(act!=NULL){
           	 s=act->sig;
               if (pri->can>ecx->can){
               	   pri->ant=ecx;
                   ecx->sig=pri;
                   pri=ecx;
                   break;
                }
               if (act->can<ecx->can and s==NULL){
                   act->sig=ecx;
                   ecx->ant=act;
                   ult=ecx;
                   break;
                }
               if (act->can<ecx->can and s->can>ecx->can){
                   ecx->ant=act;
                   ecx->sig=s;
                   act->sig=ecx;
                   s->ant=ecx;
                   break;
                }
               if (act->can==ecx->can and s==NULL){
                   ecx->ant=act;
                   act->sig=ecx;
                   ult=ecx;
                   break;
                }
               if (act->can==ecx->can and s->can>ecx->can){
                   ecx->ant=act;
                   ecx->sig=s;
                   act->sig=ecx;
                   s->ant=ecx;
                   break;
                }
             act=act->sig;
            }
            }
        }
        recorrido(pri,"");
    }
   nodo* izquierdo (nodo* x){//Recorrido por el lado Izquierdo.
        return x->izq;
    }
   nodo* derecho(nodo* y){//Recorrido por el lado Derecho.
       return y->der;
    }
   void recorrido(nodo* z, string acum){//Recorrido del arbol.
       nodo* tmp=z;
   	   if (tmp != NULL && tmp->izq==NULL and tmp->der==NULL){
   	   	  agregarauxi(tmp->let, acum);
   	   	  //cout << tmp->let << " " << acum << endl;
   	   }else if (tmp!=NULL){
      	 recorrido(izquierdo(tmp), acum +'0');
      	 recorrido(derecho(tmp), acum +'1');
        }
    }
   void concatenar(){//Pasa el texto a la cadena de bits.
      int i=0;
      string s;
      char k;
   	  auxiliar* tmp;
   	  casilisto* tms;
   	  tms=prime;
   	   for (i=0; i<=lon; i++){
   	   	   k=tms->texto[i];
   	   	   tmp=primero;
           while (tmp!=NULL){
               if (k==tmp->letra){
         	     s=s+tmp->bits;
         	     break;
                }
             tmp=tmp->siguiente;
            }
   	    }
   	    tms->cadena=s;
    }
   void salida (){
   	  casilisto* tmp;
      string a, b, c, z;
      int num, j, x, y, i=0, resul=0, cot=0;
      int aux=0;
      tmp=prime;
     while (num!=0){
       num=tmp->cadena.length();
       resul=0;
       aux=0;
         if (num>7){
           j=num-7;
           x=num-j;
           b=tmp->cadena.substr(j);
           tmp->cadena=tmp->cadena.substr(0,j);
           y=b.length();
             for (i=y-1; i>=0; i--){
               if (b[i]=='1'){
                 resul=resul+pow(2,cot);
                 aux=pow(2,cot);
                }
               cot++;
              }
           resul=resul+32;
           printf("%c", resul);
          }else{
         	 y=tmp->cadena.length();
             for (i=y-1; i>=0; i--){
               if (tmp->cadena[i]=='1'){
                 resul=resul+pow(2,cot);
                 aux=pow(2,cot);
                }
               cot++;
              }
             resul=resul+32;
             printf("%c", resul);
    	       break;
            }
         cot=0;
        }
    }
   void mostrar(){
       casilisto* tmp;
       tmp=prime;
       cout << tmp->texto << endl;
       cout << tmp->cadena << endl;
    }
};

int main(){
  lisprio uno;
  string cadena;
  int cantidad=1;
  cout << "Indique la cadena." << endl;
  getline(cin, cadena);
  int z = cadena.length();
  uno.casilitexto(cadena);
  uno.longitud(z);
  char le;
  int i=0, j=0;
   while(i!=z){
     le=cadena[i]; 
     j=0;
       if (uno.validar(le)){//Primero consulta con validar para ver que el caracter no se alla contado.
           while(j!=z){
             j=j+1;
               if (le==cadena[j]){
                 cantidad=cantidad +1;
                }
            }
         uno.agregar(le,cantidad);//Manda la la letra y la cantidad que se repite.
         cantidad=0;
        }
     i=i+1;
    }
    uno.huffman();
    uno.concatenar();
    //uno.mostrar();
    uno.salida();
    cout << " " << endl;

 return 0;
}