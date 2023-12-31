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
	int  i = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(null)";
	while (my_string[i])
	{
		_putchar(my_string[i]);
		i++;
	}
	return (i);
}
