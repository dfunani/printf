#include "main.h"


/**
 * printStr - prints string
 * @str to print
 *
 */

void printStr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
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
	va_start(ap, format);
	int i;
	char *str;

	i = 0;
	while (format[i])
	{
		if (format[i] == '[' && format[i + 1] == '%')
		{
			while (format[i] != ']')
			{
				if (format[i - 1] == '%')
				{
					switch (format[i])
					{
					case 's':
						str = va_arg(ap, char *);
						printStr(str);
						break;
					}
				}
				i++;
			}

		}
		else
		{
			_putchar(format[i]);
		}
		i++;
	}
	va_end(ap);
	return (0);
}
