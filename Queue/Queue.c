#include "Queue.h"

//Create new node for Linked List. Update new Node's value
Node* new_node(int value, Node* next)
{
	Node* new = malloc(sizeof(Node));
	new->value = value;
	new->next = next;
	return new;
}

//Deallocate Linked List and Queue
void free_queue(Queue* queue)
{
	queue->rear = NULL;
	Node* prev = queue->front;
	Node* curr = queue->front;
	while(curr)
	{
		prev = curr;
		curr = curr->next;
		free(prev);
	}
	free(queue);
}

//Allocate new Queue on the heap
Queue* new_queue()
{
	Queue* q = malloc(sizeof(Queue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

void enqueue(Queue** queue, int value)
{
	Node* new = new_node(value, NULL);
	if ((*queue)->front == NULL)
	{
		(*queue)->front = new;
		(*queue)->rear  = new;
		return ;
	}

	(*queue)->rear->next = new;
	(*queue)->rear = (*queue)->rear->next;
}

int dequeue(Queue** queue)
{
	Node* prev = (*queue)->front;
	(*queue)->front = (*queue)->front->next;
	int result = prev->value;
	free(prev);
	return result;
}

int peek(Queue* queue)
{
	return queue->front->value;
}

void print_queue(Queue* queue)
{
	Node* temp = queue->front;
	while (temp)
	{
		printf("%d\t", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
