#include <iostream>
using namespace std;
int minimo(int m, int arr[], int tam, int ind)
{
  if(ind==tam)
  {
    return m;
  }

else
{

 if (arr[ind]<m){
 m=arr[ind];
                  }

                return minimo( m, arr, tam, ind+1);
}}
 int main ()
 {
  int min, tam, index;
  tam=6;
  index=0;
    int arr[]={4,2,3,-1,3,1};
    min=arr[index];
  cout<<minimo(min, arr,tam, index)<<endl;
 }
