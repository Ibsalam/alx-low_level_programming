#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * in a listint_t list
 * @head: pointer to a pointer to the first node in the list
 * @idx: the index at which the new node should be inserted
 * @n: data to insert in the new node
 *
 * Return: the address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node;
listint_t *current;
unsigned int i = 0;
if (idx == 0)
	return (add_nodeint(head, n));
current = *head;
while (current != NULL && i < idx - 1)
{
current = current->next;
i++;
}
if (current == NULL)
	return (NULL);
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
	return (NULL);
new_node->n = n;
new_node->next = current->next;
current->next = new_node;
return (new_node);
}
