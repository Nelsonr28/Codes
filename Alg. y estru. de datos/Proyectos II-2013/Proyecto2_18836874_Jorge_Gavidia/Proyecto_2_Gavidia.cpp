//Proyecto 2 
//Autor:Jorge Gavidia Ci 18836874
//Seccion C1 
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <ctype.h>
using namespace std;

//*********************************************************//
//clase lista_siguiendo 
class lista_siguiendo {

	public:	
			private:
			class nodosiguiendos{
				public:
						string usuario;
						nodosiguiendos *proximo; 
				};
			nodosiguiendos *primero;
			int cantidad;
		
	public:
		typedef nodosiguiendos *posicion;
		
		lista_siguiendo(){
			primero=NULL;
			cantidad=0;
		}
		~lista_siguiendo (){
			nodosiguiendos  *aux;
			while (primero!=NULL){
				aux=primero;
				primero=primero->proximo;
				delete aux;
			}
		}
		
		int tamano (){
			return (cantidad);
		}

		bool esvacio(){
			return (primero==NULL);
		}
				
		posicion comienzo (){
			return (primero);
		}
		
		posicion final (){
			return (NULL);
		}
		
		string acceder (posicion x){
			return (x->usuario);
		}
		
		void siguiente (posicion &p){
			p=p->proximo;
		}
		
		void agregar(string &nombre){//inserta en orden  
			nodosiguiendos *nuevo= new nodosiguiendos;
			nuevo->usuario= nombre;
			nuevo-> proximo=NULL;
			
			nodosiguiendos *anterior=NULL;
			nodosiguiendos *aux=primero;
			
			while (((aux!=NULL))&&((aux->usuario)<(nuevo->usuario))){
					anterior=aux;
					aux=aux->proximo;
			}
			if (anterior==NULL){
				nuevo->proximo=primero;
				primero=nuevo;
				
			}
			else{
				anterior->proximo=nuevo;
				nuevo->proximo=aux;
			}
		cantidad++;
		}
		void eliminar (posicion p){
			if (p==primero){
				primero=primero->proximo;
			}	
			else{
				nodosiguiendos *aux;
				aux=primero;
				while (aux->proximo != p){
					aux=aux->proximo;
				}
				aux->proximo=p->proximo;
			}
			delete p;
			cantidad--;
		}
		void imprimir (lista_siguiendo &L){
			lista_siguiendo::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
				cout<< L.acceder(p);
				L.siguiente(p);
			}
		}
	
};//Fin de Clase lista_siguiendo 

//***************************************************************//
//clase lista_twetts
class lista_twetts {
	
	private:
			class nodo_tweet{//Nodo con doble apuntador
				public:
						string tweet; 
						string usuario;
						nodo_tweet *proximo;
						nodo_tweet *anterior;
	
			};
			nodo_tweet *primero; //Apuntador al 1er elemento
			nodo_tweet *ultimo;	//Apuntador al ultimo elemento
			int cantidad;
		
	public:
		typedef nodo_tweet *posicion;
		
		lista_twetts (){ //Constructor
			primero=NULL;
			ultimo=NULL;
			cantidad=0;
		}
		~lista_twetts  (){ // Destructor
			nodo_tweet *aux;
			while (primero!=NULL){
				aux=primero;
				primero=primero->proximo;
				delete aux;
			}
		}
		
		int tamano (){
			return (cantidad);
		}

		bool esvacio(){
			return (primero==NULL);
		}
				
		posicion comienzo (){
			return (primero);
		}
		
		posicion final (){
			return (NULL);
		}
		
		posicion ultimos (){
			return (ultimo);
		}
		
		string acceder (posicion x){
			return (x->tweet);
		}
		
		void siguiente (posicion &p){
			p=p->proximo;
		}
		
		void anterior (posicion &p){
			p=p->anterior;
		}
		
