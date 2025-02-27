#ifndef SANDPILES_H
#define SANDPILES_H

#include <stdio.h>

void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void add_grid(int grid1[3][3], int grid2[3][3]);
int grid_is_stable(int grid[3][3]);
void toppling_grid(int grid[3][3]);
void print_middle_grid(int grid[3][3]);

#endif