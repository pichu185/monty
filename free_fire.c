#include "monty.h"

/**
 * free_and_close - entry point
 * @stack: the opcode
 * @buff: kkkk
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void free_and_close(stack_t **stack, char *buff)
{
	stack_t *fire;

	free(buff);
	while (*stack)
	{
		fire = *stack;
		*stack = (*stack)->next;
		free(fire);
	}
	fclose(ext.file);
}
