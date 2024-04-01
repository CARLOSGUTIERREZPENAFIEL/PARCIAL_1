#ifndef MODULOS_H
#define MODULOS_H
void liberar_memoria(int** matriz,unsigned int dimension);
void rotarM(int **matriz, unsigned int orden);
void cambiar_matriz(int** matriz1,int** matriz2, unsigned int dimension);
int* validar();
int** CrearM(unsigned int n);
bool comparar_arreglos(int** matriz1,int** matriz2, unsigned int fila, unsigned int columna, unsigned int fila_temp, unsigned int columna_temp, int condicion);
#endif // MODULOS_H
