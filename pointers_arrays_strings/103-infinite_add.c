#include "main.h"

/**
 * infinite_add - adds two numbers stored as strings
 * @n1: first number
 * @n2: second number
 * @r: result buffer
 * @size_r: buffer size
 *
 * Return: pointer to result or 0 if it can't fit
 */
char *infinite_add(char *n1, char *n2, char *r, int size_r)
{
	int i, j, k, carry = 0, sum;
	int len1 = 0, len2 = 0, max;

	while (n1[len1])
		len1++;
	while (n2[len2])
		len2++;

	max = (len1 > len2 ? len1 : len2) + 1;

	if (size_r <= max)
		return (0);

	r[size_r - 1] = '\0';
	i = len1 - 1;
	j = len2 - 1;
	k = size_r - 2;

	while (i >= 0 || j >= 0 || carry)
	{
		sum = carry;

		if (i >= 0)
			sum += n1[i--] - '0';
		if (j >= 0)
			sum += n2[j--] - '0';

		carry = sum / 10;
		r[k--] = (sum % 10) + '0';
	}

	return (r + k + 1);
}
