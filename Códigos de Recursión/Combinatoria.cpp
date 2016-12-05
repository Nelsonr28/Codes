#include <iostream>

using namespace std;

int Factorial (int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
      return n * Factorial (n-1);
    }

}

int Combinatoria (int n, int m)
{
  int resultado;
     resultado = Factorial(n)/(Factorial(m)*Factorial(n-m));
}                                                        

int main ()
{
  int n, m;
  cin >> n;
  cin >> m;
  cout << Combinatoria (n, m) << endl;
}
