#include "monty.h"
/**
* _add - adds the top two elements of stack.
* @stack: head
* @line_number: line_number
* by: laila and mega
* Return: void
*/
void _add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	_pop(stack, line_number);
}
