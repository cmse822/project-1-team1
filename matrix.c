#include <stdlib.h>
#include "matrix.h"

void matrix_alloc(matrix_t *mat) {
	mat->data = malloc(mat->rows * sizeof(float *));
	for (int i = 0; i < mat->rows; i++) {
		mat->data[i] = malloc(mat->cols * sizeof(float));
	}
}

void matrix_free(matrix_t *mat) {
	for (int i = 0; i < mat->rows; i++) {
		free(mat->data[i]);
	}
	free(mat->data);
}
