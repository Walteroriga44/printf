#include "main.h"

/**
 * get_width - Calculates the width for printing.
 * @format: Formatted str in which to print the args.
 * @i: List of args to be printed.
 * @list: list of args.
 *
 * Return: width value.
 */
int get_width(const char *format, int *i, va_list list)
{
	int curr_a;
	int width = 0;

	for (curr_a = *i + 1; format[curr_a] != '\0'; curr_a++)
	{
		if (is_digit(format[curr_a]))
		{
			width *= 10;
			width += format[curr_a] - '0';
		}
		else if (format[curr_a] == '*')
		{
			curr_a++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = curr_a - 1;

	return (width);
}
