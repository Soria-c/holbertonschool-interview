#include "search_algos.h"

/**
 * print2 - implementation of the algorithm
 * @array: pointer to array of integers
 * @size: size of the aray
 * Return: nothing
 */
void print2(int *array, size_t size)
{
	int i = -1;

	printf("Searching in array: ");
	while (++i < (int)size)
		(i < (int)size - 1) ? printf("%d, ", array[i]) : printf("%d", array[i]);
	printf("\n");
}


/**
 * advanced_binary - implementation of the algorithm
 * @array: pointer to array of integers
 * @size: size of the aray
 * @value: value to search for
 * Return: index of the value in array if found, -1 otherwise
 */
int advanced_binary(int *array, size_t size, int value)
{
	int f;

	if (!array)
		return (-1);
	print2(array, size);
	if (array[(size - 1) / 2] == value)
		return ((size - 1) / 2);
	if (size <= 1)
		return (-1);
	if (value > array[(size - 1) / 2])
	{
		f = advanced_binary(&array[((size - 1) / 2) + 1], (size / 2), value);
		if (f == -1)
			return (-1);
		return ((f + ((size - 1) / 2)) + 1);
	}
	return (advanced_binary(array, ((size - 1) / 2), value));
}
