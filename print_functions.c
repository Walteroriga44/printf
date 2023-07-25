#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a character.
 * @types: List of arg
 * @buffer: Buffer array
 * @flags:  ...
 * @width: ...
 * @precision: ...
 * @size: ...
 * Return: Number of chars printed
 */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a str
 * @types: List a of arg
 * @buffer: Buffer array
 * @flags:  Calculates flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (a = width - length; a > 0; a--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints (%) sign
 * @types: Lista of arguments
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: Number of chars printed
 */
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print integer.
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision
 * @size: Size
 * Return: Number of characters printed
 */
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int k = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[k--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[k--] = (num % 10) + '0';
		num /= 10;
	}

	k++;

	return (write_number(is_negative, k, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: List args
 * @buffer: Buffer array
 * @flags:  Calculates active flags
 * @width: width.
 * @precision: Precision
 * @size: Size
 * Return: Numbers of character printed.
 */
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, z, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	a[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		a[z] = (x / y) % 2;
	}
	for (z = 0, sum = 0, count = 0; z < 32; z++)
	{
		sum += a[z];
		if (sum || z == 31)
		{
			char j = '0' + a[z];

			write(1, &j, 1);
			count++;
		}
	}
	return (count);
}

