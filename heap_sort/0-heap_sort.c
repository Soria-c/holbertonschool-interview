#include "sort.h"

/**
 * swap - Swap two elements on a int array
 *
 * @array: Pointer to the int array
 * @a_idx: Index of the first element
 * @b_idx: Index of the second element
 *
 * Return: Void.
 */
void swap(int *array, int a_idx, int b_idx)
{
	int tmp = 0;

	tmp = array[a_idx];
	array[a_idx] = array[b_idx];
	array[b_idx] = tmp;
}

/**
 * heapify - Changes the array to convert it into a heap
 *
 * @array: Pointer to the int array.
 * @array_size: Size of the array.
 * @heap_size: Size of the heap.
 * @node_idx: Index of node (parent node).
 *
 * Return: Void
 */
void heapify(int *array, size_t array_size, size_t heap_size, size_t node_idx)
{
	size_t left_idx = (2 * node_idx) + 1;
	size_t right_idx = (2 * node_idx) + 2;
	size_t largest_idx = node_idx;

	if ((left_idx < heap_size) && (array[left_idx] > array[largest_idx]))
		largest_idx = left_idx;

	if ((right_idx < heap_size) && (array[right_idx] > array[largest_idx]))
		largest_idx = right_idx;

	if (node_idx != largest_idx)
	{
		swap(array, node_idx, largest_idx);
		print_array(array, array_size);
		heapify(array, array_size, heap_size, largest_idx);
	}
}

/**
 * heap_sort - Sort an array with heap_sort algorithm
 *
 * @array: Pointer to array to sort
 *
 * @size: Size of array
 *
 * Return: Void
 */
void heap_sort(int *array, size_t size)
{
	int i = 0;

	if (!array || size <= 1)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		heapify(array, size, i, 0);
	}

}
