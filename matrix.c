#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"


/*

    IMPLEMENTA AS FUNÇÕES DESCRITAS EM "MATRIX.H"

*/

double** createMatrix(int size) {

    double** matrix;
    int i;

    matrix = calloc(size, sizeof(double*));
    for( i = 0; i < size; i++) {
        matrix[i] = calloc(size, sizeof(double));
    }
    return matrix;
}

void swapZeroLine(double** matrix, int size){

    int i, j, k;
    int total;

    for(i = 0; i < size; i++) {
        total = 0;
        for( j = 0; j < size; j++) {
        if(matrix[i][j] == 0){
            total++;
            }
        }
        if(total == size){
            for (k = 0; k < size; k++) {
                matrix[i][k] = 1;
            }
        }
    }
}

void getStochasticMatrix(double** matrix, int size){

    double total;
    int i,j;

    for(i = 0; i < size; i++) {
        total = 0;
        for( j = 0; j < size; j++) {
            if(matrix[i][j] == 1){
                total++;
            }
        }
        for(j = 0; j < size; j++) {
            if(matrix[i][j] == 1){
             matrix[i][j] = 1/total;
            }
        }
    }
}

void dampingFactor(double** matrix, double df, int size){

    int i, j;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            matrix[i][j] = (( 1 - df) * matrix[i][j]) + (df * 1/(size));
        }
    }
}

void pow2Matrix(double** matrix, double** matrix_aux, double** matrix_answ, int size){

    int c, d, k;
    double sum = 0;

    for (c = 0; c < size; c++) {
      for (d = 0; d < size; d++) {
        for (k = 0; k < size; k++) {
          sum += matrix[c][k] * matrix_aux[k][d];
        }
        matrix_answ[c][d] = sum;
        sum = 0;
      }
    }
}

double norm(double **matrix,int size){

  int i, j;
  double sum = 0;

  for(i = 0; i < size; i++){
       for(j = 0; j < size; j++){
            sum += matrix[i][j] * matrix[i][j];
       }
  }
  return sum;
}
