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
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	printf("%i\n", (*stack)->n);
}

/**
 * pop_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void pop_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%i: can't pop an empty stack\n", l_count);
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	aux = (ext.stack);
	aux = aux->next;
	if (aux != NULL)
		aux->prev = NULL;
	free(ext.stack);
	ext.stack = aux;
}

/**
 * nop_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void nop_f(stack_t **stack, unsigned int l_count)
{
	(void)stack;
	(void)l_count;
}

/**
 * swap_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void swap_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;
	int i = 0, temp;

	aux = *stack;
	while (aux)
	{
		i++;
		aux = aux->next;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%i: can't swap, stack too short\n", l_count);
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	aux = (*stack)->next;
	temp = (*stack)->n;
	(*stack)->n = aux->n;
	aux->n = temp;
}

/**
 * add_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void add_f(stack_t **stack, unsigned int l_count)
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
		fprintf(stderr, "L%i: can't add, stack too short\n", l_count);
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	aux = (ext.stack)->next;
	aux->n = ((aux->n) + ((ext.stack)->n));
	aux->prev = NULL;
	free(ext.stack);
	ext.stack = aux;
}
