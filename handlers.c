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
	int i, res, rev;
	unsigned int num;

	res = 0, rev = 1;
	i = va_arg(list, int);
	if (i < 0)
	{
		res += _putchar('-');
		num = i * -1;
	}
	else
		num = i;
	while (num / rev > 9)
	{
		rev *= 10;
	}
	while (rev != 0)
	{
		res += _putchar(48 + (num / rev));
		num %= rev;
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
