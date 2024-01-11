#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * free_dlistint - frees a dlistint_t list
 * @head: pointer to the head of the list
 */
void free_dlistint(dlistint_t *head)
{
    dlistint_t *current, *next_node;

    current = head;

    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}
