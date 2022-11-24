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

#endif
