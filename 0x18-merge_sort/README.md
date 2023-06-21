# 0x18-merge_sort

# Files

### 0. Merge sort
### [0-merge_sort.c](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x18-merge_sort/0-merge_sort.c) | [0-O](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x18-merge_sort/0-O)

```C
alexa@ubuntu-xenial:0x18-merge_sort$ cat print_array.c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
alexa@ubuntu-xenial:0x18-merge_sort$

```

