#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<math.h>

using namespace std;

typedef struct chao {
string caracter;
string hola;
}chao;

typedef struct auxinfo {
string ab, huffman;
int frecuencia;
}info;

class nodo {
public:
    info info2;
    string fre;
    nodo *hijoiz,*hijoder;
nodo ()
{
    hijoder=NULL;

    hijoiz=NULL;
}
  ~nodo() // destructor de una clase
	{ }
    };

class cola{
public:
    nodo hijo;
    cola *next,*inicio,*nuevo,*aux,*au,*aux2;

void crea (int n, info adf[]);
void imprime ();
void encolar ();
void bytep (nodo *arbol);
void obtenerbytes(nodo *arbol,info c[],int n);
void buscarelem(info c[],int n);
  ~cola() // destructor de una clase
	{}
};


void cola :: bytep (nodo *arbol){

if (arbol!=NULL ){

if (arbol->hijoder == NULL && arbol->hijoiz != NULL){bytep(arbol->hijoiz);}

if (arbol->hijoder == NULL){return;}
if ( arbol->hijoder !=NULL){ ((arbol->hijoder)->fre)= (arbol->fre)+((arbol->hijoder)->fre +"1");}
bytep(arbol->hijoder);


if (arbol->hijoiz==NULL){return;}
if ( arbol->hijoiz!=NULL){ ((arbol->hijoiz)->fre)= (arbol->fre)+((arbol->hijoiz)->fre +"0");}
bytep(arbol->hijoiz);

}


}
void cola :: obtenerbytes(nodo *arbol,info c[],int n){

/*
cout << endl;
cout << "Nodo  " <<arbol << endl;
cout << "Frecuencia " <<arbol->info2.frecuencia << endl;
cout << "Hijo Derecho " <<arbol->hijoder << endl;
cout << "Hijo Izquierdo "<<arbol->hijoiz << endl;

cout << endl;
cout << "Nodo  " <<arbol->hijoder << endl;
cout << "Frecuencia " <<arbol->hijoder->info2.frecuencia << endl;
cout << "Hijo Derecho " <<arbol->hijoder->hijoder << endl;
cout << "Hijo Izquierdo "<<arbol->hijoiz ->hijoiz<< endl;

cout << endl;
cout << "Nodo  " <<arbol->hijoiz << endl;
cout << "Frecuencia " <<arbol->hijoiz->info2.frecuencia << endl;
cout << "Hijo Derecho " <<arbol->hijoiz->hijoder << endl;
cout << "Hijo Izquierdo "<<arbol->hijoiz->hijoiz<< endl;

cout << endl;
cout << "Nodo  " <<arbol->hijoiz->hijoder << endl;
cout << "Frecuencia " <<arbol->hijoiz->hijoder->info2.frecuencia << endl;

*/

	if (arbol!=NULL){
		if (arbol->hijoiz == NULL && arbol->hijoder==NULL){

                for (int i =0;i<n;i++){

                if (arbol->info2.ab[0] != c[i].ab[0]){ continue;}
                      else {c[i].huffman = arbol->fre ;break;}

                }}

		//cout<< "Hola soy una bella hoja  " << arbol->info2.ab << " : " << arbol->fre<< endl;}


		obtenerbytes(arbol->hijoiz,c,n); // llamada recursiva
		obtenerbytes(arbol->hijoder,c,n);
		}



}
void cola :: crea (int n, info adf[])
{
inicio = NULL;

for (int i =0; i <n; i++)
{
    if (inicio == NULL){
    nuevo = new (cola);

    nuevo->hijo.info2.ab = adf[i].ab;
    nuevo->hijo.info2.frecuencia=adf[i].frecuencia;
    nuevo->next = NULL;

    inicio = nuevo;
    aux = inicio;
    }
    else {

nuevo = new (cola);
nuevo->hijo.info2.ab = adf[i].ab;
nuevo->hijo.info2.frecuencia=adf[i].frecuencia;


aux=inicio;
if (aux->next==NULL)

{if (aux->hijo.info2.frecuencia <= nuevo->hijo.info2.frecuencia)

{ aux->next=nuevo; aux =nuevo; nuevo->next=NULL; }

if (aux->hijo.info2.frecuencia > nuevo->hijo.info2.frecuencia)

{nuevo->next=aux;aux->next=NULL;inicio=nuevo; }


}


else {

aux = inicio;

while (aux->next!=NULL){

if (nuevo->hijo.info2.frecuencia < aux->hijo.info2.frecuencia)
{

nuevo->next=inicio;
inicio = nuevo;

break;
}

if (aux->hijo.info2.frecuencia == nuevo->hijo.info2.frecuencia )
{

aux2 = aux;

while (aux != NULL && aux->hijo.info2.frecuencia == aux2->hijo.info2.frecuencia)
{
au=aux;
aux = aux->next; }


aux= au;
nuevo->next = aux->next;
aux->next = nuevo;



break;
}
if ( (nuevo->hijo.info2.frecuencia > aux->hijo.info2.frecuencia )&& (nuevo->hijo.info2.frecuencia < (aux->next)->hijo.info2.frecuencia ))

{

nuevo->next = aux->next;
aux->next = nuevo; break; }


aux = aux->next;

}


if (aux ->next  == NULL)
{
    nuevo->next=NULL;
    aux->next = nuevo;}

} }

}


}

