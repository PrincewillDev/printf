#include "main.h"

/**
 * _putchar - This function prints character to std output
 * @c: the character argument
 * Return: 1 (success)
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}
