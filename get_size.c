#include "main.h"

/**
 * get_size - Extracts and processes the size modifier from the format specifier.
 * @format: The format string containing the format specifier.
 * @i: A pointer to the current index in the format string.
 * It will be updated to the position after the size modifier.
 * Return: An integer representing the size modifier.
 * -1 if there is an error (multiple size modifiers or unsupported size modifier).
 */
int get_size(const char *format, int *i)
{
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}

