CC=gcc
FLAGS=-c -std=c11 -Wall -Werror -Wextra

all: build

build: pascal_triangle

rebuild: clean build

pascal_triangle: pascal_triangle.o
	$(CC) pascal_triangle.o -o ../bin/pascal_triangle

pascal_triangle.o:
	$(CC) $(FLAGS) pascal_triangle.c

clean:
	rm -rf *.o
	rm -rf ../bin/pascal*