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
		malloc_err();
	}

	if (op_tokens[1] == NULL)
	{
		free(new_node);
		no_int_err(line_num);
	}

	for (i = 0; op_tokens[1][i]; i++)
	{
		if (i == 0 && (op_tokens[1][i] == '-' || op_tokens[1][i] == '+'))
			continue;
		if (op_tokens[1][i] < '0' || op_tokens[1][i] > '9')
		{
			free(new_node);
			no_int_err(line_num);
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

/**
 * mon_pint - prints the value at the top of the stack, followed by a new line
 * @stack: A pointer to the top mode.
 * @line_num: The current working line number of the bytecode.
 */
void mon_pint(stack_t **stack, unsigned int line_num)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * mon_pop -  Removes the top element of the stack.
 * @stack: A pointer to the top mode.
 * @line_num: The current working line number of the bytecode.
 */
void mon_pop(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	*stack = (*stack)->next;
	if (*stack)
		(*stack)->prev = NULL;

	free(tmp);
}

/**
 * mon_swap - Swaps the top two elements of the stack.
 * @stack: A pointer to the top mode.
 * @line_num: The current working line number of the bytecode.
 */
void mon_swap(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next)
		tmp->next->prev = *stack;
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}
