#include <iostream>
#include "MODULO2.h"

using namespace std;

int* validar(){
    int* regla, *temporal;
    unsigned int capacidad, Nelementos, dimension = 2;
    while (true) {
        regla = new int[2];
        for (unsigned short int i = 0; i < 2; i++) {
            if (i == 0) {
                cout << "Ingrese un valor para K, el cual sera la posicion fila: " << endl;
                cin >> regla[i];
            } else {
                cout << "Ingrese un valor para K, el cual sera la posicion columna: " << endl;
                cin >> regla[i];
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(10000, '\n');
                break;
            }
        }
        if (regla[0] >= 1 && regla[1] >= 1) {
            break;
        } else {
            cout << "Has ingresado datos invalidos. Debes ingresar algun NUMERO mayor o igual a 1." << endl;
            delete[] regla;
        }
    }
    while (true) {
        cout << "Ingresar un valor para K (-1, 0, 1), cuando quiera parar, ingrese '-2': " << endl;
        short int dato;
        cin >> dato;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "El valor ingresado no es valido. Intente nuevamente." << endl;
            continue;
        }

        if (dato == -1 || dato == 0 || dato == 1) {
            dimension += 1;
            temporal = new int[dimension];
            for (unsigned int i = 0; i < dimension - 1; i++) {
                temporal[i] = regla[i];
            }
            temporal[dimension - 1] = dato;
            delete[] regla;
            regla = new int[dimension];
            for (unsigned int i = 0; i < dimension; i++) {
                regla[i] = temporal[i];
            }
            delete[] temporal;

        }
        else if(dato==-2){
            break;
        }
        else {
            cout << "El valor ingresado no es valido. Intente nuevamente." << endl;
        }
    }
    temporal = new int[dimension+1];
    temporal[0] = dimension;
    for(unsigned int i = 1; i<= dimension; i++){
        temporal[i] = regla[i-1];
    }
    delete[] regla;
    return temporal;
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
