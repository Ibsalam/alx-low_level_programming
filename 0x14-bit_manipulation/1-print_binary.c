#include "main.h"

/**
 * _print_binary_recursive - Helper function to print binary
 * representation recursively.
 * @n: Unsigned long integer to be printed in binary.
 *
 * Recursively prints the binary representation of the number.
 */
void _print_binary_recursive(unsigned long int n)
{
	if (n == 0)
		return;

	_print_binary_recursive(n >> 1);
	_putchar((n & 1) ? '1' : '0');
}

/**
 * print_binary - Prints the binary representation of a number.
 * @n: Unsigned long integer to be printed in binary.
 *
 * Format: The output should be printed as a binary string.
 * Uses the custom _putchar function defined in main.h.
 */
void print_binary(unsigned long int n)
{
	if (n == 0)
		_putchar('0');
	else
	_print_binary_recursive(n);
		_putchar('\n');
}
