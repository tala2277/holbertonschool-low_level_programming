#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0, j;
	char *sep = "";

	char types[] = {'c', 'i', 'f', 's'};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;
		while (j < 4)
		{
			if (format[i] == types[j])
			{
				printf("%s", sep);

				if (j == 0)
					printf("%c", va_arg(args, int));
				if (j == 1)
					printf("%d", va_arg(args, int));
				if (j == 2)
					printf("%f", va_arg(args, double));
				if (j == 3)
				{
					char *str = va_arg(args, char *);
					printf("%s", str ? str : "(nil)");
				}

				sep = ", ";
			}
			j++;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}
