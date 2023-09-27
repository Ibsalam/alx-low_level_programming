#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t linked list safely
 * @h: pointer to a pointer to the first node in the list
 *
 * Return: the size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
size_t size = 0;
listint_t *current, *temp;
listint_t *loop_start = NULL;

current = *h;

while (current != NULL)
{
size++;
temp = current;

if (current->next >= loop_start)
{
loop_start = current->next;
}
else
{
current = current->next;
free(temp);
break;
}

current = current->next;
free(temp);
}

*h = NULL;

return (size);
}
