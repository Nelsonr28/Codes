#include <iostream>
#include <iomanip>

using namespace std;

int caras [6][3][3];
int caras2 [6][3][3];

void guarda();
void print_cube();

int main ()
{
  int i = 1;

  for (int k = 0; k < 6; k++)
    {
      for (int f = 0; f < 3; f ++)
        {
          for (int c = 0; c < 3; c++)
            {
              caras [k][f][c] = i;
              //caras2 [k][f][c] = i;
              i++;
            }
        }
    }
    print_cube();
}

/*void guardar()
{
  for (int k = 0; k < 6; k++)
    {
      for (int f = 0; f < 3; f++)
        {
          for (int c = 0; c < 3; c++)
            {
              caras [k][f][c] ;//= caras2 [k][f][c];
            }
        }
    }
}*/

void print_cube()
{

  for (int k = 0; k < 6; k++)
    {
      for (int f = 0; f < 3; f ++)
        {
          for (int c = 0; c < 3; c++)
            {
              cout << setw(3) << caras [k][f][c];
            }
            cout << endl;
        }
        cout << endl;
    }

}
