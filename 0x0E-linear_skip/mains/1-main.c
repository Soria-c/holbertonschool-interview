#include "../search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	skiplist_t *list, *res;
	int array[] = {
	    0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99};
	size_t size = sizeof(array) / sizeof(array[0]);

	list = create_skiplist(array, size);
	print_skiplist(list);

	res = linear_skip(list, -1);
	printf("Found %d at index: %p\n\n", -1, (void *)res);

	res = linear_skip(list, 5);
	printf("Found %d at index: %p\n\n", 5, (void *)res);

	res = linear_skip(list, 999);
	printf("Found %d at index: %p\n", 999, (void *)res);

	free_skiplist(list);
	return (EXIT_SUCCESS);
}
