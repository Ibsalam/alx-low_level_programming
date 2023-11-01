#include <stdlib.h>

/**
 * _strdup - Duplicates a string.
 *
 * @str: The string to duplicate
 *
 * Return: (Pointer to the duplicated string) or (NULL)
 * if str is NULL or memory allocation fails
 */
char *_strdup(char *str)
{
	char *duplicate;
	unsigned int length, i;

	if (str == NULL)
{
	return (NULL);
}
	length = 0;
	while (str[length] != '\0')
{
	length++;
}

	duplicate = (char *)malloc(length + 1);

	if (duplicate == NULL)
{
	return (NULL);
}

	for (i = 0; i < length; i++)
{
	duplicate[i] = str[i];
}

	duplicate[length] = '\0';

	return (duplicate);
}
