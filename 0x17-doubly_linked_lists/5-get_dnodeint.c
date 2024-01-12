#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * get_dnodeint_at_index - returns the nth node of a dlistint_t linked list
 * @head: pointer to the head of the list
 * @index: index of the node, starting from 0
 *
 * Return: pointer to the nth node, or NULL if the node does not exist
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
    unsigned int i;

    for (i = 0; head != NULL && i < index; i++)
        head = head->next;

    return (i == index) ? head : NULL;
}
