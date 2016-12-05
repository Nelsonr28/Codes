#include <iostream>

using namespace std;

int ElemImpares (int arr [], int arrayImpar [], int tam, int ind, int impares)  // retorna los elementos impares en un segundo array
{
  if (ind == tam)    //si el indice es igual al tamaño: Caso base
  {
    
  }
  else
  {

    if (arr [ind] % 2 != 0)    //si el residuo de la división es distinto de 0, es impar
    {
      impares = impares + 1;    //contador de el número de elementos impares que hay en el arreglo original
      for (int i = 0; i < impares; i++)    //barro el arreglo hasta el número de elementos impares. Siendo este el tamaño del arreglo
      {
      impares = 0;        //inicializo nuevamente impares, para evitar repetir los números
        arrayImpar [i] = arr [ind];    //copia los elementos impares al arreglo nuevo
        cout << arrayImpar [i] << " ";  //muestra los elementos impares en el arreglo nuevo
      }
    }
      int resul;
     resul = ElemImpares (arr, arrayImpar, tam, ind + 1, impares);    //Caso recursivo: llama a la función hasta llegar al caso base
  }
}

int main ()
{
  int tam, ind, impares;
  tam = 10;    //tamaño del arreglo original
  ind = 0;      //indice para moverse en el arreglo original
  impares = 0;  //contador para el numero de elementos impares
  int arr [] = {2, 5, 4, 7, 11, 13, 15, 6, 23, 10};    //arreglo original inicializado
  int arrayImpar [tam];    //arreglo para guardar elementos impares
  cout << ElemImpares (arr, arrayImpar, tam, ind, impares) << endl;
}
