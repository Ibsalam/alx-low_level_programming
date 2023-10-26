#include "main.h"
#include <unistd.h>
/**
 * wildcmp - Compares two strings with wildcard support
 * @s1: The first string
 * @s2: The second string with wildcards
 *
 * Return: 0
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0')
{
	if (*s2 != '\0' && *s2 == '*')
{
	return (wildcmp(s1, s2 + 1));
}
	return (*s2 == '\0');
}
	if (*s2 == '*')
{
	return (wildcmp(s1 + 1, s2) || wildcmp(s1, s2 + 1));
}
	else if (*s1 == *s2)
{
	return (wildcmp(s1 + 1, s2 + 1));
}
	return (0);
}
