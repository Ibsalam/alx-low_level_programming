#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - Frees a listint_t linked list.
 * @h: A pointer to a pointer to the head of the linked list.
 *
 * Return: The size of the list that was freed.
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *tortoise, *hare, *temp;
	size_t count = 0;

	if (h == NULL || *h == NULL)
		return (0);

	tortoise = *h;
	hare = *h;

	while (hare != NULL && hare->next != NULL)
	{
		temp = tortoise;
		tortoise = tortoise->next;
		hare = hare->next->next;

		if (tortoise == hare)
		{
			tortoise = *h;

			while (tortoise != hare)
			{
				temp = hare;
				hare = hare->next;
				free(temp);
				count++;
			}

			temp = hare;

			while (hare->next != temp)
			{
				hare = hare->next;
				count++;
			}

			free(temp);
			count++;

			*h = NULL;
			return (count);
		}

		free(temp);
		count++;
	}

	temp = tortoise;
	while (temp != NULL)
	{
		tortoise = tortoise->next;
		free(temp);
		temp = tortoise;
		count++;
	}

	*h = NULL;

	return (count);
}
