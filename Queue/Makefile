CC=gcc

all: link

link: main.o Queue.o
	$(CC) main.o Queue.o -o program

main.o: main.c
	$(CC) -c main.c

Queue.o: Queue.c
	$(CC) -c Queue.c

run:
	./program

clean:
	rm program *.o
