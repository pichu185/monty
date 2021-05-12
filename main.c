#include "monty.h"

int main(int argc, char *argv[])
{
  FILE *file;
  size_t len = 0;
  unsigned int l_count = 1;
  char *buff = NULL;
  ssize_t eof = 0;
  char *op_code, *op_int;

  if (argc != 2)
    {
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
    }
  file = fopen(argv[1], "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  while ((eof = getline(&buff, &len, file)) != -1)
    {
      op_code = strtok(buff, " \t\n");
      if (op_code == NULL)
	{
	  l_count++;
	  continue;
	}
      op_int = strtok(NULL, " \t\n");
      validator(op_code, op_int, l_count);
      l_count++;
    }
}

int validator(char *op_code, char *op_int, unsigned int l_count)
{
  instruction_t valid[] = {
    {"push", push_f}, 
    {"pall", pall_f}, 
    {NULL, NULL}
  };
  int i, value;
  stack_t *stack;

  for (i = 0; valid[i].opcode != NULL; i++)
    {
      if (strcmp(op_code, "push") == 0)
	{
	  value = atoi(op_int);
	  if (value == 0 && (strcmp(op_int, "0") != 0))
	    {
	      fprintf(stderr, "L%u: usage: push integer", l_count);
	      exit(EXIT_FAILURE);
	    }
	  valid[i].f(&stack, l_count);
	  return (0);
        }
      if (strcmp(op_code, valid[i].opcode) == 0)
	{
	  valid[i].f(&stack, l_count);
	  return (0);
	}
    }
  fprintf(stderr, "L%u: unknown instruction %s", l_count, op_code);
  exit(EXIT_FAILURE);
}

void push_f(stack_t **stack, unsigned int l_count)
{
  stack_t *new = NULL;
  int value = 2;

  l_count = l_count;
  new = malloc(sizeof(stack_t));
  if (!new)
    {
      fprintf(stderr, "Error: malloc failed");
      free(*stack);
      exit(EXIT_FAILURE);
    }
  if (!stack)
    {
      free(*stack);
      exit(EXIT_FAILURE);
    }
  new->n = value;
  new->prev = NULL;
  new->next = *stack;
  if (*stack)
    (*stack)->prev = new;
  *stack = new;
}

void pall_f(stack_t **stack, unsigned int l_count)
{
  stack_t *aux;

  aux = *stack;
  while (aux != NULL)
    {
      fprintf(stdin, "%i", aux->n);
      aux = aux->next;
    }
}
