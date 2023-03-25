#!/usr/bin/python3
"""
The N queens puzzle is the challenge of placing
N non-attacking queens on an NxN chessboard.
Write a program that solves the N queens problem.
"""
from sys import argv


def n_queens(size: int) -> list:
    """
    N-queens solution
    Args:
        size (int): Size of the chessboard
    Return: List of solutions of N-queens
    """

    def backtrack(queens: list, xy_dif: list, xy_sum: list) -> None:
        """
        Backtracking n-queens algorithms
        Args:
            queens (List[int]): List of queens
            xy_dif (List[int]): List of xy coordinates difference
            xy_sum (List[int]): List of xy coordinates sum
        """
        num_queens = len(queens)

        if num_queens == size:
            output.append(queens)
            return

        for i in range(size):
            if ((i not in queens) and ((num_queens - i) not in xy_dif)
                    and ((num_queens + i) not in xy_sum)):
                backtrack(queens + [i], xy_dif +
                          [num_queens - i], xy_sum + [num_queens + i])

    output = []

    backtrack([], [], [])

    return [[[i, j] for i, j in enumerate(solution)] for solution in output]


if __name__ == '__main__':
    if len(argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        number = int(argv[1])
    except ValueError:
        print("N must be a number")
        exit(1)

    if (number < 4):
        print("N must be at least 4")
        exit(1)

    for results in n_queens(number):
        print(results)
