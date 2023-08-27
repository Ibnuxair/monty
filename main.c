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
	int status = EXIT_SUCCESS;

	if (argc != 2)
		return (usage_err());

	fd = fopen(argv[1], "r");
	if (!fd)
		return (open_file_err(argv));

	status = exec(fd);

	fclose(fd);
	return (status);
}
