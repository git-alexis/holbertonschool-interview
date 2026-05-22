#include <string.h>

#include "substring.h"

/**
 * _strlen - Returns the length of a string
 *
 * @s: The string
 *
 * Return: Length of the string
 */
int _strlen(char const *s)
{
	int len;

	len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * word_count - Counts occurrences of a word in words array
 *
 * @words: Array of words
 * @nb_words: Number of words
 * @word: Word to count
 * @len: Length of the word
 *
 * Return: Number of occurrences
 */
int word_count(char const **words, int nb_words,
	char const *word, int len)
{
	int i;
	int count;

	count = 0;

	for (i = 0; i < nb_words; i++)
	{
		if (strncmp(words[i], word, len) == 0)
			count++;
	}

	return (count);
}

/**
 * check_window - Checks whether a substring is valid
 *
 * @s: Substring to check
 * @words: Array of words
 * @nb_words: Number of words
 * @word_len: Length of each word
 *
 * Return: 1 if valid, 0 otherwise
 */
int check_window(char const *s, char const **words,
	int nb_words, int word_len)
{
	int i;
	int j;
	int count_found;
	char const *current;

	for (i = 0; i < nb_words; i++)
	{
		count_found = 0;

		for (j = 0; j < nb_words; j++)
		{
			current = &s[j * word_len];

			if (strncmp(words[i], current, word_len) == 0)
				count_found++;
		}

		if (count_found !=
			word_count(words, nb_words, words[i], word_len))
			return (0);
	}

	return (1);
}

/**
 * find_substring - Finds all concatenated substrings
 *
 * @s: String to scan
 * @words: Array of words
 * @nb_words: Number of words
 * @n: Stores the number of results
 *
 * Return: Array of indices
 */
int *find_substring(char const *s, char const **words,
	int nb_words, int *n)
{
	int *result;
	int s_len;
	int word_len;
	int total_len;
	int i;
	int count;

	*n = 0;

	if (!s || !words || nb_words <= 0)
		return (NULL);

	word_len = _strlen(words[0]);
	total_len = word_len * nb_words;
	s_len = _strlen(s);

	result = malloc(sizeof(int) * s_len);

	if (!result)
		return (NULL);

	count = 0;

	for (i = 0; i <= s_len - total_len; i++)
	{
		if (check_window(s + i, words, nb_words, word_len))
		{
			result[count] = i;
			count++;
		}
	}

	*n = count;

	return (result);
}
