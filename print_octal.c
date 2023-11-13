#include "main.h"

/**
 * print_octal - A function that prints an unsigned integer in octal format.
 * @o: The va_list that holds the unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */

int print_octal(va_list o)
{
	unsigned int len, powten, j, digit, n, num;
	int count = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 8;
			len++;
		}
		powten = 1;
		for (j = 1; j <= len - 1; j++)
			powten *= 8;
		for (j = 1; j <= len; j++)
		{
			digit = n / powten;
			_putchar(digit + '0');
			count++;
			n -= digit * powten;
			powten /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
