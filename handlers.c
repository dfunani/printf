#include "main.h"

/**
 * printInteger - print dec
 * @list: va list
 *
 * Return: -1 or len
 *
 */

int printInteger(va_list list)
{
	int rev, i, res, j;

	rev = 1, res = 0;
	j = va_arg(list, int);
	if (j < 0)
	{
		res += _putchar('-');
		i = j * -1;
	}
	else
		i = j;
	while (i / rev > 9)
		rev *= 10;
	while (rev != 0)
	{
		res += _putchar(48 + i / rev);
		i %= rev;
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
