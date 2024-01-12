#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: pointer to the pointer of the head of the list
 * @idx: index of the list where the new node should be added, starting at 0
 * @n: value to be added to the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
    dlistint_t *new_node, *current;
    unsigned int i;

    if (h == NULL)
        return NULL;

    if (idx == 0)
        return add_dnodeint(h, n);

    current = *h;
    for (i = 0; i < idx - 1 && current != NULL; i++)
        current = current->next;

    if (current == NULL)
        return NULL;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
        return NULL;

    new_node->n = n;
    new_node->prev = current;
    new_node->next = current->next;

    if (current->next != NULL)
        current->next->prev = new_node;

    current->next = new_node;

    return (new_node);
}
