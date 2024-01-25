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
#### Computing Node 1: _dev-intel18_
- *CPU:* two 2.4 GHz 20-core Intel Xeon Gold 6148 CPUs (40 cores)
- Under the assumption of one flop per clock cycle, the theoretical peak performance is calculated as: $\rm 1\ flop \cdot 2.4\ GHz \cdot 40\ cores = 96\ Gflop/s$.    
- L1d cache: 32    KB  
- L1i cache: 32    KB  
- L2  cache: 1024  KB
- L3  cache: 28160 KB  

#### Computing Node 2: _dev-amd20_
- *CPU:* one 2.6 GHz AMD EPYC 7H12 64-Core CPU
- Under the assumption of one flop per clock cycle, the theoretical peak performance is: $\rm 1\ flop \cdot 2.6\ GHz \cdot 64\ cores = 166.4\ Gflop/s$.  
- L1d cache: 32    KB  
- L1i cache: 32    KB  
- L2  cache: 512   KB
- L3  cache: 16384 KB  

**NOTE**: For matrix size N, when we do matrix multiplication A=B*C, the memory space needed will be  
 (for easier approximation, use 10^3 instead of 1024 here)    
N = 1000, 1000^2 floating number * 8 byte * 3 matrices / 10^6 = 24  MB;  
N = 3000, 3000^2 floating number * 8 byte * 3 matrices / 10^6 = 216 MB;   
N = 4000, 4000^2 floating number * 8 byte * 3 matrices / 10^6 = 384 MB.  

Since 384 MB is beyond L3 cache, the system will go to use RAM when the matrix size reaches 2000~3000, which makes the performance become low and takes quite a long time to finish the computing.     
We run matrix size from 1 to 3000, and the performance graphs, illustrating performance (Gflops/s) vs matrix size (N), are shown below:   
#### Intel18

<img src="/report/intel18_3000.png" alt="Alt Text" width="900"/>

<img src="/report/intel18_3000_log.png" alt="Alt Text" width="900"/>


#### Amd20
![amd20](/report/amd20.png)

If we add the theoretical peak level for a single core, it would be:
![amd20-1](/report/amd20-1.jpg)


### Q6. How does the measured performance for multiple N’s compare to peak? Are there any “features” in the plot? Explain them in the context of the hardware architecture of your system. Include in your write-up a description of your system’s architecture (processor, cache, etc.)
(hint: Pay particular attention to the comparison between different architectures and give explanations for them.)  

#### Amd20
The initial velocity of the graph line will rise rapidly, but then it will decrease in a stepwise manner. The boundaries of these stepwise decreases may correspond to the capacities of the L1, L2, and L3 caches.

We use this formula to calculate the matrix size (N) corresponding to cache capacity (KB): $ \rm Cache\ size = 24 \cdot N^2 / 1024 $

Based on the cache data provided above, we can calculate the matrix size corresponding to each cache:
| cache      |     N       |
|---         |---          |
|L1          |52           |
|L2          |157          |
|L3          |851          |
|L3 (data from AMD)          |3308          |

However, there are some discrepancies with the calculated results. While the boundaries of L1 and L2 can be explained by hardware or algorithm strategies, the drop boundary of L3 seems to be much larger than the predicted N value. I don't know the reason for this at the moment, but I noticed that the L3 cache data on the official AMD EPYC 7H12 CPU website (https://www.amd.com/en/products/cpu/amd-epyc-7h12) is slightly larger than the data output by lscpu. The official data is 256MB, which might align more closely with the calculated data.



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
