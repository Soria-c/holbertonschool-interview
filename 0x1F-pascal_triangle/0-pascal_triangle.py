#!/usr/bin/python3
""" Pascal's Triangle """


def pascal_triangle(n):
    """ Returns a list of lists of integers representing the Pascal's triangle

    args:
        @n: number of rows of the triangle

    return: list of lists of integers
    """
    if n <= 0:
        return []

    prev_row = []
    for i in range(n):
        row = [1] * (i + 1)
        for j in range(1, i):
            row[j] = prev_row[j - 1] + prev_row[j]
        yield row
        prev_row = row
