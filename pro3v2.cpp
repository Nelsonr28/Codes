#include <iostream>
#include <string>

using namespace std;

//inicio de la clase arbol
class NodoTree
{
public:
	char info;
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

class TreeBin
{
public:
	NodoTree *raiz;
	TreeBin ()
	{
		raiz = NULL;
	}

public:
	 bool treeEmpty ();
};
//fin clase arbol


//desarrollo de metodos de la clase arbol
bool TreeBin::treeEmpty ()
	{
		if (raiz == NULL)
			return true;
		return false;
	}

//fin de los metodos de la clase arbol


//inicio de la clase cola de prioridad
class NodePQueue
{
	public:
		char letra;
		int prio;
		NodePQueue *sig , *ant;
};

class Priority_Queue
{
public:
	NodePQueue *head, *tail;		//primer public: consructor y destructor respectivamente
	int tam;
	Priority_Queue ()
	{
		head = tail = NULL;
		tam = 0;
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
	return (tam);
}

void Priority_Queue::Print ()
{
	NodePQueue *aux = head;
	while (aux)
	{
		cout << aux -> letra << " " << aux -> prio << " <- ";
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
	NodePQueue *nuevo = new NodePQueue;
	nuevo -> letra = letter;
	nuevo -> prio = priority;
	nuevo -> sig = NULL;

	if (head == NULL)
	{
		head = nuevo;
		tail = nuevo;
	}
	else
	{	
		for (NodePQueue *aux = head; aux != NULL; aux = aux -> sig)
		{
			NodePQueue *aux2 = aux -> sig;
			if (aux == head && nuevo -> prio <= head -> prio)
			{
				nuevo -> sig = head;
				head = nuevo;
				return;
			}
			if (aux2 == NULL)
			{
				aux -> sig = nuevo;
				return;
			}
			if (priority < aux2 -> prio && priority <= aux2 -> prio)
			{
				nuevo -> sig = aux2;
				aux -> sig = nuevo;
				return;
			}
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