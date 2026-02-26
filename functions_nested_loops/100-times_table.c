#include "main.h"

static void print_number(int n);

/**
 * print_times_table - prints the n times table, starting with 0
 * @n: number of the times table
 */
void print_times_table(int n)
{
	int i, j;

	if (n < 0 || n > 15)
		return;

	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= n; j++)
		{
			if (j != 0)
			{
				_putchar(',');
				_putchar(' ');
				if (i * j < 100)
					_putchar(' ');
				if (i * j < 10)
					_putchar(' ');
			}
			print_number(i * j);
		}
		_putchar('\n');
	}
}

/**
 * print_number - prints a number from 0 to 225
 * @n: number to print
 */
static void print_number(int n)
{
	if (n >= 100)
		_putchar((n / 100) + '0');
	if (n >= 10)
		_putchar(((n / 10) % 10) + '0');
	_putchar((n % 10) + '0');
}
