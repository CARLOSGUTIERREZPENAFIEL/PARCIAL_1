#include <iostream>
#include "MODULO1.h"

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
void cambiar_matriz(int**& matriz1,int** matriz2, unsigned int dimension){
    matriz1 = new int*[dimension];
    for(unsigned int i = 0; i< dimension; i++){
        matriz1[i] = new int[dimension];
    }
    for(unsigned int i = 0; i< dimension; i++){
        for(unsigned int j = 0; j< dimension; j++){
            matriz1[i][j] = matriz2[i][j];
        }
    }

}
void rotarM(int **matriz, unsigned int orden){
    int **puntero_copia;
    unsigned int nueva_posicion = orden;
    puntero_copia = new int*[orden];
    for(unsigned int i = 0; i< orden;i++){
        puntero_copia[i] = new int[orden];
    }
    for(unsigned int i = 0; i< orden; i++){
        for(unsigned int j = 0; j<orden; j++){
            puntero_copia[i][j] = matriz[i][j];
        }
    }
    for(unsigned int i = 0; i< orden;i++){
        for(unsigned int j = 0; j< orden; j++){
            matriz[nueva_posicion -1][i] = puntero_copia[i][j];
            nueva_posicion -= 1;
        }
        nueva_posicion = orden;
    }
    for(unsigned int i = 0; i<orden; i++){
        delete[] puntero_copia[i];
    }
    delete[] puntero_copia;

}


