clc
clear all

clock_speed = 3.4; % GHz
cores = 1; % only one core working
flop = 1; % assuming 1 flop per clock cycle

peak_performance = clock_speed * cores * flop;

filename = 'sample.csv'; 
data = readtable(filename);

N = data{2:end, 1};
performance = data{2:end, 2};

p = plot(N, performance);
set(p, 'Color', 'blue', 'LineStyle', '-', 'Marker', '*', 'LineWidth', 1);

xlabel('matrix size, N');
ylabel('performance (Gflop/s)');

line([min(N), max(N)], [peak_performance, peak_performance], 'LineStyle', '--', 'Color', [1, 0, 0]);