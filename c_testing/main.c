#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int value;
	struct Node* next;
};

void add_node(struct Node** head)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->value = 2;
	new_node->next = NULL;

	*head = new_node;
}

int main()
{
	struct Node* head = NULL;
	add_node(&head);

	printf("head: %d\n", head->value);

	int value = 187;

	for (int i = 0; i < 8; i++)
	{
		int bit = (value >> i) & 0x1;
		printf("Iteration %d: %d\n", i, bit);
	}
	printf("Original: %d\n", value);
	
	return 0;
}
