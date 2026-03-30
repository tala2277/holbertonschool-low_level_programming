#include "main.h"

int helper_sqrt(int n, int i);

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate square root
 *
 * Return: natural square root or -1
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (helper_sqrt(n, 0));
}

/**
 * helper_sqrt - helper function to find square root
 * @n: number
 * @i: iterator
 *
 * Return: square root or -1
 */
int helper_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (helper_sqrt(n, i + 1));
}
