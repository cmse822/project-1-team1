import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# data import from csv file
filename = 'sample.csv'
performance_data = pd.read_csv(filename, delimiter=',')

Matrix_size = performance_data.iloc[:, 0]
Performance = performance_data.iloc[:, 1]

# Hardware info: https://docs.icer.msu.edu/Cluster_Resources/
# The data below is amd22 (48 nodes)
Nodes = 48;
Cores = 128;
Clock_speed = 2.445; # unit: GHz
Flops = 8;

peak_performance = Nodes * Cores * Clock_speed * Flops; # Gflop/s, theoretical peak performance
plt.axhline(y=peak_performance, color='red', linestyle='--') 

# plotting
plt.plot(Matrix_size, Performance, linestyle='-', marker='.', color='blue', linewidth=1)

plt.xlabel("Matrix size, N")        # X-axis label
plt.ylabel("Performance (Gflop/s)") # Y-axis label

x_max = np.max(Matrix_size)
xticks = np.ceil(x_max / 10);  # 10 xticks
plt.xticks(np.arange(0, x_max + xticks, xticks))

yticks = peak_performance / 10;  # 10 yticks
plt.yticks(np.arange(0, peak_performance + yticks, yticks))
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0)) # The y-axis uses scientific notation

plt.show() # Show graph
