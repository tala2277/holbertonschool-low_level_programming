#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: string to convert
 *
 * Return: integer value
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int res = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && started == 0)
			sign = -sign;
		else if (s[i] == '+' && started == 0)
			;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			/* build as negative to avoid overflow (handles INT_MIN) */
			res = res * 10 - (s[i] - '0');
		}
		else if (started == 1)
			break;

		i++;
	}

	if (sign > 0)
		return (-res);
	return (res);
}
