
CC=g++

CFLAGS=-c -Wall

all:
	$(CC) $(CFLAGS) Field.cpp -o Field.o -I ./../SFML-2.5.1/include
	$(CC) $(CFLAGS) Cell.cpp -o Cell.o -I ./../SFML-2.5.1/include
	$(CC) $(CFLAGS) GameOfLife.cpp -o GameOfLife.o  -I ./../SFML-2.5.1/include
	$(CC) GameOfLife.o Field.o Cell.o -o GameOfLife -L ./../SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system
	export LD_LIBRARY_PATH=./../SFML-2.5.1/lib && ./GameOfLife

compile:
	$(CC) $(CFLAGS) Field.cpp -o Field.o -I ./SFML-2.5.1/include
	$(CC) $(CFLAGS) Cell.cpp -o Cell.o -I ./SFML-2.5.1/include
	$(CC) $(CFLAGS) GameOfLife.cpp -o GameOfLife.o  -I ./SFML-2.5.1/include
	$(CC) GameOfLife.o Field.o Cell.o -o GameOfLife -L ./SFML-2.5.1/lib -lsfml-graphics -lsfml-window -lsfml-system

run:
	export LD_LIBRARY_PATH=./SFML-2.5.1/lib && ./GameOfLife

clean:
	rm -rf *.o GameOfLife

