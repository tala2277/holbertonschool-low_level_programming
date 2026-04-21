#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - Generates a key for crackme5.
 * @argc: The number of arguments.
 * @argv: The arguments vector.
 *
 * Return: 0 on success, 1 on error.
 */
int main(int argc, char *argv[])
{
	char *u;
	char k[7];
	int l, i, s = 0, p = 1, m, sq = 0, r;
	char *lookup = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789./";

	if (argc != 2)
		return (1);

	u = argv[1];
	for (l = 0; u[l]; l++)
		;

	/* Key[0] */
	k[0] = lookup[(l ^ 59) & 63];
	/* Key[1] */
	for (i = 0; i < l; i++)
		s += u[i];
	k[1] = lookup[(s ^ 79) & 63];
	/* Key[2] */
	for (i = 0; i < l; i++)
		p *= u[i];
	k[2] = lookup[(p ^ 85) & 63];
	/* Key[3] */
	m = u[0];
	for (i = 0; i < l; i++)
		if (u[i] > m)
			m = u[i];
	srand(m ^ 14);
	k[3] = lookup[rand() & 63];
	/* Key[4] */
	for (i = 0; i < l; i++)
		sq += u[i] * u[i];
	k[4] = lookup[(sq ^ 239) & 63];
	/* Key[5] */
	for (i = 0, r = 0; i < u[0]; i++)
		r = rand();
	k[5] = lookup[(r ^ 229) & 63];

	k[6] = '\0';
	printf("%s", k);
	return (0);
}
