#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"

int main() {

    double** matrix;
    double** matrix_aux;
    double** matrix_answ;
    double** matrix_nrm;
    int size = 0, i, j, c, n = 0;
    double df, nrm = 1;

    scanf("%d %lf", &size, &df);

    matrix = createMatrix(size);
    matrix_aux = createMatrix(size);
    matrix_answ = createMatrix(size);
    matrix_nrm = createMatrix(size);

	while(scanf("%d %d", &i, &j) != -1){
		matrix[i][j] = 1;
	}

    //funções sequenciais
    swapZeroLine(matrix, size);
    getStochasticMatrix(matrix, size);
    dampingFactor(matrix, df, size);

    pow2Matrix(matrix, matrix, matrix_answ, size);
    for(c = 0; c < size; c++){
        for(j = 0; j < size; j++){
            matrix_aux[c][j] = matrix_answ[c][j];
        }
    }

    n = 2;
    while(n < 2000 && nrm > 0.00000000001) {
        //multiplica as matrizes
        pow2Matrix(matrix, matrix_aux, matrix_answ, size);
        for(c = 0; c < size; c++){
            for(j = 0; j < size; j++){
                matrix_nrm[c][j] = matrix_answ[c][j] - matrix_aux[c][j];
                matrix_aux[c][j] = matrix_answ[c][j];
            }
        }
        //calcula a norma da matriz
        nrm = norm(matrix_nrm, size);
        n++;
    }

    //stdout no que foi solicitado
    for( j = 0; j < size; j++) {
        printf("%d %.4lf\n", j, matrix_answ[1][j]);
    }

    //limpa os espaços alocados
    free(matrix);
    free(matrix_answ);
    free(matrix_aux);
    return 0;
}
