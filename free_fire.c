#include "monty.h"

void free_a(stack_t **stack, char *buff)
{
  stack_t *fire;

  free(buff);
  while (*stack)
    {
      fire = *stack;
      *stack = (*stack)->next;
      free(fire);
    }
}
