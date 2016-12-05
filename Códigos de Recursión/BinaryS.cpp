#include <iostream>

using namespace std;

bool BinaryS (int arr[], int ind, int ind2, int n)
{
  int m;
  m = (ind + ind2)/ 2;
  if ((arr[m]!= n) && (ind == ind2))
    return false;
  if (arr[m] == n)
  return true;
  if (arr[m] < n)
  return BinaryS (arr, m + 1, ind2, n);
  if (arr[m] > n)
  return BinaryS (arr, ind , m - 1, n);
}


int main ()
{
  int tam, n, ind, ind2;
  tam = 8;
  int arr[] = {3, 5, 9, 15, 20, 25, 26, 28};

  cin >> n;
  if (BinaryS (arr, 0, tam - 1, n))
  {
  cout << "El elemento esta en el arreglo" << endl;
  }
  else
  cout << "No esta" << endl;
}
