# 0x1B-radix_sort

# Files

### 0. Radix sort
### [0-radix_sort.c](https://github.com/Ineffable22/holbertonschool-interview/blob/main/0x1B-radix_sort/0-radix_sort.c)

```C
alexa@ubuntu-xenial:0x1B-radix_sort$ cat `print_array.c`
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
alexa@ubuntu-xenial:0x1B-radix_sort$

```

