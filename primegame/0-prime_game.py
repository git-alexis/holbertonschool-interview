#!/usr/bin/python3
"""
Maria and Ben play a game choosing prime numbers optimally.
This function determines the overall winner after x rounds.
"""


def isWinner(x, nums):
    """
    Determines the winner of each round of the Prime Game.

    Args:
        x (int): Number of rounds.
        nums (list): List of integers representing the upper limit
        for each round.

    Returns:
        string: Winner name or None for no winner.
    """
    if not nums or x < 1:
        return None

    max_n = max(nums)

    sieve = [True for _ in range(max_n + 1)]
    sieve[0] = sieve[1] = False

    for i in range(2, int(max_n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, max_n + 1, i):
                sieve[j] = False

    primes_count = [0] * (max_n + 1)
    count = 0
    for i in range(1, max_n + 1):
        if sieve[i]:
            count += 1
        primes_count[i] = count

    maria_wins = 0
    ben_wins = 0

    for n in nums:
        if primes_count[n] % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    elif ben_wins > maria_wins:
        return "Ben"
    return None
