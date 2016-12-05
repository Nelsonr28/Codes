#include <iostream>
#include <fstream>
using namespace std;

int main()
{	
    string tx,binario,binario2="";
	char lt;
	int ult=0;
	int  op,i=2,x,valor=0,cant,a=0;
	fstream E;
	cin>>op;
	if(op==1)//lectura por consola
	{
		cin.ignore();
		getline(cin,tx);}
	if(op==2)//lectura por archivo
	{
		E.open("ENTRADA.txt", fstream::in | fstream::binary);
		cin.ignore();
		getline(E,tx);
		}
		if (tx[0]=='1'){ult=1;}
		if (tx[0]=='2'){ult=2;}
		if (tx[0]=='3'){ult=3;}
		if (tx[0]=='4'){ult=4;}
		if (tx[0]=='5'){ult=5;}
		if (tx[0]=='6'){ult=6;}
		cout<<tx<<endl;
		while (tx[i]!=' ')
		{
			i++;
			x=i-2;
		}	
		cout<<x<<endl;	
	   for(i=2; i<x+2; i++)
	     {
			lt=tx[i];
			valor=lt;
		    cout<<"ascii: "<<valor<<endl;
			valor=valor-32;
			cout<<valor<<endl;
	     do 
	      {
		   	cant=valor%2;
		   	valor=valor/2;
				if(cant==0){binario="0"+binario;}
				if(cant==1){binario="1"+binario;}
				if(valor/2==0){a++;}
	       }while (a!=2);
	       cout<<"binario1: "<<binario<<endl;
	     int  h=binario.length();
			  h=7-h;
				if(h==1 ){binario="0"+binario;}
				if(h==2 ){binario="00"+binario;}
				if(h==3 ){binario="000"+binario;}
				if(h==4 ){binario="0000"+binario;}
				if(h==5 ){binario="00000"+binario;}
				if(h==6 ){binario="000000"+binario;}
			cout<<"este es mi numero binario "<<binario<<endl;
				binario2=binario+binario2;
			 binario="";
			 a=0;		 
			}
			int g; g=binario2.length();
			binario2=binario2.substr(ult,g-1);
			g=binario2.length();
			cout<<"mi cadena+ tiene tamaño "<<g<<endl;
		cout<<"mi binario es: "<<binario2<<endl;
		
		typedef struct {
			char simb;
			string recor;
		}tabla;
			i=x+1;
		int s=0,cuenta=0;
		int n=tx.length();
		//cout<<h<<endl;
		tabla codigo[n];
		for (int j=i+1; j<n; j++)
			{
			   if (tx[j]!='1' and tx[j]!='0' and tx[j]!=' ') {codigo[s].simb=tx[j];s++;cuenta++;} 
				 if(tx[j]==' ' and tx[j+1]==' ' and tx[j-1]==' ') {codigo[s].simb=tx[j];s++;cuenta++;}
				   if (tx[j]=='0' or tx[j]=='1'){s--; codigo[s].recor=codigo[s].recor+tx[j]; s++;}	    
			}
		for(i=0; i<cuenta; i++){
			cout<<codigo[i].simb<<" "<<codigo[i].recor<<endl;
			}

	    string compara="";
	   
		for(int j=0; j<g; j++)
		{
			compara=compara+binario2[j];
			
				for(int i=0; i<cuenta; i++)
				{   
					if(compara==codigo[i].recor)
					{  // cout<<compara<<endl; 
						cout<<codigo[i].simb;
						compara="";break;
					}
				}	 
		 }
  }
