#include "main.h"

/**


* get_flags - Calculates active flags
* @format: Formatted str in which to print the args
* @i: A pointer to the current index in the format string
* Return: An int representing flags.
*/

int get_flags(const char *format, int *i)

{
	/* - + 0 # ' ' */

	/* 1 2 4 8 16 */

	int a, curr_i;

	int flags = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};

	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for(a = 0; FLAGS_CH[a] != '\0'; a++)

                        if (format[curr_i] == FLAGS_CH[a])

                        {

                                flags |= FLAGS_ARR[a];

                                break;

                        }


                if (FLAGS_CH[a] == 0)

                        break;

        }


        *i = curr_i - 1;


        return (flags);

}
