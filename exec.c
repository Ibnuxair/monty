#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

void prototype(void);
char **op_tokens;

/**
 * free_tokens - Frees the tokens array.
 */
void free_tokens(void)
{
	int i;

	if (op_tokens == NULL)
		return;

	for (i = 0; op_tokens[i]; i++)
		free(op_tokens[i]);
	free(op_tokens);
	op_tokens = NULL;
}

/**
 * is_line_empty - Checks if a line consists only of delimiters.
 * @line: The input string to check.
 * @delims: The set of delimiter characters.
 *
 * Return: 1 if the line is empty or contains only delimiters, 0 otherwise.
 */
int is_line_empty(char *line, char *delims)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delims[i]; j++)
		{
			if (line[i] == delims[j])
				break;
		}
		if (delims[j] == '\0')
			return (0);
	}
	return (1);
}

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
		{"swap", mon_swap},
		{"add", mon_add},
		{"nop", mon_nop},
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
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int exec(FILE *fd)
{
	stack_t *stack = NULL;
	char *line = NULL, *opcode;
	size_t len = 0, status = EXIT_SUCCESS;
	unsigned int line_num = 0;
	void (*op_func)(stack_t **, unsigned int);

	while (getline(&line, &len, fd) != -1)
	{
		line_num++;
		op_tokens = splitLine(line);
		if (op_tokens == NULL)
		{
			if (is_line_empty(line, DELIMS))
				continue;
			free(line);
			free_stack(&stack);
			return (malloc_err());
		}
		else if (op_tokens[0][0] == '#')
		{
			free_tokens();
			continue;
		}
		opcode = op_tokens[0];
		op_func = find_instruction(opcode);
		if (op_func)
			op_func(&stack, line_num);
		else
		{
			free_stack(&stack);
			status = invalid_op_err(op_tokens[0], line_num);
			free_tokens();
			free(line);
			return (status);
		}
	}
	free_stack(&stack);
	free_tokens();
	free(line);
	return (status);
}
