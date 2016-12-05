#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace  std;

class nodo{
 public:
 	char let;
 	int can;
 	string codigo;
 	nodo* sig;
 	nodo* ant;
 	nodo* der;
 	nodo* izq;
   nodo (){
 	 let=' ';
 	 can=0;
     codigo="2";
 	 sig=NULL;
 	 ant=NULL;
 	 der=NULL;
 	 izq=NULL;
 	}
};

class auxiliar{
 public:
 	char letra;
 	string bits;
 	auxiliar* siguiente;
	auxiliar(){
       letra=' ';
       bits=" ";
       siguiente=NULL;
	}
};

class lisprio{
 public:
    int lon;
	nodo* pri;
	nodo* act;
	nodo* raiz;
	nodo* ult;
    auxiliar* primero;
   lisprio(){
        pri=NULL;
        act=NULL;
        raiz=NULL;
        ult=NULL;
	    lon=0;
	    primero=NULL;
	}
   bool lisvacia(){//Verifica que la lista este vacia.
      return (pri==NULL);
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
         cout << eax->let <<" "<< ebx->let << " " << x << endl;
         ecx->can=x;
           if (pri==NULL){
             ecx->izq=eax;
             ecx->der=ebx;
             eax->codigo="0";
             ebx->codigo="1";
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
//        recorrido(pri);
    }
   void longitud (){//temporalmente sin utilizar.
       nodo* tmp;
       tmp=pri;
       while(tmp!=NULL){
         lon=lon+1;
         tmp=tmp->sig;
        }
        cout << lon << endl;
    }
   nodo* izquierdo (nodo* x, string w){//Recorrido por el lado Izquierdo.
        nodo* tmp, *as;
        string acu;
        tmp=x;
        tmp=tmp->izq;
        acu=acu+tmp->codigo;
        return tmp;
    }
   nodo* derecho(nodo* y, string w){//Recorrido por el lado Derecho.
       nodo* tmp, *as;
       string acu;
       tmp=y;
       tmp=tmp->der;
       acu=acu+tmp->codigo;
       return tmp;
    }
/*   void recorrido(nodo* z){//Recorrido del arbol.
   	    nodo* tmp=z;
   	    //string acu;
   	    //acu=acu+tmp->codigo;
       if (tmp->izq!=NULL){
       	 recorrido(izquierdo(tmp));
         //recorrido(derecho(tmp));
           //if (tmp->let!=pri->let){
             cout << acu << " " ;
            //}
           /*if (tmp->let!=' '){
           	 auxiliar* nuevo= new auxiliar();
             auxiliar* t;
             t=nuevo;
             t->letra=;
             cout << tmp->let << " -> " << acu << endl;	
            }/*else{
             cout << tmp->can << " -> " << acu << endl;
            }
        }else if(tmp->der!=NULL){
            recorrido(derecho(tmp));
            //if (tmp->let!=pri->let){
             cout << acu << " " ;
            //}
        }
    }*/
   void mostrar(){//temporalmente sin utilizar.
       nodo* tmp;
       tmp=pri;
       /*while(tmp!=NULL){
            cout << tmp->let << " " << tmp->can << endl;
            tmp=tmp->sig;
        }
        cout << "Primero. " << tmp->can << endl;
        cout << "Ultimo. " << ult->can<< endl;*/
    }
};

int main(){
  lisprio uno;
  string cadena;
  int cantidad=1;
  cout << "Indique la cadena." << endl;
  getline(cin, cadena);
  int z = cadena.length();
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
         uno.agregar(le,cantidad);
         cantidad=0;
        }
     i=i+1;
    }
    uno.longitud();
    uno.huffman();
    //uno.mostrar();
    cout << " " << endl;

 return 0;
}