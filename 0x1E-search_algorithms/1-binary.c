#include "search_algos.h"

/**
 * binary_search - Search for a value in a sorted array of integers using binary search algorithm
 * @array: Pointer to the first element of the array to search in
 * @size: Number of elements in the array
 * @value: Value to search for
 * Return: Index where value is located, or -1 if not found or array is NULL
 */
int binary_search(int *array, size_t size, int value)
{
    int left = 0;
    int right = size - 1;
    int mid;
    size_t i;

    if (array == NULL)
        return -1;

    while (left <= right)
    {
        printf("Searching in array: ");
        for (i = left; i <= (size_t)right; i++)
        {
            printf("%d", array[i]);
            if (i < (size_t)right)
                printf(", ");
        }
        printf("\n");

        mid = (left + right) / 2;

        if (array[mid] < value)
            left = mid + 1;
        else if (array[mid] > value)
            right = mid - 1;
        else
            return mid;
    }

    return -1; /* Value not found */
}

