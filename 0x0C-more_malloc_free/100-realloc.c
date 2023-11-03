#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: Pointer to the previously allocated memory.
 * @old_size: Size in bytes of the old allocated space.
 * @new_size: New size in bytes of the memory block.
 *
 * Return: Pointer to the newly allocated memory block, or NULL on failure.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *new_ptr;

	if (new_size == old_size)
	return (ptr);

	if (ptr == NULL)
{
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	return (NULL);
} else if (new_size == 0)
{
	free(ptr);
	return (NULL);
} else
{
	unsigned int i;

	new_ptr = malloc(new_size);

	if (new_ptr == NULL)
	return (NULL);

	if (new_size < old_size)
	old_size = new_size;

	for (i = 0; i < old_size; i++)
{
	*((char *)new_ptr + i) = *((char *)ptr + i);
}
	free(ptr);
}

	return (new_ptr);
}
