#!/usr/bin/python3
"Function that calculates the perimeter of an island in a grid"


def island_perimeter(grid):
    "Code that calculates the perimeter of an island in a grid"
    perimeter = 0
    height = len(grid)
    width = len(grid[0])

    for indexRow in range(height):
        for indexCol in range(width):
            if grid[indexRow][indexCol] == 1:
                if indexRow == 0 or grid[indexRow - 1][indexCol] == 0:
                    perimeter += 1
                if indexRow == height - 1 or grid[indexRow + 1][indexCol] == 0:
                    perimeter += 1
                if indexCol == 0 or grid[indexRow][indexCol - 1] == 0:
                    perimeter += 1
                if indexCol == width - 1 or grid[indexRow][indexCol + 1] == 0:
                    perimeter += 1

    return perimeter
