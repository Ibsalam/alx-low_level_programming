#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_list - Prints all elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes.
 */
size_t print_list(const list_t *h)
{
	int nodeCount = 0;

	while (h != NULL)
{
	if (h->str == NULL)

		printf("[0] (nil)\n");
	else
		printf("%s\n", h->str);

	h = h->next;
	nodeCount++;
	}

	return (nodeCount);
}
