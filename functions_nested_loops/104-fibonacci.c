#include <stdio.h>

/**
 * main - prints the first 98 Fibonacci numbers
 *
 * Return: Always 0
 */
int main(void)
{
	unsigned long a_low = 1, b_low = 2, next_low;
	unsigned long a_high = 0, b_high = 0, next_high;
	unsigned long limit = 10000000000;
	int i;

	printf("1, 2");

	for (i = 3; i <= 98; i++)
	{
		next_low = a_low + b_low;
		next_high = a_high + b_high;

		if (next_low >= limit)
		{
			next_high += next_low / limit;
			next_low %= limit;
		}

		printf(", ");
		if (next_high)
			printf("%lu%010lu", next_high, next_low);
		else
			printf("%lu", next_low);

		a_low = b_low;
		a_high = b_high;
		b_low = next_low;
		b_high = next_high;
	}

	printf("\n");
	return (0);
}
