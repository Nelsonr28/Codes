#include <iostream>

using namespace std;


int sumaElementos(int cont, int n, int arr[], int indice) //retorna el suma de los elementos de un arreglo de enteros
{
    if(indice == n) //Caso Base: si ya se recorrió todo el arreglo
    {
        return cont;
    }
    else //Caso Recursivo: llamar hasta llegar al final del arreglo
    {
        cont = cont + arr[indice]; //se suma el valor de la posición actual
        return sumaElementos(cont,n,arr,indice+1);
    }
}


int main()
{
    int n, cont, indice;

    n = 7;      //tamaño del arreglo
    int arr[] = {4,8,6,1,5,2,3};   //definimos el arreglo
    indice = 0;    //comenzamos desde la posicion 1
    cont = 0; //se inicializa el contador

    cout << sumaElementos(cont,n,arr,indice) << endl;


}
