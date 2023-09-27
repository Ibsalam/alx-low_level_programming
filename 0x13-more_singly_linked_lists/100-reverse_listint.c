#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list
 * @head: pointer to a pointer to the first node in the list
 *
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
    listint_t *prev = NULL;
    listint_t *current = *head;
    listint_t *next_node;

    while (current != NULL)
    {
        next_node = current->next;

        current->next = prev;

        prev = current;
        current = next_node;
    }

    *head = prev;

    return (*head);
}
