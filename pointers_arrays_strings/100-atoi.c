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
	int result = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' && started == 0)
			sign = -sign;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			started = 1;
			result = result * 10 + (s[i] - '0');
		}
		else if (started == 1)
			break;

		i++;
	}

	return (result * sign);
}
