// Header for matrix data type and functions.

/* Matrix is stored as a pointer to a pointer to a float.
 * We will store the array such that A[i][j] is the element
 * at row i and column j.
 */
typedef struct matrix_s {
	size_t rows;
	size_t cols;
	float **data;
} matrix_t;

void matrix_alloc(matrix_t *mat);

void matrix_free(matrix_t *mat);

// Fill a matrix with random entries between 0 and 1.
//void fill_random_matrix(matrix *mat);

// Executes C = A * B.
//void matrix_multiply(matrix a, matrix b, matrix *c);
