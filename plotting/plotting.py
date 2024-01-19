# import packages
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd

# data import from csv file
filename = 'sample.csv'

try:
    # Attempt to read the CSV file
    performance_data = pd.read_csv(filename, delimiter=',')

    Matrix_size = performance_data.iloc[:, 0]
    Performance = performance_data.iloc[:, 1]

except FileNotFoundError:
    # Print the file is not found
    print(f"Error: The file '{filename}' was not found.")

except pd.errors.ParserError:
    # Handle errors during parsing the CSV file
    print(f"Error: There was an error parsing '{filename}'. Please check its format.")

except ValueError as e:
    # Handle other value-related errors (such as incorrect columns)
    print(f"Error: An error occurred with the data in '{filename}'. {e}")    

# Hardware configuration
Nodes = 48
Cores = 128
Clock_speed = 2.445  # in GHz
Flops = 8

# Calculate theoretical peak performance
peak_performance = Nodes * Cores * Clock_speed * Flops

# Create a figure with a specific size
plt.figure(figsize=(10, 6))

# Plot the theoretical peak performance as a horizontal line
plt.axhline(y=peak_performance, color='red', linestyle='--', label='Theoretical Peak Performance') 

# Plot the performance data
plt.plot(Matrix_size, Performance, linestyle='-', marker='o', color='blue', linewidth=1, label='Performance Data')

# Set labels and title
plt.xlabel("Matrix Size, N")
plt.ylabel("Performance (Gflop/s)")
plt.title("Performance vs Matrix Size")

# Set x-axis ticks
x_max = np.max(Matrix_size)
xticks = np.ceil(x_max / 10)  # 10 xticks
plt.xticks(np.arange(0, x_max + xticks, xticks))

# Set y-axis ticks and format
yticks = peak_performance / 10  # 10 yticks
plt.yticks(np.arange(0, peak_performance + yticks, yticks))
plt.ticklabel_format(style='sci', axis='y', scilimits=(0,0))

# Enable grid and legend
plt.grid(True)
plt.legend()

# Display the plot
plt.show()
