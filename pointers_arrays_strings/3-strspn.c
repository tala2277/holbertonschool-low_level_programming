#include "main.h"

/**
 * _strspn - gets length of prefix substring
 * @s: string to search
 * @accept: accepted bytes
 *
 * Return: number of bytes in the initial segment
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i, j, found, count = 0;

	for (i = 0; s[i] != ', '; i++)
	{
		found = 0;
		for (j = 0; accept[j] != ', '; j++)
		{
			if (s[i] == accept[j])
			{
				found = 1;
				break;
			}
		}
		if (!found)
			break;
		count++;
	}
	return (count);
}
