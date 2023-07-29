#!/usr/bin/python3
"""
Island Perimeter
"""


def island_perimeter(grid: list) -> int:
    """
    Calculate the perimeter of the island
    0 represents water
    1 represents land
    Each cell is square, with a side length of 1
    Cells are connected horizontally/vertically (not diagonally).
    grid is rectangular, with its width and height not exceeding 100

    Args:
        grid (list): Is a list of list of integers

    Return:
            The perimeter of the island described in grid
    """
    if grid is None or type(grid) is not list or grid == []:
        return 0
    perimeter = 0
    max_row = len(grid)
    max_column = len(grid[0])
    for i in range(max_row):
        for j in range(max_column):
            if grid[i][j] == 1:
                if i + 1 == max_row:
                    perimeter += 1
                if j + 1 == max_column:
                    perimeter += 1
                if i == 0:
                    perimeter += 1
                if j == 0:
                    perimeter += 1
                continue
            if i > 0 and grid[i - 1][j] == 1:
                perimeter += 1
            if j > 0 and grid[i][j - 1] == 1:
                perimeter += 1
            if j + 1 != max_column and grid[i][j + 1] == 1:
                perimeter += 1
            if i + 1 != max_row and grid[i + 1][j] == 1:
                perimeter += 1
    return perimeter
