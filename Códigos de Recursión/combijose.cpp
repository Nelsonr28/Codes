#include <iostream>

using namespace std;

  int factorial ( int n)
  {
    if ( n==0 || n==1)
      {
        return 1;
      }
    else
      {
        return n*factorial(n-1);
      }

  }

  int combinatoria (int n, int m)
  {
    int combi;

    combi= factorial(n)/ (factorial(m) * factorial(n-m));
  }

  int main()
  {
    int  n;
    int  m;
    cin>>n>>m;
    cout<<combinatoria (n,m)<<endl;
  }
