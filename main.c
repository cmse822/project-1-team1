#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "block_matrix.h"
#include "get_walltime.h"

void print_matrix(block_matrix_t mat) {
	for (int i = 0; i < mat.rows; i++) {
		for(int j = 0; j < mat.cols; j++) {
			printf("%f ", matrix_get(mat, i, j));
		}
		printf("\n");
	}
}

int main() {

	const int repeat = 10;

	double start_time, end_time;
	
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

	get_walltime(&start_time);

	for (int i = 0; i < repeat; i++) {
		block_matrix_multiply(matA, matB, &matC);
	}

	get_walltime(&end_time);

	print_matrix(matC);

	block_matrix_free(&matA);
	block_matrix_free(&matB);
	block_matrix_free(&matC);

	double total_time = (end_time - start_time) / repeat;
	double Mflop = (matA.rows * matB.cols * matA.cols +
                        matA.rows * matB.cols * (matA.cols - 1)) / 1000000.0;
	double performance = Mflop / total_time;

	printf("running time: %f s\n", total_time);
	printf("FLOPS: %f MFLOPS\n", Mflop);
	printf("performance: %f Mflop/s\n", performance);

	return 0;
}
