#ifndef SORT_H
#define SORT_H

#include <stddef.h>

void print_subarray(int *array, size_t start, size_t size);
void merge(int *array, int *buffer, size_t left, size_t mid, size_t right);
void merge_recursive(int *array, int *buffer, size_t left, size_t right);
void merge_sort(int *array, size_t size);
void print_array(const int *array, size_t size);

#endif /* SORT_H */
