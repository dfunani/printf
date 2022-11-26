#include "main.h"

/**
 * printUnsigned - func printing int pos only
 * @list: list to print
 *
 * Return: len
 *
 */

int printUnsigned(va_list list)
{
	int num, dividend, res;

	res = 0, dividend = 1;
	num = va_arg(list, unsigned int);
	if (num < 0)
		return (-1);
	while (num / dividend < 9)
		dividend *= 10;
	while (dividend != 0)
	{
		res += _putchar(num / dividend + 48);
		num %= dividend;
		dividend /= 10;
	}
	return (res);
}
