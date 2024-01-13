all: matmul

matmul: main.o matrix.o block_matrix.o
	gcc main.o matrix.o block_matrix.o -o matmul

main.o: main.c
	gcc -c main.c -o main.o

matrix.o: matrix.c matrix.h
	gcc -c matrix.c -o matrix.o

block_matrix.o: block_matrix.c block_matrix.h
	gcc -c block_matrix.c -o block_matrix.o
