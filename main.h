#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int _putchar(char c);
int _puts(char *s);
int _calcnumofdigits(int number);
char *numtostr(int num, int digits, char *s);
int _printf(const char *format, ...);


#endif /* MAIN_H */
