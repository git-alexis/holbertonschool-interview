#!/usr/bin/python3
"""
Determines the fewest number of coins needed to meet a given total
"""


def makeChange(coins, total):
    if total <= 0:
        return 0

    listChange = [total + 1] * (total + 1)
    listChange[0] = 0

    for index in range(1, total + 1):
        for coin in coins:
            if coin <= index:
                listChange[index] = min(listChange[index],
                                        listChange[index - coin] + 1)

    if listChange[total] != total + 1:
        return listChange[total]
    else:
        return -1
