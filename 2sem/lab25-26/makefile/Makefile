CC = gcc
CFLAGS = -g
OBJ = main.o list.o sort.o
PROG = program

build: main.o list.o sort.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

sort.o: sort.c sort.h
	$(CC) $(CFLAGS) -c sort.c

clean: 
	rm $(PROG)
