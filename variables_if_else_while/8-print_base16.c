#include <stdio.h>

/**
 * main - prints numbers in base 16
 *
 * Return: Always 0
 */
int main(void)
{
	int n;
	char c;

	n = 0;
	while (n <= 9)
	{
		putchar(n + '0');
		n = n + 1;
	}

	c = 'a';
	while (c <= 'f')
	{
		putchar(c);
		c = c + 1;
	}

	putchar('\n');

	return (0);
}
