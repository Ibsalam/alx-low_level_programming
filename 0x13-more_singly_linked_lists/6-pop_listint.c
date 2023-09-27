#include <stdlib.h>
#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: pointer to a pointer to the first node in the list
 *
 * Return: the head node's data (n), or 0 if the list is empty
 */
int pop_listint(listint_t **head)
{
int data;
listint_t *temp;
if (*head == NULL)
	return (0);
temp = *head;
data = temp->n;
*head = (*head)->next;
free(temp);
return (data);
}
