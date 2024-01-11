#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
	fill_constant_matrix(&matA, 1.0);
	print_matrix(matA);
	printf("\n");

	matrix_t matB;
	matB.rows = 2;
	matB.cols = 2;
	matrix_alloc(&matB);
	fill_constant_matrix(&matB, -2.0);
	print_matrix(matB);
	printf("\n");

	matrix_t matC;
	matC.rows = matA.rows;
	matC.cols = matB.cols;
	matrix_alloc(&matC);
	fill_constant_matrix(&matC, 0.0);
	print_matrix(matC);
	printf("\n");

	bool success = matrix_multiply(matA, matB, &matC);
	if (!success) return -1;

	print_matrix(matC);

	matrix_free(&matA);
	matrix_free(&matB);
	matrix_free(&matC);

	return 0;
}