		void agregar(string usuario,string dato){ // agregar al PRINCIPIO
			nodo_tweet *nuevo= new nodo_tweet;
			nuevo->tweet=dato;
			nuevo->usuario=usuario;
			nuevo->proximo=NULL;
			nuevo->anterior=NULL;
			if (primero==NULL){
				primero=nuevo;
				ultimo=nuevo;
			}
			else{
				nuevo->proximo=primero;
				primero->anterior=nuevo;
				primero=nuevo;
			}
		cantidad++;
		}
		
		posicion buscar (lista_twetts  &L,string tweet,string usuario){
			lista_twetts::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
				if((L.acceder(p)==tweet)&&(p->usuario==usuario)){
					return (p);
					break;
				}
				siguiente(p);	
				}
		
		}
	
		void eliminar (posicion p){
			if (p==primero){
				primero=primero->proximo;
				primero->anterior=NULL;
			}	
			else{
				nodo_tweet *aux;
				aux=primero;
				if (p==ultimo){
				ultimo=ultimo->anterior;
				ultimo->proximo=NULL;
				}
				while (aux->proximo != p){
					aux=aux->proximo;
				}
				aux->proximo=p->proximo;
				p->proximo->anterior=aux;
			}
			delete p;
			cantidad--;
		}
			void imprimir (lista_twetts  &L){ //imprime en orden normal
			lista_twetts ::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
				cout<<p->usuario<<": "<<L.acceder(p)<<endl;
				L.siguiente(p);
			}
		}
		
			void imprimirrves (lista_twetts  &L){//imprime en orden inverso
				lista_twetts ::posicion p;
				p=L.ultimos();
					do{
					cout<< L.acceder(p);
					anterior(p);
					if (p==L.comienzo()){
					cout<< L.acceder(p);
					}
				}while (p!=L.comienzo());
			}
};//Fin clase PilaTweets			
	
//***************************************************************//
//clase lista_seguidores
class lista_seguidores {
	
	private:
			class nodoseguidores{ //nodo 
				public:
						string usuario; 
						nodoseguidores *proximo;
			};
			nodoseguidores *primero;
			int cantidad;
		
	public:
		typedef nodoseguidores *posicion;
		
		lista_seguidores(){
			primero=NULL;
			cantidad=0;
		}
		~lista_seguidores (){
			nodoseguidores *aux;
			while (primero!=NULL){
				aux=primero;
				primero=primero->proximo;
				delete aux;
			}
		}
		
		int tamano (){
			return (cantidad);
		}

		bool esvacio(){
			return (primero==NULL);
		}
				
		posicion comienzo (){
			return (primero);
		}
		
		posicion final (){
			return (NULL);
		}
		
		string acceder (posicion x){
			return (x->usuario);
		}
		
		void siguiente (posicion &p){
			p=p->proximo;
		}
		
		void agregar(string dato){ //inserta en orden 
			nodoseguidores *nuevo= new nodoseguidores;
			nuevo->usuario= dato;
			nuevo-> proximo=NULL;
			
			nodoseguidores *anterior=NULL;
			nodoseguidores *aux=primero;
			
			while (((aux!=NULL))&&((aux->usuario)<(nuevo->usuario))){
					anterior=aux;
					aux=aux->proximo;
			}
			if (anterior==NULL){
				nuevo->proximo=primero;
				primero=nuevo;
				
			}
			else{
				anterior->proximo=nuevo;
				nuevo->proximo=aux;
			}
	
		cantidad++;
		}
			 
		void eliminar (posicion p){
			if (p==primero){
				primero=primero->proximo;
			}	
			else{
				nodoseguidores *aux;
				aux=primero;
				while (aux->proximo != p){
					aux=aux->proximo;
				}
				aux->proximo=p->proximo;
			}
			delete p;
			cantidad--;
		}
			void imprimir (lista_seguidores &L){
			lista_seguidores::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
				cout<< L.acceder(p);
				L.siguiente(p);
			}
		}
};

