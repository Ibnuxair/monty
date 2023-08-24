#include "monty.h"

/**
 * find_instruction - gets the opcode
 * @opcode: the command
 *
 * Return: the pointer to the opcode, null when not found
 */

instruction_t *find_instruction(char *opcode)
{
    size_t i;
    instruction_t instructions[] = {
        {"push", handlePush},
        /* Add more instructions as needed */
    };

    size_t NUM_INSTRUCTIONS = sizeof(instructions) / sizeof(instructions[0]);
    
    for (i = 0; i < NUM_INSTRUCTIONS; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
        {
            return &instructions[i];
        }
    }
    return NULL;
}

/**
 * loop - executes the main loop
 * @argv: the arguments vector
 */

void loop(char **argv, FILE *fd)
{
    stack_t *stack = NULL;
    instruction_t *instruction;
    char *line = NULL, *opcode = NULL;
    size_t len = 0;
    unsigned int line_num = 0;

    while (getline(&line, &len, fd) != -1)
    {
        line_num++;

        if (sscanf(line, "%ms", &opcode) == 1)
        {
            instruction = find_instruction(opcode);
            if (instruction != NULL)
            {
                instruction->f(&stack, line_num);
            }
            else
            {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
                exit(EXIT_FAILURE);
            }
            free(opcode);
        }
    }
    free(line);
}
