#include "search_algos.h"

/**
 * jump_list - searches for a value in a sorted list of integers
 *             using the Jump search algorithm
 * @list: pointer to the head of the list to search in
 * @size: number of nodes in list
 * @value: value to search for
 *
 * Return: pointer to the first node where value is located,
 *         or NULL if value is not found or list is NULL
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
    size_t jump, prev, curr;
    listint_t *node;

    if (list == NULL)
        return (NULL);

    jump = sqrt(size);
    prev = 0;
    curr = jump;

    while (curr < size && list[curr].n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", curr, list[curr].n);
        prev = curr;
        curr += jump;
    }

    printf("Value found between indexes [%lu] and [%lu]\n", prev, curr);

    curr = (curr < size) ? curr : size - 1;
    node = &list[prev];

    while (node != NULL && node->n < value)
    {
        printf("Value checked at index [%lu] = [%d]\n", node->index, node->n);
        node = node->next;
    }

    if (node != NULL && node->n == value)
        return (node);

    return (NULL);
}
