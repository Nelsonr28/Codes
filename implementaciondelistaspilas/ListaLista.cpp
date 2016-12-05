/*********************************************************
* Archivo:     ListaListas.cpp
* Lenguaje:    C++
* Estudiantes: Qaser Awan Ruiz
* Institución: Instituto Tecnológico de Costa Rica
* Notas:
*				-Restricciones:
*					No me hago responsable del uso que le den
*					a los algoritmos.
*
*        		-Observaciones:
*		  			El prototipo del trabajo fue brindado
*					en el curso de estructuras de datos.
*********************************************************/
#ifndef ListaListasa
#define ListaListasa
#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <string.h>

//******************  Clase para las Listas de Listas *******************
//Nodo para la ListaLista
class NodosListaLista{
	public:
	int datos,peso;
	NodosListaLista *siguiente;
	NodosListaLista *siguiente2;
	//Constructores
	NodosListaLista(){
		datos=0;
		siguiente=NULL;
		siguiente2=NULL;
	}
	NodosListaLista(int valor){
		datos=valor;
		siguiente=NULL;
		siguiente2=NULL;
	}
	NodosListaLista(int valor,int valor2){
			datos=valor;
			peso=valor2;
			siguiente=NULL;
			siguiente2=NULL;
	}
	NodosListaLista(int valor,NodosListaLista *signodo){
		datos=valor;
		siguiente=signodo;
	}
};

//Prototipo ListaLista
//-----------------------------------------------------
class ListaLista{
	public:
	NodosListaLista *PrimerNodo;
	NodosListaLista *UltimoNodo;
	//Constructor
	ListaLista(){
		PrimerNodo=UltimoNodo=NULL;
	}
	//Retorna si esta vacia la lista
	int VaciaLista(){
		return PrimerNodo==NULL;
	}
	//Inserta un elemento en una posicion dada
	void InsertaEncabezado(int,int);
	//Inserta un elemento de un encabezado
	void InsertaElementos(int,int,int);
	//Imprime la lista
	void Imprimir();
	//Carga la lista de listas
	void CrearLL();
	//Cargar los encabezados
	void CargarEncabezados();
	//Carga los destinos
	void CargarDestinos();

};
//------------------------------------------------------
//Metodos para ListaLista
//------------------------------------------------------
//Inserta un elemento en el encabezado en una posicion dada
void ListaLista::InsertaEncabezado(int ElemInser,int Posicion){
	if(VaciaLista())
		PrimerNodo=UltimoNodo=new NodosListaLista (ElemInser);
	else{
		if(Posicion <= 1){
			NodosListaLista *Nuevo=new NodosListaLista(ElemInser);
			Nuevo->siguiente=PrimerNodo;
			PrimerNodo=Nuevo;
		}
		else{
			NodosListaLista *Aux=PrimerNodo;
			int i=2;
			while((i != Posicion) & (Aux->siguiente != NULL)){
				i++;
				Aux=Aux->siguiente;
			}
			NodosListaLista *Nuevo=new NodosListaLista(ElemInser);
			Nuevo->siguiente=Aux->siguiente;
			Aux->siguiente=Nuevo;
		}
	}
}
//Inserta al inicio un elemento
void ListaLista::InsertaElementos(int CodL,int Peso,int Encab){
	bool enc=false;
	if(VaciaLista())
		cout<<"No hay encabezados";
	else{
		NodosListaLista *p=PrimerNodo;
		while(p!=NULL & enc==false){
			if((*p).datos==Encab){
				enc=true;
				if(p->siguiente2==NULL){
					p->siguiente2=new NodosListaLista(CodL,Peso);
				}
				else{
					NodosListaLista *temp=p->siguiente2;
					while(temp->siguiente2!=NULL){
						temp=temp->siguiente2;
					}
					temp->siguiente2=new NodosListaLista(CodL,Peso);
					temp=NULL;
					delete temp;
				}
			}
			else{
				p=p->siguiente;
			}
		}
		if(enc==false)
			cout<<"No se encontro encabezado\n";
		p=NULL;
		delete p;
	}

}
//Imprime la lista
void ListaLista::Imprimir(){
	NodosListaLista *p=PrimerNodo;
	NodosListaLista *temp;
	if(PrimerNodo==NULL){
		cout<<"Lista Vacia\n";
	}
	else{
		while(p!=NULL){
			cout<<"Punto Inicio: "<<(*p).datos;
			temp=p->siguiente2;
			while(temp!=NULL){
				cout<<"\n   "<<"Punto llegada: "<<(*temp).datos<<"\n   Peso: "<<(*temp).peso;
				temp=temp->siguiente2;
			}
			cout<<"\n";
			p=p->siguiente;
		}
	}
	temp=NULL;
	p=NULL;
	delete temp;
	delete p;
}
//Carga la lista de listas
void ListaLista::CrearLL(){
	CargarEncabezados();
	CargarDestinos();
}
//Carga los encabezados
void ListaLista::CargarEncabezados(){
	char buffer[100]="";
	char * pch;
	int codi,pos;
	ifstream encabezados ("c:/Vertices.txt");
	if(!encabezados.is_open()){
		cout << "Error archivo no existe\n";
	}
	else{
		while(!encabezados.eof()){
			encabezados.getline (buffer,100);
			if(strcmp(buffer,"")){
				pch = strtok (buffer,"; ");
				codi=atoi(pch);
				pch = strtok (NULL, ";");
				pos=atoi(pch);
				InsertaEncabezado(codi,pos);
			}
		}
	}
	pch=NULL;
	delete pch;
}
//Carga los destinos
void ListaLista::CargarDestinos(){
	char buffer[100]="";
	char * pch;
	int codl,peso,codi;
	ifstream encabezados ("c:/Destinos.txt");
	if(!encabezados.is_open()){
		cout << "Error archivo no existe\n";
	}
	else{
		while(!encabezados.eof()){
			encabezados.getline (buffer,100);
			if(strcmp(buffer,"")){
				pch = strtok (buffer,"; ");
				codi=atoi(pch);
				pch = strtok (NULL, ";");
				codl=atoi(pch);
				pch = strtok (NULL, ";");
				peso=atoi(pch);
				InsertaElementos(codl,peso,codi);
			}
		}
	}
	pch=NULL;
	delete pch;
}

void main(){
	ListaLista m;
	m.InsertaEncabezado(1,0);
	m.InsertaEncabezado(2,1);
	m.InsertaEncabezado(3,2);
	m.InsertaEncabezado(4,3);
	//Para el 1
	m.InsertaElementos(11,1,1);
	m.InsertaElementos(22,1,1);
	m.InsertaElementos(33,1,1);
	m.InsertaElementos(44,1,1);
	//Para el 2
	m.InsertaElementos(10,1,2);
	m.InsertaElementos(20,1,2);
	m.InsertaElementos(30,1,2);
	m.InsertaElementos(40,1,2);

	//...
	m.Imprimir();
}
//-------------------------------------------------------------------
//Fin clase Lista Lista
#endif