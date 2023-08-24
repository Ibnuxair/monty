#include "monty.h"
/**
 * pall_func - prints the stack
 * @head: This is the head of the stack
 * @counter: This will not be used here
 * Return: always nothing
*/
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)counter;
	tmp = *stack;
	if (tmp == NULL)
		return;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	return;
}
