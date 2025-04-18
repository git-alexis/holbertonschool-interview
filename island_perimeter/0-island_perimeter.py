#!/usr/bin/python3
"Function that calculates the perimeter of an island in a grid"


def island_perimeter(grid):
    "Code that calculates the perimeter of an island in a grid"
    perimeter = 0
    height = len(grid)
    width = len(grid[0])

    for indexRow in range(height):
        for indexColumn in range(width):
            if grid[indexRow][indexColumn] == 1:
                if indexRow == 0 or grid[indexRow - 1][indexColumn] == 0:
                    perimeter += 1
                if indexRow == height - 1 or grid[indexRow + 1][indexColumn] == 0:
                    perimeter += 1
                if indexColumn == 0 or grid[indexRow][indexColumn - 1] == 0:
                    perimeter += 1
                if indexColumn == width - 1 or grid[indexRow][indexColumn + 1] == 0:
                    perimeter += 1

    return perimeter
