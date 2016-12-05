#include<iostream>
#include<string>
#include<fstream>
using namespace std;
//#############################################################################################################################
string convertir(string aconvertir)//esta funcion convierte toda palabra en minuscula 
{
	string dato;
	for(int i=0;i<aconvertir.size();i++)
	{
		dato+=tolower(aconvertir[i]);//usa el metodo "tolower" para convertir un caracter del abecedario a minuscula
	}
	return dato;// retorna el string en minuscula servira para ordenar alfabeticamente los nombres de usuario en la lista
}
//############################################################################################################################
	
class siguiendos// esta es una lista que tendra a los usuarios que siguen a otros usuarios
{
private:
class node // estructura que permitira guardar la informacion de los usuarios que son seguidores y siguiendos
{
	public:
 		string seguidor;//el nombre de usuario que esta siguiendo a otro
 		string seguido;// el nombre de usuario que seguido por otro
 		node*siguiente;
 		public:
 		node(string a,string b)// constructor de la clase node
 		{
 			seguidor=a;
 			seguido=b;
 			siguiente=NULL;
 		}
};
public:
 		node*seguidores,*seguidos,*cola,*primero;// declaracion de los apuntadores para las estructura de la lista  
 		siguiendos()//constructor de la clase siguiendos
 		{
 			seguidores=NULL;
 			seguidos=NULL;
 			primero=cola=NULL;
 		}
 
bool ya_lo_sigue(string usuario1,string usuario2)// esta funcion permite asegurar que un usuario no siga mas de una vez a otro
{
	node*aux=seguidores;
	while(aux!=NULL)
	{
		if(aux->seguidor==usuario1 && aux->seguido==usuario2)// se comprueba que no esta siguiendo a un mismo usuario
		{
			return true;
		}
		aux=aux->siguiente;
	}
	return false;

}
void agregar_cola(string a,string b)// como en el enunciado del proyecto2 no describe claramente la forma en la que se deben guardar
{
	if(primero==NULL)     // los datos correspondientes al programa esta accion permite ordenar como una cola a los usuarios que siguen a otros
	{
		node*aux=new node(a,b);// de manera que cuando se guarden en el archivo "entrada.in" queden tal como se muestra en el ejemplo de archivo puesto en el enunciado de este proyecto
		primero=aux;
		cola=primero;
		
	}
	else
	{
	  node*aux=new node(a,b);
	  cola->siguiente=aux;
	  cola=aux;
	}
}
void guardar() //apoyandoce de la accion agregar_cola almacena la informacion proveida por el programa en el area destinada para los "siguiendos" en el archivo entrada.in
{
	fstream archivo;
	string ruta="entrada.in";// ruta de archivo donde se guardara la informacion del programa
	archivo.open(ruta.c_str(),fstream::app|fstream::out);
	node*aux=primero;
	archivo<<"siguiendos"<<"\n";
	while (aux!=NULL)
	{
		archivo<<aux->seguidor<<" "<<aux->seguido<<"\n";
		aux=aux->siguiente;
		
	}
	archivo.close();
}	
void agregar_seguidor(string a,string b)//esta accion sirve para ir ordenando alfabeticamente los usuarios que siguen a otro usuario
{
if(!ya_lo_sigue(a,b))//de manera que al mostrarlos por pantalla estan ordenados 
{
	if (seguidores==NULL)
	{
		node*aux;
		aux= new node(a,b);
		seguidores=aux;
	}
	else
	{
		node*aux,*ant=seguidores,*sig;
		string copia1=convertir(a);//convierte todo caracter del abecedario que este en la variable "a" a minuscula
		aux= new node(a,b);
		while(ant->siguiente!=NULL &&copia1.compare(convertir(ant->seguidor))>0)//este ciclo se ejecutara mientras en valor de la palabra (dado por el metodo "compare")sea mayo al de las que estan en la lista
		{
			sig=ant;
			ant=ant->siguiente;
		}
	
			if(copia1.compare(convertir(ant->seguidor))<=0)//por alguna de estas dos condiciones se detuvo el ciclo ahora se debe evaluar cual fue
		{
		if(copia1.compare(convertir(ant->seguidor))==0)// en este caso las palabras son iguales,se colocara despues de aquella palabra en la que se cumplio esta condicion
		{
			sig=ant->siguiente;
			ant->siguiente=aux;	
			aux->siguiente=sig;
		}
		else
		{
		  if(ant==seguidores)//nunca se cumplio la condion de ciclo se colocara de primero
		{
		aux->siguiente=ant;
	    seguidores=aux;
		}
		else
		{
		aux->siguiente=ant;
		sig->siguiente=aux;
		}
		}
		}
		else
	{
		ant->siguiente=aux;
	}
}
}
}
void agregar_seguidos(string a,string b)//de manera analoga esta accion ordena alfabeticamente los usuarios pero por los nombres de usuario de los que son seguidos por otro usuario
{
	if (seguidos==NULL) // de manera que cuando se vayan a mostrar los siguiendos esten tambien ordenados alfabeticamente
	{
		node*aux;
		aux= new node(a,b);
		seguidos=aux;
		
	}
	else
	{
		node*aux,*ant=seguidos,*sig;
		string copia1=convertir(b);// convierte todo caracter del abecedario que este en b en minuscula
		aux= new node(a,b);
		while(ant->siguiente!=NULL &&copia1.compare(convertir(ant->seguido))>0)// esta vez comparo pero con el nombre de usuario que es seguido por otro y evalua si es mayor que la palabra que esta en la lista
		{
			sig=ant;
			ant=ant->siguiente;
		}
	
			if(copia1.compare(convertir(ant->seguido))<=0)
		{
		if(copia1.compare(convertir(ant->seguido))==0)
		{
			sig=ant->siguiente;
			ant->siguiente=aux;	
			aux->siguiente=sig;
		}
		else
		{
		  if(ant==seguidos)
		{
		aux->siguiente=ant;
	    seguidos=aux;
		}
		else
		{
		aux->siguiente=ant;
		sig->siguiente=aux;
		}
		}
		}
		else
	{
		ant->siguiente=aux;
	}
}
}
void eliminar_siguiendo(string a,string b)// accion que permite eliminar de la lista a un usuario que sigue a otro en particular
{

	if(seguidos->siguiente==NULL && seguidos->seguidor== a && seguidos->seguido== b)// comparo que sea el seguidor y su correspondiente siguiendo
	{
		node*aux=seguidos;
		seguidos=NULL;
		delete aux;
	}
	else
	{
	node*aux=seguidos,*aux2;
	while((aux!=NULL) && ((aux->seguidor!=a) ||(aux->seguido!=b)))//se posiciona en el nodo que esta buscando y en el anterior para su posterior eliminacion
	{

     aux2=aux;aux=aux->siguiente;
	}
	if(aux==seguidos)
	{
		node*copia=seguidos;
		seguidos=seguidos->siguiente;
		delete copia;
	}
	else
	{
		node*copia=aux;
		aux2->siguiente=aux->siguiente;
		delete copia;
	}
	}
}
void dejar_de_seguir(string usuario,int pos)//apoyandose en la accion eliminar_siguiendo permite dejar de seguir a un usuario
{
	if(seguidores->siguiente==NULL&& pos-1==0)// que no es mas que eliminar de la lista de seguidores a un usuario en particular
	{
	 node*aux=seguidores;
	 seguidores=NULL;
	 delete aux;	
	}
	else
	{
	node*aux=seguidores,*aux2;
	while(pos!=0&&aux!=NULL)
	{
		if(aux->seguidor==usuario){pos--;}if(pos!=0){aux2=aux;aux=aux->siguiente;}//como en esta lista estan todos los seguidores para que la consulta pueda ser O(n)
	}
	if(aux==seguidores)// se necesita identificar a cual de los siguiendos de un usuario en particular se va a dejar de seguir(sacar de la lista)
	{
		eliminar_siguiendo(aux->seguidor,aux->seguido);
		node*copia=seguidores;
		seguidores=seguidores->siguiente;
		delete copia;
	}
	else
	{
		eliminar_siguiendo(aux->seguidor,aux->seguido);
		node*copia=aux;
		aux2->siguiente=aux->siguiente;
		delete copia;
	}
   }
}
void mostrar_seguidos(string usuario,bool &vacio)//muestra los siguiendo(es decir los usuarios que tienen como seguidor un usuario en particular)
{
	node* aux=seguidos;
	int tiene=0;
	int pos=1;
	cout<<"Indique el usuario al cual desea dejar de seguir"<<endl<<endl;
	while(aux!=NULL)
	{
		if(aux->seguidor==usuario)//verifica que realmente este usuario sea seguido por aquel nombre de usuario que es pasado por parametro
		{
		cout<<pos<<") "<<aux->seguido<<endl;
		pos++;
		tiene++;
	    }
	    aux=aux->siguiente;
	    if(tiene>0)
	    {
	    	vacio=false;
	    }
	}
	
	
}
void mostrar_seguidores(string usuario)//igualmente esta accion muestra aquellos nodos en cuya informacion "usuario" coincida con la que le es pasada por parametro 
{
	node*aux=seguidores;
	cout<<"Los seguidores de "<<usuario<<" son:"<<"\n";
	while (aux!=NULL)
	{
		if(aux->seguido==usuario)//verifica que sea el usuario correcto
		{
		cout<<aux->seguidor<<endl;
	    }
	    aux=aux->siguiente;
	}
	cout<<endl;
}
void mostrar_siguiendos(string usuario)//esta accion muestra aquellos nodos en cuya informacion "usuario" coincida con la que le es pasada por parametro para mostrar los usuarios que este sigue
{
	node*aux=seguidos;
	cout<<"Los siguiendos de "<<usuario<<" son:"<<"\n";
	while (aux!=NULL)
	{
	if(aux->seguidor==usuario)//verifica que el nombre de usuario sea el solicitado por parametro
		{
		cout<<aux->seguido<<endl;
	    }
	    aux=aux->siguiente;
	}
	cout<<endl;
}
};	


