#include "Queue.h"

int main()
{
	Queue* queue = new_queue();
	for (int i = 0; i < 10; i++)
	{
		enqueue(&queue, i);
		printf("%d\n", peek(queue));
	}

	print_queue(queue);

	free_queue(queue);
}
