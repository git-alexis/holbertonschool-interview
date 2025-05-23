#!/usr/bin/python3
"""Module to compute minimum operations to get n H characters."""


def minOperations(n):
    """
    Returns the minimum number of operations needed to get exactly n H characters.

    Args:
        n (int): Target number of H characters.

    Returns:
        int: Minimum number of operations or 0 if n is impossible.
    """
    if n < 2:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
