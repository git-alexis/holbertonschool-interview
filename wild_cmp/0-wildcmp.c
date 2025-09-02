#include "holberton.h"

/**
 * move_until_same_character - Moves the string pointer
 * to the next specified character.
 *
 * @str: Array to change.
 * @character: Specified character.
 *
 * Return: The rest of the string starting with the character.
 */
char *move_until_same_character(char *str, char character)
{
	if (*str == character || *str == '\0')
	{
		return (str);
	}
	else
	{
		return (move_until_same_character(str + 1, character));
	}
}

/**
 * does_contain_other - Checks if the rest of a string
 * contains the specified character
 *
 * @str: Array to verify.
 * @character: Specified character.
 *
 * Return: 1 if the string contains the character, 0 if not.
 */
int does_contain_other(char *str, char character)
{
	if (*str == '\0')
	{
		return (0);
	}
	else if (*str == character)
	{
		return (1);
	}
	else
	{
		return (does_contain_other(str + 1, character));
	}
}

/**
 * move_until_no_star - Moves the string pointer
 * on the next character that is not a star.
 *
 * @str: Array to change.
 *
 * Return: The rest of the string starting with a non-asterisk character.
 */
char *move_until_no_star(char *str)
{
	if (*str == '*')
	{
		return (move_until_no_star(str + 1));
	}
	else
	{
		return (str);
	}
}

/**
 * only_stars - Checks if a string have only stars for content.
 *
 * @str: Array to verify.
 *
 * Return: 1 if the string contains only stars, 0 if not.
 */
int only_stars(char *str)
{
	if (*str == '*')
	{
		return (only_stars(str + 1));
	}
	else if (*str == '\0')
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

/**
 * wildcmp - Compares two strings to see
 * if the strings can be considered identical.
 *
 * @s1: First array to compare.
 * @s2: Second array to compare.
 *
 * Return: 1 if the strings can be considered identical, 0 otherwise.
 */
int wildcmp(char *s1, char *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);

	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == '\0')
		return (only_stars(s2));

	if (*s1 != *s2 && *s2 != '*')
		return (0);

	if (*s2 == '*')
	{
		s2 = move_until_no_star(s2);

		if (*s2 == '\0')
			return (1);

		char *temp = s1;

		if (does_contain_other(temp + 1, *s2) == 1)
			s1 = move_until_same_character(s1 + 1, *s2);

		return (wildcmp(s1, s2));
	}
	else
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}
}
