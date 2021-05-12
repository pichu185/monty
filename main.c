#include "monty.h"

int main(int argc, char *argv[])
{
  FILE *file;
  size_t len = 0, l_count = 0;
  char *buff = NULL;
  ssize_t eof = 0;
  char *op_code, *op_int;

  file = fopen(argv[1], "r");
  if (file == NULL)
    {
      fprintf(stderr, "Error: Can't open file %s", argv[1]);
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
      validator(op_code, op_int); //si el token es un string cualquiera, preguntar si es el nombre de un opcode valido. Si no es, return -1
      l_count++;
    }
}

int validator(char *op_code, char *op_int)
{
  instruction_t valid[] = {{"push", push_f}, {"pall", pall_f}, {NULL, NULL}};

  
}
