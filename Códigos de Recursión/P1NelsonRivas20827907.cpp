#include <iostream>
#include <string>

using namespace std;


  enum   //Direccion en que se mueve el cubo
  {
    mov_horario,    //Movimiento en sentido de las agujas del reloj
    mov_antihor    // ""        ""    "" contrario ""    ""
  };

  enum
  {
    frente, der, izq, arr, atras, abajo
  };

//##############################################################################
class Cube      //Esta clase es para almacenar las caracteristicas del cubo
{
public:
  char caras [6][3][3];

  typedef struct colores
  {
    char rojo, azul, verde, blanco, naranja, amarillo;
  }COLORES;


public:

  void guardar()
  {
    for (int k = 0; k < 6; k++)
      {
        for (int f = 0; f < 3; f++)
          {
            for (int c = 0; c < 3; c++)
              {
                cin >> caras [k][f][c];
              }
          }
      }
  }

  void print_cube()
  {

    for (int k = 0; k < 6; k++)
      {
        for (int f = 0; f < 3; f ++)
          {
            for (int c = 0; c < 3; c++)
              {
                cout << caras [k][f][c]<< "  ";
              }
              cout << endl;
          }
          cout << endl;
      }

  }
  void rotar_cara(int c, int m){
    char aux[3][3];

    for(int i =0;i<3;++i)
      for(int j =0;j<3;++j)
        aux[i][j] = caras[c][i][j];

    if(m == mov_horario)
      {

        caras[c][0][2] = aux[0][0];
        caras[c][1][2] = aux[0][1];
        caras[c][2][2] = aux[0][2];
        caras[c][0][1] = aux[1][0];
        caras[c][1][1] = aux[1][1];
        caras[c][2][1] = aux[1][2];
        caras[c][0][0] = aux[2][0];
        caras[c][1][0] = aux[2][1];
        caras[c][2][0] = aux[2][2];
      }
    else
      {
        caras[c][0][0] = aux[0][2];
        caras[c][0][1] = aux[1][2];
        caras[c][0][2] = aux[2][2];
        caras[c][2][0] = aux[0][0];
        caras[c][1][0] = aux[0][1];
        caras[c][2][2] = aux[2][0];
        caras[c][2][1] = aux[1][0];
        caras[c][1][2] = aux[2][1];
        caras[c][2][2] = aux[2][0];

      }

  }

protected:
  int cara_moved;      //Caras que son movidas
  int color_nom [6];
};
//##############################################################################


int main ()
{
  Cube c;
  c.guardar();
  c.print_cube();
  cout<<"________"<<endl;
  c.rotar_cara(0,mov_antihor);
  c.print_cube();
}
