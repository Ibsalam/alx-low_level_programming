#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * main - Entry point
 *
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 *
 * Return: (0) if successful, (1) if there is an error
 */
int main(int argc, char *argv[])
{
	int i, sum = 0;

	if (argc == 1)
{
	printf("0\n");
	return (0);
}

	for (i = 1; i < argc; i++)
{
	char *arg = argv[i];
	int num = atoi(arg);

	if (num == 0 && arg[0] != '0')
{
	printf("Error\n");
	return (1);
}

	if (num < 0)
{
	printf("Error\n");
	return (1);
}

	sum += num;
}

	printf("%d\n", sum);

	return (0);
}
