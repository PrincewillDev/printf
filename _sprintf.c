#include <stdio.h>
#include <stdarg.h>

/**
 * _sprintf - Formats and prints data to a string
 * @str: The string buffer to write to
 * @format: The format string
 * @...: Optional arguments to format
 *
 * Return: The number of characters written to the buffer, excluding the null
 * byte, or -1 if an unsupported conversion specifier was encountered
 */
int _sprintf(char *str, const char *format, ...)
{
	va_list args;
	int num, written = 0, i = 0;
	char *s;

	if (str == NULL)
		return (-1);
	if (format == NULL)
	{
		str[0] = '\0';
		return (0);
	}
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == 'd' || format[i] == 'i' )
			{
				num = va_arg(args, int);
				written += sprintf(str + written, "%d", num);
			}
			else if (format[i] == 's')
			{
				s = va_arg(args, char *);
				written += sprintf(str + written, "%s", s);
			}
			else
				return (-1);
		}
		else
			str[written++] = format[i];
		i++;	}
	str[written] = '\0';
	va_end(args);
	return (written);
}
