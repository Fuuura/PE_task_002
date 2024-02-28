CC=gcc
FLAGS=-c -std=c11 -Wall -Werror -Wextra

all: build

build: pascal_triangle pascal_matrix

rebuild: clean build

pascal_triangle.o:
	$(CC) $(FLAGS) pascal_triangle.c -DBASE -DMATRIX

pascal_triangle: pascal_triangle.o base
	$(CC) pascal_triangle.o -o ../bin/pascal_triangle

pascal_matrix: pascal_triangle.o matrix
	$(CC) pascal_triangle.o -o ../bin/pascal_matrix

base:
	$(CC) $(FLAGS) pascal_triangle.c -DBASE

matrix:
	$(CC) $(FLAGS) pascal_triangle.c -DMATRIX


clean:
	rm -rf *.o
	rm -rf ../bin/pascal*