/**
 * _putchar_hex - Print the hexadecimal representation of a character.
 * @c: The character whose hexadecimal representation to print.
 *
 * Return: The number of characters printed.
 */

int _putchar_hex(char c)
{
	int count = 0;
	int value, i;
	char hex_digits[] = "0123456789ABCDEF";

	for (i = 1; i >= 0; i--)
	{
		value = (c >> (i * 4)) & 0xF;
		_putchar(hex_digits[value]);
		count++;
	}
	return count;
}
