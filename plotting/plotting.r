# install and load packages
install.packages("ggplot2")
install.packages("readr")
install.packages("scales")

library(ggplot2)
library(readr)
library(scales)

# Data imported from CSV file
filename <- '/Users/songtraming/Desktop/sample.csv'

# Read CSV files
tryCatch({
  performance_data <- read_csv(filename, show_col_types = FALSE)
  Matrix_size <- performance_data[[1]]
  Performance <- performance_data[[2]]
  
  # Hardware Configuration
  Nodes <- 48
  Cores <- 128
  Clock_speed <- 2.445  # GHz
  Flops <- 8
  
  # Calculate theoretical peak performance
  peak_performance <- Nodes * Cores * Clock_speed * Flops
  
  # Display the plot
  p <- ggplot() + 
    geom_line(aes(x = Matrix_size, y = Performance, color = "Performance Data"), size = 1) +
    geom_hline(aes(yintercept = peak_performance, color = "Theoretical Peak Performance"), linetype = "dashed") +
    scale_color_manual(values = c("Performance Data" = "blue", "Theoretical Peak Performance" = "red")) +
    scale_x_continuous(breaks = 0:6, limits = c(0, 6)) +
    scale_y_continuous(labels = scientific) +
    labs(x = "Matrix Size, N", y = "Performance (Gflop/s)", 
         title = "Performance vs Matrix Size") +
    theme_minimal() +
    theme(panel.grid.major = element_line(color = "grey"),
          panel.grid.minor = element_blank(),
          legend.position = "bottom")
  
  print(p)
}, error = function(e) {
  cat("Error: There was an error with the file", filename, "\n", e$message)
})
