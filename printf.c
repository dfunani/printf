#include "main.h"

/**
 * manager - writes the character c to stdout
 * @str: The character to print
 * @list: list toprint
 * @funcs: funcs to run
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int manager(const char *str, va_list list, specifiers funcs[])
{
	int i, j, res, trav;

	res = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%')
		{
			for (j = 0; funcs[j].spec != NULL; j++)
			{
				if (funcs[j].spec[0] == str[i + 1])
				{
					trav = funcs[j].func(list);
					if (trav == -1)
						return (-1);
					res += trav;
					break;
				}
			}
			if (funcs[j].spec == NULL && str[i + 1] != ' ')
			{
				if (str[i + 1] != '\0')
				{
					_putchar(str[i]);
					_putchar(str[i + 1]);
					res += 2;
				}
				else
					return (-1);
			}
			i++;
		}
		else
		{
			_putchar(str[i]);
			res++;
		}
	}
	return (res);
}

/**
 * _printf - an implementation of printf
 * @format: what to print and how
 *
 * Return: Status int
 *
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int result;
	specifiers array[] = {
		{"s", printStr},
		{"c", printChar},
		{"%", printPercent},
		{"d", printInteger},
		{"i", printInteger},
		{"b", printBinary},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = manager(format, ap, array);
	va_end(ap);
	return (result);
}
