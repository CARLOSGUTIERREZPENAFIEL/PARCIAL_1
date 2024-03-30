#include <iostream>
#include <stdlib.h>
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
int* validar_Regla(){
    int *regla, Ncerraduras,temporal;
    bool confirmar = true;
    cout<<"cuantas estructuras desea tener para su cerradura? "<<endl;
    cin>>Ncerraduras;
    while(confirmar){
        regla = new int[Ncerraduras+2];
        for(int i = 0; i<2; i++){
            if(i == 0){
                cout<<"Ingresar el numero de fila: "<<endl;
                cin>>regla[i];
            }
            else{
                cout<<"Ingrese el numero de columna: "<<endl;
                cin>>regla[i];
            }
        }
        if(regla[0] >2 || regla[1]>2){
            confirmar = false;
        }
        else{
            cout<<"has ingresado datos invalidos, debes ingresar algun dato mayor o igual a 3"<<endl;
            delete[] regla;
        }
    }
    cout<<"A continuacion ingresar las condiciones para la comparacion (-1,0,1) :"<<endl;
    for(int i = 2; i<Ncerraduras+1; i++){
        cout<<"ingresar una condicion: "<<endl;
        cin>>temporal;
        while(temporal != -1 && temporal != 0 && temporal != 1){
            cout<<"ingresar una condicion valida (-1,0,1)"<<endl;
            cin>> temporal;
        }
        regla[i]= temporal;
    }
    for(int i = 0; i < Ncerraduras+1; i++){
        cout<<regla[i]<<endl;
    }
    return regla;

}
