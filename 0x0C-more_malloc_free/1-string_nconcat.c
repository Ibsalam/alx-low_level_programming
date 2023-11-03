#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - Concatenates two strings.
 * @s1: The first string.
 * @s2: The second string.
 * @n: The maximum number of bytes from s2 to concatenate.
 *
 * Return: Pointer to a newly allocated space in memory containing s1
 * followed by the first n bytes of s2 and null-terminated,
 * or NULL if the function fails.
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *result;
	unsigned int len_s1 = 0, len_s2 = 0;
	unsigned int i, j;

	if (s1 == NULL)
	s1 = "";
	if (s2 == NULL)
	s2 = "";

	while (s1[len_s1])
	len_s1++;

	while (s2[len_s2])
	len_s2++;

	if (n >= len_s2)
	n = len_s2;

	result = (char *)malloc(len_s1 + n + 1);

	if (result == NULL)
	return (NULL);

	for (i = 0; i < len_s1; i++)
	result[i] = s1[i];

	for (j = 0; j < n; j++)
	result[i + j] = s2[j];

	result[i + j] = '\0';

	return (result);
}
