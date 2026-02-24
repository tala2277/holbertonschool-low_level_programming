#include <stdio.h>

/**
 * main - prints numbers from 0 to 9 using putchar
 *
 * Return: Always 0
 */
int main(void)
{
	int n;

	n = 0;

	while (n <= 9)
	{
		putchar(n + '0');
		n = n + 1;
	}

	putchar('\n');

	return (0);
}
