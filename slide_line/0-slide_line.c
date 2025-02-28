#include "slide_line.h"

/**
 * shift_left - Moves all numbers to the left, removing zeros
 *
 * @line: Array representing the line of numbers
 * @size: Size of the array
 */
void shift_left(int *line, size_t size)
{
	size_t i, j = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * shift_right - Moves all numbers to the right, removing zeros
 *
 * @line: Array representing the line of numbers
 * @size: Size of the array
 */
void shift_right(int *line, size_t size)
{
	int i;
	size_t j = size - 1;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if ((size_t)i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}

/**
 * merge_left - Merges adjacent equal numbers to the left
 * and sets the merged number's right neighbor to zero
 *
 * @line: Array representing the line of numbers
 * @size: Size of the array
 */
void merge_left(int *line, size_t size)
{
	size_t i;

	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}
}

/**
 * merge_right - Merges adjacent equal numbers to the right
 * and sets the merged number's left neighbor to zero
 *
 * @line: Array representing the line of numbers
 * @size: Size of the array
 */
void merge_right(int *line, size_t size)
{
	int i;

	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}
}

/**
 * slide_line - Slides and merges numbers in a 2048-like fashion
 *
 * @line: Array representing the line of numbers
 * @size: Size of the array
 * @direction: Direction of the slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);

	if (direction == SLIDE_LEFT)
	{
		shift_left(line, size);
		merge_left(line, size);
		shift_left(line, size);
	}
	else
	{
		shift_right(line, size);
		merge_right(line, size);
		shift_right(line, size);
	}

	return (1);
}
