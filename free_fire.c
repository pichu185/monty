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

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
