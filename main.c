#include "monty.h"

externs_t ext;

/**
 * main - entry point
 * @argc: the opcode
 * @argv: function to handle the opcode
 * Description: opcode and its function
 * Return: 0 on succes 1 on failure
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	unsigned int l_count = 1;
	ssize_t eof = 0;
	char *op_code, *op_int;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	ext.file = fopen(argv[1], "r");
	if (ext.file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	ext.buff = NULL;
	while ((eof = getline(&(ext.buff), &len, ext.file)) != -1)
	{
		op_code = strtok(ext.buff, " \t\n");
		if ((op_code == NULL) || op_code[0] == '#')
		{
			l_count++;
			continue;
		}
		op_int = strtok(NULL, " \t\n");
		validator(op_code, op_int, l_count);
		l_count++;
	}
	free_and_close(&(ext.stack), ext.buff);
	return (0);
}

/**
 * validator - entry point
 * @op_code: the opcode
 * @op_int: kkkk
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * Return: for stack, queues, LIFO, FIFO Holberton project
 */
int validator(char *op_code, char *op_int, unsigned int l_count)
{
	instruction_t valid[] = {{"push", push_f}, {"pall", pall_f}, {"pint", pint_f},
				 {"pop", pop_f}, {"nop", nop_f}, {"swap", swap_f}, {"add", add_f},
				 {"mul", mul_f}, {"div", div_f}, {"sub", sub_f}, {"mod", mod_f},
				 {"pchar", pchar_f}, {"pstr", pstr_f}, {"rotl", rotl_f},
				 {"rotr", rotr_f}, {NULL, NULL}};
	int i;

	for (i = 0; valid[i].opcode != NULL; i++)
	{
		if (strcmp(op_code, "push") == 0)
		{
			if (!op_int)
			{
				fprintf(stderr, "L%u: usage: push integer\n", l_count);
				free_and_close(&(ext.stack), ext.buff);
				exit(EXIT_FAILURE);
			}
			if (strcmp(op_int, "-0") == 0)
				op_int = "0";
			ext.value = atoi(op_int);
			if ((ext.value == 0 && (strcmp(op_int, "0") != 0)) || is_int(op_int) == 0)
			{
				fprintf(stderr, "L%u: usage: push integer\n", l_count);
				free_and_close(&(ext.stack), ext.buff);
				exit(EXIT_FAILURE);
			}
			valid[i].f(&(ext.stack), l_count);
			return (0);
		}
		if (strcmp(op_code, valid[i].opcode) == 0)
		{
			valid[i].f(&(ext.stack), l_count);
			return (0);
		}
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", l_count, op_code);
	free_and_close(&(ext.stack), ext.buff);
	exit(EXIT_FAILURE);
}

/**
 * push_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void push_f(stack_t **stack, unsigned int l_count)
{
	stack_t *new = NULL;

	l_count = l_count;
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	if (!stack)
	{
		free_and_close(&(ext.stack), ext.buff);
		exit(EXIT_FAILURE);
	}
	new->n = ext.value;
	new->prev = NULL;
	new->next = ext.stack;
	if (ext.stack)
		(ext.stack)->prev = new;
	ext.stack = new;
}

/**
 * pall_f - entry point
 * @stack: the opcode
 * @l_count: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
void pall_f(stack_t **stack, unsigned int l_count)
{
	stack_t *aux;

	l_count = l_count;
	aux = *stack;
	while (aux != NULL)
	{
		printf("%i\n", aux->n);
		aux = aux->next;
	}
}

/**
 * is_int - entry point
 * @op_int: the opcode
 * Description: opcode and its function
 * Return: for stack, queues, LIFO, FIFO Holberton project
 */
int is_int(char *op_int)
{
	int i = 0;

	if (op_int[0] == '-')
		i++;
	for (; op_int[i] != '\0' ; i++)
	{
		if (isdigit(op_int[i]) == 0)
			return (0);
	}
	return (1);
}
