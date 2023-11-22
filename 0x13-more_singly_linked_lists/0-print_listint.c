#include "lists.h"

/**
 * print_listint - Prints all elements of a linked list.
 * @h: A pointer to the head of the linked list.
 *
 * Return: The number of nodes.
 */
size_t print_listint(const listint_t *h)
{
	size_t nodeCount = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		nodeCount++;
	}

	return (nodeCount);
}
