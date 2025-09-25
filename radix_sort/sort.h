#ifndef SORT_H
#define SORT_H

#include <stddef.h>
#include <stdlib.h>

void print_array(const int *array, size_t size);
void radix_sort(int *array, size_t size);
int get_max(int *array, size_t size);
void counting_sort_digit(int *array, size_t size, int position);

#endif
