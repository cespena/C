#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <stdio.h>
#include <stdlib.h>

//Queue will be implemented as a Linked List. This struct represents a node
//in the Linked List
typedef struct Node
{
	int value;
	struct Node* next;
} Node;

//The linked list will be stored in this struct. There are two pointer pointing
//to either end of the list. Front is where we dequeue and rear is where we enqueue.
typedef struct Queue
{
	Node* front;
	Node* rear;
} Queue;

//Private Functions
Node* new_node(int value, Node* next);					//Allocated a new Node on the heap
void free_queue(Queue* queue);							//Deallocate Queue at the end of program

//Queue Funtions
Queue* new_queue();						//Initialize Queue
void enqueue(Queue** queue, int value);	//Add item to back of Queue
int dequeue(Queue** queue);				//Remove items from front of Queue
int peek(Queue* queue);				//Look at the front of the Queue

//Not a main function of a Queue. Used for debugging.
void print_queue(Queue* queue);

#endif //QUEUE_HPP
