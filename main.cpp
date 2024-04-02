#include <iostream>
#include "MODULOS.h"
using namespace std;

int main()
{

    int pCondicion = 3;
    int nMayor;
    int* resultadoValidacion = validar();
    int Tam_K = resultadoValidacion[0];
    int Condiciones = Tam_K-2;
    if (resultadoValidacion[1] > resultadoValidacion[2]){
        nMayor = resultadoValidacion[1];
    }
    else{
        nMayor = resultadoValidacion[2];
    }
    if ((nMayor%2)==0){
        nMayor++;
    }
    int pCambiante1[2];
    pCambiante1[0] = resultadoValidacion[1];
    pCambiante1[1] = resultadoValidacion[2];
    int pCambiante2[2];
    pCambiante2[0] = pCambiante1[0];
    pCambiante2[1] = pCambiante1[1];
    int nCambiante = nMayor;
    int** M_Base = CrearM(nMayor);
    int dimension = nMayor;
    int c_Matricez=resultadoValidacion[0]-1;
    int X[c_Matricez];
    int P[c_Matricez];
    int pArreglos = 1;
    int** Matriz_B = CrearM(nCambiante);
    X[0]=nMayor;
    P[0]=0;

    while(Condiciones >= 1){
        bool Comparar = false;
        while(Comparar == false){
            int rotacion=0;

            while(rotacion<=3){

                Comparar =  comparar_arreglos(M_Base, Matriz_B, pCambiante1[0]-1, pCambiante1[1]-1, pCambiante2[0]-1, pCambiante2[1]-1, resultadoValidacion[pCondicion]);

                if(Comparar == false){
                    rotarM(Matriz_B, nCambiante);
                    rotacion++;

                }
                else{
                    X[pArreglos]=nCambiante;
                    P[pArreglos]=rotacion;
                    pArreglos++;
                    liberar_memoria(M_Base,dimension);
                    cambiar_matriz(M_Base,Matriz_B, nCambiante);
                    dimension = nCambiante;

                    liberar_memoria(Matriz_B,nCambiante);
                    nCambiante = nMayor;
                    Matriz_B = CrearM(nCambiante);
                    pCambiante1[0] = pCambiante2[0];
                    pCambiante1[1] = pCambiante2[1];
                    pCambiante2[0] = resultadoValidacion[1];
                    pCambiante2[1] = resultadoValidacion[2];

                    rotacion = 10;
                }

                if(rotacion==4){
                    liberar_memoria(Matriz_B, nCambiante);
                    nCambiante+=2;
                    Matriz_B = CrearM(nCambiante);

                    if(dimension < nCambiante){
                        pCambiante1[0] = pCambiante2[0];
                        pCambiante1[1] = pCambiante2[1];
                        pCambiante2[0]++;
                        pCambiante2[1]++;

                    }
                    else{
                        pCambiante2[0]++;
                        pCambiante2[1]++;
                    }
                }
            }
        }

        Condiciones--;
        pCondicion++;

    }
    cout << "Para una regla K: (";
    for(int i = 1; i < Tam_K; i++) {
        cout << resultadoValidacion[i] << ", ";
    }
    cout << resultadoValidacion[Tam_K] << ") una posible cerradura podria ser:" << endl << "X(";
    for(int i = 0; i < c_Matricez-1; i++) {
        cout << X[i] << ", ";
    }
    cout << X[c_Matricez-1] << ")" << endl << "Esta cerradura tendria las siguientes rotaciones en su respectivo orden a X:" << endl <<"R(";;

    for(int i = 0; i < c_Matricez-1; i++) {
        cout << P[i] << ", ";
    }
    cout << P[c_Matricez-1] << ")" << endl;
    delete[] resultadoValidacion;
    liberar_memoria(M_Base, dimension);
    liberar_memoria(Matriz_B, nCambiante);

    return 0;
}
