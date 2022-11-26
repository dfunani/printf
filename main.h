#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>

/**
* struct specifiers - defines a structure for symbols and functions
*
* @spec: The operator
* @func: The function associated
*
*/

typedef struct specifiers
{
	char *spec;
	int (*func)(va_list);
} specifiers;

int _printf(const char *format, ...);
int printStr(va_list list);
int printChar(va_list list);
int printPercent(va_list list);
int _putchar(char c);
int manager(const char *str, va_list list, specifiers funcs[]);
int printInteger(va_list args);
int printBinary(va_list list);

#endif
