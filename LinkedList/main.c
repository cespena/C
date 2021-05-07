#include <stdio.h>
#include "LinkedList.h"

int main()
{

	int list[] = {1, 2, 3, 4, 5};
	Node* head = NULL;
	for (int i = 0; i < 5; i++)
	{
		insert_node(&head, list[i]);
	}
	print_list(head);
	
	reverse_list(&head);
	printf("Reversed List\n");
	print_list(head);
	printf("\n");

	Node* node = NULL;
	node = element(head, 0);
	node ? printf("Head[0]: %d\n", node->value) : printf("head[0] is NULL\n");
	node = element(head, 4);
	node ? printf("Head[4]: %d\n", node->value) : printf("head[4] is NULL\n");
	node = element(head, 5);
	node ? printf("Head[5]: %d\n", node->value) : printf("head[5] is NULL\n");
	node = element(head, -1);
	node ? printf("Head[-1]: %d\n", node->value) : printf("head[-1] is NULL\n");
	printf("\n");

	exists(head, 3) ? printf("3 exists\n") : printf("3 does not exist\n");
	exists(head, 1) ? printf("1 exists\n") : printf("1 does not exist\n");
	printf("Size: %d\n", length(head));
	printf("\n");

	remove_node(&head, 3) ? printf("3 removed\n") : printf("3 not removed\n");
	printf("Size: %d\n", length(head));
	remove_node(&head, 1) ? printf("1 removed\n") : printf("1 not removed\n");
	printf("Size: %d\n", length(head));
	printf("\n");

	exists(head, 3) ? printf("3 exists\n") : printf("3 does not exist\n");
	exists(head, 1) ? printf("1 exists\n") : printf("1 does not exist\n");
	printf("Size: %d\n", length(head));

	free_list(head);
	

	return 0;
}
