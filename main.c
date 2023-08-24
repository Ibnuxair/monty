#include "monty.h"

/**
 * main - tests the code
 * @argc: the arguments count
 * @argv: the arguments vector
 *
 * Return: always 0 (success)
 */

int main(int argc, char **argv)
{
	FILE *fd;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	exec(fd);

	fclose(fd);
	return (EXIT_SUCCESS);
}
