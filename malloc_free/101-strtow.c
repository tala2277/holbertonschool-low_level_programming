#include "main.h"
#include <stdlib.h>

/**
 * count_words - counts number of words
 * @str: string
 *
 * Return: number of words
 */
int count_words(char *str)
{
	int i = 0, count = 0;

	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			count++;
		i++;
	}
	return (count);
}

/**
 * strtow - splits a string into words
 * @str: string
 *
 * Return: array of words or NULL
 */
char **strtow(char *str)
{
	char **words;
	int i = 0, j, k, w = 0, start, len;

	if (str == NULL || str[0] == '\0')
		return (NULL);

	len = count_words(str);
	if (len == 0)
		return (NULL);

	words = malloc(sizeof(char *) * (len + 1));
	if (words == NULL)
		return (NULL);

	while (str[i])
	{
		if (str[i] != ' ')
		{
			start = i;
			while (str[i] && str[i] != ' ')
				i++;

			words[w] = malloc(sizeof(char) * (i - start + 1));
			if (words[w] == NULL)
				return (NULL);

			for (j = start, k = 0; j < i; j++, k++)
				words[w][k] = str[j];

			words[w][k] = '\0';
			w++;
		}
		else
			i++;
	}

	words[w] = NULL;

	return (words);
}
