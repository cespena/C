CC=gcc

all: link

link: main.o LinkedList.o
	$(CC) main.o LinkedList.o

main.o: main.c 
	$(CC) -c main.c 

LinkedList.o: LinkedList.c
	$(CC) -c LinkedList.c

run:
	./a.out

clean:
	rm a.out *.o
