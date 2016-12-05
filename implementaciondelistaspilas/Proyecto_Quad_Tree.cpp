#include <iostream>
#include <fstream>
#include <stdlib.h>
using namespace std;

class QuadNodo{
	public:	
		string Info;
		string Tipo;
        int x,y;
        QuadNodo *NE;
		QuadNodo *NO;
		QuadNodo *SE;
		QuadNodo *SO;
		
        QuadNodo(int Px, int Py,string N,string P){
        	Info=N;
        	Tipo=P;
        	x=Px;
        	y=Py;
        	NE=NO= NULL;
        	SE=SO= NULL;
        }
    };

class Lista{
	public:
		class QuadList{
			public:	
				string Info;
				string Tipo;
        		int x,y;
        		QuadList *Next;
        
        	QuadList(int Px, int Py,string N,string P,QuadList *M){
        		Info=N;
        		Tipo=P;
        		x=Px;
        		y=Py;
        		Next=M;
        	}
		};
		
		QuadList *Primero;
		
		Lista(){
			Primero=NULL; 
		}
		
		bool Vacia(){return !Primero;}
		
		void Insertar(int x, int y, string N,string P){ 
			if(Vacia()) Primero=new QuadList(x,y,N,P,NULL); 
			else{ 
				QuadList *Aux=Primero;
				if(x <= Aux->x || y < Aux->y ){ 
					Primero=new QuadList(x,y,N,P,Aux); 
				}
				else{
					while(Aux->Next &&  (x >= Aux->Next->x )) Aux=Aux->Next; 
					Aux->Next=new QuadList(x,y,N,P,Aux->Next);
				}
			}
		}
		
		void Mostrar(){ 
			if(!Vacia()){ 
				QuadList *Aux=Primero; 
				while(Aux){ 
					cout<<"Sitio: "<<Aux->x<<" "<<Aux->y<<endl;	
       				cout<<"Tipo: "<<Aux->Tipo<<endl;
       				cout<<"Codigo: "<<Aux->Info<<endl;
       				cout<<endl;
					Aux=Aux->Next;
				}
			}
		}
		
		void Destructor(){
			QuadList *Aux;
	
			while(Primero != NULL){
				Aux=Primero;
				Primero=Primero->Next;
				delete Aux;
			}
		}
		
};
   
class QuadTree{
	public:
		QuadNodo *Root;
		Lista *List;
		
		QuadTree(){
			Root= NULL;
			List= new Lista();
		}
		
		void Insertar(QuadNodo *&TheRoot,int Px, int Py, string Pinfo,string Ptipo) {
     		if(TheRoot == NULL){
     			TheRoot = new QuadNodo(Px,Py,Pinfo,Ptipo);
			}
     		else{
         			if(Px <= TheRoot->x && Py >= TheRoot->y ){
         				Insertar(TheRoot->NO,Px,Py,Pinfo,Ptipo);
           			}
        			else if(Px <= TheRoot->x && Py <= TheRoot->y){
						Insertar(TheRoot->SO,Px,Py,Pinfo,Ptipo);
         			}
         			else if(Px >= TheRoot->x && Py >= TheRoot->y){
						Insertar(TheRoot->NE,Px,Py,Pinfo,Ptipo);
         			}
         			else if(Px >= TheRoot->x && Py <= TheRoot->y){
						Insertar(TheRoot->SE,Px,Py,Pinfo,Ptipo);
         			}
     		 }
   		}
       
