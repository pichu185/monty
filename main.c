#include "monty.h"

int main(int argc, char *argv[])
{
  FILE *file;
  size_t len = 0, l_count = 1;
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
      op_code = strtok(buff, " \t");
      if (op_code == "\n")
	{
	  l_count++;
	  continue;
	}
      op_int = strtok(NULL, " \t");
      validator(op_code, op_int, l_count); //si el token es un string cualquiera, preguntar si es el nombre de un opcode valido. Si no es, return -1
      l_count++;
    }
}

int validator(char *op_code, char *op_int, size_t l_count)
{
  instruction_t valid[] = {{"push", push_f}, {"pall", pall_f}, {NULL, NULL}};
  int i;
  stack_t **stack;

  for (i = 0; valid[i].opcode != NULL; i++)
    {
      if (strcmp(op_code, "push") == 0)
	{
	  valid[i].f(&stack, l_count, op_int);
	  return (1);
        }
      if (strcmp(opcode, valid[i].opcode) == 0)
	{
	  valid[i].f(&stack, l_count);
	  return (1)
	}
    }
  fprintf(stderr, "L%i: unknown instruction %s", l_count, op_code);
  exit(EXIT_FAILURE);
}

void push_f(stack_t **stack, l_count, op_int)
{
  stack_t *new = NULL;
  int value;

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
  new->n = n;
  new->prev = NULL;
  new->next = *stack;
  if (*stack)
    (*stack)->prev = new;
  *stack = new;
}
