#include <iostream>
#include <string>

using namespace std;
//##############################################################################
class Cube      //Esta clase es para almacenar las caracteristicas del cubo
{
public:
  typedef struct colors
  {
    char rojo;    //Cara frontal del cubo
    char azul;    // "" derecha ""
    char verde;    //"" izquierda ""
    char blanco;    //"" superior ""
    char naranja;   //"" trasera ""
    char amarillo;   //"" inferior ""
  }colors_t;

  typedef struct moved     //Direccion en que se mueve el cubo
  {
    int mov_horario;    //Movimiento en sentido de las agujas del reloj
    int mov_antihor;    // ""        ""    "" contrario ""    ""
  }moved_t;

public:
  Cube ();      //Constructor de la clase cubo
  ~Cube ();     //Destuctor ""    ""
  void gira_frente_izquierda();
  void gira_frente_derecha();
  void gira_izquierda_arriba();
  void gira_izquierda_abajo();
  void gira_derecha_arriba();
  void gira_derecha_abajo();
  void gira_arriba_izquierda();
  void gira_arriba_derecha();
  void gira_abajo_izquierda();
  void gira_abajo_derecha();
  void gira_fondo_izquierda();
  void gira_fondo_derecha();

protected:
  colors_t caras [6][3][3];    //Matriz del cubo
  colors_t cara_moved;      //Caras que son movidas
  moved_t lado_moved;       //Lado al que fue movido una cara
  char color_nom [6];
};
//##############################################################################

Cube::Cube()
{
  color_nom [rojo] = "rojo";
  color_nom [azul] = "azul";
  color_nom [verde] = "verde";
  color_nom [blanco] = "blanco";
  color_nom [amarillo] = "amarillo";
  color_nom [naranja] = "naranja";
}

Cube::~Cube()
{

}


int main ()
{

}
