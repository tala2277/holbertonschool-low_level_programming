#include <stdio.h>

/**
 * main - prints numbers from 0 to 9
 *
 * Return: Always 0
 */
int main(void)
{
	int n;

	n = 0;

	while (n <= 9)
	{
		printf("%d", n);
		n = n + 1;
	}

	printf("\n");

	return (0);
}
