#include <stdlib.h>
#include <stdio.h>
#include "holberton.h"

void mul(char *argv[]);
/**
 * main - Checks arguments.
 * @argc: number of command line arguments.
 * @argv: array containing the program command line arguments.
 * Return: 0 if successful.
 */
int main(int argc, char *argv[])
{
	int i, j;

	if (argc != 3)
	{
		printf("Error\n");
		exit(98);
	}
	for (i = 1; i < argc; i++)
	{
		for (j = 0; argv[i][j] != '\0'; j++)
		{
			if (argv[i][j] < 48 || argv[i][j] > 57)
			{
				printf("Error\n");
				exit(98);
			}
		}
	}
	mul(argv);
	return (0);
}
/**
 * mul - takes the product between the arguments
 * @argv: address of the arguments
 */
void mul(char *argv[])
{
	int i, j, w, n, k, d, c, z, m, carry, ld, carry2, ld2;
	int *num, x, y, b, s1, s2;

	d = z = s1 = s2 = 0;
	num = calloc(1, 4);
	for (i = 0; argv[1][i] != '\0'; i++)
		s1 += '0' - argv[1][i];
	for (j = 0; argv[2][j] != '\0'; j++)
		s2 += '0' - argv[2][j];
	if (s2 == 0 || s1 == 0)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}
	x = 2;
	y = 1;
	if (i > j)
	{
		w = j;
		j = i;
		i = w;
		x = 1;
		y = 2;
	}
	for (n = j - 1; n >= 0; n--)
	{
		carry = carry2 = m  = ld2 = ld = c = 0;
		for (k = i - 1; k >= 0; k--)
		{
			m = ('0' - argv[x][n]) * ('0' - argv[y][k]) + carry;
			ld = m % 10;
			carry = m / 10;
			if (z < c + d)
			{
				z++;
				num = realloc(num, (z + 1) * 4);
				num[c + d] = 0;
			}

			ld2 = (ld + num[c + d] + carry2) % 10;
			carry2 = (ld + num[c + d] + carry2) / 10;
			num[c + d] = ld2;
			if (k == 0)
			{
				b = 0;
				if (carry + carry2 == 0)
					b = 1;
				z++;
				num = realloc(num, (z + 1) * 4);
				num[c + d + 1] = carry + carry2;
			}
			c++;
		}
		d++;
	}
	if (b == 1)
		z--;
	for (; z >= 0; z--)
		_putchar(num[z] + '0');
	_putchar('\n');
	free(num);
}