void cola ::encolar ()
{

int suma = 0;
string letras;
cola *temp, *t;


aux=inicio;

while (aux -> next != NULL){
suma = 0;

temp = aux;
t = aux->next;

nuevo = new (cola);
suma = (aux->hijo.info2.frecuencia)+((aux->next)->hijo.info2.frecuencia);
letras = aux->hijo.info2.ab+(aux->next)->hijo.info2.ab;

nuevo->hijo.info2.ab =letras;
nuevo->hijo.info2.frecuencia = suma;
nuevo->hijo.hijoiz  = &(aux->hijo);
nuevo->hijo.hijoder = &((aux->next)->hijo);

/*
printf("++ %p ++\n",nuevo);
cout << endl << "  " << "*" << nuevo->hijo.info2.ab << "*";
printf("  frecuencia  %d \n",nuevo->hijo.info2.frecuencia);
printf("\n  hijo izquierdo %p  \n",nuevo->hijo.hijoiz);
printf("\n  hijo derecho   %p  \n",nuevo->hijo.hijoder);
//insertar ordenado en la cola otra vez
*/


//cout << endl ; imprime();
//system ("pause");


// encolar insertado

aux=inicio;

while (aux->next!=NULL){

if (nuevo->hijo.info2.frecuencia < aux->hijo.info2.frecuencia)
{nuevo->next=inicio;
inicio = nuevo;
break;}

if (aux->hijo.info2.frecuencia == nuevo->hijo.info2.frecuencia )
{aux2 = aux;
while (aux != NULL && aux->hijo.info2.frecuencia == aux2->hijo.info2.frecuencia)
{au=aux;
aux = aux->next; }
aux= au;
nuevo->next = aux->next;
aux->next = nuevo;break;}
if ( (nuevo->hijo.info2.frecuencia > aux->hijo.info2.frecuencia )&& (nuevo->hijo.info2.frecuencia < (aux->next)->hijo.info2.frecuencia ))
{nuevo->next = aux->next;
aux->next = nuevo; break; }

aux = aux->next; }

if (aux ->next  == NULL)
{
nuevo->next=NULL;
aux->next = nuevo;
}

inicio = t->next;
aux = inicio;

//Horrible problema eliminando nodos ;( llorando
/*
if (temp)
delete temp;
if (t)
delete t;
*/

if (aux == NULL ){break; }


}




}

void cola :: imprime()
{

aux = inicio;
//printf(" \n %p \n ",aux );
if (aux == NULL){printf("estoy vacia ;( ");  }

else {
while (aux->next != NULL){

printf(" Direccion de memoria de aux %p  ",aux);
cout << " Letra " <<  aux->hijo.info2.ab << " Frecuencia  " << aux->hijo.info2.frecuencia << " Hijo iz "<< aux->hijo.hijoiz << " Hijo der " << aux->hijo.hijoder << endl;

aux = aux->next;


}
if (aux->next == NULL)
{printf(" Direccion de memoria de aux %p  ",aux);
   cout << " Letra " <<  aux->hijo.info2.ab << " Frecuencia  " << aux->hijo.info2.frecuencia << " Hijo iz "<< aux->hijo.hijoiz << " Hijo der " << aux->hijo.hijoder << endl;
}

}

}

