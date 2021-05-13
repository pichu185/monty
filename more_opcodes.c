#include "monty.h"

/**
 * sub_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void sub_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;
	int i = 0;

	aux = *stack;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%i: can't sub, stack too short\n", l_count);
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	aux = (ext.stack)->next;
	aux->n = ((aux->n) - ((ext.stack)->n));
	aux->prev = NULL;
	free(ext.stack);
	ext.stack = aux;
}