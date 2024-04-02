#include <iostream>
#include "MODULOS.h"

using namespace std;

int** CrearM(unsigned int n) {
    int** M = new int*[n];
    for (unsigned int i = 0; i < n; ++i) {
        M[i] = new int[n];
    }

    unsigned int valor = 1;
    unsigned int inicio = 0;
    unsigned int limiteM = n;
    unsigned int CentroM = n / 2;

    while (inicio < n) {
        for (unsigned int j = 0; j < limiteM; ++j) {
            if (inicio == CentroM && j == CentroM) {
                M[inicio][j] = 0;
            } else {
                M[inicio][j] = valor++;
            }
        }
        ++inicio;
    }
    return M;
}

void liberar_memoria(int** matriz, unsigned int dimension){
    for(unsigned int i = 0; i < dimension; ++i) {
        delete[] matriz[i];
    }
    delete[] matriz;
}


bool comparar_arreglos(int** matriz1,int** matriz2, unsigned int fila, unsigned int columna, unsigned int fila_temp, unsigned int columna_temp, int condicion){
    bool confirmar = false;

    if(condicion == -1){
        if(matriz1[fila][columna] < matriz2[fila_temp][columna_temp]){
            confirmar = true;
        }
        else{
            confirmar = false;
        }
    }
    else if(condicion == 0){
        if(matriz1[fila][columna] == matriz2[fila_temp][columna_temp]){
            confirmar = true;
        }
        else{
            confirmar = false;
        }
    }
    else if(condicion == 1){
        if(matriz1[fila][columna] > matriz2[fila_temp][columna_temp]){
            confirmar = true;
        }
        else{
            confirmar = false;
        }
    }

    return confirmar;

}
