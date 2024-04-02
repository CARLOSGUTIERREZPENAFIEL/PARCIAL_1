#include <iostream>
#include "MODULOS.h"

using namespace std;


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



int* validar(){
    int* regla, *temporal;
    unsigned int capacidad, Nelementos;
    int dato, dimension = 2;
    char continuar = 'y';
    bool confirmar =  true;
    while(confirmar){
        regla = new int[2];
        for(unsigned int i = 0; i<2; i++){
            if(i == 0){
                cout<<"Ingresar un valor para K: "<<endl;
                cin>>regla[i];
            }
            else{
                cout<<"Ingrese un valor para K: "<<endl;
                cin>>regla[i];
            }
        }
        if((regla[0] >=3 || regla[1]>=3) && (regla[0]>0 && regla[1]>0)){
            confirmar = false;
        }
        else{
            cout<<"has ingresado datos invalidos, debes ingresar algun dato mayor o igual a 3"<<endl;
            delete[] regla;
        }
    }
    while(continuar == 'y' || continuar == 'Y'){
        cout<<"ingresar un valor para K (-1,0,1): "<<endl;
        cin>>dato;
        if(dato == -1 || dato == 0 || dato == 1){
            dimension += 1;
            temporal = new int[dimension];
            for(unsigned int i = 0; i < dimension-1; i++){
                temporal[i] = regla[i];
            }
            temporal[dimension-1] = dato;
            delete[] regla;
            regla = new int[dimension];
            for(unsigned int i = 0; i< dimension; i++ ){
                regla[i]= temporal[i];
            }
            delete[] temporal;
            cout<<"quiere ingresar otro valor para k? \n y/n: "<<endl;
            cin>> continuar;
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
