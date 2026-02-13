#!/usr/bin/python3
"""
0-nqueens.py

Solves the N Queens problem.
"""
import sys


def is_safe(row, col, cols, diag1, diag2):
    """
    Checks if a queen can be placed safely.

    Args:
        row (int): Row index
        col (int): Column index
        cols (set): Used columns
        diag1 (set): Used main diagonals (row - col)
        diag2 (set): Used anti-diagonals (row + col)

    Returns:
        bool: True if safe, False otherwise
    """
    if col in cols:
        return False
    if (row - col) in diag1:
        return False
    if (row + col) in diag2:
        return False
    return True


def backtrack(row, board_size, board, cols, diag1, diag2, solutions):
    """
    Places queens using backtracking.

    Args:
        row (int): Current row
        board_size (int): Size of board
        board (list): Current board positions
        cols (set): Used columns
        diag1 (set): Used main diagonals (row - col)
        diag2 (set): Used anti-diagonals (row + col)
        solutions (list): Found solutions

    Returns:
        None
    """
    if row == board_size:
        solutions.append(board[:])
        return

    for col in range(board_size):
        if is_safe(row, col, cols, diag1, diag2):

            board.append(col)
            cols.add(col)
            diag1.add(row - col)
            diag2.add(row + col)

            backtrack(row + 1, board_size, board,
                      cols, diag1, diag2, solutions)

            board.pop()
            cols.remove(col)
            diag1.remove(row - col)
            diag2.remove(row + col)


def print_solutions(solutions):
    """
    Prints all solutions.

    Args:
        solutions (list): List of N-Queens solutions
    """
    for solution in solutions:
        result = []
        for row, col in enumerate(solution):
            result.append([row, col])
        print(result)


def main():
    "Handles program input."
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        board_size = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)

    if board_size < 4:
        print("N must be at least 4")
        sys.exit(1)

    solutions = []

    backtrack(0, board_size, [], set(), set(), set(), solutions)

    print_solutions(solutions)


if __name__ == "__main__":
    main()
