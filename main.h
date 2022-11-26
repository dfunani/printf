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
int printUnsigned(va_list);
int printOctal(va_list);
int printHex(va_list);
int printHeX(va_list);
char *_memcpy(char *dest, char *src, unsigned int n);
unsigned int _len(unsigned int num, int base);
char *_rev(char *s);
int hex_check(int num, char x);
void write_base(char *str);

#endif
