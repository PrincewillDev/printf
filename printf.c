#include "main.h"

/**
 * _putchar - Prints a single character
 * @c: Character to be printed
 *
 * Return: Number of bytes printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
	B
}

/**
 * B
 * _puts - a function which prints a string to stdout
 * @s: a string to print
 *
 * Return: the length of the string
 * A
 */
int _puts(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		_putchar(s[i]);
		i++;
	}
	return (i);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string that directs the format of the output
 * Return: the number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{	va_list args;
	char *s;
	int i = 0, count = 0, d;

	va_start(args, format);
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					i += 2;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "null";
					count += _puts(s);
					i += 2;
					break;
				case 'i':
				case 'd':
					d = va_arg(args, int);
					count += _puts(d);

					i += 2;
					break;
				case '%':
					count += _putchar('%');
					i += 2;
					break;
				default:
					count += _putchar(format[i]);
					i++;

			continue;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
