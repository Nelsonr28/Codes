#include <iostream>
#include <string>
using namespace std;

int main()
{
	string palabra;	
	int tam; int i, x,j;
	char alf[27]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '};
	int cont[27]={0};
	
	getline(cin,palabra);
	tam=palabra.length();
	cout<<tam<<endl;
	for ( i=0; i<tam; i++)
	{
	    for (j=0; j<27; ++j)
	    {
			if(palabra[i]==alf[j])
			{
	     		cont[j]++;
			}
	    }
	}
for (x=0; x<27; x++)
{
	if (cont[x]!=0)
	{
		cout<<alf[x]<<":"<<cont[x]<<" ";
	}
} 
cout<<endl;
}