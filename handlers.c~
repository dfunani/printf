#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * printChar - prints a char
 * @list: list to print
 *
 * Return: int len of chars
 *
 */

int printChar(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * printPercent - print %
 * @list: list to print
 *
 * Return: int len
 *
 */

int printPercent(__attribute__((unused))va_list list)
{
	_putchar('%');
	return (1);
}

/**
 * printStr - prints string
 * @list: to print
 *
 * Return: int length
 */

int printStr(va_list list)
{
	int i;
	char *str;

	i = 0;
	str = va_arg(list, char *);
	if (str == NULL)
		str = "(nil)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}

int manager(const char *str, va_list list, specifiers funcs[])
{
	int i, j, res;

	res = 0;
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '%')
		{
			for (j = 0; funcs[j].spec != NULL; j++)
			{
				if (funcs[j].spec[0] == str[i + 1])
				{
					res += funcs[j].func(list);
					break;
				}
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
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = manager(format, ap, array);
	va_end(ap);
	return (result);
}
