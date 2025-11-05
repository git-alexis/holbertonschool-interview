#include "regex.h"

/**
 * regex_match - Checks if a pattern matches a string.
 *
 * @str: The string to check.
 * @pattern: The pattern to match.
 *
 * Return: 1 if pattern matches str, 0 otherwise.
 */
int regex_match(const char *str, const char *pattern)
{
	if (!*pattern)
		return (!*str);

	if (*(pattern + 1) == '*')
	{
		if (regex_match(str, pattern + 2))
			return (1);

		if (*str && (*str == *pattern || *pattern == '.'))
			return (regex_match(str + 1, pattern));

		return (0);
	}

	if (*str && (*str == *pattern || *pattern == '.'))
		return (regex_match(str + 1, pattern + 1));

	return (0);
}
