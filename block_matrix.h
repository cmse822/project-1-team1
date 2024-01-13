// Get the i, j element of a matrix mat.
#define matrix_get(mat, i, j) (mat.data[i * mat.cols + j])
#define matrix_set(mat_ptr, i, j, value) mat_ptr->data[i * mat_ptr->cols + j] = value

/* The matrix is stored as a single block
 * in memory. It is stored such that all of the values
 * for row 1 come first, then all of the values for row2, etc.
 */
typedef struct matrix_s {
	size_t rows;
	size_t cols;
	float *data;
} block_matrix_t;

void block_matrix_alloc(block_matrix_t *mat);

void block_matrix_free(block_matrix_t *mat);

void fill_constant_block_matrix(block_matrix_t *mat, float value);

void block_matrix_multiply(block_matrix_t a, block_matrix_t b, block_matrix_t *c);