//******************Clase*Principal**************************************//
class lista_twitter { //Clase lista de usurios 
	
	public:	
			private:
			class nodoinfousurio{ //Nodo
				public:
						string nombre;
 					 	string email;
 						string usuario;
 						string password;
 						lista_seguidores lista_seg;//lista de seguidores 
 						lista_siguiendo lista_sig;//lista de siguiendo
						nodoinfousurio *proximo; 
				};
			nodoinfousurio *primero;
			int cantidad;
		
	public:
//metodos propios de la lista 
		typedef nodoinfousurio *posicion;
		
		lista_twitter();
		
		~lista_twitter();
		
		int tamano();

		bool esvacio();
				
		posicion comienzo();
		
		posicion final();
		
		string acceder (posicion x);
		
		void siguiente (posicion &p);
		
		void agregar(string &nombre, string &email, string &usuario, string &password );//inserta al final 
		
		void imprimir (lista_twitter &L);
	
//metodos de manejo de la lista 	
		//Metodos de Carga de del Archivo
		void cargar_archivo (lista_twitter &L,lista_twetts &Ltweets);//metodo leer de archivo
		void usuarioss(string linea); //Carga los usuarios 
		void siguiendoss(lista_twitter &L,string linea);//Carga los Siguiendos
		void buscar_insertar_sig (lista_twitter &L,string primero,string segundo);//Carga los Siguiendos
		void buscar_insertar_seg (lista_twitter &L,string primero,string segundo);//Carga los Seguidores
		void cargar_tweets (string linea,lista_twetts &Ltweets);//Carga los Tweets
		void agregar_usuarios();//En el menú principal agrega los usuarios nuevos
		posicion loguin (lista_twitter &L);//Lee el loguin
		posicion buscar_loguin (lista_twitter &L,string &usuario,string &password);//Busca el puntero del loguin e ingresa
		void menu_loguin (lista_twitter &L,string usuario);//muestra el menu completo del programa logueado
			
};
//******************METODOS*CLASE*LISTA*USUARIOS***************************//

lista_twitter:: lista_twitter(){ //Constructor
				primero=NULL;
				cantidad=0;
}
lista_twitter::~lista_twitter (){ //Destructor
			nodoinfousurio *aux;
			while (primero!=NULL){
				aux=primero;
				primero=primero->proximo;
				delete aux;
			}
}
int lista_twitter::tamano (){
					return (cantidad);
}
bool lista_twitter::esvacio(){
			return (primero==NULL);
}
lista_twitter::posicion lista_twitter::comienzo (){
					return (primero);
}
lista_twitter::posicion lista_twitter::final (){
					return (NULL);
}
string lista_twitter::acceder (posicion x){
			return (x->nombre);
}		
void lista_twitter::siguiente (posicion &p){
			p=p->proximo;
}
void lista_twitter::agregar(string &nombre, string &email, string &usuario, string &password ){//inserta en orden
			nodoinfousurio *nuevo= new nodoinfousurio;
			nuevo->nombre= nombre;
			nuevo->email= email;
			nuevo->usuario= usuario;
			nuevo->password= password;
			nuevo-> proximo=NULL;
			
			nodoinfousurio *anterior=NULL;
			nodoinfousurio *aux=primero;
			while ((aux!=NULL)&&((aux->usuario)<(nuevo->usuario))){
					anterior=aux;
					aux=aux->proximo;
				}
			if (anterior==NULL){
				nuevo->proximo=primero;
				primero=nuevo;
				
			}
			else{
				anterior->proximo=nuevo;
				nuevo->proximo=aux;
			}
		cantidad++;

}
void lista_twitter::imprimir (lista_twitter &L){
			lista_twitter::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
				cout<< L.acceder(p);
				L.siguiente(p);
			}
}
//******************METODOS*DE*CARGA*******************************************//
void lista_twitter::cargar_archivo (lista_twitter &L,lista_twetts &Ltweets){ //Carga de archivo
	const char user[9]="usuarios";
	const char sigui[11]="siguiendos";
	const char tweet[7]="tweets";
	bool usuarios=false;
	bool siguiendos=false;
	bool tweett=false;
	ifstream fe("entrada.in"); 	// Abre un fichero de entrada
	string linea;
	while(!fe.eof()){
		
		getline(fe,linea);	// Leeremos mediante getline, si lo hiciéramos mediante el operador << sólo leeríamos parte de la cadena:
   		
		cout <<linea<< endl;//Muestra la linea que carga 
		if (linea!=""){
		linea.erase(linea.end()-1);//Borramos salto de lineas 
		}
		
		if (linea==user){ //Si linea==usuarios
			usuarios=1;			
			getline(fe,linea);	//leemos siguiente linea 
			cout <<linea<< endl;
		}
		if (sigui==linea){//Si linea==siguiendos
			siguiendos=1;
			getline(fe,linea);	//leemos siguiente linea 
			cout<<linea<<endl;
		}
		if (tweet==linea){//Si linea==tweets
			tweett=1;
			getline(fe,linea);	//leemos siguiente linea 
			cout <<linea<< endl;
		}
	
   	    if ((usuarios==true)&&(siguiendos==false)&&(tweett==false)){ // leemos usuarios
			  
				usuarioss(linea);
   		}
   		if ((usuarios==true)&&(siguiendos==true)&&(tweett==false)){// leemos siguiendos
   				
   				siguiendoss (L,linea);
   		}
   		
   		if(((usuarios==true)&&(siguiendos==true)&&(tweett==true))&&(linea!="")){// leemos tweets
				
				cargar_tweets (linea,Ltweets);
   		}

	}//while
	fe.close();//cerramos Archivo de lectura
}

