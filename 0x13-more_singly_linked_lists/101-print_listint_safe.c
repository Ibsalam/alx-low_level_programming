#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - Prints a listint_t linked list.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *tortoise = head, *hare = head;
	size_t count = 0;

	if (head == NULL)
	{
		return (0);
	}

	while (hare != NULL && hare->next != NULL)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;

		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			printf("-> [%p] %d\n", (void *)tortoise, tortoise->n);
			fprintf(stderr, "Infinite loop detected\n");
			exit(98);
		}
	}

	if (tortoise != NULL)
	{
		printf("[%p] %d\n", (void *)tortoise, tortoise->n);
		count++;
	}

	return (count);
}
