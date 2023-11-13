#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - A function that prints a character.
 * @c: The va_list containing the character to be printed.
 *
 * Return: The number of characters printed (always 1).
 */

int print_char(va_list c)
{
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	return (1);
}

/**
 * print_porcentage - A function that prints a percentage symbol.
 *
 * Return: The number of characters printed (always 1).
 */

int print_porcentage(void)
{
	_putchar('%');
	return (1);
}
