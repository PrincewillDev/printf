#include "main.h"

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
