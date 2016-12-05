#include <iostream>
#include <string>

using namespace std;

  string capicua ( char arr [], int i, int f )
  {
    if( i==f)
      {
        return "es capicua";
      }

    else
      {
        if( arr[i] >= arr[f])
          {
            return capicua(arr, i+1, f-1);

          }

        else
          {
            return "no es capicua";
          }


      }

  }

  int main ()
  {
    char arr[]={'a','l','l','a'};
    int i=0;
    int f=4 ;
    cout<< capicua (arr, i ,f) <<endl;
  }
