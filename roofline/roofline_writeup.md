# Roofline writeup

1. ![AMD Roofline](./roofline_amd.jpg)
   ![Intel Roofline](./roofline_intel.jpg)
   Approximately...
   - For AMD:
     - Ridge point is 13.6 GFLOPs/s at an operational intensity of about 0.19 FLOPs/byte for L1.
     - Ridge point is 13.6 GFLOPs/s at an operational intensity of about 1.2 FLOPs/byte for DRAM.
   - For Intel:
     - Ridge point is 10.1 GFLOPs/s at an operational intensity of about 0.22 FLOPs/byte for L1.
     - Ridge point is 10.1 GFLOPs/s at an operational intensity of about 0.31 FLOPs/byte for L2.
     - Ridge point is 10.1 GFLOPs/s at an operational intensity of about 0.5 FLOPs/byte for DRAM.

3. Below are the results predicted for the kernels in the Roofline paper.

**AMD**
   
| Kernel    | Operational intensity (FLOPs/byte) | L1 | L1 performance (GFLOP/s) | DRAM | DRAM performance (GFLOP/s) |
| --------- | --------------------------------- | --- | ------------------------ | ---- | -------------------------- |
| SpMV      | 0.25                            | Comp | 13.6 |  Mem | 3.0 |
| LBMHD     | 1.07                            | Comp | 13.6 | Mem | 12.9 |
| Stencil   | 0.50                            | Comp | 13.6 | Mem | 9.0 | 
| 3-D FF    | 1.64                            | Comp | 13.6 | Comp | 13.6 |

For the `SpMV` kernel, performance is compute bound for the L1 cache, and memory bound for the DRAM cache. Storage of the amtrix should
be optimized so that all of the matrix elements that are needed for the next steps of the computation are stored in L1 cache. Additionally,
SIMD instructions can be used to great advantage due to the structure of matrix-vector multiplication. For `LBMHD`, the paper remarks that 
the no-allocate store optimization yields maximal operations intensity. This is the same operational intensity as is need to reach the ridge point
for both L1 cache and DRAM on the AMD 20. 

**Intel**

| Kernel    | Operational intensity (FLOPs/byte) | L1 | L2 | DRAM |
| --------- | --------------------------------- | --- | --- | --- |
| SpMV      | 0.25                            | Comp | Mem | Mem |
| LBMHD     | 1.07                            | Comp | Comp | Comp |
| Stencil   | 0.50                            | Comp | Comp | Comp |
| 3-D FF    | 1.64                            | Comp | Comp | Comp |

For the `SpMV` kernel, performance is compute bound for the L1 cache, and memory bound for the L2 cache and DRAM. Storage of the amtrix should
be optimized so that all of the matrix elements that are needed for the next steps of the computation are stored in L1 cache. Storing elements in L2 cache
is perferable to DRAM in this case. 

3. Below are the performances predicted for the kernels in the warmup exercise.

| Kernel | Operational intensity (FLOPs/byte) | AMD performance (GFLOPs/s) | Intel performance (GFLOPs/s) |
| ------ | --------------------------------- | --------------------------- | --------------------------- |
| 1      | 0.25                            | 0.7 - 2.0                   | 5.0 - 10.1                  |
| 2      | 1.07                            | 1.5 - 8.0                   | 10.1                        |
| 3      | 0.50                            | 7.0 - 13.6                  | 10.1                        |
| 4      | 1.64                            | 13.6                        | 10.1                        |

4. Our matrix multiplication results give a maximum performance of about 0.5 GFLOPs. Given that this kernel has an operational intensity
of 0.75, our predicted maximum performance is 10.1 GFLOPs/s on Intel 18 and 7.5 to 13.6 GFLOPs, depending on wether we are reading from DRAM
or the L1 cache. 
