#include <stdio.h>
#include "singly_linked_list.h"

int main(void)
{
	struct Node * Head = NULL;
	struct Node * current = NULL;
	struct Node * list = create_singly_linked_list();
	struct Node * emptyList = NULL;
	int pos = 0, dataToSearch = 30;
	
	print_singly_linked_list(list);
	print_singly_linked_list(emptyList);
	prepend(&emptyList, 5);
	prepend(&emptyList, 10);
	print_singly_linked_list(emptyList);
	
	list->data = 9;
	print_singly_linked_list(list);
	append(list, 7);
	print_singly_linked_list(list);
	
	for(int i = 1; i <= 4; i++)
	{
		insert(&list, i, i * 10);
	}
	print_singly_linked_list(list);
	delete(&list, 1);
	print_singly_linked_list(list);
	delete(&list, 3);
	print_singly_linked_list(list);
	
	printf("%d\n", sizeOfList(list));
	
	delete(&list, 4);
	print_singly_linked_list(list);
	
	printf("%d\n", sizeOfList(list));
	
	delete(&list, 4);
	print_singly_linked_list(list);
	
	insert(&list, 4, 78);
	print_singly_linked_list(list);
	
	insert(&list, 6, 32);
	print_singly_linked_list(list);
	
	pos = search(list, dataToSearch);
	pos == -1? printf("%d not founded\n", dataToSearch): printf("%d is founded in node %d\n", dataToSearch, pos);
	
	dataToSearch = 50;
	pos = search(list, dataToSearch);
	pos == -1? printf("%d not founded\n", dataToSearch): printf("%d is founded in node %d\n", dataToSearch, pos);
	
	sort_list(&list, ASCENDING_SORT);
	print_singly_linked_list(list);
	
	sort_list(&list, DESCENDING_SORT);
	print_singly_linked_list(list);
	g
	return 0;
}