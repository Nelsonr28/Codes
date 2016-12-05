#include <iostream>

using namespace std;

/*
Ejemplo de entrada:

9
0 0 0 0 0 0 0 0 1
0 1 0 1 1 1 1 0 1
0 1 0 0 1 0 0 0 1
0 1 1 0 0 0 1 1 1
0 0 0 0 0 0 0 0 0
1 0 1 0 0 0 1 1 0
1 0 1 0 1 0 1 0 0
1 0 0 0 1 0 1 0 0
1 1 1 0 1 0 0 0 0


*/


int MovimientoI[] = {1,-1,0,0}; //posibles movimientos en las filas
int MovimientoJ[] = {0,0,1,-1}; //posibles movimientos en las columnas

class Laberinto
{
    private:

    int N; //Dimensiones del laberinto N*N
    int Matriz[100][100]; //asumimos 100 como el tama�o maximo
    int MatrizSolucion[100][100]; //Matriz que indica los pasos tomados para la solucion
    int pasosM; //cantidad de pasos para la mejor solucion
    int si, sj, fi, fj; //posiciones iniciales y finales para el laberinto

    public:

    Laberinto() //Constructor
    {
        cin >> N; //tama�o del laberinto
        int i, j;
        //Entrada del laberinto
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                cin >> Matriz[i][j]; //0 espacio libre, 1 pared
            }
        }
        //Posiciones iniciales y finales:
        si = 0;
        sj = 0;
        fi = N-1;
        fj = N-1;

        pasosM = -1; //almacena la cantidad de pasos para la mejor solucion
        Matriz[si][sj] = 2; //posicion inicial como visitada
    }

    //Backtraking:
    void solucionar(int pasos) //Parametro: Pasos realziados hasta el momento la primera vez vale 0
    {
        if(si == fi && sj == fj) //CASO BASE: si lleg� a la salida
        {
            if(pasos < pasosM || pasosM == -1) //si esta solucion es mejor que la ya almacenada
            {
                almacenar(pasos);
            }
        }
        else
        {
            int i;
            for(i=0; i<4; i++) //hay cuatro posibles candidatos de movimiento
            {
                //se selecciona candidato
                si += MovimientoI[i];
                sj += MovimientoJ[i];
                if(si>=0 && si<N && sj>=0 && sj<N && Matriz[si][sj] == 0) //si el candidato es valido
                {
                    Matriz[si][sj] = 2; //se marca como visitada la posicion con el numero 2
                    pasos += 1; //avanzo un paso
                    solucionar(pasos); //lamada recursiva
                    Matriz[si][sj] = 0; //se desmarca para buscar otras soluciones
                    pasos -= 1; //se regresa el paso (backtraking)
                }
                //se borra candidato para intentar con otro
                si -= MovimientoI[i];
                sj -= MovimientoJ[i];
            }
        }

    }

    void almacenar(int pasos)
    { //almacena la mejor solucion hasta el momento
        pasosM = pasos;
        int i, j;
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                MatrizSolucion[i][j] =  Matriz[i][j];
            }
        }
    }

    void imprimir()
    {//imprime mejor solucion
        int i, j;
        cout << "Solucion en " << pasosM << " pasos:" << endl;
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                cout << MatrizSolucion[i][j] << " ";
            }
            cout << endl;
        }
    }

};

int main()
{
    Laberinto *laberinto;
    laberinto = new Laberinto(); //Creamos un nuevo laberinto
    laberinto->solucionar(0); //se soluciona con t�cnica de backtraking
    laberinto->imprimir(); //se imprime la mejor solucion
}
