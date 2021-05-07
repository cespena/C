#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node* next;
}Node;


//Node functions
Node* new_node();	//Return new node with next pointing to NULL
void set_value(Node** current, int value);	//Gives value to Node
void set_next(Node* current, Node* next);	//Links two nodes

//Linked List Functions
void insert_node(Node** head, int value);
int remove_node(Node** head, int value);
int exists(Node* head, int value);
Node* element(Node* head, int n);
int length(Node* head);
void reverse_list(Node** head);

//Memory functions
void free_node(Node* node);
void free_list(Node* head);

//Output
void print_list(Node* head);




#endif //LINKEDLIST_H
