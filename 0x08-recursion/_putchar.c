#include "main.h"
#include <unistd.h>
/**
 * _putchar - writes a character to stdout
 * @c: The character to print
 *
 * Return: On success, the number of character written.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
        return (write(1, &c, 1));
}
