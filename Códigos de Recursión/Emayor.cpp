#include <iostream>
using namespace std;

  int Mayor (int arr[], int i, int tam,int Emayor){



    if ( i == tam){

      return Emayor;
    }else{

    if (Emayor<arr[i]){

      Emayor= arr[i];
    }
      return  Mayor( arr, i+1, tam, Emayor);

    }
}


  int main (){

  int tam, i;
  tam=13;

  int arr[]={1,2,3,4,5,6,7,8,15,11,12,9,13};
  i=0;
  int Emayor= arr[0];
  cout<< Mayor(arr, i, tam,Emayor)<<endl;



}
