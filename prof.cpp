#include <iostream>
#include <stdio.h>
#include <string>
#include <fstream>
using namespace std;

class NodoHuffman
{
 
 public:
 	char letter;
 	int freq;
 	string codigo;
  char marca;
 	NodoHuffman* next;
 	NodoHuffman* prev;
 	NodoHuffman* hder;
 	NodoHuffman* hizq;
   
  NodoHuffman ()
  {
 	 
    letter=' ';
 	  freq=0;
    codigo="2";
    marca=' ';
 	  next=NULL;
 	  prev=NULL;
 	  hder=NULL;
 	  hizq=NULL;
 	}
};

class nodoTabla//Tabla donde se tiene la letra y los bits correspondientes.
{
 public:
 	char letra;
 	string bits;
 	nodoTabla* next;
	nodoTabla()
  {
       letra=' ';
       bits=" ";
       next=NULL;
	}
};

class nodoGuardar//Es el nodo que guarda el texto y su cadena de bits.
{
 public:
  string text;
  string chain;
  nodoGuardar()
  {
      text=" ";
      chain=" ";
  }
  
};

class Priority_list
{
 public:
  
  int lon;
	NodoHuffman* head;
	NodoHuffman* act;
	NodoHuffman* root;
	NodoHuffman* tail;
  nodoTabla *prim;
  nodoTabla *ult;
  nodoGuardar *primero;

   Priority_list()
   {
        head=NULL;
        act=NULL;
        root=NULL;
        tail=NULL;
	      lon=0;
	      prim=NULL;
        ult= NULL;
        primero=NULL;
	}

  bool listVacia();
  void Insertlist(char x, int y);
  bool validate(char t);
  void CodeHuffman();
  void longitud ();
  void Print();
  void GuararText(string t);
  void Guardarbits(string b);


};


  
  bool Priority_list::listVacia()
  {
    return (head==NULL);
  }
  bool vaciaTabla()//Verifica que la lista este vacia.
  {
      nodoTabla *prim;
      return (prim==NULL);
    }
  void Priority_list::Insertlist (char x, int y)
  {//Agrega el NodoHuffman en la cola de prioridad.
   	   
    NodoHuffman* nuevo = new NodoHuffman();
   	NodoHuffman* aux=nuevo;
   	aux->letter = x;
   	aux->freq = y;
    
    if (listVacia())
    {
          head=aux;
          tail=aux;
    }else
    {
      NodoHuffman* sig;
      act=head;
      while(act!=NULL)
      {
        sig=act->next;
        
        if (head -> freq > aux -> freq)
        {
            head -> prev =aux;
            aux -> next= head;
            head = aux;
            break;
        }
        
        if (act->freq < aux->freq && sig==NULL)
        {
             act -> next=aux;
             aux -> prev=act;
             tail=aux;
              break;
        }
               
        if (act->freq < aux-> freq && sig -> freq > aux -> freq)
        {
          
              aux -> prev=act;
              aux -> next=sig;
              act -> next=aux;
              sig -> prev=aux;
               break;
        }
              
        if (act -> freq == aux -> freq && sig==NULL)
        {
              aux -> prev=act;
              act -> next=aux;
              tail=aux;
                 break;
        }
               
        if (act -> freq== aux -> freq && sig -> freq > aux -> freq)

        {
              aux -> prev=act;
              aux -> next=sig;
              act -> next=aux;
              sig -> prev=aux;
              break;
        }
             
          act=act->next;
      }
    }
  }

   bool Priority_list::validate(char t)
   {//Verifica que el caracter no se repita.
      
      NodoHuffman *aux;
      int cont=0;
      aux=head;
      
      while(aux != NULL)
      {
           if (aux -> letter == t)
           {
             cont=cont+1;
             break;
            }
              aux= aux -> next;
      }
       
       if (cont==0)
       {
          return true;
       }else
       {
          return false;
       }
    }

