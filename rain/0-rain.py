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

    if walls:
        value1 = 0
        value2 = 0
        for index1 in range(0, len(walls)):
            value1 = walls[index1]
            if value1 > 0:
                for index2 in range(index1 + 1, len(walls)):
                    value2 = walls[index2]
                    if value2 > 0:
                        water += min(value1, value2) * (index2 - index1 - 1)
                        index1 = index2
                        value1 = value2
                        break

    return water
