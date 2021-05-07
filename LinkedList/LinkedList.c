#include "LinkedList.h"

Node* new_node()
{
	Node* node = malloc(sizeof(Node));
	node->next = NULL;
	return node;
}

void set_value(Node** current, int value)
{
	(*current)->value = value;
}

void set_next(Node* current, Node* next)
{
	current->next = next;
}

void insert_node(Node** head, int value)
{
	Node* new = new_node();
	set_value(&new, value);
	set_next(new, *head);
	*head = new;
}

int remove_node(Node** head, int value)
{
	Node* previous = NULL;
	Node* current = *head;

	while (current)
	{
		if (value == current->value)
		{
			if (previous)
				previous->next = current->next;
			else
				*head = current->next;
			free_node(current);
			return 1;
		}
		previous = current;
		current = current->next;
	}
	return 0;
}

int exists(Node* head, int value)
{
	Node* temp = head;
	while (temp)
	{
		if (value == temp->value)
		{
			return 1;
		}
		temp = temp->next;
	}
	return 0;
}

Node* element(Node* head, int n)
{
	if (n >= 0 && n < length(head))
	{
		Node* current = head;
		int count = 0;
		while (count++ < n)
			current = current->next;
		return current;
	}
	return NULL;
}

int length(Node* head)
{
	Node* temp = head;
	int size = 0;
	while (temp)
	{
		size++;
		temp = temp->next;
	}
	return size;
}

void reverse_list(Node** head)
{
	Node* previous = NULL;
	Node* current = *head;
	Node* next = NULL;

	while (current)
	{
		next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}
	*head = previous;
}

void free_node(Node* node)
{
	free(node);
}

void free_list(Node* head)
{
	Node* previous = NULL;
	Node* current = head;

	while (current)
	{
		previous = current;
		current = current->next;
		free_node(previous);
	}
}

void print_list(Node* head)
{
	Node* temp = head;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
}
