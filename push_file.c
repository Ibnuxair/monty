#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	tmp = (stack_t *)malloc(sizeof(stack_t));

