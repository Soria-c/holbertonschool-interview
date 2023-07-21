#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/* The maximum decimal number of one digit is 9, so we have ten digits */
#define D_MAX 10

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);

#endif /* _SORT_H_ */
