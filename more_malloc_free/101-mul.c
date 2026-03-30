#include "main.h"
#include <stdlib.h>

int _putchar(char c);

int _isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

void _error(void)
{
	char *err = "Error\n";
	int i = 0;

	while (err[i])
	{
		_putchar(err[i]);
		i++;
	}
	exit(98);
}

int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

int main(int argc, char *argv[])
{
	char *n1, *n2;
	int len1, len2, i, j, carry, n1d, n2d;
	int *res;
	int start = 0;

	if (argc != 3)
		_error();

	n1 = argv[1];
	n2 = argv[2];

	for (i = 0; n1[i]; i++)
		if (!_isdigit(n1[i]))
			_error();

	for (i = 0; n2[i]; i++)
		if (!_isdigit(n2[i]))
			_error();

	len1 = _strlen(n1);
	len2 = _strlen(n2);

	res = malloc(sizeof(int) * (len1 + len2));
	if (!res)
		exit(1);

	for (i = 0; i < len1 + len2; i++)
		res[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		n1d = n1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2d = n2[j] - '0';
			carry += res[i + j + 1] + (n1d * n2d);
			res[i + j + 1] = carry % 10;
			carry /= 10;
		}
		res[i + j + 1] += carry;
	}

	while (start < len1 + len2 - 1 && res[start] == 0)
		start++;

	for (; start < len1 + len2; start++)
		_putchar(res[start] + '0');
	_putchar('\n');

	free(res);
	return (0);
}
