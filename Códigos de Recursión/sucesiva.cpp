#include <iostream>

using namespace std;

  int sucesiva( int arr [], int i, int k, int cont)
  {

    if ( cont == k)
      {

        return cont;
      }
    else
      {
        if ((arr[i] < arr[i+1] )&&(arr[i+1]==(arr[i]+1)))
          {

            cont+= arr[i];


            //cout<<cont<<endl;

             sucesiva( arr, i++, k, cont);
          }


      }
  }

  int main()
  {
    int i=0, k=16, cont=0;

    int arr[]={1,2,3,4,5,6};

    cout<< sucesiva(arr, i, k, cont)<<"--"<<endl;

  }
