#include "sort.h"

/**
 * get_max - Finds the maximum number in an array.
 *
 * @array: The array.
 * @size: Number of elements..
 *
 * Return: The maximum number
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Stable counting sort by a specific digit.
 *
 * @array: The array.
 * @size: Number of elements.
 * @position: The digit position (1, 10, 100, ...).
 */
void counting_sort_digit(int *array, size_t size, int position)
{
	int *output, count[10] = {0};
	size_t i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / position) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size; i > 0; i--)
	{
		output[count[(array[i - 1] / position) % 10] - 1] = array[i - 1];
		count[(array[i - 1] / position) % 10]--;
	}

	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array using LSD radix sort.
 *
 * @array: The array.
 * @size: Number of elements.
 */
void radix_sort(int *array, size_t size)
{
	int max, position;

	if (!array || size < 2)
		return;

	max = get_max(array, size);

	for (position = 1; max / position > 0; position *= 10)
	{
		counting_sort_digit(array, size, position);
		print_array(array, size);
	}
}
