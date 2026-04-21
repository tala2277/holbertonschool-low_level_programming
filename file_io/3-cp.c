#include "main.h"
#include <stdio.h>

/**
 * close_file - closes a file descriptor
 * @fd: file descriptor to close
 *
 * Return: nothing
 */
void close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * open_source - opens source file for reading
 * @filename: source file name
 *
 * Return: file descriptor
 */
int open_source(char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (fd);
}

/**
 * open_dest - opens destination file for writing
 * @filename: destination file name
 *
 * Return: file descriptor
 */
int open_dest(char *filename)
{
	int fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (fd);
}

/**
 * copy_content - copies content from one file to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @file_to: destination file name
 * @file_from: source file name
 *
 * Return: nothing
 */
void copy_content(int fd_from, int fd_to, char *file_to, char *file_from)
{
	ssize_t rd, wr;
	char buffer[1024];

	rd = read(fd_from, buffer, 1024);
	while (rd > 0)
	{
		wr = write(fd_to, buffer, rd);
		if (wr == -1 || wr != rd)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file_to);
			exit(99);
		}
		rd = read(fd_from, buffer, 1024);
	}
	if (rd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file_from);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @argc: number of arguments
 * @argv: array of arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fd_from, fd_to;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	fd_from = open_source(argv[1]);
	fd_to = open_dest(argv[2]);
	copy_content(fd_from, fd_to, argv[2], argv[1]);
	close_file(fd_from);
	close_file(fd_to);

	return (0);
}
