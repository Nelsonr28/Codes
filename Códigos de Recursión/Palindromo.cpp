#include <iostream>

using namespace std;

int Palindromo (int n, int m)
{
  if (n < 10)
  {
    return n;
  }
  else
  {
    m = n % 10;
    while (n >= 10)
    {
      n = n / 10;
    }
    m = m;
    n = n;
    return Palindromo (n, m);
  }
}

int main ()
{
  int n, m;
  cin >> n;
  cout << Palindromo (n, m) << endl;
  if (m == n)
  {
    cout << "Es palindromo" << endl;
  }
  else
  {
    cout << "No es palindromo" << endl;
  }
}
