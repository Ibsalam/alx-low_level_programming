#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * free_list - Frees a linked list.
 * @head: A pointer to the head of the linked list.
 */
void free_list(list_t *head)
{
	list_t *current, *next_node;

	current = head;
	while (current != NULL)
	{
		next_node = current->next;
		free(current->str);
		free(current);
		current = next_node; /* Move to the next node */
	}
}
