# Roofline writeup

1. [roofline_amd.jpg](./roofline_amd.jpg) [roofline_intel.jpg](./roofline_intel.jpg) 
For AMD, the ridge point is 13.6 GFLOPs/s at an operations intensity of about 1.9 FLOPs/byte.
For Intel, the ridge point is 10.1 GFLOPs/s at an operations intensity of about 2.2 FLOPs/byte.

2.
| Kernel | Operational intensity (FLOPs/byte) | AMD performance (GFLOPs/s) | Intel performance (GFLOPs/s) |
| -----  | ---------------------------------- | -------------------------- | ---------------------------- |
| 1 | 0.25 | 0.7 - 1.0 | |
| 2 | 1.07 | | |
| 3 | 0.50 | | |
| 4 | 1.64 | | |
