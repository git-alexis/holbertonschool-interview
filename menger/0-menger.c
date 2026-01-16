#include <stdio.h>
#include <math.h>

/**
 * is_filled - Determines the content of the current position
 *
 * @level: Level number of the Menger Sponge
 * @line: Line number
 * @column: Column number
 *
 * Return: 1 if position have to be filled or 0 if he should be empty
 */
int is_filled(int level, int line, int column)
{
	int pos_line;
	int pos_column;

	pos_line = line % 3;
	pos_column = column % 3;

	if (level == 0)
		return (1);
	if ((pos_line == 1) && (pos_column == 1))
		return (0);

	return (is_filled(level - 1, line / 3, column / 3));
}

/**
 * menger - Draws a 2D version of the Menger sponge
 *
 * @level: Level number of the Menger Sponge
 *
 * Return: Nothing
 */
void menger(int level)
{
	int size = pow(3, level);
	int line, column;

	for (line = 0; line < size; line++)
	{
		for (column = 0; column < size; column++)
		{
			if (is_filled(level, line, column))
			{
				putchar('#');
			}
			else
			{
				putchar(' ');
			}
		}
		putchar('\n');
	}
}
