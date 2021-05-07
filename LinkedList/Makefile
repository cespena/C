CC=gcc

all: link

link: main.o LinkedList.o
	$(CC) main.o LinkedList.o  -o program

main.o: main.c 
	$(CC) -c main.c 

LinkedList.o: LinkedList.c
	$(CC) -c LinkedList.c

run:
	./program

clean:
	rm program *.o
