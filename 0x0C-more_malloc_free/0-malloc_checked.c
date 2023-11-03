#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocates memory using malloc
 * and checks for success.
 * @b: The size of the memory to allocate.
 *
 * Return: Pointer to the allocated memory (if successful).
 *         Exits with status value 98 (if malloc fails).
 */
void *malloc_checked(unsigned int b)
{
	void *ptr = malloc(b);

	if (ptr == NULL)
{
	exit(98);
}

	return (ptr);
}
