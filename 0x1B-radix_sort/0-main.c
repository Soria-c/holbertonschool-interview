#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	int array2[] = {19, 48, 9771000, 99, 7771000, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);
	size_t n2 = sizeof(array2) / sizeof(array[0]);

	printf("First\n");
	print_array(array, n);
	putchar(0xA);
	radix_sort(array, n);
	putchar(0xA);
	print_array(array, n);
	putchar(0xA);
	putchar(0xA);
	printf("Second\n");
	print_array(array2, n2);
	putchar(0xA);
	radix_sort(array2, n2);
	putchar(0xA);
	print_array(array2, n2);
	return (0);
}
