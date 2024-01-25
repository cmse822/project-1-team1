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
   
| Kernel    | Operational intensity (FLOPs/byte) | L1 | DRAM |
| --------- | --------------------------------- | --- | --- |
| SpMV      | 0.25                            | Comp | Mem |
| LBMHD     | 1.07                            | Comp | Mem |
| Stencil   | 0.50                            | Comp | Mem | 
| 3-D FF    | 1.64                            | Comp | Comp |


**Intel**

| Kernel    | Operational intensity (FLOPs/byte) | L1 | L2 | DRAM |
| --------- | --------------------------------- | --- | --- | --- |
| SpMV      | 0.25                            | Comp | Mem | Mem |
| LBMHD     | 1.07                            | Comp | Comp | Comp |
| Stencil   | 0.50                            | Comp | Comp | Comp |
| 3-D FF    | 1.64                            | Comp | Comp | Comp |

3. Below are the performances predicted for the kernels in the warmup exercise.

| Kernel | Operational intensity (FLOPs/byte) | AMD performance (GFLOPs/s) | Intel performance (GFLOPs/s) |
| ------ | --------------------------------- | --------------------------- | --------------------------- |
| 1      | 0.25                            | 0.7 - 2.0                   | 5.0 - 10.1                  |
| 2      | 1.07                            | 1.5 - 8.0                   | 10.1                        |
| 3      | 0.50                            | 7.0 - 13.6                  | 10.1                        |
| 4      | 1.64                            | 13.6                        | 10.1                        |

4. Below are the 
