#include "main.h"
#include <stdlib.h>

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 *
 * Return: On success, 1. On error, -1.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _is_digit - Checks if a character is a digit.
 * @c: The character to check.
 *
 * Return: 1 if it's a digit, 0 otherwise.
 */
int _is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - Calculates the length of a string.
 * @str: The string to calculate the length of.
 *
 * Return: The length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len])
	len++;
	return (len);
}

/**
 * _atoi - Converts a string to an integer.
 * @s: The string to convert.
 *
 * Return: The integer value of the string.
 */
int _atoi(char *s)
{
	int sign = 1;
	int result = 0;
	int i = 0;

	if (s[0] == '-')
{
	sign = -1;
	i++;
}

	while (s[i])
{
	if (!_is_digit(s[i]))
{
	return (0);
}
	result = result * 10 + (s[i] - '0');
	i++;
}

	return (result * sign);
}

/**
 * main - Multiplies two positive numbers.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Return: 0 on success, 98 on error.
 */
int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
{
	write(1, "Error\n", 6);
	return (98);
}

	num1 = _atoi(argv[1]);
	num2 = _atoi(argv[2]);

	if (num1 == 0 || num2 == 0)
{
	write(1, "Error\n", 6);
	return (98);
}

	result = num1 * num2;
	_putchar(result + '0');
	_putchar('\n');

	return (0);
}
