#include <iostream>

using namespace std;


bool arregloOrdenado(int n, int arr[], int indice) //retorna true si el arreglo esta ordenado, false en otro caso
{
    if(indice == n) //Caso Base: si ya se recorrió todo el arreglo
    {
        return true;
    }
    if(arr[indice-1] > arr[indice]) //Caso Base: si el anterior es mayor que el actual entonces no está ordenado
    {
        return false;
    }
    else //Caso Recursivo: llamar hasta llegar al final del arreglo
    {
        return arregloOrdenado(n,arr,indice+1);
    }
}


int main()
{
    int n, indice;

    n = 7;      //tamaño del arreglo
    int arr[] = {4,8,6,1,5,2,3};   //definimos el arreglo
    indice = 1;    //comenzamos a verificar desde la posición 2

    if(arregloOrdenado(n,arr,indice)) //si retorna true
    {
        cout << "Arreglo Ordenado"<< endl;
    }
    else
    {
        cout << "Arreglo No ordenado" << endl;
    }

}