void lista_twitter::usuarioss(string linea){ //Carga y desgloza la linea con los datos de Usuarios 
	char c;
	int i=0;
	int cont=1;
	string nombre;
	string correo;
	string usuario;
	string password;
			
				if (cont==1){ // NOMBRE
   					while (c!=' '){ // encontrar el primer ' '
						c=tolower(linea[i]);
						nombre=nombre+c;
						i++;
						}
 					cont++;					
				}
					if (cont==2){ // CORREO
					c='1';
   					while (c!=' '){ // encontrar el primer ' '
						c=tolower(linea[i]);;
						correo=correo+c;
						i++;
						}
					cont++;
				}
					if (cont==3){ //USUARIO
					c='1';
   					while (c!=' '){ // encontrar el primer ' '
						c=tolower(linea[i]);
						usuario=usuario+c;
						i++;
						}
					cont++;
				}
					if (cont==4){ //CONTRASENA
					int a;
					while (c!='\0') { // encontrar el salto de linea o final de linea
						c=tolower(linea[i]);
						a=c;
						if (a!=13){// es un caracter nulo encontrado en el archivo
						password=password+c;
						}
						i++;
					}
				}
					
	agregar (nombre,correo,usuario,password);//metodo de la clase lista_twitter que agrega el usuario
}

void lista_twitter::siguiendoss(lista_twitter &L,string linea){//Desgloza la linea con los datos de Siguiendos
	char c;
	int i=0;
	int cont=1;
	string primero;
	string segundo;
			
				if (cont==1){ // siguiendo a o primero
					while (c!=' '){ // encontrar el primer ' '
						c=tolower(linea[i]);
						primero=primero+c;
						i++;
						}
 					cont++;					
				}//if
					if (cont==2){ // usuario o segundo
					c='1';
					int a;
   					while (c!='\0'){
						c=tolower(linea[i]);
						a=c;
						if (a!=13){// es un caracter nulo encontrado en el archivo
						segundo=segundo+c;
						}
						i++;
						}
					segundo.erase(segundo.end()-1);//borrar salto de linea
					segundo=segundo+' ';//agregar el espacio
				}//if
		if (primero!=segundo){ //no se puede seguir a si mismo 
		buscar_insertar_sig (L,primero,segundo); //insertar siguiendos
		buscar_insertar_seg (L,primero,segundo); //Insertar Seguidores 
		}
}//fin siguiendoss

