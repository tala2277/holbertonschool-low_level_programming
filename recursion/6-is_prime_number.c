#include "main.h"

int helper_prime(int n, int i);

/**
 * is_prime_number - checks if a number is prime
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (helper_prime(n, 2));
}

/**
 * helper_prime - checks divisibility recursively
 * @n: number
 * @i: divisor
 *
 * Return: 1 if prime, 0 otherwise
 */
int helper_prime(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (helper_prime(n, i + 1));
}
