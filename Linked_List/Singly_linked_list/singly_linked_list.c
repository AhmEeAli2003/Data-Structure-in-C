#include <stdio.h>
#include <stdlib.h>
#include "singly_linked_list.h"
#include "singly_list_private.h"


struct Node * create_singly_linked_list(void)
{	
	struct Node * Head = (struct Node *) malloc(sizeof(struct Node));;
	
	Head->next = NULL;
	Head->data = 0;
	/*
	current = Head;
	while (size > 1)
	{
		struct Node * new = (struct Node *) malloc(sizeof(struct Node));
		new->data = 0;
		current->next = new;
		current = new;
		size--;
	}
	current->next = NULL;
	*/
	return Head;
}

int isEmpty(struct Node * Head)
{
	return Head == NULL;
}

void print_singly_linked_list(struct Node * list)
{
	struct Node * current = list;
	
	
	if(!isEmpty(list))
	{
		printf("[Head: %d]", current->data);
		current = current->next;
		while(current != NULL)
		{
			printf("-> [%d]", current->data);
			current = current->next;
		}
	}
	else
	{
		printf("The list is empty!");
	}
	printf("\n");
}

void prepend(struct Node ** head_ref, int new_data)
{
	struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
	

	new_node->data = new_data;
	new_node->next = *(head_ref); //If list is empty next will be NULL.
	*(head_ref) = new_node;
}

void append(struct Node * head, int new_data)
{
	struct Node * new_node = (struct Node *) malloc(sizeof(struct Node));
	struct Node * current = head;
	
	new_node->data = new_data;
	new_node->next = NULL;
	
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = new_node;
}

int sizeOfList(struct Node *head)
{
	int counter = 0;
	struct Node * current = head;
	
	while(current->next != NULL)
	{
		current = current->next;
		counter++;
	}
	counter++;
	return counter;
}
void insert(struct Node ** head_ref, int position, int new_data)
{
	struct Node * new = (struct Node *) malloc(sizeof(struct Node));
	struct Node * current = *(head_ref);
	int i = 0;
	
	if(position > sizeOfList(*(head_ref)) + 1)
	{
		printf("postion [%d] Out Of range to insertion!\n", position);
	}
	else if(position == sizeOfList(*(head_ref)) + 1)
	{
		append(*(head_ref), new_data);
	}
	else if(position == 1)
	{
		prepend(head_ref, new_data);	
	}
	else
	{
		for(i = 2; i < position; i++)
		{
			if(current->next != NULL)
			{
				current = current->next;
			}
		}
		
		new->data = new_data;
		new->next = current->next;
		current->next = new;
	}
	
}

void delete(struct Node ** head_ref, int position)
{
	struct Node * current = *(head_ref);
	int i = 0;
	
	if(position >= sizeOfList(*(head_ref)) + 1)
	{
		printf("postion [%d] Out Of range to deletion!\n", position);
	}
	else if(position == 1)
	{
		*(head_ref) = current->next;
	}
	else if(position == sizeOfList(*(head_ref)))
	{
		while(current->next->next != NULL)
		{
			current = current->next;
		}
		
		current->next = NULL;
	}
	else
	{
		for(i = 2; i < position; i++)
		{
			if(current->next != NULL)
			{
				current = current->next;
			}
		}

			current->next = current->next->next;
	}
	
}

int search(struct Node * head, int data)
{
	int position = 1;
	struct Node * current = head;
	
	while(current->next != NULL)
	{
		if(current->data == data)
		{
			return position;
		}
		else
		{
			position++;
			current = current->next;
		}
	}
	
	return -1;
}

void Ascending_sort(struct Node **head_ref)
{
	struct Node * current = *(head_ref), *index = NULL;
	int temp;
		
	while(current != NULL)
	{
		index = current->next;
		
		while(index != NULL)
		{
			if(current->data > index->data)
			{
				temp = current->data;
				current->data = index->data;
				index->data = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}

void Descending_sort(struct Node **head_ref)
{
	struct Node * current = *(head_ref), *index = NULL;
	int temp;
		
	while(current != NULL)
	{
		index = current->next;
		
		while(index != NULL)
		{
			if(current->data < index->data)
			{
				temp = current->data;
				current->data = index->data;
				index->data = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}
void sort_list(struct Node **head_ref, int sort_mechanism)
{
	if(head_ref != NULL)
	{
		switch(sort_mechanism)
		{
			case 1: //Ascending
				Ascending_sort(head_ref);
				break;
			case 2: //Descending
				Descending_sort(head_ref);
				break;
			default:
				printf("Invalid sort mechanism!\n");
				return;
				
		}
	}
	else
	{
		return;
	}
}