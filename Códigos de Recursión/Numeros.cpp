#include <iostream>

using namespace std;

int main ()
{
  int sum_pos = 0;
  int sum_nega = 0;
  int sum_total = 0;
  for (int i = -500; i <= 500; i++)
    {
      if ((i % 2 != 0) && (i > 0))
        {
          sum_pos+= i;
        }
        if ((i % 2 != 0) && (i < 0))
          {
            sum_nega+= i;
          }
          sum_total = sum_total + i;
    }
    cout << "suma de numeros positivos: " << sum_pos << endl;
    cout << "suma de numeros negativos: " << sum_nega << endl;
    cout << "suma total de numeros: " << sum_total << endl;
}
//La suma total de elementos te da cero ya que; se restan ambos debido a que uno es el inverso del otro
//Lo que no entiendo es que; si es la suma del total de numeros que hay de -500 a 500, si es así, haras esto:
//sum_total = sum_pos - (sum_nega);
