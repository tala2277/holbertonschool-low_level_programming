#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * main - handles username input
 * @argc: number of arguments
 * @argv: arguments vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	char key[7];
	int i, sum;
	char *name;
	char *lookup = "A-CH@n3123456789h";

	if (argc != 2)
		return (1);

	name = argv[1];
	sum = 0;

	for (i = 0; name[i]; i++)
		sum += name[i];

	srand(sum ^ 0x11);

	for (i = 0; i < 6; i++)
		key[i] = lookup[rand() & 0xF];

	key[6] = '\0';
	printf("%s", key);

	return (0);
}
