#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "block_matrix.h"

void print_matrix(block_matrix_t mat) {
	for (int i = 0; i < mat.rows; i++) {
		for(int j = 0; j < mat.cols; j++) {
			printf("%f ", matrix_get(mat, i, j));
		}
		printf("\n");
	}
}

int main() {
	block_matrix_t matA;
	matA.rows = 3;
	matA.cols = 2;
	block_matrix_alloc(&matA);
	fill_constant_block_matrix(&matA, -3.9);

	block_matrix_t matB;
	matB.rows = matA.cols;
	matB.cols = 4;
	block_matrix_alloc(&matB);
	fill_constant_block_matrix(&matB, 1.4);

	block_matrix_t matC;
	matC.rows = matA.rows;
	matC.cols = matB.cols;
	block_matrix_alloc(&matC);
	fill_constant_block_matrix(&matC, 0.0);

	print_matrix(matC);

	block_matrix_multiply(matA, matB, &matC);

	print_matrix(matC);

	block_matrix_free(&matA);
	block_matrix_free(&matB);
	block_matrix_free(&matC);

	return 0;
}
