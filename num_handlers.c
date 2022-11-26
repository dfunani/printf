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

/**
 * printOctal - prints base 8
 * @list: list to print
 *
 * Return: len
 *
 */

int printOctal(va_list list)
{
	int octalNum[100];
	int i = 0;
	int j = 0;
	int res = 0;
	unsigned int n;

	n = va_arg(list, unsigned int);
	while (n != 0)
	{
		octalNum[i] = n % 8;
		n = n / 8;
		i++;
	}
	for (j = i - 1; j >= 0; j--)
		res += _putchar(octalNum[j] + 48);
	return (res);
}
