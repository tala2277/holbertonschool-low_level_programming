#include "main.h"
#include <stdlib.h>

/**
 * print_error - prints Error and exits
 */
void print_error(int *result)
{
	if (result != NULL)
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
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/**
 * is_digit - checks if string contains only digits
 * @s: string
 *
 * Return: 1 if all digits, 0 otherwise
 */
int is_digit(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * print_result - prints number stored in array
 * @result: result array
 * @size: size of array
 */
void print_result(int *result, int size)
{
	int i;

	i = 0;
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
 * main - multiplies two positive numbers
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success
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
		print_error(NULL);

	num1 = argv[1];
	num2 = argv[2];

	if (!is_digit(num1) || !is_digit(num2))
		print_error(NULL);

	len1 = _strlen(num1);
	len2 = _strlen(num2);
	len = len1 + len2;

	result = malloc(sizeof(int) * len);
	if (result == NULL)
		print_error(NULL);

	for (i = 0; i < len; i++)
		result[i] = 0;

	for (i = len1 - 1; i >= 0; i--)
	{
		carry = 0;
		for (j = len2 - 1; j >= 0; j--)
		{
			mul = (num1[i] - '0') * (num2[j] - '0');
			mul += result[i + j + 1] + carry;
			result[i + j + 1] = mul % 10;
			carry = mul / 10;
		}
		result[i] += carry;
	}

	print_result(result, len);
	free(result);

	return (0);
}
