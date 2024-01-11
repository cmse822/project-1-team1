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
