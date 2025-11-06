#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - checks if an unsigned integer is a palindrome.
 *
 * @n: number to check.
 *
 * Return: 1 if n is a palindrome, 0 otherwise.
 */
int is_palindrome(unsigned long n)
{
	unsigned long reversed = 0, temp = n;

	while (temp != 0)
	{
		reversed = reversed * 10 + (temp % 10);
		temp /= 10;
	}

	if (n == reversed)
		return (1);
	return (0);
}
