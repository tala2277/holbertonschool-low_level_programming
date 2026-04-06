#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_c - print char
 */
void print_c(va_list args, char *sep)
{
	printf("%s%c", sep, va_arg(args, int));
}

/**
 * print_i - print int
 */
void print_i(va_list args, char *sep)
{
	printf("%s%d", sep, va_arg(args, int));
}

/**
 * print_f - print float
 */
void print_f(va_list args, char *sep)
{
	printf("%s%f", sep, va_arg(args, double));
}

/**
 * print_s - print string
 */
void print_s(va_list args, char *sep)
{
	char *str = va_arg(args, char *);
	printf("%s%s", sep, str ? str : "(nil)");
}

/**
 * print_all - prints anything
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
	char *sep = "";

	void (*funcs[])(va_list, char *) = {
		print_c, print_i, print_f, print_s
	};

	char types[] = {'c', 'i', 'f', 's'};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				funcs[j](args, sep);
				sep = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
