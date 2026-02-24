#include <stdio.h>

/**
 * main - prints alphabet except e and q
 *
 * Return: Always 0
 */
int main(void)
{
	char c;

	c = 'a';

	while (c <= 'z')
	{
		if (c != 'e' && c != 'q')
			putchar(c);
		c = c + 1;
	}

	putchar('\n');

	return (0);
}
