#include <stdio.h>

/**
 * main - prints combinations of single digits
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

		if (n != 9)
		{
			putchar(',');
			putchar(' ');
		}

		n = n + 1;
	}

	putchar('\n');

	return (0);
}
