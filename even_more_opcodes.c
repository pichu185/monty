#include "monty.h"

/**
 * pstr_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void pstr_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;

	aux = *stack;
	l_count = l_count;
	while (aux)
	{
		if (!isascii(aux->n) || aux->n == 0)
			break;
		printf("%c", aux->n);
		aux = aux->next;
	}
	printf("\n");
}

/**
 * rotl_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void rotl_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;
	int temp;

	if (*stack == NULL)
		return;
	l_count = l_count;
	aux = *stack;
	temp = aux->n;
	while (aux->next != NULL)
	{
		aux->n = aux->next->n;
		aux = aux->next;
	}
	aux->n = temp;
}

/**
 * rotr_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void rotr_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;
	int temp;

	if (*stack == NULL)
		return;
	l_count = l_count;
	aux = *stack;
	while (aux->next != NULL)
		aux = aux->next;
	temp = aux->n;
	while (aux->prev != NULL)
	{
		aux->n = aux->prev->n;
		aux = aux->prev;
	}
	aux->n = temp;
}
