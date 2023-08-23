#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

struct Node
{
	int data;
	struct Node * next;
	
};

#define ASCENDING_SORT    1
#define DESCENDING_SORT   2

struct Node * create_singly_linked_list(void);

int isEmpty(struct Node * list);

void print_singly_linked_list(struct Node * list);

void prepend(struct Node ** head_ref, int new_data);

void append(struct Node * head, int new_data);

void insert(struct Node ** head_ref, int postion, int new_data);

void delete(struct Node ** head_ref, int position);

int sizeOfList(struct Node *head);

int search(struct Node * head, int data);

void sort_list(struct Node **head_ref, int sort_mechanism);

#endif