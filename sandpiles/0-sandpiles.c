#include "sandpiles.h"

/**
 * add_grid - Adds grid2 to grid1 element by element
 *
 * @grid1: First grid
 * @grid2: Second grid to add
 */

void add_grid(int grid1[3][3], int grid2[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid1[i][j] += grid2[i][j];
}

/**
 * grid_is_stable - Checks whether the grid is stable
 *
 * @grid: The grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */

int grid_is_stable(int grid[3][3])
{
    int i, j;

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            if (grid[i][j] > 3)
                return (0);
    return (1);
}

/**
 * toppling_grid - Performs toppling on the grid
 *
 * @grid: The grid to modify
 */

void toppling_grid(int grid[3][3])
{
    int i, j;
    int temp[3][3] = {0};

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
            {
                temp[i][j] -= 4;
                if (i > 0) temp[i - 1][j] += 1;
                if (i < 2) temp[i + 1][j] += 1;
                if (j > 0) temp[i][j - 1] += 1;
                if (j < 2) temp[i][j + 1] += 1;
            }
        }
    }

    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            grid[i][j] += temp[i][j];
}

/**
 * print_grid - Displays a 3x3 grid
 *
 * @grid: The grid to display
 */

void print_middle_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j > 0)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * sandpiles_sum - Calculates the sum of two sandpiles and stabilises the result
 *
 * @grid1: First grid
 * @grid2: Second grid to be added
 */

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    add_grid(grid1, grid2);

    while (!grid_is_stable(grid1))
    {
        print_middle_grid(grid1);
        toppling_grid(grid1);
    }
}