void lista_twitter:: buscar_insertar_seg (lista_twitter &L,string primero,string segundo){  //insertar seguidores

			lista_twitter::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
					if(p->usuario==(segundo)){
						p->lista_seg.agregar(primero);
						break;
					}
					L.siguiente(p);	
			}
}
	
void lista_twitter:: buscar_insertar_sig (lista_twitter &L,string primero,string segundo){//insertar siguiendos
			
			lista_twitter::posicion p;
			p=L.comienzo();
			while (p!=L.final()){
					if(p->usuario==primero){
						p->lista_sig.agregar(segundo);
						break;
					}
					L.siguiente(p);	
			}
}
				
void lista_twitter:: cargar_tweets (string linea,lista_twetts &Ltweets){//Buscar e insertar Tweets
char c;
	int i=0;
	int cont=1;
	string usuario;
	string tweetts;
			
				if (cont==1){ // usuario
					while (c!=' '){ // encontrar el primer ' '
						c=tolower(linea[i]);
						usuario=usuario+c;
						i++;
						}
 					cont++;					
				}//if
					if (cont==2){ // Tweets 
					c='1';
   					while (c!='\0'){ // encontrar el ultimo ' '
						c=tolower(linea[i]);
						tweetts=tweetts+c;
						i++;
						}
					cont++;
				}//if

	Ltweets.agregar(usuario,tweetts);
	
}//Fin cargar_tweets
//*****************Metodos*Dentro*del*Menu*******************************************//
void lista_twitter::agregar_usuarios(){
		
	string linea;
	char a[128];

		cout<<"Indique Nombre, Email, Nombre de usuario y clave"<<endl; getchar ();
		cin.getline(a, 128, '\n');
		linea=a;
		usuarioss(linea);
		cout<<"Operacion exitosa"<<endl;
		
}//Fin Agregar_usuarios

lista_twitter::posicion lista_twitter::loguin (lista_twitter &L){ //Pedir Loguin

	string linea;
	char a[128];
	char c;
	int i=0;
	int cont=1;
	string usuario;
	string password;
	lista_twitter::posicion p;	
	
		cout<<"Indique nombre de usuario y clave"<<endl; getchar ();
		cin.getline(a, 128, '\n');
		linea=a;
	
				if (cont==1){ // usuario
   					while (c!=' '){ // encontrar el primer ' '
						c=tolower(linea[i]);				
						usuario=usuario+c;
						i++;
						}
 					cont++;					
				}//if
				if (cont==2){ // password
					c='1';
   					while (c!='\0'){ // encontrar el primer ' '
						c=tolower(linea[i]);
						password=password+c;
						i++;
						}
					cont++;
				}//if	
				
		p=buscar_loguin (L,usuario,password);
 
return (p);	 
}//loguin 

lista_twitter::posicion lista_twitter:: buscar_loguin (lista_twitter &L,string &usuario,string &password){

	lista_twitter::posicion p;
	p=L.comienzo();

		while (p!=L.final()){
			if((p->usuario==usuario)&&(p->password==password)){ //Si encuentra el Usuario y Password 
				return (p);//Retorna el puntero al nodo 
				break;
				}
		L.siguiente(p);
		}
		return (NULL);//Si no encontro los datos Retorna NULL 
}//buscar_loguin

