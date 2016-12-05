#include <iostream>

using namespace std;

int MenorElemento (int arr [], int tam, int ind, int menor)
{
  if (ind == tam)
  {
    return menor;
  }
  else
  {
    if (menor > arr[ind])
    {
      menor = arr[ind];
    }
    return MenorElemento (arr, tam, ind + 1, menor);
  }
}

int main ()
{
  int tam, ind, menor;
  tam = 10;
  ind = 1;
  int arr [] = {8, 5, 6, 7, 10, 9, 3, 2, 11, 15};
  menor = arr[0];
  cout << MenorElemento (arr, tam, ind, menor) << endl;
}
