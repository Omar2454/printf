#include "main.h"
#include <stdio.h>
#include <stdlib.h>

int print_char(va_list c)
{
	unsigned char my_char;

	my_char = va_arg(c, int);
	_putchar(my_char);
	return (1);
}

int print_porcentage(void)
{
	_putchar('%');
	return (1);
}
