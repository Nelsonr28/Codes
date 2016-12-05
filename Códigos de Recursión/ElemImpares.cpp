#include <iostream>

using namespace std;

int ElemImpares (int arr [], int tam, int ind, int impares)
{
  if (ind == tam)
  {
    return impares;
  }
  else
  {

    if (arr [ind] % 2 != 0)
    {
      impares = impares + 1;
    }
    return ElemImpares (arr, tam, ind + 1, impares);
  }
}

int main ()
{
  int tam, ind, impares;
  tam = 13;
  ind = 0;
  impares = 0;
  int arr [] = {1,2,3,4,5,6,7,8,10,11,9,21};
  cout << "Hay " << ElemImpares (arr, tam, ind, impares) << " elementos impares en el arreglo" << endl;
}
