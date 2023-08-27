#include "monty.h"

/**
 * usage_err - Prints usage message.
 *
 * Return: (EXIT_FAILURE) always.
 */
int usage_err(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * open_file_err - Prints message when it’s not possible to open the file.
 * @argv: The arguments vector.
 *
 * Return: (EXIT_FAILURE) always.
 */
int open_file_err(char **argv)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	return (EXIT_FAILURE);
}

/**
 * invalid_op_err - Prints a message, if the file contains an invalid instn.
 * @line_num: Number of the current line.
 * @opcode: The opcode.
 *
 * Return: (EXIT_FAILURE) always.
 */
int invalid_op_err(char *opcode, unsigned int line_num)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
	return (EXIT_FAILURE);
}

/**
 * no_int_err - Prints message when there's no integer value provided.
 * @line_num: Number othe current line.
 *
 * Return: (EXIT_FAILURE) always.
 */
int no_int_err(unsigned int line_num)
{
	fprintf(stderr, "L%u: usage: push integer\n", line_num);
	return (EXIT_FAILURE);
}

/**
 * malloc_err - Prints message when there's memory allocation error.
 *
 * Return: (EXIT_SUCCESS) always.
 */
int malloc_err(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	return (EXIT_FAILURE);
}