class tweet //lista que permite almacenar los "tweet" de todos los usuarios
{
 	private:
 		class node// estructura que permite almacenar la informacion relacionada a un tweet como cual usuario lo creo y el texto
 		{
 		public:
 		string usuario;string comentario;int posicion;node*siguiente;
 	    node(string a,string b,int e)
 		{
 			siguiente=NULL;usuario=a;comentario=b;posicion=e;
 	    }
 	    node(string a,string b)
 		{
 			siguiente=NULL;usuario=a;comentario=b;
 	    }
 		};
 	public:
 		node*inicio,*inicio2,*final;int etiqueta;// declaracion de los apuntadores para la lista de los tweets
 		tweet()
 		{
 			inicio=inicio2=final=NULL;etiqueta=1;
 	    }
void agregar_a_cola(string u,string t)//debido a que en el enunciado del proyecto no se especifica el orden en el cual se ha de organizar los tweet en el archivo "entrada.in"
{
	if(inicio2==NULL)//siguiendo el modelo del enunciado esta accion guarda los tweet sin ordenar "cronologicamente",los guarda como una cola cada tweet que se cree para su posterior respaldo en el archivo
	{
		node*aux=new node(u,t);inicio2=aux;final=aux;
	}
	else
	{
	    node*aux=new node(u,t);	final->siguiente=aux;final=aux;
	}
}
void guardar()//almacena tada la informacion de los tweets que se han creado en el programa y los guarda en la seccion de "tweets" en el archivo "entrada.in"
{
	fstream archivo;
	string ruta="entrada.in";
	archivo.open(ruta.c_str(),fstream::app|fstream::out);
	node*aux=inicio2;
	archivo<<"tweets"<<"\n";
	while (aux!=NULL)
	{
		archivo<<aux->usuario<<" "<<aux->comentario<<"\n";
		aux=aux->siguiente;
		
	}
	archivo.close();
}	
void crear_tweet(string u,string t)//al momento que el usuario inicie sesion y cree un tweet este se pondra con todos los demas ordenados de manera "cronologica"
{
	if(inicio==NULL)//a cada tweet se le asigna un numero que determina su "tiempo" es decir si es reciente o ya es viejo con respecto a otros tweet creados previamente
	{
	 node*aux=new node(u,t,etiqueta);inicio=aux;etiqueta++;
	}
	else
	{
	node*nuevo=new node(u,t,etiqueta);etiqueta++;node *aux=inicio,*aux1;
		while(aux->siguiente!=NULL && nuevo->posicion < aux->posicion)
		{
			aux1=aux;aux=aux->siguiente;
		}
		if(nuevo->posicion>=aux->posicion)
		{
			if(nuevo->posicion==aux->posicion)
			{
				delete nuevo;
			}
			else
			{
				if(aux==inicio)
				{
					nuevo->siguiente=aux;inicio=nuevo;
				}
				else
				{
				nuevo->siguiente=aux;aux1->siguiente=nuevo;
				}
			}
		}
		else
		{
			aux->siguiente=nuevo;
		}
	}
	
}
void eliminar(string usuario,int pos)//esta accion permite eliminar un tweet de un usuario en particular
{
	
	if(inicio->siguiente==NULL&& pos-1==0 &&inicio->usuario==usuario)
	{
	 node*aux=inicio;
	 inicio=NULL;
	 delete aux;	
	}
	else
	{
	node*aux=inicio,*aux2;
	while(pos!=0&&aux!=NULL)
	{
		if(aux->usuario==usuario){pos--;}if(pos!=0){aux2=aux;aux=aux->siguiente;}// de acuerdo al usuario y los tweets que este haya creado se le asigna una posicion que pasada por parametro permite eliminar el tweet correcto
	}
	if(aux==inicio)
	{
		
		node*copia=inicio;
		inicio=inicio->siguiente;
		delete copia;
	}
	else
	{
		
		node*copia=aux;
		aux2->siguiente=aux->siguiente;
		delete copia;
	}
   }	
}
void eliminar_tweet(string usuario,int &ap)//accion que muestra los tweets que un usuario ha creado anteriormente ordenados cronologicamente(los mas recientes primero)
{
    node* aux=inicio;
	int pos=1;
	cout<<endl;
	cout<<"Seleccione el tweet que desea eliminar"<<endl<<endl;
	while(aux!=NULL)
	{
		if(aux->usuario==usuario)
		{
		cout<<pos<<") "<<aux->comentario<<endl;
		pos++;
	    }
	    aux=aux->siguiente;
	}
	cout<<pos<<") "<<"Salir"<<endl;
	ap=pos;
}
void mostrar()//cuando un usuario inicia secion esta opcion permite recorrer la lista de tweets y mostrar los tweets de todos los usuarios a la hora de ver muro
{
	node*aux=inicio;
	int pos=1;
	cout<<endl;
	cout<<"Tweets"<<endl;
	while(aux!=NULL)
	{
		cout<<pos<<") "<<aux->comentario<<endl;aux=aux->siguiente;pos++;
	}
	cout<<endl;
}
};

