#include <stdio.h>

/**
 * is_palindrome - Checks if a number is a palindrome.
 * @n: The number to be checked.
 *
 * Return: 1 if the number is a palindrome, 0 otherwise.
 */
int is_palindrome(int n)
{
    int original = n, reverse = 0;

    while (n > 0)
    {
        reverse = reverse * 10 + n % 10;
        n /= 10;
    }

    return (original == reverse);
}

/**
 * largest_palindrome_product - Finds the largest palindrome made from
 * the product of two 3-digit numbers.
 *
 * Return: The largest palindrome.
 */
int largest_palindrome_product(void)
{
    int largest_palindrome = 0;

    for (int i = 100; i < 1000; i++)
    {
        for (int j = i; j < 1000; j++)
        {
            int product = i * j;

            if (is_palindrome(product) && product > largest_palindrome)
            {
                largest_palindrome = product;
            }
        }
    }

    return (largest_palindrome);
}

/**
 * main - Entry point of the program.
 *
 * Return: Always 0.
 */
int main(void)
{
    int result = largest_palindrome_product();
    printf("The largest palindrome made from the product of two 3-digit numbers is: %d\n", result);

    return (0);
}