void cola :: buscarelem(info c[],int n)
{
nodo *anew;
anew = &(inicio->hijo);
bytep(anew);
obtenerbytes(anew,c,n);
}

void frecuencia(info a[],int n)
{

    printf("Tabla de frecuencia \n" );
for (int i =0; i < n;i++){ cout <<a[i].ab << "   " << a[i].frecuencia <<"\t" <<  endl; }

}

void muestracodigo(info c[],int cont){

printf(" \nTabla de codigos \n" );
for (int i =0; i < cont;i++){ cout << c[i].ab << "  " << c[i].huffman<< endl; }
}


void obtener_frase_completa(string nueva,info c[],int cont)
{
int tam = nueva.length(); // tamaño de la cadena
string codificado="";
// cambiar 11 por el tam
for (int i =0; i < tam ;i++){ // recorrere la frase
  for (int j=0; j < cont;j++){ // recorrer el arreglo

            if (nueva[i]==c[j].ab[0]){
            codificado += c[j].huffman;
            break; } }   }

cout << codificado << endl;


tam = codificado.length();

int yu =7,a=0,potencia=-1;
unsigned char  valor;
int mod=0, div =0 ,co=0;
string codigo;

mod = tam%7;
co = tam/7;
printf ( "{  %d   } ", mod );
printf ( "{  %d   } ", co );



printf(" * %d *",tam);
for (int i = tam; i >=0;i--){
//cout << codificado[i];

  if (codificado[i]=='1')
{
/*
printf ("\nvalor de i %d ", i );
printf ("valor de potencia %d \n", potencia );
*/

a += pow(2,potencia);}

if (i == (tam-yu)){

    yu= yu+7;
    cout << "  ";
    a=a+32;
    cout << a << " ";
    valor = char(a) ;
    codigo += valor;
    cout << valor << " ";

    a=0; potencia=-1;

div++;

}


potencia++; }

if (div == co)
{
    yu= yu+7;
    cout << "  ";
    a=a+32;
    cout << a << " ";
    valor = char(a) ;
    codigo += valor;
    cout << valor << " ";

    a=0; potencia=-1;

}


cout << endl <<  "*** "<< codigo <<  " *** ";

}

string bio(int numero){
	int divisor =2,dividendo,resto;
	string binario ="";
	dividendo = numero;
 while(dividendo >= divisor){
 resto = dividendo % 2;
  if(resto == 1)
   binario = "1" + binario;
  else
   binario = "0" + binario;

   dividendo = dividendo/divisor;
 }
  if(dividendo == 1)
   binario = "1" + binario;
  else
   binario = "0" + binario;

 return binario;  }

