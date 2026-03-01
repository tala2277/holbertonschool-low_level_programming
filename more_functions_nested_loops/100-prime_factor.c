#include <stdio.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0.
 */
int main(void)
{
	unsigned long n = 612852475143;
	unsigned long factor = 2;
	unsigned long last_factor = 1;

	while (n > 1)
	{
		if (n % factor == 0)
		{
			last_factor = factor;
			n /= factor;
			while (n % factor == 0)
				n /= factor;
		}
		factor++;
	}

	printf("%lu\n", last_factor);
	return (0);
}
