#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - write a character to stdout
 *
 * @arg: the character to print
 * @count: the count of chracters printed
 */
void print_char(va_list arg, int *count)
{
	char c = va_arg(arg, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * print_str - write a string to stdout
 *
 * @arg: string to print
 * @count: the count of characters printed
 */
void print_str(va_list arg, int *count)
{
	char *s = va_arg(arg, char *);

	for (; *s; s++)
	{
		write(1, s, 1);
		(*count)++;
	}
}

/**
 * print_percent - write a percent symbol to stdout
 *
 * @arg: unused
 * @count: the count of characters printed
 */
void print_percent(va_list arg, int *count)
{
	(void)arg;
	write(1, "%", 1);
	(*count)++;
}

/**
 * _printf - print formatted output to stdout
 *
 * @format: format string
 *
 * Return: the number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...);
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				print_char(args, &count);
			}
			else if (*format == 's')
			{
				print_str(args, &count);
			}
			else if (*format == '%')
			{
				print_percent(args, &count);
			}
			else
			{
				write(1, "%", 1);
				count++;
				if (*format)
				{
					write(1, format, 1);
					count++;
				}
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}
