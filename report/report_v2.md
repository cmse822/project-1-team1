# <p style="text-align: center;"> CMSE 822 &nbsp;&nbsp;&nbsp; SS24
## <p style="text-align: center;">  Project 1  Memory Hierarchies and Performance of Serial Applications

<p style="text-align: right; font-size: 18px;">  &#9786; Team 1  </p>
<p style="text-align: right; font-size: 18px;">  Benjamin DalFavero, Reza Khan Mohammadi, Tairan Song, Xiaotian Hua, Ziyu Cheng</p>  



# Warm-up

| | Operations (FLOPs) | Memory access (byte) | Algorithmic intensity (FLOPs/byte) |
| --- | --- | --- | --- |
|   Y[j] += Y[j] + A[j][i] * B[i] | 3 | 32 | 0.094 | 
|     s += A[i] * A[i]            | 2 | 8  | 0.250 | 
|     s += A[i] * B[i]            | 2 | 16 | 0.125 | 
|     Y[i] = A[i] + C*B[i]        | 2 | 24 | 0.167 |   
|


# Part 1: Matrix-matrix Multiplication

### Q2. For a given matrix size N, what is the total number of floating point operations performed by this operator?  

In a N*N matrix, the total number of floating point operations performed by matrix multiplication is $N^3+N^2(N-1)=N^2(2N-1)$ .   


### Q3. Compute the performance in Mflop/s of the matrix-matrix multiply for N=100.
Considering a matrix of size `100`, we repeated calculation for `20` times, the performance achieved is:
- *Performance:* 575.928 Mflops/s
- *Average time:* 0.003455 s
- *Floating-point operations:*  $100^2*(2*100-1) / 10^3 = 1.99$ Mflops

### Q4. How does the performance you measured in (3) compare to the theoretical peak performance of your system?
The laptop is Apple M2 pro chips:
- *CPU:* 12 cores
- *Clock speed:* 3.4 GHz
- *Cache:* 192 KB instruction cache, 128 KB data cache

Assuming one flop per clock cycle, the peak performance is: $12 \cdot 3.4 \cdot 1 = 40.8$ Gflop/s.

The performance in (3) is _0.575 Gflop/s_ , which is significantly lower than the peak performance calculated above _40.8 Gflop/s_.

### Q5. Make a plot of the resulting measured Gflop/s vs. N.
- **Computing Node 1: _dev-intel18_**
- *CPU:* two 2.4 GHz 20-core Intel Xeon Gold 6148 CPUs (40 cores)
- Under the assumption of one flop per clock cycle, the theoretical peak performance is calculated as: $\rm 1\ flop \cdot 2.4\ GHz \cdot 40\ cores = 96\ Gflop/s$.   

The performance graph, illustrating Gflops/s vs N, is :   
(insert plot here)    


- **Computing Node 2: _dev-amd20_**
- *CPU:* one 2.6 GHz AMD EPYC 7H12 64-Core CPU
- Assuming that only one floating-point operation is performed in each clock cycle, and we are using a single core for computation, the theoretical peak performance of each core is: $\rm 1\ flop \cdot 2.6\ GHz \cdot 1\ cores = 2.6\ Gflop/s$.

The performance graph, illustrating Gflops/s vs N, is :   

![替代文本](/report/amd20.png)


### Q6. How does the measured performance for multiple N’s compare to peak? Are there any “features” in the plot? Explain them in the context of the hardware architecture of your system. Include in your write-up a description of your system’s architecture (processor, cache, etc.)
(hint: Pay particular attention to the comparison between different architectures and give explanations for them.)  

|           |**intel18**      |**amd20**|
|---        |---              |---            |
|clock speed|2.4 GHz          |2.6 GHz        |
|cache size |                 |               |
|peak performance|96 Gflop/s  |166.4 Gflop/s  |
|  




---
# Part 2: The Roofline Model 

### Q3. Run Empirical Roofline Tool(ERT) in serial mode.
    |             | peak performance | bandwidths|
    |---          |---               |---            |
    |cache level 1|                  |               |
    |cache level 2|                  |               |
    |cache level 3|                  |               |
    |DRAM         |                  |               |
    |

    The 'ridge point' of the roofline for case ...... lies at ......  


### Q4. (Descriptions of the four floating point (FP) kernels can be found in Table2 in the paper.)  
On the platforms we are testing, the performance of the four FP kermel will be...   
(need plots)

    |kernel |performance   |decription   | 
    |---    |---           |---  |
    |SpMV   |              |Sparse Matrix-Vector multiply: y = A*x where A is a sparse matrix and x, y are dense vectors; multiplies and adds equal.|
    |LBMHD  |              |Lattice-Boltzmann Magnetohydro- dynamics is a structured grid code with a series of time steps.|
    |Stencil|              |A multigrid kernel that updates 7 nearby points in a 3-D stencil for a 2563 problem.|
    |3-D FFT|              |Three-Dimensional Fast Fourier Transform (2 sizes: 1283 and 5123). |


### Q5. On the platforms we are testing, the performance of the four kermels given in the Warm-up will be...    
(need plots)


    |kernel                        |performance| 
    |---                            |---  |
    |`Y[j] += Y[j] + A[j][i] * B[i]`|     |
    |`s += A[i] * A[i]`             |     |
    |`s += A[i] * B[i]`             |     |
    |`Y[i] = A[i] + C*B[i]`         |     |
    |

### Q6. Compare results for the roofline model to what we obtained for the matrix-matrix multiplication operation from Part 1.  
The relationship between the rooflines of memory badwidth and the features in the algorithmic performance as a function of matrix size is ......
