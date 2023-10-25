#include "main.h"
int find_sqrt(int n, int x);
/**
 * _sqrt_recursion - Returns the natural square root of a number
 * @n: The number to find the square root of
 *
 * Return: The natural square root of n, or -1 if n does
 * not have a natural square root
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
{
	return (-1);
}
else if (n == 0 || n == 1)
{
	return (n);
}
	else
{
	return (find_sqrt(n, 1));
}
}

/**
 * find_sqrt - Helper function to find the square root using recursion
 * @n: The number to find the square root of
 * @x: The current guess for the square root
 *
 * Return: The natural square root of n, or -1 if it
 * doesn't have a natural square root
 */
int find_sqrt(int n, int x)
{
	if (x * x == n)
{
	return (x);
}
	else if (x * x > n)
{
	return (-1);
}
	else
{
	return (find_sqrt(n, x + 1));
}
}
