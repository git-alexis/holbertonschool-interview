#!/usr/bin/python3
"""
Module to calculate how many square units of water will be retained
after it rains.
"""


def rain(walls):
    """
    Returns the number of square indicating total amount of rainwater
    retained.

    Args:
        walls (array of int): representation of the walls

    Returns:
        int: Total amount of rainwater retained or 0 if walls is empty.
    """
    water = 0

    for i in range(1, len(walls) - 1):

        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])

        right = walls[i]
        for j in range(i + 1, len(walls)):
            right = max(right, walls[j])

        water += (min(left, right) - walls[i])

    return water
