#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - handles username input
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	const char *username;
	size_t i, len;

	if (argc != 2)
		return (1);

	username = argv[1];
	len = strlen(username);

	for (i = 0; i < len; i++)
		putchar(username[i]);

	putchar('\n');

	return (0);
}
