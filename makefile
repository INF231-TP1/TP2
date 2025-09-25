CC = gcc
CFLAGS = -Wall -Wextra
OBJECTS = main.o tp2.o

all: main

main: $(OBJECTS)
	$(CC) $(CFLAGS) -o main $(OBJECTS)

main.o: main.c tp2.h
	$(CC) $(CFLAGS) -c main.c

tp2.o: tp2.c tp2.h
	$(CC) $(CFLAGS) -c tp2.c

clean:
	rm -f main $(OBJECTS)
