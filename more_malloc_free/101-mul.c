#include "main.h"
#include <stdlib.h>

/**
 * error_exit - prints Error and exits
 * @result: pointer to free
 */
void error_exit(int *result)
{
	if (result)
		free(result);

	_putchar('E');
	_putchar('r');
	_putchar('r');
	_putchar('o');
	_putchar('r');
	_putchar('\n');
	exit(98);
}

/**
 * _strlen - returns length of string
 * @s: string
 *
 * Return: length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i])
		i++;
	return (i);
}

/**
 * is_digit - checks if string contains digits only
 * @s: string
 *
 * Return: 1 or 0
 */
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

/**
 * print_result - prints result
 * @result: array
 * @size: size
 */
void print_result(int *result, int size)
{
	int i = 0;

	while (i < size && result[i] == 0)
		i++;

	if (i == size)
	{
		_putchar('0');
		_putchar('\n');
		return;
	}

	while (i < size)
	{
		_putchar(result[i] + '0');
		i++;
	}
	_putchar('\n');
}

/**
 * main - multiplies two numbers
 * @argc: count
 * @argv: args
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *num1;
	char *num2;
	int len1;
	int len2;
	int len;
	int i;
	int j;
	int mul;
	int carry;
	int *result;

	if (argc != 3)
		error_exit(NULL);

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		error_exit(NULL);

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		error_exit(NULL);

	i = 0;
	while (i < len)
	{
		result[i] = 0;
		i++;
	}

	i = len1 - 1;
	while (i >= 0)
	{
		carry = 0;
		j = len2 - 1;

		while (j >= 0)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			mul += result[i + j + 1] + carry;
			result[i + j + 1] = mul % 10;
			carry = mul / 10;
			j--;
		}
		result[i] += carry;
		i--;
	}

	print_result(result, len);
	free(result);

	return (0);
}
