#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"
char **op_tokens;
/**
 * find_instruction - gets the opcode
 * @opcode: the command
 *
 * Return: the pointer to the opcode, null when not found
 */

void (*find_instruction(char *opcode))(stack_t**, unsigned int)
{
	size_t i, op_num;
	instruction_t instructions[] = {
		{"push", mon_push},
		{"pall", mon_pall},
		{"pint", mon_pint},
		{"pop", mon_pop},
		{NULL, NULL}
		/* Add more instructions as needed */
	};

	op_num = sizeof(instructions) / sizeof(instructions[0]);

	for (i = 0; i < op_num; i++)
	{
		if (strcmp(opcode, instructions[i].opcode) == 0)
		{
			return (instructions[i].f);
		}
	}
	return (NULL);
}

/**
 * exec - executes the code
 * @fd: file descriptor/pointer
 */

void exec(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, *opcode;
	size_t len = 0;
	unsigned int line_num = 0;
	void (*op_func)(stack_t **, unsigned int);

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		op_tokens = splitLine(line);
		if (!op_tokens)
			continue;

		opcode = op_tokens[0];
		op_func = find_instruction(opcode);

		if (op_func)
		{
			op_func(&stack, line_num);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
			free(line);
			fclose(fd);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
}
