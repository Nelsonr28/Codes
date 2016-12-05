#include <iostream>

using namespace std;


int mayorElemento(int mayor, int n, int arr[], int indice) //retorna el mayor elemento de un arreglo de enteros
{
    if(indice == n) //Caso Base: si ya se recorrió todo el arreglo
    {
        return mayor;
    }
    else //Caso Recursivo: llamar hasta llegar al final del arreglo
    {
        if(mayor < arr[indice]) //se busca el mayor elemento
        {
            mayor = arr[indice];
        }
        return mayorElemento(mayor,n,arr,indice+1);
    }
}


int main()
{
    int n, mayor, indice;

    n = 7;      //tamaño del arreglo
    int arr[] = {4,8,6,1,5,2,3};   //definimos el arreglo
    mayor = arr[0];     //definimos el primer elemento como
                        //el mayor para comenzar a buscar
    indice = 1;    //comenzamos a buscar desde la posición 2

    cout << mayorElemento(mayor,n,arr,indice) << endl;

}
