#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
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
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct externs_s - opcode and its function
 * @value: the opcode
 * @stack: function to handle the opcode
 * @file: jjj
 * @buff: sdahsd
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct externs_s
{
	int value;
	stack_t *stack;
	FILE *file;
	char *buff;
} externs_t;

extern externs_t ext;

int validator(char *op_code, char *op_int, unsigned int l_count);
void push_f(stack_t **stack, unsigned int l_count);
void pall_f(stack_t **stack, unsigned int l_count);
int is_int(char *op_int);
void free_a(stack_t **stack, char *buff);
void pint_f(stack_t **stack, unsigned int l_count);
void pop_f(stack_t **stack, unsigned int l_count);
void nop_f(stack_t **stack __attribute__((unused)), unsigned int l_count __attribute__((unused)));

#endif
