#include "main.h"
/**
 * _putchar - prints a char
 * @c: Character to be printed
 * Return: Number of bytes printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - a function which prints a string to stdout
 * @s: a string to print
 *
 * Return: the length of the string
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
 * _calcnumofdigits - Calculates number of digits in a given number
 * @number: Number received
 * Return: Number of digits in number
 */
int _calcnumofdigits(int number)
{
	/* Calculates no of digits in number */
	int dividend = number, divisor;
	int digits = 1;
	/* Add 1 if number is negative */
	if (number < 0)
	{
		digits++;
		dividend = -number;
	}

	divisor = 10;
	while (dividend >= 10)
	{
		dividend = dividend / divisor;
		digits++;
	}
	return (digits);
}

/**
 * numtostr - Stores an integer var passed in a string
 * @num: Integer received
 * @digits: Number of digits in integer
 * @s: Pointer to allocated memory to hold integer string
 * Return: Pointer to string containing number digits
 */
char *numtostr(int num, int digits, char *s)
{
	int i = 0, j = 0, divisor = 1;

	if (num < 0)
	{
		s[i] = '-';
		i++;
		num = -num;
	}
	while (j < digits)
	{
		divisor *= 10;
		j++;
	}
	while (i < digits)
	{
		divisor /= 10;
		s[i] = '0' + (num / divisor) % 10;
		i++;
	}
	s[i] = '\0';
	return (s);
}

/**
 * _printf - a function that produces output according to a format
 * @format: character string that directs the format of the output
 * Return: the number of characters printed, excluding the null byte
 */
int _printf(const char *format, ...)
{	va_list args;
	char *s, *buff;
	int i = 0, count = 0, integer, no_of_digits;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{	case 'c':
					count += _putchar(va_arg(args, int));
					i += 2;
					break;
				case 's':
					s = va_arg(args, char *);
					if (s == NULL)
						s = "(null)";
					count += _puts(s);
					i += 2;
					break;
				case 'i':
				case 'd':
					integer = va_arg(args, int);
					no_of_digits = _calcnumofdigits(integer);
					buff = malloc(sizeof(char) * (no_of_digits + 1));
					if (buff == NULL)
						return (-1);
					_puts(numtostr(integer, no_of_digits, buff));
					count += no_of_digits;
					free(buff);
					i += 2;
					break;
				case '\0':
					return (-1);
				case '%':
					count += _putchar('%');
					i += 2;
					break;
				default:
					count += _putchar(format[i]);
					i++;
					break;
			} continue;
		}
		count += _putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
