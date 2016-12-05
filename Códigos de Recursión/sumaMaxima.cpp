#include <iostream>

using namespace std;

/*
Algoritmos y Estructura de Datos
Ej 13 Practica de Backtraking
*/


int const N = 4; //Tamaño de la matriz

int Matriz[N][N] = {{-1,0,-5,0},{-3,9,7,-9},{-8,6,-8,0},{-5,-8,15,5}}; //Inicializamos la matriz
///Posibles movimentos a realizar:
int MovimientoSupI[] = {0,1,0,-1,0,0,0,0};
int MovimientoSupJ[] = {1,0,-1,0,0,0,0,0};
int MovimientoInfI[] = {0,0,0,0,0,1,0,-1};
int MovimientoInfJ[] = {0,0,0,0,1,0,-1,0};
///
int Marca[N+1][N+1][N+1][N+1]; //Para marcar las submatrices ya verificadas

void print(int, int, int, int); //Accion que Imprime una sub-Matriz
int sumar(int, int, int, int); //Funcion que retorna la suma de una subMatriz
void sumaMaxima(int, int, int, int, int&, int&, int&, int&, int&); /*Accion Backtraking recibe los limites
                                                                de la subMatriz actual y los de la mejor Solucion
                                                                conseguida hasta ese momento*/

int main()
{
    int Lif, Lsf, Lic, Lsc, suma;
    Lif = 0; //Limite inferior de fila
    Lic = 0; //Limite inferior de columna
    Lsf = 1; //Limite superior de fila
    Lsc = 1; //Limite superior de columna
    suma = Matriz[0][0]; //Mejor suma hasta ese momento, se inicializa con la primera posicion de la matriz

    Marca[Lif][Lsf][Lic][Lsc] = 1; //Inidca que esta matriz ya fue utilizada

    print(0,N,0,N); //imprimiendo la matriz de entrada

    sumaMaxima(0,1,0,1,Lif,Lsf,Lic,Lsc,suma); //Busca la submatriz de suma maxima y almacena la informacion
                                                //en las variables Lif, Lsf, Lic, Lsc y suma

    cout << "Suma maxima: " << suma <<endl; //imprimiendo la suma maxima

    print(Lif,Lsf,Lic,Lsc); //imprimiendo la sub-matriz de suma maxima

}

//Backtraking: Buscando todas las posibles subMatrices

void sumaMaxima(int LifAct, int LsfAct, int LicAct, int LscAct ,int &Lif, int &Lsf, int &Lic, int &Lsc, int &sumMejor)
{
    int sumAct = sumar(LifAct,LsfAct,LicAct,LscAct);

    if(sumAct > sumMejor) //Si la suma actual es la mejor se almacena ésta como solucion parcial
    {
        Lif = LifAct;
        Lsf = LsfAct;
        Lic = LicAct;
        Lsc = LscAct;
        sumMejor = sumAct;
    }

    for(int i=0; i<8; i++) //Para cada candidato de movimiento
    {
        //Se selecciona un candidato
        LifAct = LifAct + MovimientoInfI[i];
        LicAct = LicAct + MovimientoInfJ[i];
        LsfAct = LsfAct + MovimientoSupI[i];
        LscAct = LscAct + MovimientoSupJ[i];

        //Si el candidato es valido: Es decir que los limites esten dentro del rango y que no haya sido utilizada anteriormente esta subMatriz
        if(LifAct>=0 && LicAct>=0 && LsfAct<=N && LscAct<=N && LifAct<LsfAct && LicAct < LscAct && Marca[LifAct][LsfAct][LicAct][LscAct] == 0) //si no ha sido evaluado anteriormente
        {
            Marca[LifAct][LsfAct][LicAct][LscAct] = 1; //Se marca esta subMatriz
            sumaMaxima(LifAct,LsfAct,LicAct,LscAct,Lif,Lsf,Lic,Lsc,sumMejor); //Llamada Recursiva
        }
        //Regresando al paso anterior
        LifAct = LifAct - MovimientoInfI[i];
        LicAct = LicAct - MovimientoInfJ[i];
        LsfAct = LsfAct - MovimientoSupI[i];
        LscAct = LscAct - MovimientoSupJ[i];
    }

}

//Imprimiendo SubMatriz
void print(int iniI, int finI, int iniJ, int finJ)
{
    for(int i=iniI; i<finI; i++)
    {
        for(int j=iniJ; j<finJ; j++)
        {
            cout << Matriz[i][j] << " ";
        }
        cout << endl;
    }

}

//Retorna suma de la SubMatriz
int sumar(int iniI, int finI, int iniJ, int finJ)
{
    int suma = 0;
    for(int i=iniI; i<finI; i++)
    {
        for(int j=iniJ; j<finJ; j++)
        {
            suma = suma + Matriz[i][j];
        }
    }
    return suma;
}
