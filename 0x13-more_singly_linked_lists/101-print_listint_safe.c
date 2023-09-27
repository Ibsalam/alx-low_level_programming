#include "lists.h"
#include <unistd.h>

/**
 * looped_listint_len - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_listint_len(const listint_t *head)
{
    const listint_t *tortoise, *hare;
    size_t nodes = 1;

    if (head == NULL || head->next == NULL)
        return (0);

    tortoise = head->next;
    hare = (head->next)->next;

    while (hare)
    {
        if (tortoise == hare)
        {
            tortoise = head;
            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
                hare = hare->next;
            }

            tortoise = tortoise->next;
            while (tortoise != hare)
            {
                nodes++;
                tortoise = tortoise->next;
            }

            return (nodes);
        }

        tortoise = tortoise->next;
        hare = (hare->next)->next;
    }

    return (0);
}

/**
 * custom_putint - Prints an integer to the standard output.
 * @n: The integer to print.
 */
void custom_putint(int n)
{
    char buffer[32];
    int i = 0;

    if (n == 0)
    {
        write(1, "0", 1);
        return;
    }

    while (n != 0)
    {
        buffer[i++] = (n % 10) + '0';
        n /= 10;
    }

    while (i > 0)
    {
        write(1, &buffer[--i], 1);
    }
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
    size_t nodes, node_count = 0;

    nodes = looped_listint_len(head);

    if (nodes == 0)
    {
        for (; head != NULL; nodes++)
        {
            custom_putint(head->n);
            write(1, "\n", 1);
            head = head->next;
        }
    }
    else
    {
        for (node_count = 0; node_count < nodes; node_count++)
        {
            custom_putint(head->n);
            write(1, "\n", 1);
            head = head->next;
        }

        custom_putint(head->n);
        write(1, "\n", 1);
    }

    return (nodes);
}
