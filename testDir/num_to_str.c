#include <stdio.h>
#include <stdlib.h>

/**
 * _calcnumdigits - Calculates number of digits in a given number
 * @number - Number received
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
 * @num - Integer received
 * @digits - Number of digits in integer
 * Return: Pointer to string containing number digits
 */

char *numtostr(int num, int digits, char *s)
{
	int i = 0, divisor = 1;

	if (num < 0)
	{
		s[i] = '-';
		i++;
		num = -num;
	}
	while (i < digits)
	{
		divisor *= 10;
		i++;
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
 * main - Prints a string
 * Return: 0 if success
 */
int main(void)
{
	int salary = -14510;
	int no = _calcnumofdigits(salary);
	char *buff = malloc(sizeof(char) * (no + 1));

	if (buff == NULL)
	{
		printf("Error: Malloc failed");
		return (-1);
	}
	printf("%d\n", no);
	printf("%s\n", numtostr(salary, no, buff));
	free(buff);

	return (0);
}
