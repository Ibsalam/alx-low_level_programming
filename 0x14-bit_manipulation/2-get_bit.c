#include "main.h"

/**
 * get_bit - Returns the value of a bit at a given index.
 * @n: Unsigned long integer.
 * @index: Index of the bit to retrieve, starting from 0.
 *
 * Return: Value of the bit at index or -1 if an error occurred.
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int mask = 1UL << index;

	if (index >= (sizeof(unsigned long int) * 8))
	{
		return (-1);
	}

	if ((n & mask) == mask)
		return (1);
	else
		return (0);
}
