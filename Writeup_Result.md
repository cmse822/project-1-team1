# <p style="text-align: center;"> CMSE 822 &nbsp;&nbsp;&nbsp; SS24
## <p style="text-align: center;">  Project 1  Memory Hierarchies and Performance of Serial Applications

<p style="text-align: right; font-size: 18px;">  &#9786; Team 1  </p>
<p style="text-align: right; font-size: 18px;">  Benjamin DalFavero, Reza Khan Mohammadi, Tairan Song, Xiaotian Hua, Ziyu Cheng</p>  

### Warm-up

Compute the arithmetic intensities of the following kernels in units of FLOPs/byte, assuming 8 bytes per float. Included a table in your project report listing the arithmetic intensities for these kernels.

|kernel                             | arithmetic intensities  | 
|---                                |---                |
|`Y[j] += Y[j] + A[j][i] * B[i]`    |3/(4*8) = 3/32     |     
|`s += A[i] * A[i]`                 |2/(1*8)=1/4        |
|`s += A[i] * B[i]`                 |2/(2*8)=1/8        |
|`Y[i] = A[i] + C*B[i]`             |2/(3*8)=1/12       |



### Part 1: Matrix-matrix Multiplication

1. Code for matrix multiplication.  

2. For a given matrix size _N_, the total number of floating point operations performed by matrix multiplication is _N^2(2N-1)_.  

3. Performance in Mflop/s for _N_=100 is ......  

4.  Hardware system's architecture
    |           | system 1(name)  | system 2(name)|
    |---        |---              |---            |
    |clock speed|                |               |
    |cache size |                 |               |
    |peak performance|            |               |
    |


    Compared to the theoretical peak performance, the performance we measured in (3) ...

5. Run experiments on matrices whose size _N_ ranges from 1 to 10,000,000.   
Plot to show Gflop/s vs. _N_, with a horizontal line representing the theoritical peak performance.    
......



6. The hardware architecture is ......  
Compared to the theoretical peak performance, the performance we measured in (5) ...  
Features in our plot......    
(hint: Pay particular attention to the comparison between different architectures and give explanations for them.)  


## Part 2: The Roofline Model 

3. Run Empirical Roofline Tool(ERT) in serial mode.
    |             | peak performance | bandwidths|
    |---          |---               |---            |
    |cache level 1|                  |               |
    |cache level 2|                  |               |
    |cache level 3|                  |               |
    |DRAM         |                  |               |
    |

    The 'ridge point' of the roofline for case ...... lies at ......  


4. (Descriptions of the four floating point (FP) kernels can be found in Table2 in the paper.)  
On the platforms we are testing, the performance of the four FP kermel will be...   
(need plots)

    |kernel |performance   |decription   | 
    |---    |---           |---  |
    |SpMV   |              |Sparse Matrix-Vector multiply: y = A*x where A is a sparse matrix and x, y are dense vectors; multiplies and adds equal.|
    |LBMHD  |              |Lattice-Boltzmann Magnetohydro- dynamics is a structured grid code with a series of time steps.|
    |Stencil|              |A multigrid kernel that updates 7 nearby points in a 3-D stencil for a 2563 problem.|
    |3-D FFT|              |Three-Dimensional Fast Fourier Transform (2 sizes: 1283 and 5123). |


5. On the platforms we are testing, the performance of the four kermels given in the Warm-up will be...    
(need plots)


    |kernel                        |performance| 
    |---                            |---  |
    |`Y[j] += Y[j] + A[j][i] * B[i]`|     |
    |`s += A[i] * A[i]`             |     |
    |`s += A[i] * B[i]`             |     |
    |`Y[i] = A[i] + C*B[i]`         |     |
    |

6. Compare results for the roofline model to what we obtained for the matrix-matrix multiplication operation from Part 1.  
The relationship between the rooflines of memory badwidth and the features in the algorithmic performance as a function of matrix size is ......

