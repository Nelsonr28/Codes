#include <iostream>
#include <string>

using namespace std;

//inicio de la clase arbol
class NodoTree
{
public:
	char letra;
	int prio;
	NodoTree *hizq, *hder;
	NodoTree (char elem)		//inicializa como hoja
	{
		info = elem;
		hizq = hder = NULL;
	}

	NodoTree (char elem, NodoTree *izq, NodoTree *der)
	{
		info = elem;
		hizq = hder = NULL;
	}
};

class TreeBin// arbol binario.
{
public:
	NodoTree *raiz;
	TreeBin ()
	{
		raiz = NULL;
	}

public:
	 bool treeEmpty ();
	 bool IsLeaf ();
};
//fin clase arbol


//desarrollo de metodos de la clase arbol
bool TreeBin::treeEmpty ()
	{
		if (raiz == NULL)
			return true;
		return false;
	}

bool Priority_Queue::IsLeaf ()
{
	if (this -> hizq == NULL  && this -> hder == NULL)
		return true;
	return false;
}

bool TreeBin::CreateTree ()
{
	while ()
}

//fin de los metodos de la clase arbol


//inicio de la clase cola de prioridad
class NodePQueue
{
	public:
		char letra;
		int prio;
		NodePQueue *sig , *ant;
		NodePQueue (char letter, int priority, NodePQueue *next)
		{
			letra = letter;
			prio = priority;
			sig = next;
		}
};

class Priority_Queue
{
public:
	NodoTree 
	NodePQueue *head, *tail;		//primer public: consructor y destructor respectivamente
	int tam;
	Priority_Queue ()
	{
		head = tail = NULL;
	}

~Priority_Queue ()
	{
		while (head != NULL)
		{
			NodePQueue *au = head -> sig;
			delete head;
			head = au;
		}
	}

public:						//segundo public: metodos
	bool IsEmpty ();
	int SizeQueue ();
	void Print ();
	bool validar(char aux);
	void Enqueu (char letter, int priority);
	void Dequeu (char letter, int priority);
};
//fin clase cola de prioridad


//desarrollo de funciones
bool Priority_Queue::IsEmpty ()
{
	if (head == NULL)
		return true;
	return false;
}

int Priority_Queue::SizeQueue ()
{
	return tam;
}

void Priority_Queue::Print ()
{
	NodePQueue *aux = head;
	while (aux)
	{
		cout << aux -> letra<< " " << aux -> prio << " <- ";
		aux = aux -> sig;
	}
}

bool Priority_Queue::validar(char aux)
{
	NodePQueue *aux1;
	aux1= head;

	while(aux1!=NULL)
	{
		if (aux1->letra==aux)
		{
			return false;
		}
		aux1=aux1->sig;
	}
	return true;
}	

void Priority_Queue::Enqueu (char letter, int priority)
{
	if (IsEmpty ())
	{
		head = new NodePQueue (letter, priority, NULL);
		tail=head;
	}
	else
	{
		NodePQueue *aux = head;
		if (aux -> prio >= priority)
		{
			head = new NodePQueue (letter, priority, aux);
		}
		else 
		{
			while (aux -> sig && aux -> sig -> prio <= priority)
				aux = aux -> sig;
				aux -> sig = new NodePQueue (letter, priority, aux -> sig);
		}
	}
}

void Priority_Queue::Dequeu (char letter, int priority)
{
	if (IsEmpty ())
	{
		cout << "esta vacia" << endl;
		return;
	}
	else
	{
		NodePQueue *aux = head;
		head = head -> sig;
		delete aux;
	}
}

int main ()
{
	Priority_Queue queue;
	int priority;
	int contL, priori=0;
	string frase;
	char letter, aux;
	
	getline(cin, frase);

	contL= frase.length();

	for(int i=0; i<contL; i++)
	{
		for(int j=0; j<=contL; j++)
		{
			if(frase[i]==frase[j])
			{
				priori++;
			}
		}
		aux=frase[i];

		//cout<<"soy aux: "<<aux<<endl;
		if (queue.validar(aux))
		{
			queue.Enqueu(aux,priori);
		}
		priori=0;
	}
	queue.Print();
	cout<<endl;
	queue.Dequeu (aux, priori);
	queue.Print ();

	return 0;
}