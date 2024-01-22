# warm-up answer
| | Operations (FLOPs) | Memory access (byte) | Algorithmic intensity (FLOPs/byte) |
| --- | --- | --- | --- |
|   Y[j] += Y[j] + A[j][i] * B[i] | 4 | 32 | 0.125 | 
|     s += A[i] * A[i]            | 2 | 8  | 0.25  | 
|     s += A[i] * B[i]            | 2 | 16 | 0.125 | 
|     Y[i] = A[i] + C*B[i]        | 2 | 24 | 0.167 | 

# Part 1: Matrix-matrix Multiplication
## 2. For a given matrix size N, what is the total number of floating point operations performed by this operator?
In a N*N matrix, the total number of floating-point operations can be represented as follows:
$N^3+N^2(N-1)=2N^3-N^2$

## 3. Compute the performance in Mflop/s of the matrix-matrix multiply for N=100.
Considering a matrix of size `100`, when repeated `20` times, the performance achieved is:
- **Performance:** 575.928 Mflops/s
- **Average time:** 0.003455 s
- **Floating-point operations:** 1.99 Mflop

## 4. How does the performance you measured in (3) compare to the theoretical peak performance of your system?
My laptop is Apple M2 pro chips:
- **CPU:** 12 cores
- **Clock speed:** 3.4 GHz
- **Cache:** 192 KB instruction cache, 128 KB data cache

Assuming 1 FLOP per clock cycle, the peak performance is: $12 \cdot 3.4 \cdot 1 = 40.8\ \rm {GFLOP/s}$

The performance in (3) is significantly lower than the peak performance calculated above.

## 5. Make a plot of the resulting measured Gflop/s vs. N.
- **computing node:** dev-intel18
- **CPU:** two 2.4 GHz 20-core Intel Xeon Gold 6148 CPUs (40 cores)

Under the assumption of 1 FLOP per clock cycle, the theoretical peak performance is calculated as: $\rm 1\ FLOP \cdot 2.4\ GHz \cdot 40\ cores = 96\ GFLOPS$.

The performance graph, illustrating Gflops/s vs N, is presented:

- **computing node:** dev-amd20
- **CPU:** one 2.6 GHz AMD EPYC 7H12 64-Core CPU

Under the assumption of 1 FLOP per clock cycle, the theoretical peak performance is: $\rm 1\ FLOP \cdot 2.6\ GHz \cdot 64\ cores = 166.4\ GFLOPS$.

The graph displaying Gflops/s vs N is shown:
