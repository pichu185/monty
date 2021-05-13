#include "monty.h"

externs_t ext;

int main(int argc, char *argv[])
{
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
  ext.file = fopen(argv[1], "r");
  if (ext.file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
      exit(EXIT_FAILURE);
    }
  while ((eof = getline(&buff, &len, ext.file)) != -1)
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
  instruction_t valid[] = {{"push", push_f}, {"pall", pall_f}, {NULL, NULL}};
  int i;

  for (i = 0; valid[i].opcode != NULL; i++)
    {
      if (strcmp(op_code, "push") == 0)
	{
	  if (valid_int(op_int) == 1)
	    {
	      ext.value = atoi(op_int);
	    }
	  else
	    {
	      fprintf(stderr, "L%u: usage: push integer\n", l_count);
	      exit(EXIT_FAILURE);
	    }
	  printf("%s ----- %i\n", op_int, ext.value);
	  if (ext.value == 0 && (strcmp(op_int, "0") != 0))
	    {
	      fprintf(stderr, "L%u: usage: push integer\n", l_count);
	      exit(EXIT_FAILURE);
	    }
	  valid[i].f(&(ext.stack), l_count);
	  return (0);
        }
      if (strcmp(op_code, valid[i].opcode) == 0)
	{
	  printf("identifica pall\n");
	  valid[i].f(&(ext.stack), l_count);
	  return (0);
	}
    }
  fprintf(stderr, "L%u: unknown instruction %s", l_count, op_code);
  exit(EXIT_FAILURE);
}

void push_f(stack_t **stack, unsigned int l_count)
{
  stack_t *new = NULL;

  l_count = l_count;
  new = malloc(sizeof(stack_t));
  if (!new)
    {
      fprintf(stderr, "Error: malloc failed");
      free(ext.stack);
      exit(EXIT_FAILURE);
    }
  if (!stack)
    {
      free(ext.stack);
      exit(EXIT_FAILURE);
    }
  printf("valor: %i antes de insertar al nodo  \n", ext.value);
  new->n = ext.value;
  new->prev = NULL;
  new->next = ext.stack;
  if (ext.stack)
    (ext.stack)->prev = new;
  ext.stack = new;
  /*
  aux = *stack;
  while (aux)
    {
      printf("%i (valores de la lista)\n", aux->n);
      aux = aux->next;
    }
  */
}

void pall_f(stack_t **stack, unsigned int l_count)
{
  stack_t *aux;

  aux = ext.stack;
  while (aux != NULL)
    {
      printf("%i\n", aux->n);
      aux = aux->next;
    }
  printf("termina de recorrer lista\n");
}

int valid_int(char *op_int)
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
