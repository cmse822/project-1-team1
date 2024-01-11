all: matmul

matmul: main.o matrix.o
	gcc main.o matrix.o -o matmul

main.o: main.c
	gcc -c main.c -o main.o

matrix.o: matrix.c matrix.h
	gcc -c matrix.c -o matrix.o
