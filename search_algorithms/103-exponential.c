#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints a subarray
 * @array: Pointer to the first element of array
 * @start: Start index
 * @end: End index
 */
void print_array(int *array, size_t start, size_t end)
{
	size_t i;

	printf("Searching in array: ");
	for (i = start; i <= end; i++)
	{
		printf("%d", array[i]);
		if (i < end)
			printf(", ");
	}
	printf("\n");
}

/**
 * binary_search_expo - Binary search used after exponential range is found
 * @array: Pointer to array
 * @left: Left boundary
 * @right: Right boundary
 * @value: Target value
 *
 * Return: Index where value is found or -1
 */
int binary_search_expo(int *array, size_t left, size_t right, int value)
{
	size_t mid;

	while (left <= right)
	{
		print_array(array, left, right);
		mid = left + (right - left) / 2;
		if (array[mid] == value)
			return (mid);
		else if (array[mid] > value)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return (-1);
}

/**
 * exponential_search - Searches using exponential search
 * @array: Pointer to the array
 * @size: Number of elements
 * @value: Value to search for
 *
 * Return: Index of value or -1
 */
int exponential_search(int *array, size_t size, int value)
{
	size_t bound = 1;

	if (!array)
		return (-1);

	if (array[0] == value)
		return (0);

	while (bound < size && array[bound] < value)
	{
		printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
		bound *= 2;
	}

	size_t left = bound / 2;
	size_t right = bound < size ? bound : size - 1;
	printf("Value found between indexes [%lu] and [%lu]\n", left, right);
	return (binary_search_expo(array, left, right, value));
}
