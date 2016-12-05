#include <iostream>

using namespace std;

float media(int cont, int n, int arr[], int indice) //retorna la media de los elementos de un arreglo de enteros
{
    if(indice == n) //Caso Base: si ya se recorri� todo el arreglo
    {
        return cont/n; //como ya es el ultimo elemento se divide la suma total entre el tama�o del arreglo
                            //se coloca (float) para que pueda retornar la divisi�n real en vez de la divisi�n entera (div)
    }
    else //Caso Recursivo: llamar hasta llegar al final del arreglo
    {
        cont = cont + arr[indice]; //se suma el valor de la posici�n actual
        return media(cont,n,arr,indice+1);
    }
}


int main()
{
    int n, cont, indice;

    n = 7;      //tama�o del arreglo
    int arr[] = {4,8,6,1,5,2,3};   //definimos el arreglo
    indice = 0;    //comenzamos desde la posicion 1
    cont = 0; //se inicializa el contador

    cout << media(cont,n,arr,indice)<< endl;

}
