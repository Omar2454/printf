#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_string - A function that prints a string to the standard output.
 * @s: The va_list that holds the string to be printed.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list s)
{
	char *my_string;
	int i, count = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(null)";
	for (i = 0; my_string[i]; i++)
	{
		if ((my_string[i] > 0 && my_string[i] < 32) || my_string[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			count += 2;
			count += print_hex((unsigned int)my_string[i], 1);
		}
		else
		{
			_putchar(my_string[i]);
			count++;
		}
	}
	return (count);
}
