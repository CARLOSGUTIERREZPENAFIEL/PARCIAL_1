#include <iostream>
#include "MODULO2.h"
#include "MODULO1.h"
using namespace std;

int main()
{
    bool Comparar , validar_condicion;
    int** M_Base, **Matriz_B, **Matriz_original;
    unsigned int dimension;
    unsigned int nCambiante;
    unsigned int c_Matrices;
    unsigned int pCondicion = 3;
    unsigned int nMayor;
    unsigned int numero_validar_1;
    int* resultadoValidacion = validar();
    unsigned int Tam_K = resultadoValidacion[0];
    unsigned int Condiciones = Tam_K-2;
    unsigned int pCambiante1[2];
    unsigned int pCambiante2[2];



    if (resultadoValidacion[1] > resultadoValidacion[2]){
        nMayor = resultadoValidacion[1];
    }
    else{
        nMayor = resultadoValidacion[2];
    }
    if ((nMayor%2)==0){
        nMayor++;
    }
    else if(nMayor==1){
        nMayor=3;
    }
    if(resultadoValidacion[1]==2 && resultadoValidacion[2]==2){
        nMayor=5;
    }
    pCambiante1[0] = resultadoValidacion[1];
    pCambiante1[1] = resultadoValidacion[2];
    pCambiante2[0] = pCambiante1[0];
    pCambiante2[1] = pCambiante1[1];
    nCambiante = nMayor;
    M_Base = CrearM(nMayor);
    Matriz_original = CrearM(nMayor);
    dimension = nMayor;
    c_Matrices=resultadoValidacion[0]-1;
    int X[c_Matrices];
    int P[c_Matrices];
    int pArreglos = 1;
    Matriz_B = CrearM(nCambiante);
    X[0]=nMayor;
    P[0]=0;


    while(Condiciones >= 1){
        Comparar = false;
        while(Comparar == false){
            unsigned int rotacion=0;

            while(rotacion<=3){
                if(resultadoValidacion[pCondicion] == 1){
                    validar_condicion = verificar_condicion(Matriz_original,nMayor,M_Base[pCambiante1[0]-1][pCambiante1[1]-1]);
                    if(validar_condicion == true){
                        cout<< "No se puede crear una cerradura con la clave ingresada"<< endl;
                        delete[] resultadoValidacion;
                        liberar_memoria(M_Base, dimension);
                        liberar_memoria(Matriz_B, nCambiante);
                        liberar_memoria(Matriz_original,nMayor);
                        return 0;

                    }
                }

                Comparar =  comparar_arreglos(M_Base, Matriz_B, pCambiante1[0]-1, pCambiante1[1]-1, pCambiante2[0]-1, pCambiante2[1]-1, resultadoValidacion[pCondicion]);

                if(Comparar == false){
                    rotarM(Matriz_B, nCambiante);
                    rotacion++;

                }
                else{

                    numero_validar_1 -= 1;

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
                    numero_validar_1 += 1;

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
    for(unsigned int i = 1; i < Tam_K; i++) {
        cout << resultadoValidacion[i] << ", ";
    }
    cout << resultadoValidacion[Tam_K] << ") una posible cerradura podria ser:" << endl << "X(";
    for(unsigned int i = 0; i < c_Matrices-1; i++) {
        cout << X[i] << ", ";
    }
    cout << X[c_Matrices-1] << ")" << endl << "Esta cerradura tendria las siguientes rotaciones en su respectivo orden a X:" << endl <<"R(";;

    for(unsigned int i = 0; i < c_Matrices-1; i++) {
        cout << P[i] << ", ";
    }
    cout << P[c_Matrices-1] << ")" << endl;
    delete[] resultadoValidacion;
    liberar_memoria(M_Base, dimension);
    liberar_memoria(Matriz_B, nCambiante);

    return 0;
}
