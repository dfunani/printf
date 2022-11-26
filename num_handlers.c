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
	unsigned int num;
	int res;
	char *octal;
	char *rev;

	num = va_arg(list, unsigned int);

	if (num == 0)
		return (_putr('0'));
	if (num < 1)
		return (-1);
	len = base_len(num, 8);

	octal_rep = malloc(sizeof(char) * len + 1);
	if (octal_rep == NULL)
		return (-1);
	for (len = 0; num > 0; len++)
	{
		octal_rep[len] = (num % 8) + 48;
		num = num / 8;

	}
	octal_rep[len] = '\0';
	rev_str = rev_string(octal_rep);
	if (rev_str == NULL)
		return (-1);

	write_base(rev_str);
	free(octal_rep);
	free(rev_str);
	return (len);
}
