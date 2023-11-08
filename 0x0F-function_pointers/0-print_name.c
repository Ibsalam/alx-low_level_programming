#include "function_pointers.h"

/**
 * print_name - Prints a name using a printing function.
 * @name: The name to print.
 * @f: A function pointer to a printing function.
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
