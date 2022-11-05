

CC = g++

CFLAGS = -c -Wall

all:
	$(CC) $(CFLAGS) Coordinate.cpp -o Coordinate.o
	$(CC) $(CFLAGS) StackState.cpp -o StackState.o
	$(CC) $(CFLAGS) LSystem.cpp -o LSystem.o
	$(CC) $(CFLAGS) main.cpp -o main.o -lglut -lGL
	$(CC) main.o StackState.o LSystem.o Coordinate.o -o LSystem -lglut -lGL
	./LSystem


clean:
	rm -rf *.o LSystem
