#ifndef MODULOS_H
#define MODULOS_H
void liberar_memoria(int** matriz,unsigned int dimension);
int* validar();
bool verificar_condicion(int** matriz_base,unsigned int orden,unsigned int numero_comprobar);
bool comparar_arreglos(int** matriz1,int** matriz2, unsigned int fila, unsigned int columna, unsigned int fila_temp, unsigned int columna_temp, int condicion);
#endif // MODULOS_H
