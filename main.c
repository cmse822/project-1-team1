#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {
	matrix_t mat;
	mat.rows = 5;
	mat.cols = 5;

	matrix_alloc(&mat);

	for (int i = 0; i < mat.rows; i++) {
		for(int j = 0; j < mat.rows; j++) {
			mat.data[i][j] = 1.0;
		}
	}

	for (int i = 0; i < mat.rows; i++) {
		for(int j = 0; j < mat.rows; j++) {
			printf("%f ", mat.data[i][j]);
		}
		printf("\n");
	}

	matrix_free(&mat);

	return 0;
}
