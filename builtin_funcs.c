#include "monty.h"

/**
 * handlePush - handles the push opcode
 * @stack: the stack pointer
 * @line_num: the line number
 */
void handlePush(stack_t **stack, unsigned int line_num)
{
        int value;
	char *line;
	
	if (sscanf(line, "push %d", &value) == 1)
        {
            stack_t *new_node = malloc(sizeof(stack_t));
            if (new_node == NULL)
            {
                fprintf(stderr, "Error: malloc failed\n");
                exit(EXIT_FAILURE);
            }

            new_node->n = value;
            new_node->prev = NULL;
            new_node->next = *stack;

            if (*stack != NULL)
            {
                (*stack)->prev = new_node;
            }

            *stack = new_node;
        }
        else
        {
            fprintf(stderr, "L%u: usage: push integer\n", line_num);
            exit(EXIT_FAILURE);
        }
}
