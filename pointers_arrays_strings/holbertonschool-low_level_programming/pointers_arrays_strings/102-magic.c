#include <stdio.h>

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int a[5];
	int *p;

	p = &n;
	*(p + 8) = 98;

	a[0] = 1024;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;
	a[4] = 5;

	printf("a[2] = %d\n", a[2]);
	return (0);
}
