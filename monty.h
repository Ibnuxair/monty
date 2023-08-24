#ifndef MONTY_H
#define MONTY_H

/* Headers */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define DELIM " \n\t\a\b"

extern char **op_tokens;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Function prototypes */
void exec(FILE *fd);
void (*find_instruction(char *opcode))(stack_t**, unsigned int);
char **lineTokenizer(char *line, int *tokensNum);
char **splitLine(char *line);
int _atoi(char *s);
size_t _strlen(const char *s);
char *_strcpy(char *dest, char *src);
void mon_push(stack_t **stack, unsigned int line_num);
void mon_pall(stack_t **stack, unsigned int line_num);

#endif /* ENDIF */
