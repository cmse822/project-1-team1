# Empirical Roofline Toolkit (ERT) Analysis Report

## System Specifications
- **Device:** MacBook Pro
- **CPU:** ARM-based (10-core)

## Methodology
- Configured and executed ERT in serial mode
- Tested across FLOP counts: 1, 2, 4, 8, 16
- Recorded performance for varying computational intensity

## Results Summary

### Peak Performance
- **FP64 Maximum:** 145.2 GFLOPs/sec

### Memory Bandwidths
- **L1 Cache:** Transition to peak performance at high arithmetic intensity
- **L2 Cache:** Ridge point observed at lower arithmetic intensity compared to L1
- **DRAM:** No intersection with peak performance, indicating no bandwidth limitation within tested range

### Ridge Points
- Identified at the intersection of memory bandwidth lines and peak performance line
- Indicate transition from memory-bound to compute-bound regions

## Graphical Overview
![Empirical Roofline Graph](accessible_repo/Empirical_Roofline_Tool-1.1.0/Results.MyMacBookPro/Run.003/roofline.ps)

## Conclusion
- MacBook Pro shows a peak double-precision floating-point performance of 145.2 GFLOPs/sec.
- Performance transitions from memory-bound to compute-bound as arithmetic intensity increases.
- L1 and L2 caches exhibit expected bandwidth limitations, while DRAM does not within the tested range.
