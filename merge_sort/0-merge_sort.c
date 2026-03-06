#include "sort.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_subarray - Prints part of an array
 *
 * @array: array
 * @start: start index
 * @size: number of elements
 *
 * Return: Nothing
 */
void print_subarray(int *array, size_t start, size_t size)
{
    size_t index;

    for (index = 0; index < size; index++)
    {
        if (index)
            printf(", ");
        printf("%d", array[start + index]);
    }
    printf("\n");
}

/**
 * merge - Merges two sorted subarrays
 *
 * @array: array containing the subarrays
 * @buffer: temporary buffer used for merging
 * @left: start index of the left subarray
 * @mid: start index of the right subarray
 * @right: end index of the right subarray
 *
 * Return: Nothing
 */
void merge(int *array, int *buffer, size_t left, size_t middle, size_t right)
{
    size_t indexLeftSub = left, indexRightSub = middle, indexBuffer = left;

    printf("Merging...\n[left]: ");
    print_subarray(array, left, middle - left);

    printf("[right]: ");
    print_subarray(array, middle, right - middle);

    while (indexLeftSub < middle && indexRightSub < right)
    {
        if (array[indexLeftSub] <= array[indexRightSub])
            buffer[indexBuffer++] = array[indexLeftSub++];
        else
            buffer[indexBuffer++] = array[indexRightSub++];
    }

    while (indexLeftSub < middle)
        buffer[indexBuffer++] = array[indexLeftSub++];

    while (indexRightSub < right)
        buffer[indexBuffer++] = array[indexRightSub++];

    for (indexLeftSub = left; indexLeftSub < right; indexLeftSub++)
        array[indexLeftSub] = buffer[indexLeftSub];

    printf("[Done]: ");
    print_subarray(array, left, right - left);
}

/**
 * merge_recursive - Recursively divides and sorts the array
 *
 * @array: array to sort
 * @buffer: temporary buffer used for merging
 * @left: start index of the current section
 * @right: end index of the current section
 *
 * Return: Nothing
 */
void merge_recursive(int *array, int *buffer, size_t left, size_t right)
{
    size_t middle;

    if (right - left < 2)
        return;

    middle = left + (right - left) / 2;

    merge_recursive(array, buffer, left, middle);
    merge_recursive(array, buffer, middle, right);

    merge(array, buffer, left, middle, right);
}

/**
 * merge_sort - Sorts an array of integers using the Merge Sort algorithm
 *
 * @array: array to sort
 * @size: number of elements in the array
 *
 * Return: Nothing
 */
void merge_sort(int *array, size_t size)
{
    int *buffer;

    if (!array || size < 2)
        return;

    buffer = malloc(sizeof(int) * size);
    if (!buffer)
        return;

    merge_recursive(array, buffer, 0, size);

    free(buffer);
}
