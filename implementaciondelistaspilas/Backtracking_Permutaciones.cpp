#include <iostream>
using namespace std;

void Imprimir(int Sol[3]){
	for (int i=0; i < 3; i++){
		cout<<Sol[i];
	}
	cout<<endl;
}

void Permutaciones(int Num[3], bool Log[3], int Sol[3], int N, int S){
	int i=0;
	
	while(i < N){
		if(Log[i]==false){
			Log[i]=true;
			Sol[S]=Num[i];
			S++;
			
			if(S+1 > N){
				Imprimir(Sol);
			}
			else{
				Permutaciones(Num,Log,Sol,N,S);
			}
			S--;
			Log[i]=false;
		}
		i++;
	}
}


int main(){
	int Num[3]={1,2,3};
	bool Log[3]={false,false,false};
	int Sol[3]={0,0,0};
	Permutaciones(Num,Log,Sol,3,0);
}

