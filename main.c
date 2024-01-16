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

int main(void) {

    const int repeat = 20; // Repeat the calculation to obtain the average flops/s
    const int N_max = 9; // Matrix size, required to be 1 to 10 million
    
    double start_time, end_time;
    double total_time[N_max];
    double Gflop[N_max];
    double performance[N_max];
    
    // Output N and performance arrays for plotting
    FILE *data;

    data = fopen("performance_data.txt", "w"); // The storage path for the output document has not been set yet
    if (data == NULL) {
        perror("Error in opening file");
        return -1;
    }
    
    for (int N = 1; N <= N_max; N++) {
        
        block_matrix_t matA;
        matA.rows = N;
        matA.cols = N;
        block_matrix_alloc(&matA);
        fill_constant_block_matrix(&matA, -3.9);
        
        block_matrix_t matB;
        matB.rows = N;
        matB.cols = N;
        block_matrix_alloc(&matB);
        fill_constant_block_matrix(&matB, 1.4);
        
        block_matrix_t matC;
        matC.rows = N;
        matC.cols = N;
        block_matrix_alloc(&matC);
        fill_constant_block_matrix(&matC, 0.0);
        
        // Measure computation time
        get_walltime(&start_time);
        
        for (int i = 0; i < repeat; i++) {
            block_matrix_multiply(matA, matB, &matC);
        }
        
        get_walltime(&end_time);
        
        //print_matrix(matC);
        
        block_matrix_free(&matA);
        block_matrix_free(&matB);
        block_matrix_free(&matC);
        
        // Performance calculation, GFLOPS/s
        total_time[N-1] = (end_time - start_time) / repeat;
        Gflop[N-1] = (matA.rows * matB.cols * matA.cols +
                      matA.rows * matB.cols * (matA.cols - 1)) / 1000000000.0;
        performance[N-1] = Gflop[N-1] / total_time[N-1];
        
        printf("%f\n", performance[N-1]);
        fprintf(data, "%d\t%f\n", N, performance[N-1]);
    }

    fclose(data);
    printf("Data saved to 'performance_data.txt'\n");
    
    return 0;
}

