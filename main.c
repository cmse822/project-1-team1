#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void print_matrix(matrix_t mat) {
	for (int i = 0; i < mat.rows; i++) {
		for(int j = 0; j < mat.cols; j++) {
			printf("%f ", mat.data[i][j]);
		}
		printf("\n");
	}
}

int main() {
	matrix_t matA;
	matA.rows = 5;
	matA.cols = 3;
	matrix_alloc(&matA);
	print_matrix(matA);
	fill_constant_matrix(&matA, 1.0);
	print_matrix(matA);
	printf("\n");

	matrix_t matB;
	matB.rows = 3;
	matB.cols = 2;
	matrix_alloc(&matB);
	print_matrix(matB);
	fill_constant_matrix(&matB, -2.0);
	print_matrix(matB);
	printf("\n");

	matrix_t matC;
	matC.rows = 5;
	matC.cols = 2;
	matrix_alloc(&matC);
	print_matrix(matC);
	fill_constant_matrix(&matC, 0.0);
	print_matrix(matC);
	printf("\n");

	matrix_multiply(matA, matB, &matC);

	print_matrix(matC);

	matrix_free(&matA);
	matrix_free(&matB);
	matrix_free(&matC);

	return 0;
}
