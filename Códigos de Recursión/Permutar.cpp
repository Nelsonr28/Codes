#include <iostream>
#include <string>

using namespace std;


	void intercambio(string &str, int a, int b )
	{
		char c = str[a];
		str[a]= str[b];
		str[b]= c;
	}


	void Permute(string &text, int star, int end)

	{
		if (star==end)
		{
			cout<<endl<<"text"<<endl<<endl;
		}
		else
		{
			for (int i= star; i<= end; i++)
			{
				intercambio(text, star, i);
				Permute(text, star+1, end);
				intercambio(text, star, i);

			}
		}
	}

int main()
{
	string str;
	int a,b;
	int star, end;

	cout<<Permute(text,star,end)<<endl;

}
