#include "main.h"

/*factorial - Returns the factorial of a given number
 * @n: The number for which to calculate the factorial
 *
 * Return: The factorial of the number, or -1 if n is less than 0
 */
int factorial(int n)
{
	if (n < 0)
{
	return (-1);
}
else if (n == 0)
{
	return (1);
}
else
{
	return (n * factorial(n - 1));
}
}
