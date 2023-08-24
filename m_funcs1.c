#include "monty.h"

/**
 * mon_push - Inserts a value to a stack linked list.
 * @stack: Pointer to the top of the stac.
 * @line_num: The line number the interpreter is reading.
 */

void mon_push(stack_t **stack, unsigned int line_num)
{
	stack_t *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (op_tokens[1] == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_num);
		free(new_node);
		exit(EXIT_FAILURE);
	}

	for (i = 0; op_tokens[1][i]; i++)
	{
		if (i == 0 && (op_tokens[1][i] == '-' || op_tokens[1][i] == '+'))
			continue;
		if (op_tokens[1][i] < '0' || op_tokens[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_num);
			free(new_node);
			exit(EXIT_FAILURE);
		}
	}

	new_node->n = _atoi(op_tokens[1]);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	{
		(*stack)->prev = new_node;
	}

	*stack = new_node;
}

/**
 * mon_pall - Prints the values of a stack linked list.
 * @stack: A pointer to the top mode.
 * @line_num: The current working line number of the bytecode.
 */

void mon_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp = *stack;

	(void)line_num;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
