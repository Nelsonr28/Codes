#include <iostream>

using namespace std;

void ElemImpares (int arr [], int arrayImpar [], int tam, int ind)  // retorna los elementos impares en un segundo array
{
  if (ind > tam)    //si el indice es igual al tamaño: Caso base
  {
    return ;
  }
  else
  {

    if (arr[ind] % 2 != 0)    //si el residuo de la división es distinto de 0, es impar
    {

        cout << arr [ind] << " " << endl;  //muestra los elementos impares en el arreglo nuevo

    }
   ElemImpares (arr, arrayImpar, tam, ind + 1);    //Caso recursivo: llama a la función hasta llegar al caso base
  }
}

int main ()
{
  int tam, ind;
  tam = 10;    //tamaño del arreglo original
  ind = 0;      //indice para moverse en el arreglo original

  int arr [] = {2, 5, 4, 7, 11, 13, 15, 6, 23, 10};    //arreglo original inicializado
  int arrayImpar [tam];    //arreglo para guardar elementos impares
  ElemImpares (arr, arrayImpar, tam, ind);
}
