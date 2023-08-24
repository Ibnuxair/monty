#include "monty.h"

/**
 * _strlen - generate the lenth of a given string
 * @s: the given string
 *
 * Return: the lenth of a string
*/

size_t _strlen(const char *s)
{
	size_t count = 0;

	while (s[count] != '\0')
	{
		count++;
	}

	return (count);

}
