#include <iostream>

using namespace std;

static void rotar_cara (bool mov_horario, int face)
{
  int temp [9];

  if (mov_horario)
    {
      temp [0] = face [6];
      temp [1] = face [3];
      temp [2] = face [0];

      temp [3] = face [7];
      temp [4] = face [4];
      temp [5] = face [1];

      temp [1] = face [3];
      temp [6] = face [8];
      temp [2] = face [2];

     }
   else
     {
       temp [0] = face [2];
       temp [1] = face [5];
       temp [2] = face [8];

       temp [3] = face [1];
       temp [4] = face [4];
       temp [5] = face [7];

       temp [6] = face [0];
       temp [7] = face [3];
       temp [8] = face [6];
     }
}
