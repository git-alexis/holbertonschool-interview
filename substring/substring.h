#ifndef SUBSTRING_H
#define SUBSTRING_H

#include <stdlib.h>

int _strlen(char const *s);
int word_count(char const **words, int nb_words,
	char const *word, int len);
int check_window(char const *s, char const **words,
	int nb_words, int word_len);
int *find_substring(char const *s, char const **words,
	int nb_words, int *n);

#endif
