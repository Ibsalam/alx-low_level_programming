#include <stdio.h>
#include <stdlib.h>

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
	int cents, num_coins, i;
	int coins[] = {25, 10, 5, 2, 1};

	if (argc != 2)
{
	printf("Error\n");
	return (1);
}

	cents = atoi(argv[1]);

	if (cents < 0)
{
	printf("0\n");
	return (0);
}

	num_coins = 0;

	for (i = 0; i < 5; i++)
{
	while (cents >= coins[i])
{
	cents -= coins[i];
	num_coins++;
}

}

	printf("%d\n", num_coins);

	return (0);
}
