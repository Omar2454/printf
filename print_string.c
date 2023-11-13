#include "main.h"
#include <stdio.h>

/**
 * print_string - A function that prints a string to the standard output.
 * @s: The va_list that holds the string to be printed.
 *
 * Return: The number of characters printed.
 */

int print_string(va_list s)
{
	char *my_string;
	int i = 0, count = 0;

	my_string = va_arg(s, char *);
	if (my_string == NULL)
		my_string = "(null)";

	while (my_string[i])
	{
		// Check if the character is non-printable
		if (my_string[i] < 32 || my_string[i] >= 127)
		{
			// Print non-printable characters in the required format
			_putchar('\\');
			_putchar('x');
			// Print the ASCII code value in hexadecimal (always 2 characters)
			if (my_string[i] < 16)
				_putchar('0');
			// Use the _putchar function to print the hexadecimal value
			count += _putchar_hex(my_string[i]);
		}
		else
		{
			// Print printable characters using _putchar
			_putchar(my_string[i]);
			count++;
		}
		i++;
	}
	return count;
}
