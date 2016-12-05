#include <iostream>

using namespace std;

int main ()
{
  int n, m;
  cin >> n;
  m = n % 10;
  while (n >= 10)
  {
    n = n / 10;
    cout << "soy n --> " << n << endl;
    cout << "soy m --> " << m << endl;
  }

}
