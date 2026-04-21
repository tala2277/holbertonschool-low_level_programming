#include <stdio.h>
#include <stdlib.h>

/**
 * main - handles program arguments
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char *argv[])
{
	if (argc != 2)
		return (1);

	printf("%s\n", argv[1]);

	return (0);
}
