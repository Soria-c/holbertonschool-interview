#include "menger.h"

/**
 * menger - Print a 2D Menger Sponge with a level
 *
 * @level: Level of a menger sponge
 *
 * Return: Void
 */
void menger(int level)
{
	int i = 0, j = 0, sides = (int)(pow(3, level));
	int tmp_i = i, tmp_j = j, flag = 0;

	if (level < 0)
		return;

	for (i = 0; i < sides; i++)
	{
		for (j = 0; j < sides; j++)
		{
			tmp_i = i;
			tmp_j = j;
			flag = 0;

			for (; tmp_i || tmp_j; tmp_i /= 3, tmp_j /= 3)
			{
				if ((tmp_i % 3 == 1) && (tmp_j % 3 == 1))
				{
					putchar(' ');
					flag = 1;
					break;
				}
			}

			if (flag)
				continue;

			putchar('#');
		}
		putchar('\n');
	}
}
