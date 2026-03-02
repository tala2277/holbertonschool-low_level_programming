#include <stdio.h>

/**
 * main - entry point
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	p = a;

	n = 98;
	a[0] = 0;
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;

	*(p + 5) = 98;

	printf("a[2] = %d\n", a[2]);
	return (0);
}