int main (){
    int y=-1,op,cont=0,tam=0,con;
    ifstream ficheroEntrada;
    string nombre,frase,b;
    cola ala;
    scanf("%d",&op);

switch (op){
case 1: // lectura por archivo
{
cout << "Dime el nombre del fichero: ";
cin.ignore();
getline(cin,nombre);
ficheroEntrada.open ( nombre.c_str() , ios::in); // leo desde el nombre del archivo
if (!ficheroEntrada) { printf("No se encontro el archivo de entrada "); return 0; }


else {

getline(ficheroEntrada, frase);
	ficheroEntrada.close();}

break; }


case 2: // lectua normal
{
  
cin.ignore();
getline(cin,frase);


/*frase ="streets are stone star are not";
frase = "j'aime aller sur le bord de l'eau les jeudis ou les jours impairs";
frase = "me gusta comer ";
frase="ESTO ES UN EJEMPLO DE UN ARBOL DE HUFFMAN";
frase = "AAAAAAAAAABBBBBBBBCCCCCCDDDDDEE";
frase = "cceeedddbbaa";
frase = "clase de algoritmos computacionales";
frase="ESTO ES UN EJEMPLO DE ALGORITMO DE HUFFMAN";
frase ="doremifasollasidodosilasolfamiredo";
frase = "la casa";
frase ="streets are stone star are not";
frase = "ciencias de la computacion universitarios";
frase ="streets are stone star are not";
frase = "mi mama me mima";
frase = "la cama";
frase ="streets are stone star are not";*/

break; }



case 3: // decodificacion
{
cout << "Dime el nombre del fichero: ";
cin.ignore();
getline(cin,nombre);
ficheroEntrada.open ( nombre.c_str() , ios::in); // leo desde el nombre del archivo
if (!ficheroEntrada) { printf("No se encontro el archivo de entrada "); return 0; }

else {
string decodifico,bi,regreso;
string linea;
string ar,oi;
unsigned char a;
int g=0,ta,tanw;
int cuento=0;

while (!ficheroEntrada.eof())
{ getline(ficheroEntrada,linea); cuento++; }

ficheroEntrada.clear(); 
ficheroEntrada.seekg (0,ficheroEntrada.beg); // regreso al inicio del archivo

getline(ficheroEntrada, decodifico);

cout << " Texto codificado : "<< decodifico << endl;

ta=decodifico.length();

for (int i=0; i<ta;i++){

a=decodifico[i];
//printf ("*** %d ***" ,g );
g=a;
g=g-32;

bi =  bio(g);// paso de decimal
tanw=bi.length();

if (i==(ta-1)){

regreso=bi+regreso;
//cout <<g << "  " << "  " <<  bi << "  " << tanw <<  endl ;
break;}

while (tanw<7)
{ bi="0" + bi  ; tanw = bi.length(); }

//cout <<g << "  " << "  " <<  bi << "  " << tanw <<  endl ;

regreso=bi+regreso;

}

cuento = cuento-1;
cout << endl;

chao llegue[cuento];

while (! ficheroEntrada.eof() ){

for (int i = 0; i < cuento;i++)
{

getline(ficheroEntrada,linea);

ar = linea[0];
linea[0]=' ';

//cout << " letra : " << ar << " codigo : " ;

llegue[i].caracter= ar ;

int e=0,ol;
while (linea[e]==' '){ e++; }

ol = linea.length();
oi= "";
for (int g = e ; g < ol;g++) {
        if (linea[g]==' ')break;
        oi +=linea[g]; }

llegue[i].hola= oi;

}


}

printf (" ##%d## ",cuento);

//lectura de tabla


int r;
r=regreso.length();
cout << " *** "  << r;

	ficheroEntrada.close();
cout << " frase decodificada : " << regreso << endl;
cout << " Tabla de codigos : " << endl;
for (int i =0; i<cuento;i++)
{ cout << llegue[i].caracter << " : " ;
  cout << llegue[i].hola;
  cout << endl; }

string nueva="";
string compara="";

//cout <<"%%" << decodifico;
for(int j=0; j<r; j++)
		{
		//printf("hola");

		compara=compara+regreso[j];

				//cout <<"##"<<compara<<"##"<< endl;
				for(int i=0; i<cuento; i++)
				{
					if(compara==llegue[i].hola)
					{
						cout<<llegue[i].caracter;
						compara="";
						break;
					}
				}
		 }


cout << nueva;

}
return 0;
break;
}




}



b=frase;
tam=frase.size();

for ( int i=0;i<tam;i++)
{
char aux= frase[i];
if (aux=='1')continue;
cont++;
con =0;
for (int j=i;j<tam;j++)
{
if (aux==frase[j]){con++; frase[j]='1'; }
} }

cout << b << cont << endl;
frase = b;

// arreglo de info
info acd[cont];
info codigo[cont];

for ( int i=0;i<tam;i++)
{
char aux= b[i];
if (aux=='1')continue;
con =0; y++;

for (int j=i;j<tam;j++)
{ if (aux==b[j]){ con++; b[j]='1'; }}

acd[y].ab = aux;
codigo[y].ab=aux;
acd[y].frecuencia = con; }



ala.crea(cont , acd);
//ala.imprime();
ala.encolar();
printf("\n");
//ala.imprime();

ala.buscarelem(codigo,cont);




frecuencia(acd,cont);
muestracodigo (codigo,cont);


cout << "\n" << frase << "\n" ;
obtener_frase_completa(frase,codigo,cont);



return 0;
}


