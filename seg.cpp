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
  int len;//longitud
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
    len=0;
    prim=NULL;
    ult= NULL;
    primero=NULL;
  }
  bool listVacia();
  bool vaciaTabla();
  void Insertlist(char x, int y);
  bool validate(char t);
  void Tabla(char r, string g);
  void Travel(NodoHuffman* a, string acum);
  void CodeHuffman();
  void length (int l);
  void Concatenate();
  void Print();
  void GuararText(string t);
  void Guardarbits(string b);
};


bool Priority_list::listVacia()
{return (head==NULL);}

bool nodoTabla::vaciaTabla()//Verifica que la lista este vacia.
  {
    //nodoTabla *prim;
    return (prim==NULL);
  }
  void Priority_list::Insertlist (char x, int y)//Agrega el NodoHuffman en la cola de prioridad.
  {
       
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

   bool Priority_list::validate(char t)//Verifica que el caracter no se repita.
   {
      
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

NodoHuffman* hizquierdo (NodoHuffman* i)//Recorrido por el lado hizquierdo.
  {
      return i->hizq;
        
  }
   
NodoHuffman* hderecho(NodoHuffman* d)//Recorrido por el lado hderecho.
  {
     return d->hder;  
  }

void Priority_list::Tabla(char r, string g)//Aqui se crea la tabla con su letra y sus bits.
{
       
  nodoTabla *nuevo = new nodoTabla();
  nodoTabla *aux=nuevo;
  aux->letra=r;
  aux->bits=g;
       
  if (listVacia())
  {
    prim=aux;
    ult=aux;
  }else
  {
    ult->next=aux;
    ult=aux;
  }
}

void Priority_list::Travel(NodoHuffman* a, string acum)//Recorrido del arbol.
{
  NodoHuffman* aux=a;
       
  if (aux != NULL && aux -> hizq == NULL && aux -> hder == NULL)
  {
    Tabla(aux -> letter, acum);
    
  }else if (aux != NULL)
  {
    Travel(hizquierdo(aux), acum +'0');
    Travel(hderecho(aux), acum +'1');
  }
}


void Priority_list::CodeHuffman()//Donde se crea el arbol.
{
     
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

  Travel(head,"");
}
    
void Priority_list::length (int l)
{//Para saber cuanto es la longitud del texto.
  len=l;
}

   
   
void Priority_list::GuararText(string t)//Se guarda una copia del texto en el nodo.
{
        nodoGuardar* nuevo = new nodoGuardar();
        nodoGuardar *primero;
        primero=nuevo;
        primero->text=t;
}
void Priority_list::Guardarbits(string b)//Se guarda la cadena de bits del texto.
{
       nodoGuardar *primero;
       primero->chain=b;
}

void Priority_list::Concatenate()//Pasa el texto a la cadena de bits.
{
  string s;
  char co;
  nodoTabla* aux;
  nodoGuardar* aux1;
  aux1=primero;
  
  for (int i=0; i<=len; i++)
  {
    co=aux1->text[i];
    aux=prim;
           
    while (aux!=NULL)
    {
      if (co==aux->letra)
      {
        s=s+aux->bits;
        break;
      }
        aux=aux->next;
    }
  }
  
  aux1->chain=s;
}

void Priority_list::Print()
{
  NodoHuffman* aux;
  aux=head;
  while(aux!=NULL)
  {
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
  Queue.GuararText(chain);
  Queue.length(tam);
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
 
    
    Queue.Print();
    cout<< " " << endl<<endl;
    Queue.CodeHuffman();
    Queue.Concatenate();
    cout << " " << endl;

 return 0;
}