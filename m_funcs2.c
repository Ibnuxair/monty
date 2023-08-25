#include "monty.h"

/**
 * mon_add - Adds the top two elements of the stack.
 * * @stack: A pointer to the top mode.
 * @line_num: The current working line number of the bytecode.
 */
void mon_add(stack_t **stack, unsigned int line_num)
{
	stack_t *tmp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	tmp = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	free(tmp);
}
