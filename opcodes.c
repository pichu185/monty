#include "monty.h"

/**
 * pint_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void pint_f(stack_t **stack, unsigned int l_count)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pint, stack empty\n", l_count);
		free_a(&(ext.stack), ext.buff);
		fclose(ext.file);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}