		void BusquedaPorCoordenada(QuadNodo *TheRoot, int Px, int Py, bool &Val){
				if(TheRoot != NULL){
       				if(TheRoot->x == Px && TheRoot->y == Py){
       					cout<<"Sitio: "<<TheRoot->x<<" "<<TheRoot->y<<endl;	
       					cout<<"Tipo: "<<TheRoot->Tipo<<endl;
       					cout<<"Codigo: "<<TheRoot->Info<<endl;
       					cout<<endl;
       					Val=true;
       				}
					else{
       					
       					if(Px <= TheRoot->x && Py >= TheRoot->y ){
         					BusquedaPorCoordenada(TheRoot->NO,Px,Py,Val);
           				}
        				else if(Px <= TheRoot->x && Py <= TheRoot->y){
							BusquedaPorCoordenada(TheRoot->SO,Px,Py,Val);
         				}
         				else if(Px >= TheRoot->x && Py >= TheRoot->y){
							BusquedaPorCoordenada(TheRoot->NE,Px,Py,Val);
         				}
         				else if(Px >= TheRoot->x && Py <= TheRoot->y){	
							BusquedaPorCoordenada(TheRoot->SE,Px,Py,Val);
         				}	
       					
       			    }
				}
       }
       
        void BusquedaPorRegion(QuadNodo *TheRoot, int Px, int Py, int Px2, int Py2,bool &Val){
	      if(TheRoot!=NULL){                                                          
                if(((TheRoot->x >= Px) && (TheRoot->x <= Px2)) && ((TheRoot->y >= Py2)&&(TheRoot->y <= Py))){
				   List->Insertar(TheRoot->x,TheRoot->y,TheRoot->Info,TheRoot->Tipo);
				   Val=true;
                }
                
                if(((TheRoot->x <= Px) && (TheRoot->x >= Px2)) && ((TheRoot->y >= Py)&&(TheRoot->y <= Py2))){
				   List->Insertar(TheRoot->x,TheRoot->y,TheRoot->Info,TheRoot->Tipo);
                	Val=true;
				}
                
                if(((TheRoot->x <= Px) && (TheRoot->x >= Px2)) && ((TheRoot->y <= Py)&&(TheRoot->y >= Py2))){
				   List->Insertar(TheRoot->x,TheRoot->y,TheRoot->Info,TheRoot->Tipo);
                	Val=true;
				}
                
                if(((TheRoot->x <= Px2) && (TheRoot->x >= Px)) && ((TheRoot->y >= Py)&&(TheRoot->y <= Py2))){
				   List->Insertar(TheRoot->x,TheRoot->y,TheRoot->Info,TheRoot->Tipo);
                	Val=true;
				}
                
                BusquedaPorRegion(TheRoot->NO,Px, Py, Px2, Py2,Val);  
                BusquedaPorRegion(TheRoot->SO,Px, Py, Px2, Py2,Val);
                BusquedaPorRegion(TheRoot->NE,Px, Py, Px2, Py2,Val);
            	BusquedaPorRegion(TheRoot->SE,Px, Py, Px2, Py2,Val);                
            }
      }
	       
	    void LLenado(){
	   	fstream Archivo;
		string Texto,ruta;
		string tipo, codigo;
		int x,y;
		cin>>ruta;
		Archivo.open(ruta.c_str(), fstream::in);
			while(!Archivo.eof()){
				Archivo>>x>>y;
				Archivo>>Texto;
				tipo = Texto.substr(0,3);
				codigo = Texto.substr(3);
				Insertar(Root,x,y,codigo,tipo);
			}
		Archivo.close();
	   }

};

int main(){
	QuadTree *Arbol= new QuadTree();
	Arbol->LLenado();
	int x1,y1,x2,y2;
	string Tipo;
	bool Val=false;
	do{
		cin>>Tipo;
		if(Tipo=="SIT"){
			cin>>x1>>y1;
			cout<<endl;
			Arbol->BusquedaPorCoordenada(Arbol->Root,x1,y1,Val);
			if(Val==false){
				cout<<"Sitio No Encontrado : SIT "<<x1<<" "<<y1<<endl;
				cout<<endl;	
			}
			Val=false;	
		}
		else if(Tipo=="REG"){
			cin>>x1>>y1>>x2>>y2;
			cout<<endl;	
			Arbol->BusquedaPorRegion(Arbol->Root,x1,y1,x2,y2,Val);
			Arbol->List->Mostrar();
			Arbol->List->Destructor();
			if(Val==false){
				cout<<"Region No Encontrado : REG "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;
				cout<<endl;
			}
			Val=false;
		}
	}while(true);
	return 0;
}
