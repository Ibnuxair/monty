#include "monty.h"

/**
 * free_stack -Frees the stack.
 * @stack: Pointer to the top node.
 */
void free_stack(stack_t **stack)
{
	stack_t *tmp = *stack;

	while (tmp)
	{
		*stack = tmp->next;
		free(tmp);
		tmp = *stack;
	}
}
