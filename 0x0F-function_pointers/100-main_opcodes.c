#include <stdio.h>
#include <stdlib.h>

/**
 * main - Prints the opcodes of its own main function.
 * @argc: The number of arguments.
 * @argv: An array of arguments.
 *
 * Return: 0 on success, 1 for incorrect number of arguments, 2 for negative bytes.
 */
int main(int argc, char *argv[])
{
	int i, bytes;

	if (argc != 2)
{
	printf("Error\n");
	return (1);
}

	bytes = atoi(argv[1]);

	if (bytes < 0)
{
	printf("Error\n");
	return (2);
}

	for (i = 0; i < bytes; i++)
{
	printf("%02hhx", *((char *)main + i));
	if (i < bytes - 1)
		printf(" ");
	else
	printf("\n");
}

	return (0);
}
