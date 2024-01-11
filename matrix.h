// Header for matrix data type and functions.

typedef struct matrix_s {
	size_t rows,
	size_t cols,
	float **data
} matrix_t;
