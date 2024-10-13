#!/usr/bin/python3
""" Rotate 2D Matrix """
# from typing import List
# matrix: list[list[int]]


def rotate_2d_matrix(matrix: list) -> None:
    """ Given an n x n 2D matrix, rotate it 90 degrees clockwise """
    n = len(matrix)
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            temp = matrix[i][j]
            matrix[i][j] = matrix[n - 1 - j][i]
            matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j]
            matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i]
            matrix[j][n - 1 - i] = temp
