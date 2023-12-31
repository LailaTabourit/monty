#include "monty.h"

/**
* f_pint - prints the top
* @stack: stack head
* @line_number: line_number
* Made By Laila and Mega
* Return: void
*/

void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
}

	printf("%d\n", (*stack)->n);
}
