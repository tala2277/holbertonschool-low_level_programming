#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - handles username input
 * @argc: number of arguments
 * @argv: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	const char *username;
	size_t i;

	if (argc != 2)
		return (1);

	username = argv[1];

	for (i = 0; username[i] != '\0'; i++)
		putchar(username[i]);

	putchar('\n');

	return (0);
}
