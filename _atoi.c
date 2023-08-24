#include "monty.h"

/**
 * _atoi - convert a string to an integer
 * @s: string
 *
 * Return: integer number
 */

int _atoi(char *s)
{
	int res = 0;
	int sign = 1;
	int digit, is_digit = 0;

	while (*s != '\0')
	{
		if (*s >= '0' && *s <= '9')
		{
			is_digit = 1;
			digit = *s - '0';
			if (res > INT_MAX / 10 ||
			    (res == INT_MAX / 10 && digit > INT_MAX % 10))
			{
				/* Integer overflow occurred */
				return ((sign == 1) ? INT_MAX : INT_MIN);
			}
			res = res * 10 + digit;
		}
		else if (is_digit)
		{
			break;
		}
		else if (*s == '-')
		{
			sign *= -1;
		}
		s++;
	}

	return (res * sign);
}