void menu_loguin (lista_twitter &L,lista_twetts &Ltweets,string usuario){
//**********************Menu*De*Loguin**************************************//

	int opcion=0;
	label_menu: 
	while( opcion != 9) {
 
				/*            Impresion de Menu dentro Loguin             */
				cout << endl << " Menu Loguin: " << endl; 
				cout << "___________________________________________" << endl; 
				cout << " 1. Ver seguidores\n 2. Ver siguiendos\n 3. Crear tweet\n"; 
				cout << " 4. Eliminar tweet\n 5. Seguir\n 6. Dejar de seguir\n"; 
				cout << " 7. Ver muro\n 8. Guardar Archivo\n 9. Salir\n"; 
				cout << "\n\n\nOpcion a Introducir: "; 
				cin >> opcion; 
				
	//******************** Opciones del Menu ****************************//	
 
	switch (opcion) 
	{ 
		//*************Opcion 1 Ver Seguidores ***************//
		
		case 1:{//Ver seguidores
				
				lista_twitter::posicion p;
				p=L.comienzo();
				char entrada[30];
				string usuario;
					
					cout<<"Indique el Nombre del usuario a buscar"<<endl;getchar ();
					cin.getline(entrada,30, '\n');
					usuario=entrada;
					usuario=usuario+' ';
					
						while (p!=L.final()){
								if(p->usuario==usuario){
									p->lista_seg.imprimir(p->lista_seg);
									cout<<"Operacion exitosa"<<endl;
									break;
								}//if
								L.siguiente(p);
						}//While 
						cout<<"No se encontro usuario, Operacion exitosa"<<endl;
			break; }//Case 1
			
		//*************Opcion 2 Ver Siguiendos ***************//
		case 2:{//Ver siguiendos
		
				lista_twitter::posicion p;
				p=L.comienzo();
				char entrada[30];
				string usuario;
					
					cout<<"Indique el Nombre del usuario a buscar"<<endl;getchar ();
					cin.getline(entrada,30, '\n');
					usuario=entrada;
					usuario=usuario+' ';
					
						while (p!=L.final()){
								if(p->usuario==usuario){
									p->lista_sig.imprimir(p->lista_sig);
									cout<<"Operacion exitosa"<<endl;
									break;
								}
								L.siguiente(p);
						}
				
			break;} //Case 2
						
		//*************Opcion 3 Crear Tweet ***************//
				
		case 3:{// Crear tweet
				char entrada[140];
				string tweet;
				
					cout<<"Solo seran admitidos 140 caracteres"<<endl;
					cout<<"Indique el tweet a crear: "<<endl;getchar ();
					cin.getline(entrada, 140, '\n');
					tweet=entrada;
					Ltweets.agregar(usuario,tweet);
					cout<<"Tweet agrgado con exito"<<endl;

		break;}//Case 3
		
		//*************Opcion 4 Eliminar Tweet ***************//
						
		case 4:{//Eliminar tweet
				lista_twetts ::posicion p;
				p=Ltweets.comienzo();
				int i=1;
				int indicador;
					
					while (p!=Ltweets.final()){//Muestra los Tweets del Usuario
						if (p->usuario==usuario){
						cout<<i<<") " <<Ltweets.acceder(p)<<endl;
						i++;
						}
					Ltweets.siguiente(p);
					}
					
					cout<<"indique el numero de tweet cual desea eliminar"<<endl;
					cin>>indicador;
					
				p=Ltweets.comienzo();
				i=1;
				
					while (p!=Ltweets.final()){
						if (p->usuario==usuario){
							if (indicador==i){
								Ltweets.eliminar(p);
								cout<<"Operacion exitosa"<<endl;
								break;
							}
							i++;
						}
						Ltweets.siguiente(p);
					}//While
	
		break;}//Case 4
		
		//*************Opcion 5 Seguir nuevo Usuario ***************//
		
		case 5:{// Seguir
		
				lista_twitter ::posicion p;
				lista_twitter ::posicion puntero;
				p=L.comienzo();
				int i=1;
				int indicador;
				
					cout<<"Indique a quien desea seguir"<<endl;
						//Muestra Usuario
					while (p!=L.final()){
						if (p->usuario!=usuario){
						cout<<i<<") " <<p->usuario<<endl;//
						i++;
						}
						L.siguiente(p);
					}//While
						//leemos la Opcion
					cout<<"indique el numero al cual desea seguir"<<endl;
					cin>>indicador;
					
					p=L.comienzo();
					i=1;
						while (p!=L.final()){ //Guardamos el puntero
							if (p->usuario!=usuario){
								if (i==indicador){
									puntero=p;
									break;
								}
							i++;
							}
						L.siguiente(p);
						}
				
					//verifico si ya estoy siguiendo a este usuario
					lista_siguiendo::posicion q;
					p=L.comienzo();
					bool ya_esta=false;
						while (p!=L.final()){
								if(p->usuario==usuario){
									q=(p->lista_sig.comienzo());
										while (q!=(p->lista_sig.final())){
											if(q->usuario==puntero->usuario){
												ya_esta=true;//
												break;
											}//if	
											p->lista_sig.siguiente(q);	
										}//while
								break;
								}//if
								L.siguiente(p);
						}//While
					if (ya_esta==false) {//Si no lo sigo lo agrego
						L.buscar_insertar_sig (L,usuario,puntero->usuario); //insertar siguiendos
						L.buscar_insertar_seg (L,usuario,puntero->usuario); //Insertar Seguidores 
						cout<<"Operacion exitosa"<<endl;
					}
					else {
						cout<<"Ya sigue a este usuario"<<endl;
					}
		break;}//case 5
		 		
		 //************* Opcion 6 Dejar de Seguir Usuario ***************//
		 		
		case 6:{// Dejar de seguir
		
				lista_twitter ::posicion p;
				lista_twitter ::posicion puntero;
				p=L.comienzo();
				int i=1;
				int indicador;
					
					cout<<"Indique a quien desea dejar de seguir"<<endl;
						
						//Muestra Usuario
						
					while (p!=L.final()){
						if (p->usuario!=usuario){
						cout<<i<<") " <<p->usuario<<endl;
						i++;
						}
					L.siguiente(p);
					}
					
				cout<<"indique el numero al cual desea dejar seguir"<<endl;
				cin>>indicador; 
				
				p=L.comienzo();
				i=1;
				
				while (p!=L.final()){
					if (p->usuario!=usuario){
						if (i==indicador){
							puntero=p;//Guardamos el puntero
							break;
						}
					i++;
					}
				L.siguiente(p);
				}
				
				//verifico si ya estoy siguiendo a este usuario
				lista_siguiendo::posicion q;
				p=L.comienzo();
				bool ya_esta=false;
					while (p!=L.final()){
							if(p->usuario==usuario){
								q=p->lista_sig.comienzo();
									while (q!=(p->lista_sig.final())){
										if(q->usuario==puntero->usuario){
											ya_esta=true;
											p->lista_sig.eliminar(q);//elimino de lista siguiendo 
											break;
										}//if	
										p->lista_sig.siguiente(q);	
									}//while
							break;
							}//if
							L.siguiente(p);
					}//While
			
				if (ya_esta==true){//eliminar de seguidos 
				
				lista_seguidores::posicion q;
				p=L.comienzo();
					while (p!=L.final()){
							if(p->usuario==puntero->usuario){
								q=p->lista_seg.comienzo();
									while (q!=(p->lista_seg.final())){
										if(q->usuario==usuario){
											p->lista_seg.eliminar(q);//elimino de lista seguidores
											break;
										}//if	
										p->lista_seg.siguiente(q);	
									}//while
							break;
							}//if
							L.siguiente(p);
					}//While
					cout<<"Operacion exitosa"<<endl;
				}
				else {
					cout<< "Ud. no sigue a este usuario"<<endl;
					}			
			
		break;}//Dejar de Seguir 
		
		 //************* Opcion 7 Imprimir muro ***************//
		case 7:{ //Ver muro
				
				Ltweets.imprimir(Ltweets);
				cout<<"Operacion exitosa"<<endl;
				
		break;}
		
		 //************* Opcion 8 Guardar Archivo ***************//
		 
		case 8:{ //Guardar Archivo
			
				ofstream fs("salida.in"); //Abre Archivo 
				string linea;
				
				fs << "Usuarios" << endl;// Enviamos una cadena al fichero de salida
				//Imprimimos los Usuarios en el Archivo 
					lista_twitter ::posicion p;
					p=L.comienzo();
						while (p!=L.final()){
							linea=linea+p->nombre;
							linea=linea+p->email;
							linea=linea+p->usuario;
							linea=linea+p->password;
							linea.erase(linea.end()-1);	
							fs<<linea<<endl;//escribo en archivo	
							L.siguiente(p);
							linea.clear();//Limpio Linea
							}
						//termino de cargar usuarios 
				
				fs << "siguiendos" << endl;
				//Imprimimos los Usuarios en el Archivo 
				
					p=L.comienzo();
					lista_siguiendo::posicion q;
							while (p!=L.final()){
								q=p->lista_sig.comienzo();
								while (q!=p->lista_sig.final()){
									linea=linea+p->usuario+q->usuario;
									fs<<linea<<endl;//escribo en archivo	
									linea.clear();//Limpio Linea					
								p->lista_sig.siguiente(q);
								}	
							L.siguiente(p);
							}
					//termino de cargar siguiendos
				//Imprimimos los Usuarios en el Tweets
				fs << "tweets" << endl;
				lista_twetts::posicion r;
				r=Ltweets.ultimos();
						do{
							linea=linea+r->usuario;
							linea=linea+r->tweet;
							linea.erase(linea.end()-1);
							fs<<linea<<endl;//escribo en archivo	
							linea.clear();//Limpio Linea
							Ltweets.anterior(r);
							if (r==Ltweets.comienzo()){//si el ultimo 
								linea=linea+r->usuario;
								linea=linea+r->tweet;
								linea.erase(linea.end()-1);
								fs<<linea<<endl;
								linea.clear();
							}	
						}while(r!=Ltweets.comienzo());

				// Cerrar el fichero, 
				// para luego poder abrirlo para lectura:
				fs.close();	
				cout <<"Operacione Exitosa"<<endl;		
				
		break;} //Case 8
 
		case 9: //Salir 
		break; 
 
		default: 
		cout << "Solo se permiten las opciones (1-9)"; 
		goto label_menu; 
	}// switch 
 }//while
}//end void 
//*****************MainPPAL*******************************************// 
int main(){
lista_twitter t;
lista_twetts Ltweets;
t.cargar_archivo(t,Ltweets);

//**********************Menu*PPAL***************************************//

lista_twitter::posicion puntero;
int opcion=0;
label_menu: 
 while( opcion != 3) {
			
			/*            Impresion de Menu Ppal             */
	cout << endl << " Menu: " << endl; 
	cout << "___________________________________________" << endl; 
	cout << " 1. Registrar Usuario\n 2. Iniciar Sesion\n 3. Salir\n"; 
 
	cout << "\n\n\nOpcion a Introducir: "; 
	cin >> opcion; 
	
 	//******************** Opciones del Menu ****************************//	
 	
	switch (opcion) 
	{ 
		case 1: //Registrar Usuario
 
		t.agregar_usuarios();
		
		break; 
 
		case 2: //Iniciar Sesion
		puntero=t.loguin(t);
			if (puntero==NULL){
				cout<<"no se pudo iniciar sesion"<<endl;
				break;
			}
			else {
				//cout<<puntero->usuario<<endl;
				menu_loguin (t,Ltweets,puntero->usuario);
			}
		break; 
 
		case 3: //Salir 
		break; 
 
		default: 
		cout << "Solo se permiten las opciones (1-3)"; 
		goto label_menu; 
	}// switch 
 }//while  
 
 t.imprimir(t);
return (0);//Sale del programa 
}  
