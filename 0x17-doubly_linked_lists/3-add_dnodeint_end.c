#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to the pointer of the head of the list
 * @n: value to be added to the new node
 *
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
    dlistint_t *new_node, *last;

    new_node = malloc(sizeof(dlistint_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: Can't malloc\n");
        return( NULL);
    }

    new_node->n = n;
    new_node->next = NULL;

    if (*head == NULL)
    {
        new_node->prev = NULL;
        *head = new_node;
    }
    else
    {
        last = *head;
        while (last->next != NULL)
            last = last->next;

        last->next = new_node;
        new_node->prev = last;
    }

    return (new_node);
}
