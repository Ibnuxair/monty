#include "monty.h"
/**
 * pint_func - This func prints the value on the top
 * @stack: This is the head of the stack
 * @line_number: This is the number of the line
 * Return: Always returns nothing
*/

void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_stack(*stack);
		free(info.content);
		fclose(info.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
