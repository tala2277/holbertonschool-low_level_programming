#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Keygen for crackme5
 * @argc: Number of arguments
 * @argv: Arguments vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char key[7];
	char *lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";
	char *name;
	int len, i, sum = 0, prod = 1, max = 0, sum_sq = 0, r;

	if (argc != 2)
		return (1);

	name = argv[1];

	for (len = 0; name[len]; len++)
		;

	/* key[0] */
	key[0] = lookup[(len ^ 59) & 63];

	/* key[1] */
	for (i = 0; i < len; i++)
		sum += name[i];
	key[1] = lookup[(sum ^ 79) & 63];

	/* key[2] */
	for (i = 0; i < len; i++)
		prod *= name[i];
	key[2] = lookup[(prod ^ 85) & 63];

	/* key[3] */
	max = name[0];
	for (i = 0; i < len; i++)
		if (name[i] > max)
			max = name[i];
	srand(max ^ 14);
	key[3] = lookup[rand() & 63];

	/* key[4] */
	for (i = 0; i < len; i++)
		sum_sq += name[i] * name[i];
	key[4] = lookup[(sum_sq ^ 239) & 63];

	/* key[5] */
	for (i = 0, r = 0; i < name[0]; i++)
		r = rand();
	key[5] = lookup[(r ^ 229) & 63];

	key[6] = '\0';

	printf("%s", key);

	return (0);
}
