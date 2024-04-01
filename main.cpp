#include <iostream>
#include "MODULOS.h"
using namespace std;

int main()
{
    unsigned int dimensionM1, dimension_temporal1,dimension_temporal2, fila, columna,fila_temp,columna_temp;
    int *matriz,matriz_comparar1,*matriz_comparar2, *regla,*cerradura, Ncondicion = 0, longitud_regla, numero,condicion_abrir, rotar = 3, numero_cerradura = 1;
    bool confirmar = false;
    regla = validar();
    longitud_regla = regla[0];
    cerradura = new int[longitud_regla];
    fila = regla[1] ;
    fila_temp = regla[1] ;
    columna_temp = regla[2];
    columna = regla[2];
    cout<<"longitud de regla: "<<longitud_regla<<endl;
    cout<<"fila: "<<fila<<endl;
    cout<<"colum: "<<columna<<endl;

    if(fila > columna){
        if(fila%2 !=0){
            dimensionM1 = fila;
            dimension_temporal1 = fila;
            dimension_temporal2 = fila;
        }
        else {
            dimensionM1 = fila + 1;
            dimension_temporal1 = fila + 1;
            dimension_temporal2 = fila + 1;
        }
    }

    else if(columna > fila){
        if(columna%2 != 0){
            dimensionM1 = columna;
            dimension_temporal1 = columna;
            dimension_temporal2 = columna;
        }
        else {
            dimensionM1 = columna + 1;
            dimension_temporal1 = columna + 1;
            dimension_temporal2 = columna +1;
        }
    }
    matriz = CrearM(dimensionM1);
    cerradura[0] = dimensionM1;
    matriz_comparar1 = CrearM(dimension_temporal1);
    matriz_comparar2 = CrearM(dimension_temporal2);

    for(unsigned int i = 3; i<longitud_regla; i++){
        while(confirmar == false){
            rotar = 3;
            condicion_abrir = regla[i];
            confirmar = comparar_arreglos(matriz_comparar1,matriz_comparar2, fila -1, columna -1, fila_temp -1, columna_temp-1 ,condicion_abrir);
            if(confirmar == false){
                while(rotar >0){
                    rotarM(matriz_comparar2, dimension_temporal2);
                    confirmar = comparar_arreglos(matriz_comparar1,matriz_comparar2, fila-1, columna-1, fila_temp-1, columna_temp-1, condicion_abrir);
                    if(confirmar == true){
                        cout<<"hola"<<endl;
                        rotar = -3;
                        cerradura[numero_cerradura] = dimension_temporal2;
                        liberar_memoria(matriz_comparar1,dimension_temporal1);
                        cambiar_matriz(matriz_comparar1,matriz_comparar2,dimension_temporal2);
                        liberar_memoria(matriz_comparar2,dimension_temporal2);
                        dimension_temporal1 = dimension_temporal2;
                        dimension_temporal2 = dimensionM1;
                        matriz_comparar2 = CrearM(dimension_temporal2);
                        numero_cerradura += 1;
                    }
                    else{
                        cout<<"hola4"<<endl;
                        rotar = rotar - 1;
                        cout<<"rotarrrrrrr "<<rotar<<endl;
                    }

                }
                if(rotar  == 0){
                    cout<<"hola3"<<endl;
                    liberar_memoria(matriz_comparar2,dimension_temporal2);
                    fila = fila_temp;
                    columna = columna_temp;
                    dimension_temporal2 += 2;
                    matriz_comparar2 = CrearM(dimension_temporal2);
                    fila_temp += 1;
                    columna_temp += 1;
                }


            }
            else{
                cout<<"hola2"<<endl;
                cerradura[numero_cerradura] =  dimension_temporal2;
                liberar_memoria(matriz_comparar1,dimension_temporal1);
                cambiar_matriz(matriz_comparar1,matriz_comparar2,dimension_temporal2);
                liberar_memoria(matriz_comparar2,dimension_temporal2);
                dimension_temporal1 = dimension_temporal2;
                dimension_temporal2 = dimensionM1;
                matriz_comparar2 = CrearM(dimension_temporal2);
                fila = fila_temp;
                columna = columna_temp;
                fila_temp = regla[1];
                columna_temp = regla[2];
                numero_cerradura += 1;
                cout<<"pruebaaaaaaa"<<endl;
            }



        }
        confirmar = false;
    }

    liberar_memoria(matriz,dimensionM1);
    liberar_memoria(matriz_comparar1,dimension_temporal1);
    liberar_memoria(matriz_comparar2,dimension_temporal2);
    for(unsigned int i = 0; i<longitud_regla -1; i++){
        cout<<cerradura[i]<<",";
    }
    delete[] cerradura;

    delete[] regla;





    return 0
}
