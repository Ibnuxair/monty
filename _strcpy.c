#include "monty.h"

/**
 * *_strcpy - copies a string
 * @dest: destination
 * @src: source
 *
 *Return: dest
 */

char *_strcpy(char *dest, char *src)
{
	int j;

	j = 0;
	while (src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';

	return (dest);
}
