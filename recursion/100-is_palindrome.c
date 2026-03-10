#include "main.h"

int check_pal(char *s, int start, int end);
int str_len(char *s);

/**
 * is_palindrome - checks if a string is a palindrome
 * @s: string to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(char *s)
{
	int len = str_len(s);

	return (check_pal(s, 0, len - 1));
}

/**
 * str_len - gets length of string
 * @s: string
 * Return: length
 */
int str_len(char *s)
{
	if (*s == '\0')
		return (0);

	return (1 + str_len(s + 1));
}

/**
 * check_pal - helper to check palindrome
 * @s: string
 * @start: start index
 * @end: end index
 * Return: 1 if palindrome, 0 otherwise
 */
int check_pal(char *s, int start, int end)
{
	if (start >= end)
		return (1);
	if (s[start] != s[end])
		return (0);

	return (check_pal(s, start + 1, end - 1));
}