class usuarios//estructura que permite almacenar la informacion de cada usuario corectamente
{
	public:
	string nombre;string correo;string usuario;string clave;bool actual;usuarios*siguiente;// informacion del usuario y el apuntador  a siguiente que servira para estructurar la lista de usuarios
	
	usuarios (string n, string c, string u, string contrasena)
	{
		nombre=n;correo=c;usuario=u;clave=contrasena;siguiente=NULL;actual=false;
	}	
};
//##############################################################################
class list// esta clase servira para menejar la sesion del usuario, el registro de los mismos, asi como de cargar y guardar la informacion correspondiente
{
	public: //al programa para que este funcione correctamente
	usuarios *inicio;//con este apuntador se hara la lista de usuarios ordenados alfabeticamente
	usuarios *final;
	usuarios *inicio2;//con este se hara la lista como una cola para guardarlo en el archivo "entrada.in"
	usuarios *final2;
	string respaldo[1000000];//a la hora de buscar usuarios se almacenan temporalmente aqui para facilitar la busqueda ya que 
	// se requiere que las consultas sea a lo sumo O(n) 
	siguiendos*seguidores;// lista que permitira llevar el control de los seguidores y los siguiendos
	tweet*tweets;//lista que permitira llevar el control de los tweets de todos los usuarios
	
