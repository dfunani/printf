#include "main.h"

/**
 * printDecimal - print dec
 * @list: va list
 *
 * Return: -1 or len
 *
 */

int printInteger(va_list list)
{
	int rev, mod, i, res;

	rev = 0;
	i = va_arg(list, int);
	if (i < 0)
	{
		res =+ _putchar('-');
		i *= -1;
	}
	while (i != 0)
	{
		mod = i % 10;
		rev = (rev * 10) + mod;
		i /= 10;
	}
	while (rev != 0)
	{
		res += _putchar((rev % 10) + 48);
		rev /= 10;
	}
	return (res);
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
	return (_putchar(va_arg(list, int)));
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
	return (_putchar('%'));
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
		str = "(null)";
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	return (i);
}
