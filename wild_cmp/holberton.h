#ifndef WILD_COMPARE
#define WILD_COMPARE

#include <stdio.h>

int only_stars(char *s2);
char *move_until_no_star(char *s2);
int does_contain_other(char *str, char character);
char *move_until_same_character(char *s1, char character);
int wildcmp(char *s1, char *s2);

#endif
