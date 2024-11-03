#include "sort.h"

/**
 * print_array2 - Print Array
 * @array: Array to print
 * @left: Start index of array
 * @right: End index of array
 *
 * Return: Nothing
 */
void print_array2(int *array, int left, int right)
{
	int i = 0;

	if (!array)
		return;

	for (i = left; i < right; i++)
	{
		if (i != left)
			printf(", ");
		printf("%d", array[i]);
	}
	putchar('\n');
}

/**
 * top_down_merge - Sort the array using the top Down Merge
 * @B:     Copy Array
 * @left:  Left Index
 * @mid:   Mid Index
 * @right: Right Index
 * @A:     Original Array
 *
 * Return: Nothing
 */
void top_down_merge(int *A, int left, int mid, int right, int *B)
{
	int i = left, j = mid, k = left;

	if (!A || !B)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	print_array2(A, left, mid);
	printf("[right]: ");
	print_array2(A, mid, right);
	for (; k < right; k++)
	{
		if (i < mid && (j >= right || A[i] <= A[j]))
		{
			B[k] = A[i];
			i++;
		}
		else
		{
			B[k] = A[j];
			j++;
		}
	}

	printf("[Done]: ");
	print_array2(B, left, right);
}

/**
 * top_down_split_merge - Split A[] into 2 runs, sort both runs into B[],
 * merge both runs from B[] to A[]
 * @B:     Copy Array
 * @left:  Split Matrix left Index
 * @right: Split Matrix right Index
 * @A:     Original Array
 *
 * Return: Nothing
 */
void top_down_split_merge(int B[], size_t left, size_t right, int A[])
{
	size_t mid = 0;

	if (!A || !B || right - left <= 1)
		return;
	mid = (right + left) / 2;
	top_down_split_merge(A, left, mid, B);
	top_down_split_merge(A, mid, right, B);
	top_down_merge(B, left, mid, right, A);
}

/**
 * copy_array - Copy array
 * @A:     Array to copy
 * @start: Start index
 * @end:   End index
 * @B:     Array to save
 *
 * Return: Nothing
 */
void copy_array(int A[], int start, int end, int B[])
{
	for (; A && B && start < end; start++)
		B[start] = A[start];
}

/**
 * merge_sort - Sorts an array of integers in ascending order using
 * The Merge Sort algorithm
 * @array: Array of interger to sort
 * @size:  Size of the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
	int *array2;

	if (!array || size < 2)
		return;

	array2 = malloc(sizeof(int) * size);
	if (!array2)
	{
		fprintf(stderr, "%s: Can not malloc\n", __func__);
		return;
	}
	copy_array(array, 0, size, array2);
	top_down_split_merge(array2, 0, size, array);
	free(array2);
}
