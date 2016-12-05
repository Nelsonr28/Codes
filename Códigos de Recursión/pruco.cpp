#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int cubo[6][3][3];
int mtem[6][3][3];
int t;

void guarda();

void imprime_cubo();

void menu();

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

int main(){
    int i = 1;
    for(int f = 0; f < 6; f++){
        for(int l = 0; l < 3; l++){
            for(int a = 0; a < 3; a++){
                cubo[f][l][a] = i;
                mtem[f][l][a] = i;
                i++;
            }

        }
    }

    menu();
    return EXIT_SUCCESS;
}

void guarda(){
    for(int f = 0; f < 6; f++){
        for(int l = 0; l < 3; l++){
            for(int a = 0; a < 3; a++){
                cubo[f][l][a] = mtem[f][l][a];
            }
        }
    }
}

void imprime_cubo(){
    for(int f = 0; f < 6; f++){
        for(int l = 0; l < 3; l++){
            for(int a = 0; a < 3; a++){
                cout<<setw(6)<<cubo[f][l][a];
            }
            cout<<endl;
        }
        cout<<endl;
    }
}

void menu(){
    int opc = 0;
    while(opc != 14){
        system("cls");
        cout << "Cubo de 3 dimenciones (:Selecciona una opcion) :"<<endl
        << " 1) Mostrar Cubo"<<endl
        << " 2) Girar Frente Izquierda"<<endl
        << " 3) Girar Frente Derecha"<<endl
        << " 4) Girar Fondo Izquierda"<<endl
        << " 5) Girar Fondo Derecha"<<endl
        << " 6) Girar Izquierda Arriba"<<endl
        << " 7) Girar Izquierda Abajo"<<endl
        << " 8) Girar Derecha Arriba"<<endl
        << " 9) Girar Derecha Abajo"<<endl
        << " 10) Girar Arriba Izquierda"<<endl
        << " 11) Girar Arriba Derecha"<<endl
        << " 12) Girar Abajo Izquierda"<<endl
        << " 13) Girar Abajo Derecha"<<endl
        << " 14) Salir"<<endl;
        cin>>opc;
        switch(opc){
            case 1:
                imprime_cubo();
                system("Pause>nul");
                break;
            case 2:
                gira_frente_izquierda();
                break;
            case 3:
                gira_frente_derecha();
                break;
            case 4:
                gira_fondo_izquierda();
                break;
            case 5:
                gira_fondo_derecha();
                break;
            case 6:
                gira_izquierda_arriba();
                break;
            case 7:
                gira_izquierda_abajo();
                break;
            case 8:
                gira_derecha_arriba();
                break;
            case 9:
                gira_derecha_abajo();
                break;
            case 10:
                gira_arriba_izquierda();
                break;
            case 11:
                gira_arriba_derecha();
                break;
            case 12:
                gira_abajo_izquierda();
                break;
            case 13:
                gira_abajo_derecha();
                break;
            case 14:
                cout<<"Programa Hecho Por Julio Cesar Hernandez Hernandez";
                break;
            default:
                cout<<"Error de seleccion";
                system("Pause>nul");
                break;
        }
    }
}

void gira_frente_izquierda(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[0][t][x] = cubo[0][x][y];
        }
        t++;
    }
    guarda();
}

void gira_frente_derecha(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[0][x][t] = cubo[0][y][x];
        }
        t++;
    }
    guarda();
}

void gira_izquierda_arriba(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[0][t][x] = cubo[0][x][y];
        }
        t++;
    }
    guarda();
}

void gira_izquierda_abajo(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[x][t][0] = cubo[y][x][0];
        }
        t++;
    }
    guarda();
}

void gira_derecha_arriba(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[t][x][2] = cubo[x][y][2];
        }
        t++;
    }
    guarda();
}

void gira_derecha_abajo(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[x][t][2] = cubo[y][x][2];
        }
        t++;
    }
    guarda();
}

void gira_arriba_izquierda(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[t][0][x] = cubo[x][0][y];
        }
        t++;
    }
    guarda();
}

void gira_arriba_derecha(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[x][0][t] = cubo[y][0][x];
        }
        t++;
    }
    guarda();
}

void gira_abajo_izquierda(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[t][2][x] = cubo[x][2][y];
        }
        t++;
    }
    guarda();
}

void gira_abajo_derecha(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[x][2][t] = cubo[y][2][x];
        }
        t++;
    }
    guarda();
}

void gira_fondo_izquierda(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[2][t][x] = cubo[2][x][y];
        }
        t++;
    }
    guarda();
}

void gira_fondo_derecha(){
    t = 0;
    for(int y = 2; y >= 0; --y){
        for(int x = 0; x < 3; x++){
            mtem[2][x][t] = cubo[2][y][x];
        }
        t++;
    }
    guarda();
}