  list () //constructor de la clase list
	{
		inicio=inicio2=final=final2=NULL;
		seguidores=new siguiendos();
		tweets=new tweet();
		
	}

void agregar_a_cola(string n,string c, string u,string clave)// cuando se requiera guardar la informacion en el archivo "entrada.in" se almacenara como una cola en 
{
	if(inicio2==NULL)//seccion de "usuarios"
	{
	 usuarios*aux=new usuarios(n,c,u,clave);
	 inicio2=aux;
	 final2=aux;
	}
	else
	{
		usuarios*aux=new usuarios(n,c,u,clave);
		final2->siguiente=aux;
		final2=aux;
	}
}

void agregar(string n,string c, string u,string clave,bool & existe)//ordena alfabeticamente a los usuarios de modo que al consultarlos ya esten ordenados de esta menera
{
	
	if (inicio==NULL)
	{
		usuarios*aux;
		aux= new usuarios (n,c,u,clave);
		inicio=aux;
		final=aux;
	}
	else
	{
		usuarios*aux,*ant=inicio,*sig;
		string copia1=convertir(u);//se convierte a minuscula cada caracter del abecedario que esta en u para compararlo
		aux= new usuarios(n,c,u,clave);
		while(ant->siguiente!=NULL &&copia1.compare(convertir(ant->usuario))>0)
		{
			sig=ant;
			ant=ant->siguiente;
		}
	
			if(copia1.compare(convertir(ant->usuario))<=0)
		{
		if(copia1.compare(convertir(ant->usuario))==0)//para asegurarse de que un usuario no sea registrado mas de una vez
		{
			    cout<<endl;
				cout<<"Usuario ya existe\n"<<endl;;
				existe=true;
				delete aux;
		}
		else
		{
		  if(ant==inicio)
		{
		aux->siguiente=ant;
	    inicio=aux;
		}
		else
		{
		aux->siguiente=ant;
		sig->siguiente=aux;
		}
		}
		}
		else
	{
		ant->siguiente=aux;
	}
}
		
			
}
void deshabilitar_usuario(string usuario,string clave)//cuando un usuario inicia sesion se marca para que al consultar los nodos no sea contado entre ellos esta accion desactiva al usuario para que
{
	usuarios*aux=inicio;// se pueda consultar nuevamente 
	while(aux!=NULL)
	{
		if(aux->usuario==usuario||aux->correo==usuario && aux->clave==clave)
		{
			aux->actual=false;
			return;
		}
		aux=aux->siguiente;
		
	}
}
bool usuario_valido(string nombre,string clave)//verifica que una persona este registrado en el sistema
{
if (inicio==NULL)
{
return false;
}
else
{

	usuarios*aux=inicio;
	while(aux!=NULL)
	
	{
		if (aux->usuario==nombre && aux->clave==clave)//verifica que el nombre de usuario y clave coincidan con la de un usuario
		{
			aux->actual=true;
			return true; 
		}
		aux=aux->siguiente;
	}
return false;
}
}	
void sesion()// permite mostrar todas las opciones que se prestan a la hoara de iniciar sesion
{
	int opcion;
	string usuario; string clave;
	cout<<"Indique nombre de usuario y clave"<<endl;
	cin>>usuario>>clave;// nombre de usuario y contraseña
	cout<<endl;
if(usuario_valido(usuario,clave))//verifica que esta registrado
{

	while(opcion!=9)
	{
	cout<<"1) Ver seguidores"<<endl;//opciones
	cout<<"2) Ver siguiendos"<<endl;
	cout<<"3) Crear tweet"<<endl;
	cout<<"4) Eliminar tweet"<<endl;
	cout<<"5) Seguir"<<endl;
	cout<<"6) Dejar de seguir"<<endl;
	cout<<"7) Ver muro"<<endl;
	cout<<"8) Guardar en archivo"<<endl;
	cout<<"9) Salir"<<endl;
	cin>>opcion;
	if(opcion==1)
	{
		string usuario;
		cout<<"Indique nombre de usuario"<<endl;
		cin>>usuario;
		cout<<endl;
		seguidores->mostrar_seguidores(usuario);//se muestran los seguidores de un usuario en particular
	}
	else if(opcion==2)
	{
		string usuario;
		cout<<"Indique nombre de usuario"<<endl;
		cin>>usuario;
		cout<<endl;
		seguidores->mostrar_siguiendos(usuario);//se muestran los siguiendos de un usuario en particular
	}
	else if(opcion==3)
	{
		string tweet;
		cin.ignore();
		cout<<endl;
		cout<<"Indique el tweet a crear"<<endl<<endl;
		getline(cin,tweet);
		cout<<endl;
		if(tweet.size()>0 && tweet.size()<=140)//verifica que la cantidad de caracteres del texto no pase el limite estipulado 
		{
			tweets->crear_tweet(usuario,tweet);//crear tweet
			tweets->agregar_a_cola(usuario,tweet);
			cout<<"Tweet guardado con exito"<<endl<<endl;
		}
	
	}
	else if(opcion==4)
	{
		int pos,valor;
		tweets->eliminar_tweet(usuario,valor);
		cin>>pos;
		if(pos>0&&pos<valor)
		{
		tweets->eliminar(usuario,pos);//elimina un tweet en particular
		cout<<"Tweet eliminado con exito"<<endl<<endl;
	    }
	}
	else if(opcion==5)
	{
		
			cout<<"Indique el usuario al cual desea seguir"<<endl<<endl;
			usuarios*aux=inicio;
			int marca=1,opcion;
			while(aux!=NULL)
			{
				if(!aux->actual)//para garantizar que un usuario no se siga asi mismo esta marcado con un boolean 
				{
					respaldo[marca]=aux->usuario;//para no buscar de nuevo en la lista se usa un arreglo cuyo tiempo de acceso es constante
					cout<<marca<<") "<<aux->usuario<<endl;
					marca++;
				} 
				aux=aux->siguiente;
			}
			cout<<marca<<") Salir"<<endl;
			cin>>opcion;
			if(opcion>0 && opcion<marca)// se verifica que la opcion sea valida
			{
				
				if(!seguidores->ya_lo_sigue(usuario,respaldo[opcion]))
				{
				seguidores->agregar_cola(usuario,respaldo[opcion]);// para cuando se vaya a almacenar en el archivo "entrada.in"
				seguidores->agregar_seguidor(usuario,respaldo[opcion]);//agrega a la lista de seguidores
				seguidores->agregar_seguidos(usuario,respaldo[opcion]);//agrega a lista de siguiendos
				cout<<endl;
				cout<<"Usuario seguido con exito"<<endl<<endl;
			    }
				
				
			}
			
			
}
else if(opcion==6)
{
	int op;
	bool si=true;
	seguidores->mostrar_seguidos(usuario,si);
	if(!si)//verifica que el usuario tenga siguiendos
	{
	cin>>op;
	seguidores->dejar_de_seguir(usuario,op);//dejar de seguir (eliminar de la lista de siguiendos)
	cout<<endl;
	cout<<"Operacion exitosa"<<endl<<endl;
    }
    else
    {
    	cout<<"SIGUE A NADIE"<<endl<<endl;//si es usuario no tiene siguiendos
    }
	
}
else if(opcion==7)
{
tweets->mostrar();	//se muestra la lista de tweets ordenados cronologicamente
}
else if(opcion==8)
{
	guardar();//se guarda en el archivo la configuracion hecha en el programa en el archivo "entrada.in"
}
else if(opcion==9)
{
	deshabilitar_usuario(usuario,clave);//pone en falso el atributo actual lo que indica que el usuario finalizo su sesion
}
			
			
			
	
    }
}
}
void registrar()
{
	string nombre,email,nombre_usuario,clave;
	bool existe=false;
	cout<<"Indique Nombre, Email, Nombre de usuario y clave."<<endl;
	cin>>nombre>>email>>nombre_usuario>>clave;
	agregar(nombre,email,nombre_usuario,clave,existe);

	if(!existe)
	{
	cout<<endl;
	agregar_a_cola(nombre,email,nombre_usuario,clave);
	cout<<"Usuario guardado con exito."<<endl;
	cout<<endl;
    }

}
void mostrar()
{
	usuarios*aux=inicio;
	while(aux!=NULL)
	{
		cout<<aux->nombre<<endl;
		aux=aux->siguiente;
	}
}
void cargar_datos()
{
	fstream archivo;
	bool mark;
	string ruta="entrada.in",nombre,email,nombre_usuario,contrasena;
	archivo.open(ruta.c_str(),fstream::in);
	archivo>>nombre;
	while (nombre!="siguiendos")
	{
		archivo>>nombre;
		if(nombre!="siguiendos")
		{
		archivo>>email;
		archivo>>nombre_usuario;
		archivo>>contrasena;
		agregar(nombre,email,nombre_usuario,contrasena,mark);
		agregar_a_cola(nombre,email,nombre_usuario,contrasena);
		
	    }
		
	}
	while (nombre!="tweets")
	{
		archivo>>nombre;
		if(nombre!="tweets")
		{
		archivo>>nombre_usuario;
		seguidores->agregar_cola(nombre,nombre_usuario);
		seguidores->agregar_seguidor(nombre,nombre_usuario);
		seguidores->agregar_seguidos(nombre,nombre_usuario);
		
	    }
		
	}
	while(!archivo.eof())
	{
		archivo>>nombre;
		getline(archivo,nombre_usuario);
		nombre_usuario.erase (0,1);
		if(!archivo.eof())
		{
		tweets->crear_tweet(nombre,nombre_usuario);
		tweets->agregar_a_cola(nombre,nombre_usuario);
	    }
		
	}
	
	
	archivo.close();
	
	
}
void guardar()
{
	fstream archivo;
	string ruta="entrada.in";
	archivo.open(ruta.c_str(),fstream::out);
	archivo.close();
	archivo.open(ruta.c_str(),fstream::app|fstream::out);
	usuarios*aux=inicio2;
	archivo<<"usuarios"<<"\n";
	while (aux!=NULL)
	{
		archivo<<aux->nombre<<" "<<aux->correo<<" "<<aux->usuario<<" "<<aux->clave<<"\n";
		aux=aux->siguiente;
		
	}
	archivo.close();
	seguidores->guardar();
	tweets->guardar();
	cout<<"Documento guardado con exito"<<endl<<endl;
}
}; 
//##############################################################################

void menu()
{ 
 int opcion;
 list*p=new list();//objeto de la clase list que permitira manejar todo lo referente al programa
 p->cargar_datos();// se cargan la informacion inicial del archivo "entrada.in"
 while(opcion!=3)
{
	cout<<"1) Registrar usuario"<<endl;//menu principal
	cout<<"2) Iniciar sesion"<<endl;
	cout<<"3) Salir"<<endl;
	cin>>opcion;
  
	switch(opcion)
	{
		case 1: 
		p->registrar();//para registrar una persona
		break;
		case 2:
	    p->sesion();//abrir sesion
		break;
	}

}
}
int main()
{
	menu();//accion menu principal
}