void Priority_list::CodeHuffman()
{//Donde se crea el arbol.
     
  NodoHuffman *aux,*hizq,*hder;
  NodoHuffman *sig;
  act=head;
  int x=0;
       
  while(head!=NULL)
  {
         
    NodoHuffman* nuevo= new NodoHuffman();
    hder=nuevo;
    aux=head;
    hizq=aux -> next;
    head=hizq -> next;
    x= aux -> freq + hizq -> freq;
    cout << aux->letter <<" "<< hizq -> letter << " " << x << endl;
    hder->freq= x;

    if (head==NULL)
    {
      hder -> hizq=aux;
      hder -> hder=hizq;
      aux  -> codigo="0";
      hizq -> codigo="1";
      head =hder;
      break;
        
    }else
    {
      hder->hizq=aux;
      hder->hder=hizq;
      aux->codigo="0";
      hizq->codigo="1";
           
      while(act!=NULL)
      {
        sig=act->next;
               
        if (head -> freq > hder -> freq)
        {
          head -> prev= hder;
          hder -> next=head;
          head=hder;
          break;
        }
               
        if (act -> freq < hder -> freq && sig==NULL)
        {
          act->next=hder;
          hder->prev=act;
          tail=hder;
          break;
        }
              
        if (act -> freq < hder -> freq && sig -> freq > hder -> freq)
       {
          hder -> prev=act;
          hder -> next=sig;
          act  -> next=hder;
          sig->prev=hder;
          break;
        }

        if (act -> freq == hder -> freq && sig==NULL)
        {
          hder->prev=act;
          act->next=hder;
          tail=hder;
          break;
        }

        if (act -> freq == hder -> freq && sig -> freq > hder -> freq)
        {
          hder -> prev=act;
          hder -> next=sig;
          act  -> next=hder;
          sig  -> prev=hder;
          break;
        }

        act=act->next;
      }
             
    }
  }
}
   
   /*void longitud ()
   {//temporalmente sin utilizar.
       NodoHuffman* tmp;
       tmp=pri;
       while(tmp!=NULL){
         lon=lon+1;
         tmp=tmp->next;
        }
        cout << lon << endl;
    }
   
   NodoHuffman* hizquierdo (NodoHuffman* x, string w)
   {//Recorrido por el lado hizquierdo.
        NodoHuffman* tmp, *as;
        string acu;
        tmp=x;
        tmp=tmp->hizq;
        acu=acu+tmp->codigo;
        return tmp;
    }
   
   NodoHuffman* hderecho(NodoHuffman* y, string w)
   {//Recorrido por el lado hderecho.
       NodoHuffman* tmp, *as;
       string acu;
       tmp=y;
       tmp=tmp->hder;
       acu=acu+tmp->codigo;
       return tmp;
    }*/

   /*void recorrido(NodoHuffman* z)
   {//Recorrido del arbol.
   	    NodoHuffman* tmp=z;
   	    //string acu;
   	    //acu=acu+tmp->codigo;
       if (tmp->hizq!=NULL){
       	 //recorrido(hizquierdo(tmp,));
         //recorrido(hderecho(tmp));
           //if (tmp->let!=pri->let){
             cout << acu << " " ;
            //}
           if (tmp->let!=' '){
           	 auxiliar* nuevo= new auxiliar();
             auxiliar* t;
             t=nuevo;
             t->letra=;
             cout << tmp->let << " -> " << acu << endl;	
            }else{
             cout << tmp->can << " -> " << acu << endl;
            }
        }else if(tmp->hder!=NULL){
            //recorrido(hderecho(tmp));
            //if (tmp->let!=pri->let){
             cout << acu << " " ;
            //}
        }
    }*/

void Priority_list::GuararText(string t)
{//Se guarda una copia del texto en el nodo.
        nodoGuardar* nuevo = new nodoGuardar();
        nodoGuardar *primero;
        primero=nuevo;
        primero->text=t;
}
void Priority_list::Guardarbits(string b)
{//Se guarda la cadena de bits del texto.

       nodoGuardar *primero;
       primero->chain=b;
}
   void Priority_list::Print()
   {
       NodoHuffman* aux;
       aux=head;
       while(aux!=NULL){
            cout << aux->letter << " " << aux->freq <<"->";
            aux=aux->next;
        }
    }


int main()
{
  
  Priority_list Queue;
  string chain;
  int c=1;
  cout <<endl<< "text" << endl;
  getline(cin, chain);
  int tam = chain.length();
  char letter;
  int i=0, j=0;
   
   while(i!= tam)
   {
     letter=chain[i]; 
     j=0;
       if (Queue.validate(letter))//Primero consulta con validar para ver que el caracter no se alla contado.
       {
           while(j!=tam)
           {
             j=j+1;
               if (letter==chain[j])
               {
                 c=c+1;
                }
            }
              Queue.Insertlist(letter,c);
              c=0;
        }
              i=i+1;
    }
    
    //Queue.longitud();
    
    Queue.Print();
    cout<<endl << " " << endl<<endl;
    Queue.CodeHuffman();
    cout << " " << endl;

 return 0;
}