#include <stdarg.h>
#include <stdio.h>
#include "variadic_functions.h"

/**
 * print_all - Prints anything based on the specified format.
 * @format: A list of types of arguments passed to the function.
 * @...: The variable number of arguments.
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;

	va_start(args, format);

	while (format && format[i])
{
	char *str;
	char *sep = "";

	switch (format[i])
{
	case 'c':
	printf("%s%c", sep, va_arg(args, int));
	break;
	case 'i':
	printf("%s%d", sep, va_arg(args, int));
	break;
	case 'f':
	printf("%s%f", sep, va_arg(args, double));
	break;
	case 's':
	str = va_arg(args, char *);
	if (!str)
	str = "(nil)";
	printf("%s%s", sep, str);
	break;
	default:
	i++;
	continue;
}

	sep = ", ";
	i++;
}

	printf("\n");
	va_end(args);
}
