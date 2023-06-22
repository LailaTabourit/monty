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
	int i, valid_op;
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
		for (i = 0; instructions[i].opcode != NULL; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				valid_op = 1;
				instructions[i].f(&stack, line_num);
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
	_free_stack(&stack);
	fclose(f);
	return (0);
}
