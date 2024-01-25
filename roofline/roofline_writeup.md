# Roofline writeup

1. ![AMD Roofline](./roofline_amd.jpg)
   ![Intel Roofline](./roofline_intel.jpg) 
   For AMD, the ridge point is 13.6 GFLOPs/s at an operational intensity of about 0.19 FLOPs/byte for L1, and 1.2 for DRAM.
   For Intel, the ridge point is 10.1 GFLOPs/s at an operational intensity of about 0.22 FLOPs/byte for L1, 0.31 for L2, and 0.5 for DRAM.

2. Below are the results predicted for the kernels in the Roofline paper.

| Kernel | Operational intensity (FLOPs/byte) | AMD performance (GFLOPs/s) | Intel performance (GFLOPs/s) |
| ------ | --------------------------------- | --------------------------- | --------------------------- |
| 1      | 0.25                            | 0.7 - 2.0                   | 5.0 - 10.1                  |
| 2      | 1.07                            | 1.5 - 8.0                   | 10.1                        |
| 3      | 0.50                            | 7.0 - 13.6                  | 10.1                        |
| 4      | 1.64                            | 13.6                        | 10.1                        |

3. Below are the performances predicted for the kernels in the warmup exercise.

| Kernel | Operational intensity (FLOPs/byte) | AMD performance (GFLOPs/s) | Intel performance (GFLOPs/s) |
| ------ | --------------------------------- | --------------------------- | --------------------------- |
| 1      | 0.25                            | 0.7 - 2.0                   | 5.0 - 10.1                  |
| 2      | 1.07                            | 1.5 - 8.0                   | 10.1                        |
| 3      | 0.50                            | 7.0 - 13.6                  | 10.1                        |
| 4      | 1.64                            | 13.6                        | 10.1                        |


4. Below are the 
