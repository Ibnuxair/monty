#ifndef MONTY_H
#define MONTY_H

/* Header files */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

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

/**
 * struct info_s - This is the function used for 
 * all the infomations in the monty program
 * @file_line: this is used to store the file line
 * @file: this is the file to open
 * @arg_file: this is the file name in executing
 * the program
 * @content: the content of the file
 */

typedef struct info_s
{
	unsigned int file_line;
	FILE *file;
	char *arg_file;
	char *content;
}  info_t;

extern info_t info;

/* prototypes */
void execute(int argc, char *argv[]);
void push(stack_t **head, unsigned int line_number);
void pall_file(stack_t **head, unsigned int line_number);

#endif
