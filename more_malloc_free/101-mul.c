#include "main.h"
#include <stdlib.h>

int _putchar(char c);

void error_exit(void)
{
	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

int _strlen(char *s)
{
	int i = 0;
	while (s[i])
		i++;
	return (i);
}

int is_digit(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void print_number(int *res, int len)
{
	int i = 0;

	while (i < len && res[i] == 0)
		i++;

	if (i == len)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}

	while (i < len)
	{
		_putchar(res[i] + '0');
		i++;
	}
	_putchar('\n');
}

int main(int argc, char *argv[])
{
	char *n1, *n2;
	int len1, len2, len, i, j, carry, mul;
	int *res;

	if (argc != 3)
		error_exit();

	n1 = argv[1];
	n2 = argv[2];

	if (!is_digit(n1) || !is_digit(n2))
		error_exit();

	len1 = _strlen(n1);
	len2 = _strlen(n2);
	len = len1 + len2;

	res = malloc(sizeof(int) * len);
	if (res == NULL)
		error_exit();

	for (i = 0; i < len; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (n1[i] - '0') * (n2[j] - '0');
			mul += res[i + j + 1] + carry;
			res[i + j + 1] = mul % 10;
			carry = mul / 10;
		}
		res[i] += carry;
	}

	print_number(res, len);
	free(res);
	return (0);
}
