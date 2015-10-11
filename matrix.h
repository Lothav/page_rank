#ifndef MATRIX_H  /* Include guard */
#define MATRIX_H

//Aloca espaço na memória para uma matrix e retorna a referência desse espaço alocado.
double** createMatrix(int size);

//Troca a linha de todos os elementos iguais a zero para 1;
void swapZeroLine(double** matrix, int size);

//Gera a matriz estocástica.
void getStochasticMatrix(double** matrix, int size);

//Gera a matriz a partir do Damping Factor.
void dampingFactor(double** matrix, double df, int size);

//Faz multiplicação de matriz. Sendo que:
//1 Parametro: primeira matriz a ser mult.
//2 Parametro: segunda matriz a ser mult.
//3 Paramentro: matriz que irá receber o resultado (por referencia).
void pow2Matrix(double** matrix, double** matrix_aux, double** matrix_answ, int size);

//Calcula a norma da matriz.
double norm(double **matrix,int size);
#endif
