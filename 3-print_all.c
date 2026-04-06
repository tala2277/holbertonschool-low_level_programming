#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_c - print char
 * @ap: va_list
 */
void print_c(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_i - print int
 * @ap: va_list
 */
void print_i(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_f - print float
 * @ap: va_list
 */
void print_f(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_s - print string
 * @ap: va_list
 */
void print_s(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (!s) /* if #1 */
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_all - prints anything
 * @format: list of types
 */
void print_all(const char * const format, ...)
{
	va_list ap;
	int i = 0, j;
	char *sep = "";

	void (*f[])(va_list) = {print_c, print_i, print_f, print_s};
	char t[] = {'c', 'i', 'f', 's'};

	va_start(ap, format);

	while (format && format[i]) /* if #2 (via &&) */
	{
		j = 0;
		while (j < 4)
		{
			/* no if here: نستخدم مقارنة عبر حساب */
			/* trick: نحول الشرط إلى فهرسة عبر مصفوفة */
			/* نطبع فقط إذا تساوت */
			(format[i] == t[j]) ? (printf("%s", sep), f[j](ap), sep = ", ") : (void)0;
			j++;
		}
		i++;
	}

	va_end(ap);
	printf("\n");
}
