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
 * printStr - prints string
 * @str: to print
 *
 * Return: int length
 */

int printStr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
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
	int i, result;

	if (format == NULL || !*format)
	{
		return (0);
	}
	va_start(ap, format);
	i = 0;
	result = 0;
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
						result +=
							printStr(
								va_arg(ap,
								       char *));
						break;

					case 'c':
						_putchar(va_arg(ap, int));
						result++;
						break;

					case '%':
						_putchar('%');
						result++;
						break;
					}
				}
				i++;
			}

		}
		else
		{
			_putchar(format[i]);
			result++;
		}
		i++;
	}
	va_end(ap);
	return (result);
}
