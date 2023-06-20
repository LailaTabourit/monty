#include "monty.h"

#define BUFF_SIZE 1024
/**
* main - main function
* @argc: Number command line arguments.
* @argv: An array of arguments
* by: laila and mega
* Return: Always 0
*/
int main(int argc, char *argv[])
{
	int n, valid_op = 0;
	char buff[BUFF_SIZE], *opcode;
	stack_t *stack = NULL;
	unsigned int line_num = 0;
	instruction_t *instructions;
	FILE *f;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	f = fopen(argv[1], "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	instructions = _init_instructions();

	while (fgets(buff, BUFF_SIZE, f))
	{
		line_num++;
		opcode = strtok(buff, " \n\t");
		if (opcode == NULL || opcode[0] == '#')
			continue;
		valid_op = 0;
		for (n = 0; instructions[n].opcode != NULL; n++)
		{
			if (strcmp(opcode, instructions[n].opcode) == 0)
			{
				valid_op = 1;
				instructions[n].f(&stack, line_num);
				break;
			}
		}
		if (!valid_op)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_num, opcode);
			fclose(f);
			_free_stack(&stack);
			return (EXIT_FAILURE);
		}
	}
	fclose(f);
	_free_stack(&stack);
	return (EXIT_SUCCESS);
}
