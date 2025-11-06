#!/usr/bin/python3
"""
Reads stdin line by line and computes metrics:
- Total file size
- Count of status codes
"""

import sys


def print_stats(total_size, status_counts):
    """
    Displays current statistics

    Args:
        total_size (int): Total file sizes.
        status_counts (dictionary): dictionary of integers representing
        the number of each status codes.
    """
    print("File size: {}".format(total_size))
    for code in sorted(status_counts.keys()):
        if status_counts[code] > 0:
            print("{}: {}".format(code, status_counts[code]))


if __name__ == "__main__":
    total_size = 0
    line_count = 0
    status_counts = {
        200: 0,
        301: 0,
        400: 0,
        401: 0,
        403: 0,
        404: 0,
        405: 0,
        500: 0
    }

    try:
        for line in sys.stdin:
            parts = line.strip().split(' ')

            if len(parts) < 9:
                continue

            try:
                status_code = int(parts[-2])
                file_size = int(parts[-1])
            except (ValueError, IndexError):
                continue

            if status_code in status_counts:
                status_counts[status_code] += 1
            total_size += file_size
            line_count += 1

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)
    except KeyboardInterrupt:
        raise
