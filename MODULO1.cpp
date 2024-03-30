#include <iostream>

using namespace std;

int** CrearM(unsigned int n) {
    int** M = new int*[n];
    for (unsigned int i = 0; i < n; ++i) {
        M[i] = new int[n];
    }

    int valor = 1;
    int inicio = 0;
    int limiteM = n;
    int CentroM = n / 2;

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
