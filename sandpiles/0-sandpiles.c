#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple_corners- topples the corners
 * @grid: 3x3 grid
 * @unstable: flag
 *
 */
void topple_corners(int grid[3][3], int *unstable)
{
	int i, j;
	int local_unstable = 0;
	int toppled[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 0; i <= 2; i += 2)
	{
		for (j = 0; j <= 2; j += 2)
		{
			local_unstable += grid[i][j] >= 4 ? 1 : 0;
			toppled[(i * 3) + j] = grid[i][j] >= 4 ? 1 : 0;
			grid[i][j] = grid[i][j] >= 4 ? grid[i][j] - 4 : grid[i][j];
			*unstable += grid[i][j] >= 4 ? 1 : 0;
		}
	}
	if (!local_unstable)
		return;
	for (i = 0; i <= 2; i += 2)
	{
		for (j = 0; j <= 2; j += 2)
		{
			if (!j && toppled[(i * 3) + j])
			{
				grid[i][j + 1]++;
				*unstable += grid[i][j + 1] >= 4 ? 1 : 0;
				grid[1][0]++;
				*unstable += grid[1][0] >= 4 ? 1 : 0;
			}
			else if (j && toppled[(i * 3) + j])
			{
				grid[i][j - 1]++;
				*unstable += grid[i][j - 1] >= 4 ? 1 : 0;
				grid[1][2]++;
				*unstable += grid[1][2] >= 4 ? 1 : 0;
			}
		}
	}
}

/**
 * topple_sides- topples the corners
 * @grid: 3x3 grid
 * @unstable: flag
 *
 */
void topple_sides(int grid[3][3], int *unstable)
{
	int i, j;
	int local_unstable = 0;
	int toppled[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

	for (i = 1, j = 0; i < 9; i += 2)
	{
		j += i / 3 == j + 1 ? 1 : 0;
		local_unstable += grid[j][i % 3] >= 4 ? 1 : 0;
		toppled[(j * 3) + (i % 3)] = grid[j][i % 3] >= 4 ? 1 : 0;
		grid[j][i % 3] = grid[j][i % 3] >= 4 ? grid[j][i % 3] - 4 : grid[j][i % 3];
		*unstable += grid[j][i % 3] >= 4 ? 1 : 0;
	}

	if (!local_unstable)
		return;

	for (i = 1, j = 0; i < 9; i += 2)
	{
		j += i / 3 == j + 1 ? 1 : 0;
		if (((i % 3) % 2) && toppled[(j * 3) + (i % 3)])
		{
			grid[j][(i % 3) + 1]++;
			*unstable += grid[j][(i % 3) + 1] >= 4 ? 1 : 0;
			grid[j][(i % 3) - 1]++;
			*unstable += grid[j][(i % 3) - 1] >= 4 ? 1 : 0;
			grid[1][1]++;
			*unstable += grid[1][1] >= 4 ? 1 : 0;
		}
		else if (!((i % 3) % 2) && toppled[(j * 3) + (i % 3)])
		{
			grid[1][1]++;
			*unstable += grid[1][1] >= 4 ? 1 : 0;
			grid[j - 1][i % 3]++;
			*unstable += grid[j - 1][i % 3] >= 4 ? 1 : 0;
			grid[j + 1][(i % 3)]++;
			*unstable += grid[j + 1][i % 3] >= 4 ? 1 : 0;
		}
	}
}

/**
 * topple_center - topples the corners
 * @grid: 3x3 grid
 * @unstable: flag
 *
 */
void topple_center(int grid[3][3], int *unstable)
{
	int i, j;
	int local_unstable = 0;

	local_unstable += grid[1][1] >= 4 ? 1 : 0;
	grid[1][1] = grid[1][1] >= 4 ? grid[1][1] - 4 : grid[1][1];
	*unstable += grid[1][1] >= 4 ? 1 : 0;
	if (local_unstable)
	{
		for (i = 1, j = 0; i < 9; i += 2)
		{
			j += i / 3 == j + 1 ? 1 : 0;
			grid[j][i % 3] += 1;
			*unstable += grid[j][i % 3] >= 4 ? 1 : 0;
		}
	}
}

/**
 * sandpiles_sum - sums two grids
 * @grid1: 3x3 grid
 * @grid2: 3x3 grid
 *
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int unstable = 1;
	int local_unstable = 0;
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			local_unstable += grid1[i][j] >= 4 ? 1 : 0;
		}
	}
	unstable = local_unstable ? 1 : 0;
	while (unstable)
	{
		unstable = 0;
		printf("=\n");
		print_grid(grid1);
		topple_corners(grid1, &unstable);
		topple_sides(grid1, &unstable);
		topple_center(grid1, &unstable);
	}
}
